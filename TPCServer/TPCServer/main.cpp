#include <iostream>
#include <cstring>
#include <thread>
#include <vector>
#include <atomic>
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
typedef int SOCKET;
#define closesocket close
#endif

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 4

#ifdef _WIN32
void initializeWinsock() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup 실패!" << std::endl;
        exit(1);
    }
}
void cleanupWinsock() {
    WSACleanup();
}
#else
void initializeWinsock() {}
void cleanupWinsock() {}
#endif

std::atomic<bool> serverRunning(true);

// "Client" Class which includes socket & ID
class Client {
private:
    SOCKET m_socket;
    std::string m_ID;
public:
    Client(SOCKET socket, std::string ID) : m_socket(socket), m_ID(ID) {
    }
    ~Client() {
    }
    std::string getID() const { return this->m_ID; }
    void setID(std::string ID) { this->m_ID = ID; }

    SOCKET getSocket() const { return this->m_socket; }
    void SetSocket(SOCKET socket) { this->m_socket = socket; }
};

// send recieved messages to all clients except sender
void broadcastMessage(SOCKET senderSocket,std::string senderID, const std::string message, std::vector<Client>& clients)
{
    std::string chat = senderID + " : " + message;
    for (const Client& client : clients)
    {
        if (client.getSocket() != senderSocket)
        {
            send(client.getSocket(), chat.c_str(), chat.size(), 0);
        }
    }
}

void handleClient(SOCKET clientSocket, std::vector<Client>& clients) {
    char buffer[BUFFER_SIZE];
    bool connected = true;

    // Get ID from the client
    memset(buffer, 0, BUFFER_SIZE);
    int bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE, 0);
    if (bytesReceived == -1) {
        std::cerr << "ID 확인 실패!" << std::endl;
        closesocket(clientSocket);
        return;
    }
    std::string ID = std::string(buffer);

    // Add Client to "clients" vector
    clients.push_back(Client(clientSocket, ID));
    std::cout << "클라이언트 \"" << ID << "\" 연결됨." << std::endl;


    while (connected && serverRunning) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE, 0);
        if (bytesReceived > 0) {
            std::cout << "클라이언트 " << ID << " : " << buffer << std::endl;
            if (std::string(buffer) == "0") {
                std::cout << "서버 종료 명령 수신." << std::endl;
                serverRunning = false;
                break;
            }
            std::string response = std::string(buffer);
            
            broadcastMessage(clientSocket, ID, response, std::ref(clients));
        }
        else {
            std::cout << "클라이언트 \"" << ID << "\" 연결 종료." << std::endl;
            connected = false;
        }
    }

    closesocket(clientSocket);
    auto it = std::remove_if(clients.begin(), clients.end(), [&](const Client& c) {return c.getID() == ID; });
    clients.erase(it, clients.end());

}

int main() {
    initializeWinsock();

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "서버 소켓 생성 실패!" << std::endl;
        cleanupWinsock();
        return 1;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "바인딩 실패!" << std::endl;
        closesocket(serverSocket);
        cleanupWinsock();
        return 1;
    }

    if (listen(serverSocket, 5) < 0) {
        std::cerr << "리스닝 실패!" << std::endl;
        closesocket(serverSocket);
        cleanupWinsock();
        return 1;
    }

    std::cout << "서버가 포트 " << PORT << "에서 실행 중입니다..." << std::endl;
    std::vector<std::thread> threads;
    int clientCount = 0;

    // vector that manages "Client" class
    std::vector<Client> clients;

    while (serverRunning && clientCount < MAX_CLIENTS) {
        sockaddr_in clientAddr;
        socklen_t clientSize = sizeof(clientAddr);
        SOCKET clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientSize);
        if (clientSocket == -1) {
            std::cerr << "클라이언트 연결 실패!" << std::endl;
            continue;
        }
        //std::cout << "클라이언트 연결됨." << std::endl;

        threads.emplace_back(handleClient, clientSocket, std::ref(clients));
        clientCount++;
    }
    
    for (auto& t : threads) {
        if (t.joinable()) t.join();
    }

    closesocket(serverSocket);
    cleanupWinsock();
    std::cout << "서버가 종료되었습니다." << std::endl;
    return 0;
}