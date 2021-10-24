#pragma once
#include "draw.h"
#include <utility>
class VEHICLE {
	int x, y,next;
public:
	bool check;
public:
	pair<int, int> Move(int speed, int width);
	void setPos(int xx, int yy,int next);
	pair<int,int> getXY() {
		pair<int, int> temp(x, y);
		return temp;
	}
	void deleteVehicle(draw temp,int x, int y, int lengthCar);
	int getNext() { return next; }
	int getX() { return x; }
};

class CAR: public VEHICLE {
const
	int width = 14;
	int height = 3;
public:
	void Draw(draw temp,int x,int y);
	int getW() {
		return width;
	}
};

class BUS : public VEHICLE {
	int width = 16;
	int height = 3;
public:
	void Draw(draw temp, int x, int y);
	int getW() {
		return width;
	}
};