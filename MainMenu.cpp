#include "MainMenu.h"
#include "Button.h"
#include <iostream>

MainMenu::MainMenu() {
	titleFont = sf::Font();

	title = sf::Text();
	title.setString("FLYOVER");
	title.setCharacterSize(50);
	title.setColor(sf::Color::Cyan);
}

void MainMenu::open(sf::RenderWindow* window) {
	if (!titleFont.loadFromFile("arial.ttf")) return;
	title.setFont(titleFont);
	
	Button testButton = Button(window->getView().getSize().x/2 - 50,150,100,50,sf::Color::Red);
	title.setPosition(window->getView().getSize().x/2 - (title.getLocalBounds().width/2), 10);

	while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
			if (event.type == sf::Event::MouseButtonPressed) {
				std::cout << event.mouseButton.x << " " << event.mouseButton.y << " " << testButton.pointOnBox(event.mouseButton.x, event.mouseButton.y);
				//check buttons
				if (testButton.pointOnBox(event.mouseButton.x, event.mouseButton.y)) {
					if (testButton.getShape()->getFillColor().toInteger() == sf::Color::Red.toInteger()) testButton.getShape()->setFillColor(sf::Color::Green);
					else testButton.getShape()->setFillColor(sf::Color::Red);
				}
			}
			if (event.type == sf::Event::Closed) window->close();
        }

        window->clear();
		window->draw(*testButton.getShape());
		window->draw(title);
        window->display();
    }
}