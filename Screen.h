#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Screen {

public:
	virtual void open(sf::RenderWindow) = 0;
	virtual void handleEvent(sf::Event) = 0;
	virtual std::string getState() = 0;
};

#endif
