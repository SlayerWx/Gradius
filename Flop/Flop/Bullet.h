#include "raylib.h"
class Bullet{
private:
	float _x;
	float _y;
	int _radius;
	Color _color;
public:
	Bullet();
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);
	int getRadius();
	Color getColor();
};