#include "GameManager.h"
Enemy1* e1;
Enemy1* groundEnemy;
Player* player;
Bullet* bullets[10];
Bomb* playerBomb;
void draw() {
	BeginDrawing();
	ClearBackground(BLACK);
	drawBG1();
	DrawRectangleRec(player->getRec(), player->getColor());
	DrawRectangleRec(e1->getRec(), e1->getColor());
	DrawRectangleRec(groundEnemy->getRec(),groundEnemy->getColor());
	if (playerBomb->getIsActive())
	{
		DrawCircle(static_cast<int>(playerBomb->getX()), static_cast<int>(playerBomb->getY()), 
			static_cast<float>(playerBomb->getRadius()),
			playerBomb->getColor());
	}
	EndDrawing();
}
void collisions() {
	if (player->getRecY() < 0)
		player->setRecY(1);
	if (player->getRecY() > GetScreenHeight() - 40)
		player->setRecY(static_cast<float>(GetScreenHeight() - 41));

	if (CheckCollisionRecs(player->getRec(), e1->getRec()) ||
		CheckCollisionRecs(player->getRec(), groundEnemy->getRec()))
		scenes = menu;
	if (CheckCollisionCircleRec({ playerBomb->getX(),playerBomb->getY() },
		static_cast<float>(playerBomb->getRadius()), groundEnemy->getRec()))
		groundEnemy->setX(groundEnemy->getRec().x + GetScreenWidth() + 50);
}
void game() {
	e1 = new Enemy1();
	groundEnemy = new Enemy1(static_cast<float>(GetScreenHeight()));
	player = new Player();
	for (int i = 0; i < 10; i++){
		bullets[i] = new Bullet();
	}
	playerBomb = new Bomb(false,150,15);
	initBG1();

	while (scenes == gameplay) {
		player->input(playerBomb);
		e1->update();
		groundEnemy->GroundUpdate();
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