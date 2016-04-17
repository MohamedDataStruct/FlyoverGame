#include "LevelComplete.h"

LevelComplete::LevelComplete() {
	font = sf::Font();

	message = sf::Text();
	message.setString("LEVEL COMPLETE");
	message.setCharacterSize(50);
	message.setColor(sf::Color::Cyan);

	drawables = std::list<sf::Drawable*>();
	//drawables.push_front(message);
	drawables.push_front(continueButton.getShape());
}

void LevelComplete::open(sf::RenderWindow* window) {
    font.loadFromFile("arial.ttf");
    message.setFont(font);

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

		//draw sequence
        window->clear();
		for (std::list<sf::Drawable*>::iterator it = drawables.begin(); it != drawables.end(); it++)
			window->draw(**it);
        window->draw(message);
        window->display();
    }
}
