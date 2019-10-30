#include "raylib.h"
#include "Bullet.h"
#include "Bomb.h"
class Player {
private:
	Rectangle _rec;
	Color _color;
public:
	Player();
	void shoot();
	void bombShoot(Bomb * playerBomb);
	void input(Bomb * playerBomb);
	Rectangle getRec();
	float getRecX();
	float getRecY();
	void setRecX(float x);
	void setRecY(float y);
	Color getColor();
};
