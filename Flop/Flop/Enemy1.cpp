#include "Enemy1.h"

Enemy1::Enemy1() {
	 _rec.x = 880.0f;
	 _rec.y = GetRandomValue(40, 400);
	 _rec.height = 40.0f;
	 _rec.width = 40.0f;
	 _color = RED;
}
void Enemy1::update() {
	_rec.x -= 5.0f;
	if (_rec.x <= -40.0f) {
		_rec.x = 880.0f;
		_rec.y = GetRandomValue(40, 400);
	}
}
void Enemy1::destroy() {
	
}
Rectangle Enemy1::getRec() {
	return _rec;
}
Color Enemy1::getColor() {
	return _color;
}
