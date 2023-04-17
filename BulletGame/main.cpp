#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <Windows.h>

// canvas
struct Canvas {
	char*	frameBuffer;
	int		size;
};

extern void canvas_clear(Canvas*);

void canvas_init(Canvas* canvas, int size)
{
	canvas->frameBuffer = (char*)malloc(sizeof(char) * (size + 1));
	canvas->size = size;

	canvas_clear(canvas);
}

void canvas_clear(Canvas* canvas)
{
	//if (canvas.frameBuffer == nullptr || canvas.size <= 0) return;
	for (int i = 0; i < canvas->size; i++)
		canvas->frameBuffer[i] = ' ';
	canvas->frameBuffer[canvas->size] = '\0';
}

void canvas_draw(Canvas* canvas, const char* shape, int pos, bool visible)
{
	if (canvas->frameBuffer == nullptr || visible == false || shape == nullptr) return;

	for (int i = 0; i < strlen(shape); i++)
	{
		if (pos + i < 0) continue;
		if (pos + i > canvas->size-1) continue;

		canvas->frameBuffer[pos + i] = shape[i];
	}
}

void canvas_render(const Canvas* canvas)
{
	printf("%s\r", canvas->frameBuffer);
}

void canvas_deinit(Canvas* canvas)
{
	free(canvas->frameBuffer);
	canvas->frameBuffer = nullptr;
	canvas->size = 0;
}

// player
struct Player {
	char*	shape;
	int		pos;
	bool	visible;
};

void player_init(Player* player, const char* shape, int pos, bool visible)
{
	if (shape == nullptr) {
		printf("player shape should be determined");
		exit(0);
	}
	player->shape = (char*)malloc(sizeof(char) * (strlen(shape) + 1));
	strcpy(player->shape, shape);

	player->pos = pos;
	player->visible = visible;
}

void player_draw(const Player* player, Canvas* canvas)
{
	canvas_draw(canvas, player->shape, player->pos, player->visible);
}

void player_update(Player* player)
{
}

void player_deinit(Player* player)
{
	free(player->shape);
	player->shape = nullptr;
	player->pos = 0;
	player->visible = false;
}

// enemy
struct Enemy {
	char*	shape;
	int		pos;
	bool	visible;
};

void enemy_init(Enemy* enemy, const char* shape, int pos, bool visible)
{
	if (shape == nullptr) {
		printf("enemy shape should be determined");
		exit(0);
	}
	enemy->shape = (char*)malloc(sizeof(char) * (strlen(shape) + 1));
	strcpy(enemy->shape, shape);

	enemy->pos = pos;
	enemy->visible = visible;
}

void enemy_draw(const Enemy* enemy, Canvas* canvas)
{
	canvas_draw(canvas, enemy->shape, enemy->pos, enemy->visible);
}

void enemy_update(Enemy* enemy)
{

}

bool enemy_isColliding(const Enemy* enemy, int pos)
{
	if (pos >= enemy->pos && pos < enemy->pos + strlen(enemy->shape))
		return true;
	return false;
}

void enemy_deinit(Enemy* enemy)
{
	free(enemy->shape);
	enemy->shape = nullptr;
	enemy->pos = 0;
	enemy->visible = false;
}

// bullet
struct Bullet {
	char*	shape;
	int		pos;
	bool	visible;
	int		direction; // 0 : Left to Right, 1: Right to Left
	int		num_remainging_frames_to_fire; // 30 :
};

void bullet_init(Bullet* bullet, const char* shape, int pos, bool visible, int direction, int n_frames)
{
	if (shape == nullptr) {
		printf("bullet input shape is not defined");
		exit(0);
	}
	bullet->shape = (char*)malloc(sizeof(char) * (strlen(shape) + 1));
	strcpy(bullet->shape, shape);
	
	bullet->pos = pos;
	bullet->visible = visible;
	bullet->direction = direction;
	bullet->num_remainging_frames_to_fire = n_frames;
}

void bullet_draw(const Bullet* bullet, Canvas* canvas)
{
	canvas_draw(canvas, bullet->shape, bullet->pos, bullet->visible);
}

void bullet_fire(Bullet* bullet, const Player* player, const Enemy* enemy)
{
	if (player->pos == enemy->pos) return;

	bullet->direction = 0;
	strcpy(bullet->shape, ">");

	if (player->pos > enemy->pos)
	{
		bullet->direction = 1;
		strcpy(bullet->shape, "<");
	}

	bullet->pos = player->pos;
	if (bullet->direction == 0)
		bullet->pos += (strlen(player->shape) - 1);
	bullet->visible = true;

	return;
}

void bullet_move(Bullet* bullet)
{
	// update bullet_pos
	if (bullet->direction == 0) {
		bullet->pos++;
	}
	else {
		bullet->pos--;
	}
}

void bullet_update(Bullet* bullet, const Player* player, const Enemy* enemy)
{
	--bullet->num_remainging_frames_to_fire;
	if (bullet->num_remainging_frames_to_fire == 0)
	{
		bullet_fire(bullet, player, enemy);
	}

	if (bullet->visible == false) return;

	bullet_move(bullet);
	
	// check whether bullet pos is equal to enemy pos
	if (enemy_isColliding(enemy, bullet->pos))
	{
		bullet->visible = false;
	}
}

void bullet_deinit(Bullet* bullet)
{
	free(bullet->shape);
	bullet->shape = nullptr;
	bullet->pos = 0;
	bullet->direction = 0;
	bullet->visible = false;
	bullet->num_remainging_frames_to_fire = 0;
}


int main()
{
	Canvas	canvas;
	Player	player;
	Enemy	enemy;
	Bullet	bullet;
	Bullet	bullet2;

	canvas_init(&canvas, 80);
	player_init(&player, "(^____^)", 10, true);
	enemy_init(&enemy, "(*_*)", 50, true);
	bullet_init(&bullet, ">", 0, false, 0, 30);
	bullet_init(&bullet2, ">", 0, false, 0, 35);

	while (true) 
	{
		canvas_clear(&canvas);

		player_draw(&player, &canvas);
		enemy_draw(&enemy, &canvas);
		bullet_draw(&bullet, &canvas);
		bullet_draw(&bullet2, &canvas);

		player_update(&player);
		enemy_update(&enemy);
		bullet_update(&bullet, &player, &enemy);
		bullet_update(&bullet2, &player, &enemy);

		canvas_render(&canvas);
		Sleep(100);
	}

	bullet_deinit(&bullet2);
	bullet_deinit(&bullet);
	enemy_deinit(&enemy);
	player_deinit(&player);
	canvas_deinit(&canvas);


	return 0;
}