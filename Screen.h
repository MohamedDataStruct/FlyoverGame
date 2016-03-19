#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <SFML\Graphics.hpp>

class Screen {

public:
	virtual Screen* update(sf::RenderWindow) = 0;
	virtual void handleEvent(sf::Event) = 0;
	virtual string getState() = 0;
}

#endif