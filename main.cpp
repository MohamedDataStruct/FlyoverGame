#include <SFML/Graphics.hpp>
#include "MainMenu.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::RectangleShape shape(sf::Vector2f(100,100));
    shape.setFillColor(sf::Color::Green);

	Screen* activeScreen = (Screen*)(new MainMenu);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
			activeScreen->handleEvent(event);
        }

        window.clear();
		activeScreen->update(window);;
        window.display();
    }

    return 0;
}