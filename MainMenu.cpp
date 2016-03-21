#include "MainMenu.h"
#include "Button.h"
#include <iostream>

MainMenu::MainMenu() {
	

}

void MainMenu::open(sf::RenderWindow* window) {
	Button testButton = Button();

	while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
			if (event.type == sf::Event::MouseButtonReleased) {
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
        window->display();
    }
}