#include<iostream>
//#include<conio.h>
#include<SFML/System.hpp>
#include "player.h"
#pragma once
using namespace std;

player::player()
{
		gameOver = false;
		x = width / 2;
		y = height / 2;
		xVel = 0;
		yVel = 0;
		score = 0;
		sprite = sf::RectangleShape(sf::Vector2f(width,height));
		sprite.setFillColor(sf::Color(155,155,100,255));
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

void player::input(Direction dir) {
	switch (dir) {
		case LEFT:
			setVelocity(-7,0);
			break;
		case RIGHT:
			setVelocity(7,0);
			break;
		case UP:
			setVelocity(0,-10);
			break;
		case DOWN:
			setVelocity(0,15);
			break;
		case STOP:
			setVelocity(0,0);
			break;
	}
}

void player::setVelocity(int xV, int yV)
{
	xVel = xV;
	yVel = yV;
}

	void player::logic() {
		//move according to current velocity
		x += xVel;
		y += yVel;
		sprite.setPosition(x,y);
		//game over, shooting logic goes here.
	}

	sf::RectangleShape* player::getSprite() { return &sprite; }






