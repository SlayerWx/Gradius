#include "raylib.h"
struct Player {
	Rectangle rec;
	Color color;
};
extern Player player;

void initPlayer();
void playerInput();