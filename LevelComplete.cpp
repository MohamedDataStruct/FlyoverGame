#include "LevelComplete.h"
#include "player.h"
#include <sstream>
#include <iostream>
#include <math.h>

LevelComplete::LevelComplete() {
	font = sf::Font();

	message = sf::Text();
	message.setString("LEVEL COMPLETE");
	message.setCharacterSize(50);
	message.setColor(sf::Color::Cyan);

	scoreDisplay = sf::Text();
	scoreDisplay.setString("");
	scoreDisplay.setCharacterSize(50);
	scoreDisplay.setColor(sf::Color::White);

	drawables = std::list<sf::Drawable*>();
	//drawables.push_front(message);
	drawables.push_front(continueButton.getShape());

	anim = 0;
}

void LevelComplete::open(sf::RenderWindow* window, player p1) {
    font.loadFromFile("arial.ttf");
    message.setFont(font);
	scoreDisplay.setFont(font);

	continueButton = Button(window->getView().getSize().x/2 - 50,150,100,50,sf::Color::Red);
	message.setPosition(window->getView().getSize().x/2 - (message.getLocalBounds().width/2), 10);

	while (window->isOpen()) //function loop
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
			if (event.type == sf::Event::MouseButtonPressed) {
				//check buttons
				if (continueButton.pointOnBox(event.mouseButton.x, event.mouseButton.y)) { //simple test level button
					return;
				}
			}
			//window closed
			if (event.type == sf::Event::Closed) window->close();
        }

        //animation
        int x = anim - 60;
		//score = 1000;

        message.setPosition(window->getView().getSize().x/2 - (message.getLocalBounds().width/2)
                            +((x < 0) ? 50.0*sin(x/4.0) : 0),
                            10);
        scoreDisplay.setString(std::to_string((double long)((2*anim - 120 < p1.score) ? 2*anim - 120: p1.score)));
        scoreDisplay.setPosition(window->getView().getSize().x/2 - (scoreDisplay.getLocalBounds().width/2),
					              200);

        anim++;

		//draw sequence
        window->clear();
		for (std::list<sf::Drawable*>::iterator it = drawables.begin(); it != drawables.end(); it++)
			window->draw(**it);
        window->draw(message);
		if(anim > 60) window->draw(scoreDisplay);
        window->display();
    }
}
