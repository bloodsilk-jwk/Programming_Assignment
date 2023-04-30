#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <Windows.h>

// GameObject
struct GameObject {
	char* shape;
	int pos;
	bool visible;

	GameObject(const char* shape, int pos, bool visible) :
		shape((char*)malloc(sizeof(char)* strlen(shape) + 1)),	pos(pos), visible(visible) {
		if (this->shape != nullptr) strcpy(this->shape, shape);
	}

};

// canvas
struct Canvas {


	Canvas(int size) // 생성자 constructor
	{
		this->size = size;
		frameBuffer = (char*)malloc(sizeof(char) * (size + 1));
		clear();
	}

	void clear()
	{
		for (int i = 0; i < size; i++)
			frameBuffer[i] = ' ';
		frameBuffer[size] = '\0';
	}

	void draw(const char* shape, int pos, bool visible)
	{
		if (visible == false) return;

		for (int i = 0; i < strlen(shape); i++)
		{
			if (pos + i < 0) continue;
			if (pos + i > size - 1) continue;

			frameBuffer[pos + i] = shape[i];
		}
	}

	void render() const
	{
		printf("%s\r", frameBuffer);
	}

	~Canvas() // 소멸자 destructor
	{
		free(frameBuffer);
		frameBuffer = nullptr;
		size = 0;
	}

	char* frameBuffer;
	int		size;

};

// player
struct Player {
	GameObject gameObject;

	Player(const char* shape, int pos, bool visible) 
		: gameObject(shape, pos, visible) {
	}

	int getPos() const { return gameObject.pos; }  // getter

	int getShapeSize() const { return strlen(gameObject.shape); }

	void draw(Canvas& canvas) const
	{
		canvas.draw(gameObject.shape, gameObject.pos, gameObject.visible);
	}

	void update()
	{
	}

	~Player()
	{
		free(gameObject.shape);
		gameObject.shape = nullptr;
		gameObject.pos = 0;
		gameObject.visible = false;
	}
};

// enemy
struct Enemy {
	GameObject gameObject;

	Enemy(const char* shape, int pos, bool visible) 
		: gameObject(shape, pos, visible) {

	}

	int getPos() const { return gameObject.pos; }

	void draw(Canvas& canvas) const
	{
		canvas.draw(gameObject.shape, gameObject.pos, gameObject.visible);
	}

	void update()
	{
	}

	bool isColliding(int pos) const
	{
		return (pos >= gameObject.pos && pos < gameObject.pos + strlen(gameObject.shape));
	}

	~Enemy()
	{
		free(gameObject.shape);
		gameObject.shape = nullptr;
		gameObject.pos = 0;
		gameObject.visible = false;
	}

};

// bullet
struct Bullet {
	GameObject gameObject;
	int		direction; // 0: L2R, 1: R2L
	int		num_remaining_frames_to_fire;

	Bullet(const char* shape, int pos, bool visible, int direction, int n_frames)
		: gameObject(shape, pos, visible), direction(direction), num_remaining_frames_to_fire(n_frames) {
	}

	void draw(Canvas& canvas) const
	{
		canvas.draw(gameObject.shape, gameObject.pos, gameObject.visible);
	}

	void fire(const Player& player, const Enemy& enemy)
	{
		int player_pos = player.getPos();
		int enemy_pos = enemy.getPos();
		if (enemy_pos == player_pos) return;

		gameObject.visible = true;

		gameObject.pos = player_pos + player.getShapeSize();
		direction = 0;
		strcpy(gameObject.shape, ">");
		if (enemy_pos < player_pos)
		{
			gameObject.pos = player_pos;
			direction = 1;
			strcpy(gameObject.shape, "<");
		}
	}

	void move()
	{
		if (direction == 0) gameObject.pos++;
		else gameObject.pos--;
	}

	void update(const Player& player, const Enemy& enemy)
	{
		num_remaining_frames_to_fire--;
		if (num_remaining_frames_to_fire == 0)
		{
			fire(player, enemy);
			return;
		}
		if (gameObject.visible == false) return;

		move();

		// check whether bullet collides with enemy
		if (enemy.isColliding(gameObject.pos)) {
			gameObject.visible = false;
		}
	}

	~Bullet()
	{
		free(gameObject.shape);
		gameObject.shape = nullptr;
		gameObject.pos = 0;
		gameObject.visible = 0;
		direction = 0;
		num_remaining_frames_to_fire = 0;
	}

};

int main()
{
	Canvas* canvas = new Canvas(80);
	
	Player* player = new Player("(^___^)", 50, true);
	Enemy*	enemy = new Enemy("(*-*)", 10, true);
	Bullet* bullet = new Bullet(">", 10, false, 0, 30);
	Bullet*	bullet2 = new Bullet(">", 10, false, 0, 40);

	while (true)
	{
		canvas->clear();

		player->draw(*canvas);
		enemy->draw(*canvas);
		bullet->draw(*canvas); 
		bullet2->draw(*canvas);

		player->update();
		enemy->update();
		bullet->update(*player, *enemy); 
		bullet2->update(*player, *enemy);

		canvas->render();
		Sleep(100);
	}

	delete bullet2;
	delete bullet;
	delete enemy;
	delete player;
	delete canvas;


	return 0;
}