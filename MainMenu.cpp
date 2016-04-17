#include "MainMenu.h"
#include "Button.h"
#include "BattleStage.h"
#include "LevelComplete.h"
#include <iostream>

MainMenu::MainMenu() { //initializes main menu screen
	titleFont = sf::Font();

	title = sf::Text();
	title.setString("FLYOVER");
	title.setCharacterSize(50);
	title.setColor(sf::Color::Cyan);
}

void MainMenu::open(sf::RenderWindow* window) { // the bulk of the menu code goes here
	//prepare font
	if (!titleFont.loadFromFile("arial.ttf")) return; //the game will not start if the font doesn't load
	title.setFont(titleFont);

	//position button and title using the window size
	Button testButton = Button(window->getView().getSize().x/2 - 50,150,100,50,sf::Color::Red);
	title.setPosition(window->getView().getSize().x/2 - (title.getLocalBounds().width/2), 10);

	while (window->isOpen()) //function loop
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
			if (event.type == sf::Event::MouseButtonPressed) {
				//check buttons
				if (testButton.pointOnBox(event.mouseButton.x, event.mouseButton.y)) { //simple test level button
					BattleStage temp = BattleStage();
					temp.open(window);
					LevelComplete comp = LevelComplete();
					comp.open(window);
				}
			}
			//window closed
			if (event.type == sf::Event::Closed) window->close();
        }

		//draw sequence
        window->clear();
		window->draw(*testButton.getShape());
		window->draw(title);
        window->display();
    }
}
