#include "raylib.h"
#include "Bullet.h"
class Player {
private:
	Rectangle _rec;
	Color _color;
public:
	Player();
	void shoot();
	void input();
	Rectangle getRec();
	float getRecX();
	float getRecY();
	void setRecX(float x);
	void setRecY(float y);
	Color getColor();
};
