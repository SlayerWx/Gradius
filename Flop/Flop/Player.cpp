#include "Player.h"

Player player;

void initPlayer() {
	player.rec.x = 40.0f;
	player.rec.y = GetScreenHeight() / 2.0f;
	player.rec.width = 40;
	player.rec.height = 40;
	player.color = SKYBLUE;
}

void playerInput() {
	if (IsKeyDown(KEY_W))
		player.rec.y -= 3.0f;
	if (IsKeyDown(KEY_S))
		player.rec.y += 3.0f;
}