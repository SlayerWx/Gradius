#include "Bomb.h"
Bomb::Bomb(bool isActive,float newSpeed,int radius)
{
	itIsActive = isActive;
	speed = newSpeed;
	_radius = radius;
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
Vector2 Bomb::moveLerp(Vector2 start, Vector2 end, float percent)
{
	end.x -= start.x;
	end.y -= start.y;
	end.y *= percent;
	end.x *= percent;
	end.x += start.x;
	end.y += start.y;
	return end;
}