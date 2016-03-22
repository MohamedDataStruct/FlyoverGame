#include <SFML/Graphics.hpp>
#include "MainMenu.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 600), "Flyover Game", sf::Style::Titlebar | sf::Style::Close);

	MainMenu menu = MainMenu();

	menu.open(& window);

    return 0;
}