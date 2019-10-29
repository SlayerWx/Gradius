#include "Bullet.h"

Bullet::Bullet() {
	_x = 0;
	_y = 0;
	_radius = 13;
	_color = YELLOW;
}
float Bullet::getX() {
	return _x;
}
float Bullet::getY() {
	return _y;
}
void Bullet::setX(float x) {
	_x = x;
}
void Bullet::setY(float y) {
	_y = y;
}
int Bullet::getRadius() {
	return _radius;
}
Color Bullet::getColor() {
	return _color;
}