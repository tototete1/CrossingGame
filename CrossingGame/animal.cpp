#include "animal.h"
#include "draw.h"
#include <iostream>
#include <utility>
using namespace std;

pair<int, int> ANIMAL::Move(int speed, int width) {
	x += speed;
	if (x >= rightTopX - width)
		x = lefTopX + 2;
	if (x <= lefTopX)
		x = x - (lefTopX - rightTopX + 1) - width;
	pair<int, int> t(x, y);
	return t;
}

void ANIMAL::setPos(int xx, int yy, int nextx) {
	x = xx;
	y = yy;
	next = nextx;
}

void ANIMAL::deleteAnimal(draw temp, int x, int y, int length) {
	for (int z = 0; z < 3; z++) {
		for (int i = y; i > y - 3; i--) {
			for (int j = x; j <= x + length; j++) {
				temp.GotoXY(j, i);
				cout << " ";
			}
		}
		y += 8;
	}
}