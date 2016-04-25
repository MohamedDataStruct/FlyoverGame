#ifndef MAINMENU_H
#define MAINMENU_H

#include "Screen.h"
#include "Button.h"
#include <SFML/Graphics.hpp>

class MainMenu {
	Button continueButton;
	sf::Text title;
	sf::Text playLabel;
	sf::Font titleFont;
	sf::Font labelFont;
public:
	MainMenu();
	void open(sf::RenderWindow*);
};

#endif
