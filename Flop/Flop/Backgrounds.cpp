#include "Backgrounds.h"
//STAR CLASS METHODS
Star::Star() {
	_pos.x = GetRandomValue(1, 800);
	_pos.y = GetRandomValue(1, 480);
	_color = { 255, 255, 255, 150 }; //Lowered Alpha WHITE
	_speed = -10.0f;
	_radius = 4;
}
void Star::updatePos() {
	_pos.x += _speed;
}
Color Star::getColor() {
	return _color;
}
Vector2 Star::getPos() {
	return _pos;
}
int Star::getRadius() {
	return _radius;
}
void Star::setPos() {
	_pos.x += 820;
}

//GENERAL BG1 FUNCTIONS
Star* stars[25];
void initBG1() {
	for (int i = 0; i < 25; i++){
		stars[i] = new Star();
	}	
}
void moveBG1() {
	for (int i = 0; i < 25; i++) {
		stars[i]->updatePos();
		if (stars[i]->getPos().x < -10.0f)
			stars[i]->setPos();
	}
}
void drawBG1() {
	
	for (int i = 0; i < 25; i++) {
		DrawCircleV(stars[i]->getPos(), stars[i]->getRadius(), stars[i]->getColor());
	}
	
}