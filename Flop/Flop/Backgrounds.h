#include "raylib.h"

class Star {
	Vector2 _pos;
	Color _color;
	float _speed;
	int _radius;
public:
	Star();
	~Star();
	void updatePos();
	Color getColor();
	Vector2 getPos();
	int getRadius();
	void setPos();
};

extern Star* stars[25];

void initBG1();
void moveBG1();
void drawBG1();