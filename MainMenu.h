#ifndef MAINMENU_H
#define MAINMENU_H

#include "Screen.h"
#include <SFML\Graphics.hpp>

class MainMenu :public Screen {
	Button continueButton;
	sf::Text title;
	sf::Font titelFont;
};

#endif