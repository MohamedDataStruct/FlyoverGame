#include<iostream>
#include<conio.h>
#include "player.h"
#pragma once
using namespace std;

void player::setup()
{
	

		gameOver = false;
		dir = STOP;
		x = width / 2;
		y = height / 2;
		score = 0;

}

void player::Draw()
{
	system("cls");
	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0)
				cout << "#";

			if (i == y && j == x)
				cout << "@";
			else
				cout << " ";



			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}

	cout << "#" << endl;

	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;

}


void player::input()
{

	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'w':
			dir = UP;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

	void player::logic() {
		switch (dir)
		{
		case LEFT: x--;
			break;
		case RIGHT: x++;
			break;
		case UP: y--;
			break;
		case DOWN:y++;
			break;
		default:
			break;
		}
		if (x > width || x<0 || y>height || y < 0)
			gameOver = true;
	}






