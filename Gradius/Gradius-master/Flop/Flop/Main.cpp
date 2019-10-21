#include "raylib.h"
#include "MagicNumbers.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

enum Scenes {
	menu,
	gameplay,
	credits,
	pause,
};
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
Scenes scenes;

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
void pauseScene() {
	bool pauseBool = true;
	Rectangle resumeButton;
	resumeButton.x = screenWidth / 2 - 40;
	resumeButton.y = menuPlayTextY;
	resumeButton.height = 30;
	resumeButton.width = 97.5f;
	Rectangle menuButton;
	menuButton.x = screenWidth / 2 - 40;
	menuButton.y = menuPlayTextY + 80;
	menuButton.height = 30;
	menuButton.width = 66.0f;

	while (pauseBool) {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText(FormatText("PAUSED"), titlePosX, titlePosY, titleFontSize, WHITE);
		if (CheckCollisionPointRec(GetMousePosition(), resumeButton))
			DrawText(FormatText("Resume"), menuPlayTextX, menuPlayTextY, promptFontSize, RED);
		else
			DrawText(FormatText("Resume"), menuPlayTextX, menuPlayTextY, promptFontSize, WHITE);

		if (CheckCollisionPointRec(GetMousePosition(), menuButton))
			DrawText(FormatText("Menu"), menuPlayTextX, menuPlayTextY + 80, promptFontSize, RED);
		else
			DrawText(FormatText("Menu"), menuPlayTextX, menuPlayTextY + 80, promptFontSize, WHITE);
		EndDrawing();

		if (CheckCollisionPointRec(GetMousePosition(), resumeButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			pauseBool = false;
		}
		if (CheckCollisionPointRec(GetMousePosition(), menuButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			pauseBool = false;
			scenes = menu;
		}
	}
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
	if (IsKeyReleased(KEY_P))
		pauseScene();
}
void draw() {
	BeginDrawing();
	ClearBackground(BLACK);
	DrawRectangleRec(player.rec, player.color);
	DrawRectangleRec(enemy.rec, enemy.color);
	EndDrawing();
}
void collisions() {
	if (player.rec.y < 0)
		player.rec.y = 1;
	if (player.rec.y > GetScreenHeight() - 40)
		player.rec.y = GetScreenHeight() - 41;

	if (CheckCollisionRecs(player.rec, enemy.rec))
		scenes = menu;
}
void game() {
	
	initPlayer();
	initEnemy();
	while (scenes==gameplay) {
		input();
		enemyUpdate();
		collisions();
		draw();
	}
}
void menuScene() {
	bool menuBool = true;


		Rectangle playButton;
		playButton.x = screenWidth / 2 - 40;
		playButton.y = menuPlayTextY;
		playButton.height = 30;
		playButton.width = 65;
		Rectangle closeButton;
		closeButton.x = screenWidth / 2 - 40;
		closeButton.y = menuPlayTextY + 80;
		closeButton.height = 30;
		closeButton.width = 81.25f;
		Rectangle creditsButton;
		creditsButton.x = screenWidth / 2 - 40;
		creditsButton.y = menuPlayTextY + 160;
		creditsButton.height = 30;
		creditsButton.width = 113;


		while (menuBool) {
			BeginDrawing();
			ClearBackground(BLACK);

			DrawText(FormatText("Gradius probs"), titlePosX, titlePosY, titleFontSize, WHITE);
			if (CheckCollisionPointRec(GetMousePosition(), playButton))
				DrawText(FormatText("Play"), menuPlayTextX, menuPlayTextY, promptFontSize, RED);
			else
				DrawText(FormatText("Play"), menuPlayTextX, menuPlayTextY, promptFontSize, WHITE);

			if (CheckCollisionPointRec(GetMousePosition(), closeButton))
				DrawText(FormatText("Close"), menuPlayTextX, menuPlayTextY + 80, promptFontSize, RED);
			else
				DrawText(FormatText("Close"), menuPlayTextX, menuPlayTextY + 80, promptFontSize, WHITE);

			if (CheckCollisionPointRec(GetMousePosition(), creditsButton))
				DrawText(FormatText("Credits"), menuPlayTextX, menuPlayTextY + 160, promptFontSize, RED);
			else
				DrawText(FormatText("Credits"), menuPlayTextX, menuPlayTextY + 160, promptFontSize, WHITE);

			DrawText(FormatText("v 0.1"), 1, 1, 20, WHITE);

			EndDrawing();

			if (CheckCollisionPointRec(GetMousePosition(), playButton) && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
				menuBool = false;
				scenes = gameplay;
			}

			if (CheckCollisionPointRec(GetMousePosition(), closeButton) && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
				exit(0);
			}
			if (CheckCollisionPointRec(GetMousePosition(), creditsButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
				menuBool = false;
				scenes = credits;
			}
		}
	}
void creditScene() {
	bool creditBool = true;

	Rectangle creditsButton;
	creditsButton.x = screenWidth / 2 - 40;
	creditsButton.y = menuPlayTextY + 160;
	creditsButton.height = 30;
	creditsButton.width = 113;

	while (creditBool) {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText(FormatText("Gradius probs"), titlePosX, titlePosY, titleFontSize, WHITE);
		DrawText(FormatText("Lead Programmer"), creditsTitle1X, creditsTitle1Y, 30, WHITE);
		DrawText(FormatText("Matias Karplus"), creditsSub1X, creditsSub1Y, 20, WHITE);

		if (CheckCollisionPointRec(GetMousePosition(), creditsButton))
			DrawText(FormatText("Credits"), menuPlayTextX, menuPlayTextY + 160, promptFontSize, RED);
		else
			DrawText(FormatText("Credits"), menuPlayTextX, menuPlayTextY + 160, promptFontSize, WHITE);
		EndDrawing();



		if (CheckCollisionPointRec(GetMousePosition(), creditsButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			creditBool = false;
			scenes = menu;
		}

		if (IsKeyPressed(KEY_BACKSPACE)) {
			exit(0);
		}
	}
}


void sceneManager() {
	bool progRuntime = true;
	while (progRuntime) {
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
}
void main() {
	const int screenWidth = 800;
	const int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "Thy Flop");
	SetTargetFPS(60);
	sceneManager();
	cin.get();
}