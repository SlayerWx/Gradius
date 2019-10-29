#include "Player.h"

Player::Player() {
	_rec.x = 40.0f;
	_rec.y = GetScreenHeight() / 2.0f;
	_rec.width = 40;
	_rec.height = 40;
	_color = SKYBLUE;
}
void Player::shoot() {
	
}
void Player::input() {
	if (IsKeyDown(KEY_W))
		_rec.y -= 3.0f;
	if (IsKeyDown(KEY_S))
		_rec.y += 3.0f;
	if (IsKeyDown(KEY_SPACE))
		shoot();
}
Rectangle Player::getRec() {
	return _rec;
}
float Player::getRecX() {
	return _rec.x;

}
float Player::getRecY() {
	return _rec.y;
}
void Player::setRecX(float x) {
	_rec.x = x;
}
void Player::setRecY(float y) {
	_rec.y = y;
}
Color Player::getColor() {
	return _color;
}