#include "BattleStage.h"
#include "Button.h"
#include "player.h"
#include "Bullet.h"

void BattleStage::open(sf::RenderWindow* window) {
	//prepare level
	bool done = false;
	Button exitB = Button(0,0,50,50,sf::Color(64,64,64,255));
	player p1 = player();
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
	//list drawables
	drawables = std::list<sf::Shape*>();
	drawables.push_front(exitB.getShape());
	drawables.push_front(p1.getSprite());

	//bulk loop
	while (!done) {
		p1.logic();
		BulletLogic();
		sf::Event event;
		while(window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				done = true;
				window->close(); //check for closed window
			}
			if (event.type == sf::Event::MouseButtonPressed) { //if the exit button is clicked, prepare to back out of screen
				if (event.mouseButton.button == sf::Mouse::Left &&
					exitB.pointOnBox(event.mouseButton.x, event.mouseButton.y)) done = true;
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::W) {
					drawables.push_back(&upSq);
					p1.input(player::UP);
				}
				if (event.key.code == sf::Keyboard::S) {
					drawables.push_back(&downSq);
					p1.input(player::DOWN);
				}
				if (event.key.code == sf::Keyboard::A) {
					drawables.push_back(&leftSq);
					p1.input(player::LEFT);
				}
				if (event.key.code == sf::Keyboard::D) {
					drawables.push_back(&rightSq);
					p1.input(player::RIGHT);
				}
				if (event.key.code == sf::Keyboard::Q) {
                    drawables.push_back(&zSq);
                    newbullet(p1.getX(),p1.getY());
                }
				if (event.key.code == sf::Keyboard::X) drawables.push_back(&xSq);
			}
			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::W) {
					drawables.remove(&upSq);
					p1.input(player::STOP);
				}
				if (event.key.code == sf::Keyboard::S) {
					drawables.remove(&downSq);
					p1.input(player::STOP);
				}
				if (event.key.code == sf::Keyboard::A) {
					drawables.remove(&leftSq);
					p1.input(player::STOP);
				}
				if (event.key.code == sf::Keyboard::D) {
					drawables.remove(&rightSq);
					p1.input(player::STOP);
				}
				if (event.key.code == sf::Keyboard::Q) drawables.remove(&zSq);
				if (event.key.code == sf::Keyboard::X) drawables.remove(&xSq);
			}
		}

		//draw sequence
		window->clear();
		for (std::list<sf::Shape*>::iterator it = drawables.begin(); it != drawables.end(); it++)
			window->draw(**it);
        RenderAndDeleteBullet(window);
		window->display();
	}
	DeleteAllBullets();
}
