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
	Vector2 startLerp;
	float percent;
public:
	Bomb(bool isActive, float newSpeed,int radius);
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);
	int getRadius();
	Color getColor();
	void isActived(bool active);
	bool getIsActive();
	void moveLerp(Vector2 start,Vector2 end);
};
#endif
