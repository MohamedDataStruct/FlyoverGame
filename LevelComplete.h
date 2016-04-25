#ifndef LEVELCOMPLETE_H
#define LEVELCOMPLETE_H
#include <SFML/Graphics.hpp>
#include <list>
#include "Button.h"
#include "player.h"

class LevelComplete {
	Button continueButton;
	sf::Text message;
	sf::Text scoreDisplay;
	sf::Font font;
	std::list<sf::Drawable*> drawables;
	int anim;
public:
    LevelComplete();
	void open(sf::RenderWindow*, player);

};

#endif // LEVELCOMPLETE_H_INCLUDED
