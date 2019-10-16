#include "raylib.h"
#include <stdlib.h>

struct Player {
	Rectangle rec;
	Color color;
};
struct Enemy1 {
	Rectangle rec;
	Color color;
};
Player player;
Enemy1 enemy;

void initPlayer() {
	player.rec.x = 40.0f;
	player.rec.y = GetScreenHeight() / 2.0f;
	player.rec.width = 40;
	player.rec.height = 40;
	player.color = SKYBLUE;
}
void initEnemy() {
	enemy.rec.x = 880.0f;
	enemy.rec.y = rand() % 400 + 40;
	enemy.rec.height = 40.0f;
	enemy.rec.width = 40.0f;
	enemy.color = RED;
}
void enemyUpdate() {
	enemy.rec.x -= 5.0f;
	if (enemy.rec.x <= -40.0f) {
		enemy.rec.x = 880.0f;
		enemy.rec.y = rand() % 400 + 40;
	}
}
void input() {
	if (IsKeyDown(KEY_W))
		player.rec.y -= 3.0f;
	if (IsKeyDown(KEY_S))
		player.rec.y += 3.0f;
}
void draw() {
	BeginDrawing();
	ClearBackground(RAYWHITE);
	DrawRectangleRec(player.rec, player.color);
	DrawRectangleRec(enemy.rec, enemy.color);
	EndDrawing();
}
void collisions(bool& progRuntime) {
	if (player.rec.y < 0)
		player.rec.y = 1;
	if (player.rec.y > GetScreenHeight() - 40)
		player.rec.y = GetScreenHeight() - 41;

	if (CheckCollisionRecs(player.rec, enemy.rec))
		progRuntime = false;
}
void game() {
	bool progRuntime = true;
	initPlayer();
	initEnemy();
	while (progRuntime) {
		input();
		enemyUpdate();
		collisions(progRuntime);
		draw();
	}
}
void main() {
	const int screenWidth = 800;
	const int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "Thy Flop");
	SetTargetFPS(60);

}