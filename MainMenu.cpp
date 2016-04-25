#include "MainMenu.h"
#include "Button.h"
#include "BattleStage.h"
#include "LevelComplete.h"
#include "Bullet.h"
#include <iostream>

MainMenu::MainMenu() { //initializes main menu screen
	titleFont = sf::Font();
	labelFont = sf::Font();

	title = sf::Text();
	title.setString("FLYOVER");
	title.setCharacterSize(50);
	title.setColor(sf::Color::Cyan);

	playLabel = sf::Text();
	playLabel.setString("Play");
	playLabel.setCharacterSize(30);
	playLabel.setColor(sf::Color::White);
}

void MainMenu::open(sf::RenderWindow* window) { // the bulk of the menu code goes here

	//prepare font
	if (!titleFont.loadFromFile("arial.ttf")) return; //the game will not start if the font doesn't load
	if (!labelFont.loadFromFile("arial.ttf")) return;
	title.setFont(titleFont);
	playLabel.setFont(labelFont);

	//position button and title using the window size
	Button testButton = Button(window->getView().getSize().x/2 - 50,150,100,50,sf::Color(128,128,128,255));
	playLabel.setPosition(window->getView().getSize().x/2 - playLabel.getGlobalBounds().width/2,
                            175 - playLabel.getGlobalBounds().height);
	title.setPosition(window->getView().getSize().x/2 - (title.getLocalBounds().width/2), 10);

	while (window->isOpen()) //function loop
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
			if (event.type == sf::Event::MouseButtonPressed) {
				//check buttons
				if (testButton.pointOnBox(event.mouseButton.x, event.mouseButton.y)) { //simple test level button
					DeleteAllBullets();
					BattleStage().open(window);
				}
			}
			//window closed
			if (event.type == sf::Event::Closed) window->close();
        }

        newbullet(rand()%495,600);
        BulletLogic();
		//draw sequence
        window->clear();
        RenderAndDeleteBullet(window);
		window->draw(*testButton.getShape());
		window->draw(title);
		window->draw(playLabel);
        window->display();
    }
}
