#ifndef LEVELCOMPLETE_H
#define LEVELCOMPLETE_H
#include <SFML/Graphics.hpp>
#include <list>
#include "Button.h"

class LevelComplete {
	Button continueButton;
	sf::Text message;
	sf::Font font;
	std::list<sf::Drawable*> drawables;
	int anim;
public:
    LevelComplete();
	void open(sf::RenderWindow*);

};

#endif // LEVELCOMPLETE_H_INCLUDED
