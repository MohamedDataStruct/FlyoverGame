#include "BattleStage.h"
#include "Button.h"

void BattleStage::open(sf::RenderWindow* window) {
	//prepare level
	bool done = false;
	Button exitB = Button(0,0,50,50,sf::Color::Color(64,64,64,255));
	// keyboard display parts
	sf::RectangleShape upSq = sf::RectangleShape(sf::Vector2f(50,50));
	sf::RectangleShape downSq = sf::RectangleShape(sf::Vector2f(50,50));
	sf::RectangleShape leftSq = sf::RectangleShape(sf::Vector2f(50,50));
	sf::RectangleShape rightSq = sf::RectangleShape(sf::Vector2f(50,50));
	sf::RectangleShape zSq = sf::RectangleShape(sf::Vector2f(50,50));
	sf::RectangleShape xSq = sf::RectangleShape(sf::Vector2f(50,50));
	//display colors
	upSq.setFillColor(sf::Color::Green);
	downSq.setFillColor(sf::Color::Green);
	leftSq.setFillColor(sf::Color::Green);
	rightSq.setFillColor(sf::Color::Green);
	zSq.setFillColor(sf::Color::Red);
	xSq.setFillColor(sf::Color::Cyan);
	//display positons
	upSq.setPosition(50,500);
	downSq.setPosition(50,550);
	leftSq.setPosition(0,550);
	rightSq.setPosition(100,550);
	zSq.setPosition(0,500);
	xSq.setPosition(100,500);

	//bulk loop
	while (!done) {

		sf::Event event;
		while(window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				done = true;
				window->close(); //check for closed window
			}
			if (event.type == sf::Event::MouseButtonPressed) { //if the exit button is clicked, prepare to back out of screen
				if (event.mouseButton.button == sf::Mouse::Button::Left &&
					exitB.pointOnBox(event.mouseButton.x, event.mouseButton.y)) done = true;
			}
		}

		//draw sequence
		window->clear();
		window->draw(*exitB.getShape());
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) window->draw(upSq);
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) window->draw(downSq);
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) window->draw(leftSq);
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) window->draw(rightSq);
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) window->draw(zSq);
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)) window->draw(xSq);
		window->display();
	}
}