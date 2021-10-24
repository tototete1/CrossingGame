#include "draw.h"
#include <iostream>
#include <windows.h>
#include <dos.h>
#include <stdlib.h>
using namespace std;


/*void draw::drawDinosa() {
	x = 31; y = 35;
	GotoXY(x, y); cout << "//"; x = x - 3; y = y - 1; GotoXY(x, y); cout << "`-._. )/`"; x = x - 1; y -= 1; GotoXY(x, y); cout << ".___.--'" << " /`_'";
	x -= -8; y -= 1; GotoXY(x, y); cout << "/(" << char(92) << "_/)"; x -= -2; y -= 1; GotoXY(x, y);
	cout << "@ @";
}*/

void draw::drawCar() {
	x = 20;
	y = 22;
	GotoXY(x, y);
	cout << "|" << "_" << "(-)" << "___" << "(-)" << "_" << "_/";
	x++; y--;
	GotoXY(x, y);
	cout << "__";
	x += 2;
	cout << "/"; x += 2; GotoXY(x, y); cout << "/" << "_" << "||" << "_" << "|"; x += 8; GotoXY(x, y); cout << char(92); x -= 9; y--;
	GotoXY(x, y); cout << "_________";
	GotoXY(50, 50);
}
void draw::drawBus() {
	x = 11;
	y = 4;
	GotoXY(x, y);
	cout << "|" << "_" << "(-)" << "____" << "(-)" << "__" << "|"; y--; GotoXY(x, y); cout << "|" << " |" << "_|" << " " << "||" << " " << "|_|" << char(92) << "_";
	y--; x++; GotoXY(x, y); cout << "___________";
	GotoXY(50, 50);
}
void draw::drawtop() {
	x = lefTopX + 1;
	y = lefTopY;
	while (x < 100) {
		GotoXY(x, y);
		cout << "_";
		x++;
	}
}
void draw::drawleft() {
	x = lefTopX;
	y = lefTopY + 1;
	while (y <= leftBottomY) {
		GotoXY(x, y);
		cout << (char)179;
		y++;
	}
}
void draw::drawright() {
	x = rightTopX;
	y = rightTopY + 1;
	while (y <= rightBottomY) {
		GotoXY(x, y);
		cout << (char)179;
		y++;
	}
}
void draw::drawbottom() {
	x = leftBottomX;
	y = leftBottomY;
	while (x < rightBottomX) {
		GotoXY(x, y);
		cout << "_";
		x++;
	}
}
void draw::drawLane() {
	x = lefTopX + 1;
	y = 4;
	GotoXY(x, y);
	cout << "___________________________________________________________________________________________________";
	y += 4; GotoXY(x, y);
	cout << "___________________________________________________________________________________________________";
	y += 4; GotoXY(x, y);
	cout << "___________________________________________________________________________________________________";
	y += 4; GotoXY(x, y);
	cout << "___________________________________________________________________________________________________";
	y += 4; GotoXY(x, y);
	cout << "___________________________________________________________________________________________________";
	y += 4; GotoXY(x, y);
	cout << "___________________________________________________________________________________________________";
	y += 4; GotoXY(x, y);
	cout << "___________________________________________________________________________________________________";
	GotoXY(50, 50);
}

void draw::drawScore() {
	x = 110; y = 3;
	GotoXY(x, y);
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
	y += 16;
	GotoXY(x, y);
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
	y -= 16;
	while (y <= 19) {
		GotoXY(x, y);
		cout << "%";
		y++;
	}
	x += 31;
	y -= 17;
	while (y <= 19) {
		GotoXY(x, y);
		cout << "%";
		y++;
	}
	y -= 12;
	x -= 30; GotoXY(x, y);
	cout << "******************************";
	x += 20;
	y += 50;
	GotoXY(x, y); cout << "a";
}
void draw::drawGuild() {
	x = 101, y = 27;
	GotoXY(x, y);
	cout << "############################################";
	y += 15;
	GotoXY(x, y);
	cout << "############################################";
	y += 30;
	while (y <= 50) {
		GotoXY(x, y);
		cout << "a";
		y++;
	}
	GotoXY(50, 50);
}
void draw::drawPerson() {
	x = 11, y = 41;
	GotoXY(x, y); cout << "o " << "  o"; y -= 1; x += 1; GotoXY(x, y); cout << "/" << " " << char(92); y -= 1; x -= 1; GotoXY(x, y);
	cout << "/" << "(_)" << char(92); y -= 1; x += 1; GotoXY(x, y); cout << "_O_";
	GotoXY(50, 50);
}
void draw::move() {
	if (GetAsyncKeyState(VK_LEFT)) {
		/*GotoXY(x, y); cout << "  " << "   "; y -= 1; x += 1; GotoXY(x, y); cout << " " << " " << " "; y -= 1; x -= 1; GotoXY(x, y);
		cout << " " << "   " << char(92); y -= 1; x += 1; GotoXY(x, y); cout << "   ";*/
		y--;
		drawPerson();
	}
	else {
		y++;
		drawPerson();
	}
}

void draw::ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}
void draw::drawStreet() {
	ShowConsoleCursor(0);
	remove_scrollbar();
	drawtop();
	drawbottom();
	drawleft();
	drawright();
	drawLane();
	drawScore();
	drawGuild();
	GotoXY(50, 50);
}