#include "draw.h"
#include <utility>
class ANIMAL {
	int x, y, next;
public:
	bool check;
public:
	pair<int, int> Move(int speed, int width);
	void setPos(int xx, int yy, int next);
	pair<int, int> getXY() {
		pair<int, int> temp(x, y);
		return temp;
	}
	void deleteAnimal(draw temp, int x, int y, int length);
	int getNext() { return next; }
	int getX() { return x; }
};

class Dinosa :public ANIMAL {

};