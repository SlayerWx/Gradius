#include "Enemy1.h"

Enemy1::Enemy1() {
	_rec.x = 880.0f;
	_rec.y = static_cast<float>(GetRandomValue(40, 400));
	_rec.height = 40.0f;
	_rec.width = 40.0f;
	_color = RED;
}
Enemy1::Enemy1(float posInY) {
	_rec.x = 880.0f;
	_rec.height = 20.0f;
	_rec.width = 50.0f;
	_rec.y = posInY - _rec.height;
	_color = RED;
}
void Enemy1::update() {
	_rec.x -= 5.0f;
	if (_rec.x <= -40.0f) {
		_rec.x = 880.0f;
		_rec.y = static_cast<float>(GetRandomValue(40, 400));
	}
}
void Enemy1::GroundUpdate() {
	_rec.x -= 3.0f;
	if (_rec.x <= -40.0f) {
		_rec.x = 1380.0f;
	}
}
void Enemy1::destroy() {
	
}
Rectangle Enemy1::getRec() {
	return _rec;
}
void Enemy1::setX(float newX)
{
	_rec.x = newX;
}
Color Enemy1::getColor() {
	return _color;
}
