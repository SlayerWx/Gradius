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
void Player::bombShoot(Bomb* playerBomb) {
	if (!playerBomb->getIsActive())
	{
		playerBomb->isActived(true);
		playerBomb->setX(_rec.x + _rec.width);
		playerBomb->setY(_rec.y + _rec.height);
	}
}
void Player::input(Bomb* playerBomb) {
	if (IsKeyDown(KEY_W))
		_rec.y -= 3.0f;
	if (IsKeyDown(KEY_S))
		_rec.y += 3.0f;
	if (IsKeyDown(KEY_SPACE))
		shoot();
	if (IsKeyPressed(KEY_C))
		bombShoot(playerBomb);
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