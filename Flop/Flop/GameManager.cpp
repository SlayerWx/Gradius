#include "GameManager.h"
Enemy1* e1;
Player* player;
Bullet* bullets[10];
Bomb* playerBomb;
void draw() {
	BeginDrawing();
	ClearBackground(BLACK);
	drawBG1();
	DrawRectangleRec(player->getRec(), player->getColor());
	DrawRectangleRec(e1->getRec(), e1->getColor());
	EndDrawing();
}
void collisions() {
	if (player->getRecY() < 0)
		player->setRecY(1);
	if (player->getRecY() > GetScreenHeight() - 40)
		player->setRecY(GetScreenHeight() - 41);

	if (CheckCollisionRecs(player->getRec(), e1->getRec()))
		scenes = menu;
}
void game() {
	e1 = new Enemy1;
	player = new Player;
	for (int i = 0; i < 10; i++){
		bullets[i] = new Bullet();
	}
	playerBomb = new Bomb(true,150);

	initBG1();

	while (scenes == gameplay) {
		player->input();
		e1->update();
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