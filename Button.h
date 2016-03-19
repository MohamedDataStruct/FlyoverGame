#ifndef BUTTON_H
#define BUTTON_H

#include <SFML\Graphics.hpp>

class Button {
	int x, y, width, height;
	sf::RectangleShape shape;
public:
	Button();
	Button(int,int,int,int,sf::Color);

	sf::Shape* getShape();

	bool pointOnBox(int,int);
}



#endif