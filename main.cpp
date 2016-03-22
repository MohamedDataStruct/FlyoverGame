#include <SFML/Graphics.hpp>
#include "MainMenu.h"

int main()
{ //simply create the window and start the main menu
	sf::RenderWindow window(sf::VideoMode(500, 600), "Flyover Game", sf::Style::Titlebar | sf::Style::Close); //sets window size and atributes (closable, has titlebar)

	MainMenu menu = MainMenu();

	menu.open(& window);

    return 0;
}