#include "GameManager.h"
void draw() {
	BeginDrawing();
	ClearBackground(BLACK);
	drawBG1();
	DrawRectangleRec(player.rec, player.color);
	DrawRectangleRec(enemy1.rec, enemy1.color);
	EndDrawing();
}
void collisions() {
	if (player.rec.y < 0)
		player.rec.y = 1;
	if (player.rec.y > GetScreenHeight() - 40)
		player.rec.y = GetScreenHeight() - 41;

	if (CheckCollisionRecs(player.rec, enemy1.rec))
		scenes = menu;
}
void game() {

	initPlayer();
	initEnemy1();
	initBG1();
	while (scenes == gameplay) {
		playerInput();
		enemy1Update();
		collisions();
		moveBG1();
		draw();
		pauseInput();
	}
}

void pauseInput() {
	if (IsKeyReleased(KEY_P))
		pauseScene();
}

void initProgram() {
	const int screenWidth = 800;
	const int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "Thy Flop");
	SetTargetFPS(60);
}

void sceneManager() {
	initProgram();
	while (!WindowShouldClose()) {
		switch (scenes) {
		case menu:
			menuScene();
			break;
		case gameplay:
			game();
			break;
		case credits:
			creditScene();
			break;
		}
	}
	CloseWindow();
}