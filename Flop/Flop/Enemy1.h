#include "raylib.h"

class Enemy1 {
private:
	Rectangle _rec;
	Color _color;
public:
	Enemy1();
	Enemy1(float posInY);
	Rectangle getRec();
	void setX(float newX);
	Color getColor();
	void destroy();
	void update();
	void GroundUpdate();
};

