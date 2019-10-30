#ifndef BOMB_H
#define BOMB_H
#include "raylib.h"
class Bomb
{
private:
	float _x;
	float _y;
	int _radius;
	Color _color;
	bool itIsActive;
	float speed;
public:
	Bomb(bool isActive, float newSpeed);
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);
	int getRadius();
	Color getColor();
	void TheBombIsActived(bool active);
	void move();
};
#endif
