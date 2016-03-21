#include <SFML/Graphics.hpp>
#include "MainMenu.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	MainMenu menu = MainMenu();

	menu.open(& window);

    return 0;
}