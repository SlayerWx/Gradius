#include "Bomb.h"
Bomb::Bomb(bool isActive,float newSpeed,int radius)
{
	itIsActive = isActive;
	speed = newSpeed;
	_radius = radius;
	percent = 0.0f;
}
float Bomb::getX() {
	return _x;
}
float Bomb::getY() {
	return _y;
}
void Bomb::setX(float x) {
	_x = x;
}
void Bomb::setY(float y) {
	_y = y;
}
int Bomb::getRadius() {
	return _radius;
}
Color Bomb::getColor() {
	return _color;
}

void Bomb::isActived(bool active)
{
	itIsActive = active;
}
bool Bomb::getIsActive()
{
	return itIsActive;
}
void Bomb::moveLerp(Vector2 start,Vector2 end)
{
	if (startLerp.x < -10 && startLerp.y < -10)
	{
		startLerp.x = start.x;
		startLerp.y = start.y - _radius;
		percent = 0.1f;
	}
	end.y += _radius*2;
	end.x -= startLerp.x;
	end.y -= startLerp.y;
	end.y *= percent;
	end.x *= percent;
	end.x += startLerp.x;
	end.y += startLerp.y;
	percent += 0.02f;
	_x = end.x;
	_y = end.y;
	if (percent > 0.99f)
	{
		startLerp.x = -15;
		startLerp.y = -15;
		percent = 0.1f;
		itIsActive = false;
	}
}