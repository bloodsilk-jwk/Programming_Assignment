#include <iostream>
#include <cstring>
#include <thread>
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

class TCPClient {
private:
    SOCKET clientSocket;
    sockaddr_in serverAddr;
    bool running = true;
    // ID
    std::string ID;

public:
    TCPClient(const std::string& serverIP = "127.0.0.1", int port = PORT) {
        std::cout << "ID를 입력하세요 : " << std::endl;
        std::cin >> ID;

        initializeWinsock();
        clientSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (clientSocket == -1) {
            std::cerr << "소켓 생성 실패!" << std::endl;
            cleanupWinsock();
            exit(1);
        }

        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(port);
        inet_pton(AF_INET, serverIP.c_str(), &serverAddr.sin_addr);

        if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
            std::cerr << "서버 연결 실패!" << std::endl;
            closesocket(clientSocket);
            cleanupWinsock();
            exit(1);
        }
        std::cout << "서버에 연결 성공!" << std::endl;

        if (send(clientSocket, ID.c_str(), ID.size(), 0) == -1) {
            std::cerr << "ID 전송 실패!" << std::endl;
            closesocket(clientSocket);
            cleanupWinsock();
            exit(1);
        }
        std::cout << "ID 전송 성공!" << std::endl;
    }

    void receiveLoop() {
        char buffer[BUFFER_SIZE];
        while (running) {
            memset(buffer, 0, BUFFER_SIZE);
            int bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE, 0);
            if (bytesReceived > 0) {
                std::cout << buffer << std::endl;
            }
            else if (bytesReceived == 0) {
                std::cout << "서버 연결 종료." << std::endl;
                running = false;
            }
            else {
                std::cerr << "데이터 수신 오류." << std::endl;
                running = false;
            }
        }
    }

    void sendLoop() {
        std::string input;
        while (running) {
            std::cin >> input;
            if (input == "exit") {
                running = false;
                break;
            }
            send(clientSocket, input.c_str(), input.size(), 0);
        }
    }

    void run() {
        std::thread recvThread(&TCPClient::receiveLoop, this);
        sendLoop();
        recvThread.join();
    }

    void closeClient() {
        closesocket(clientSocket);
        cleanupWinsock();
        std::cout << "클라이언트 종료!" << std::endl;
    }
};

int main() {
    std::cout << "클라이언트 모드로 실행됩니다." << std::endl;

    TCPClient client;
    client.run();
    client.closeClient();
    return 0;
}