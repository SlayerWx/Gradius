#include "raylib.h"

class Enemy1 {
private:
	Rectangle _rec;
	Color _color;
public:
	Enemy1();
	Rectangle getRec();
	Color getColor();
	void destroy();
	void update();
};

