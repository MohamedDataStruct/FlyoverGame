#include "Button.h"

Button::Button() {
	x = 0;
	y = 0;
	width = 50;
	height = 50;
	shape = sf::RectangleShape(sf::Vector2f(50,50));
	shape.setFillColor(sf::Color::Red);
}

Button::Button(int xPos, int yPos, int w, int h, sf::Color color) {
	x = xPos;
	y = yPos;
	width = w;
	height = h;
	shape = sf::RectangleShape(sf::Vector2f(w,h));
	shape.setFillColor(color);
}

sf::Shape* Button::getShape() { return &shape; }

bool Button::pointOnBox(int u, int v) {
	if (u < x || u > x+width ||
		v < y || v > y+height) return false;
	return true;
}