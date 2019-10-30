#include "Bomb.h"
Bomb::Bomb(bool isActive,float newSpeed)
{
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

void Bomb::TheBombIsActived(bool active)
{
	itIsActive = active;
}

void Bomb::move()
{
	if (itIsActive)
	{
		_y += speed * GetFrameTime();
	}
}
