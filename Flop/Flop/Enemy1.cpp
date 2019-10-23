#include "Enemy1.h"
Enemy1 enemy1;

void initEnemy1() {
	enemy1.rec.x = 880.0f;
	enemy1.rec.y = GetRandomValue(40,400);
	enemy1.rec.height = 40.0f;
	enemy1.rec.width = 40.0f;
	enemy1.color = RED;
}

void enemy1Update() {
	enemy1.rec.x -= 5.0f;
	if (enemy1.rec.x <= -40.0f) {
		enemy1.rec.x = 880.0f;
		enemy1.rec.y = GetRandomValue(40, 400);
	}
}