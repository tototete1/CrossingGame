#include "VEHICLE.h"
#include "draw.h"
#include <iostream>
#include <utility>
using namespace std;

pair<int,int> VEHICLE::Move(int speed,int width) {
	x += speed;
	if (x >= rightTopX - width)
		x = lefTopX+2;
	if (x <= lefTopX)
		x = x - (lefTopX - rightTopX + 1) - width;
	pair<int, int> t(x, y);
	return t;
}

void VEHICLE::setPos(int xx, int yy,int nextx) {
	x = xx;
	y = yy;
	next = nextx;
}

void VEHICLE::deleteVehicle(draw temp,int x, int y, int lengthCar) {
	for (int z = 0; z < 3; z++) {
		for (int i = y; i > y - 3; i--) {
			for (int j = x; j <= x + lengthCar; j++) {
				temp.GotoXY(j, i);
				cout << " ";
			}
		}
		y += 8;
	}
}



//========================
void CAR::Draw(draw temp,int x, int y) {
	//x = 20;
	//y = 22;
	int t = x;
	for (int i = 0; i < 3; i++) {
		x = t;
		temp.GotoXY(x, y);
		cout << "|" << "_" << "(-)" << "___" << "(-)" << "_" << "_/";
		x++; y--;
		temp.GotoXY(x, y);
		cout << "__";
		x += 2;
		cout << "/"; x += 2; temp.GotoXY(x, y); cout << "/" << "_" << "||" << "_" << "|"; x += 8; temp.GotoXY(x, y); cout << char(92); x -= 9; y--;
		temp.GotoXY(x, y); cout << "_________";
		temp.GotoXY(50, 50);
		y += 10;
	}
}

void BUS::Draw(draw temp, int x, int y) {
	int t = x;
	for (int i = 0; i < 3; i++) {
		x = t;
		temp.GotoXY(x, y);
		cout << "|" << "_" << "(-)" << "____" << "(-)" << "__" << "|"; y--; temp.GotoXY(x, y); cout << "|" << " |" << "_|" << " " << "||" << " " << "|_|" << char(92) << "_";
		y--; x++; temp.GotoXY(x, y); cout << "___________";
		temp.GotoXY(50, 50);
		y += 10;
	}
}