#ifndef BATTLESTAGE_H
#define BATTLESTAGE_H

#include <SFML/Graphics.hpp>
#include <list>

class BattleStage {
	//some member needed to store obstacles and enemies
	std::list<sf::Shape*> drawables;
public:
	void open(sf::RenderWindow*);
};

#endif