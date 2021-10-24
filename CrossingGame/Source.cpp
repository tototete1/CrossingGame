#include "draw.h"
#include "VEHICLE.h"
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <dos.h>
#include <stdlib.h>
#include <thread>


using namespace std;
CAR car[3];
BUS bus[3];
const int numberOfVehicle = 3;
void ThreadGame(draw temp) {
	pair<int, int> t;
	int x, y;
	while (1) {
		for (int i = 0; i < numberOfVehicle; i++) {
			int next = car[i].getNext();
			if (car[next].check == 1) {
				t = car[i].getXY();
				x = t.first;
				y = t.second;
				car[i].deleteVehicle(temp, x, y, car[i].getW());
				t = car[i].Move(-1, car[i].getW());
				x = t.first;
				y = t.second;
				if (x == 85) {
					for (int j = 0; j < numberOfVehicle; j++) {
						car[j].check = (j == i);
					}
				}
				if (car[next].check == 1) car[i].Draw(temp, x, y);
			}
			else {
				int x1 = car[i].getX();
				int x2 = car[next].getX();
				if (abs(x2 - x1) >= 33) {
					t = car[i].getXY();
					x = t.first;
					y = t.second;
					car[i].deleteVehicle(temp, x, y, car[i].getW());
					t = car[i].Move(-1, car[i].getW());
					x = t.first;
					y = t.second;
					if (x == 85) {
						for (int j = 0; j < numberOfVehicle; j++) {
							car[j].check = (j == i);
						}
					}
					car[i].Draw(temp, x, y);
				}
			}
		}
		for (int i = 0; i < numberOfVehicle; i++) {
			int next = bus[i].getNext();
			if (bus[next].check == 1) {
				t = bus[i].getXY();
				x = t.first;
				y = t.second;
				bus[i].deleteVehicle(temp, x, y, bus[i].getW());
				t = bus[i].Move(1, bus[i].getW());
				x = t.first;
				y = t.second;
				if (x == 2) {
					for (int j = 0; j < numberOfVehicle; j++) {
						bus[j].check = (j == i);
					}
				}
				if (bus[next].check == 1) bus[i].Draw(temp, x, y);
			}
			else {
				int x1 = bus[i].getX();
				int x2 = bus[next].getX();
				if (abs(x2 - x1) >= 33) {
					t = bus[i].getXY();
					x = t.first;
					y = t.second;
					bus[i].deleteVehicle(temp, x, y, bus[i].getW());
					t = bus[i].Move(1, bus[i].getW());
					x = t.first;
					y = t.second;
					if (x == 2) {
						for (int j = 0; j < numberOfVehicle; j++) {
							bus[j].check = (j == i);
						}
					}
					bus[i].Draw(temp, x, y);
				}
			}
		}
		Sleep(100);

	}
}

void ResetData(){
	int carDistance = (rightBottomX - leftBottomX - 1) / numberOfVehicle;
	int laneDistance = 3;
	int carStartX = 85;
	int carStartY = 7;
	int busStartX = 2;
	int busStartY = 11;
	//set up for Car
	for (int i = 0; i < numberOfVehicle; i++) {
		car[i].setPos(carStartX, carStartY,(i+1)%3);
		carStartX = carStartX - carDistance;
		car[i].check = (i == 0);
	}
	for (int i = 0; i < numberOfVehicle; i++) {
		bus[i].setPos(busStartX, busStartY,(i+1)%3);
		busStartX = busStartX + carDistance;
		bus[i].check = (i == 0);

	}
}

int main() {
	draw temp;
	temp.resizeConsole(1200 , 800);
	temp.drawStreet();
	system("color F0");
	ResetData();
	
	pair<int, int> t;

	/*for (int i = 0; i < numberOfVehicle; i++) {
		t = car[i].getXY();
		car[i].Draw(temp, t.first, t.second);
	}
	for (int i = 0; i < numberOfVehicle; i++) {
		t = bus[i].getXY();
		bus[i].Draw(temp, t.first, t.second);
	}*/

	thread t1(ThreadGame,temp);
	while (1) {
		int temp = toupper(_getch());
	}
	return 0;
}
