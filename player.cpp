#include<iostream>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include "player.h"
#include "Enemies.h"
#pragma once
using namespace std;

player::player()
{
		gameOver = false;
		x = 230;
		y = 500;
		xVel = 0;
		yVel = 0;
		score = 0;

		texture = sf::Texture();
		texture.loadFromFile("Sprites/speedship.png");
		sprite = sf::Sprite();
		sprite.setTexture(texture);
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
			setVelocity(0,-7);
			break;
		case DOWN:
			setVelocity(0,7);
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
		//keep it from flying off screen
		if (x > 436) x = 436;
		if (x < 0) x = 0;
		if (y > 536) y = 536;
		if (y < 0) y = 0;
		sprite.setPosition(x,y);
		//game over, shooting logic goes here.
	
		if (true == PlayerCollision(x,x+63,y))
		{
			gameOver = true;
			
		}
	}

sf::Sprite* player::getSprite() { return &sprite; }

int player::getX() { return x; }

int player::getY() { return y; }

int player::getXVel() { return yVel; }

int player::getYVel() { return xVel; }

