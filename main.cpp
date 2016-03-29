#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "player.h"

int main()
{ //simply create the window and start the main menu
	sf::RenderWindow window(sf::VideoMode(500, 600), "Flyover Game", sf::Style::Titlebar | sf::Style::Close); //sets window size and atributes (closable, has titlebar)

	MainMenu menu = MainMenu();

	window.setFramerateLimit(60);
	menu.open(& window);

    return 0;
}