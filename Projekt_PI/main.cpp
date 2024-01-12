#include "Menu.h"

int main()
{
	sf::RenderWindow MENU(sf::VideoMode(1600, 900), "Dungeon Conquest", sf::Style::Default | sf::Style::Titlebar);
	MENU.setFramerateLimit(120);

	Menu menu;
	menu.grajMuzyke();
	//poczatkowo wszystkie okna maja byc zamkniete

	while (MENU.isOpen())
	{
		menu.eventPolling(&MENU);

		menu.mainUpdate(&MENU);

		MENU.clear();

		menu.mainDraw(&MENU);

		MENU.display();
	}
}