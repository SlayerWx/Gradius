#include "raylib.h"

struct Enemy1 {
	Rectangle rec;
	Color color;
};

extern Enemy1 enemy1;
void initEnemy1();
void enemy1Update();
void drawBG1();