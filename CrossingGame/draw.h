#pragma once
#include <iostream>
#include <windows.h>
#include <dos.h>
#include <stdlib.h>

#define lefTopX 0
#define lefTopY 0

#define leftBottomX 0
#define leftBottomY 32

#define rightTopX 100
#define rightTopY 0

#define rightBottomX 100
#define rightBottomY 32

using namespace std;
class draw {
private:
	float x, y;
public:
	draw() {
		x = y = 0;
	}
	~draw() {

	}
	void drawBus();
	void drawtop();
	void drawleft();
	void drawbottom();
	void drawright();
	void drawStreet();
	void drawCar();
	void drawLane();
	void drawScore();
	void drawGuild();
	void drawPerson();
	void move();
	void resizeConsole(int width, int height) {
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r);
		MoveWindow(console, r.left, r.top, width, height, TRUE);
	}
	void XoaManHinh()
	{
		HANDLE hOut;
		COORD Position;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		Position.X = 0;
		Position.Y = 0;
		SetConsoleCursorPosition(hOut, Position);
	}
	void textcolor(int x)
	{
		HANDLE mau;
		mau = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(mau, x);
	}
	void FixConsoleWindow() {
		HWND consoleWindow = GetConsoleWindow();
		LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
		style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
		SetWindowLong(consoleWindow, GWL_STYLE, style);
	}
	void GotoXY(int x, int y) {
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	void ShowConsoleCursor(bool showFlag);
	void remove_scrollbar()
	{
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(handle, &info);
		COORD new_size =
		{
			info.srWindow.Right - info.srWindow.Left + 1,
			info.srWindow.Bottom - info.srWindow.Top + 1
		};
		SetConsoleScreenBufferSize(handle, new_size);
	}
};