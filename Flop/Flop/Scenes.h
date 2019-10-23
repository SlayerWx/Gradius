#include "raylib.h"
#include <iostream>
using namespace std;

enum Scenes {
	menu,
	gameplay,
	credits,
	pause,
};
extern Scenes scenes;

void menuScene();
void creditScene();
void pauseScene();
void sceneManager();