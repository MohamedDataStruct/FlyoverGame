#include "Button.h"

Button::Button() { //default, super basic constructor
	x = 0;
	y = 0;
	width = 50;
	height = 50;
	shape = sf::RectangleShape(sf::Vector2f(50,50));
	shape.setFillColor(sf::Color::Red);
}

Button::Button(int xPos, int yPos, int w, int h, sf::Color color) { //constructor to set position, size, and color of button
	x = xPos;
	y = yPos;
	width = w;
	height = h;
	shape = sf::RectangleShape(sf::Vector2f(w,h));
	shape.setPosition(x,y);
	shape.setFillColor(color);
}

sf::Shape* Button::getShape() { return &shape; } //get the button's shape for painting to the screen

bool Button::pointOnBox(int u, int v) { // checks to see if the absolute coordinate lies on top of the button
	if (u < x || u > x+width ||
		v < y || v > y+height) return false;
	return true;
}