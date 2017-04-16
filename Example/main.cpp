#include <iostream>
#include "Map.hpp"
#include "MapDrawable.hpp"
int main()
{
	Map map("tree.tmx");
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "TMX SFML");
	window.setFramerateLimit(60);
	MapDrawable MapDraw(map);

	while (window.isOpen())
	{
		sf::Event zdarzenie;
		while (window.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == sf::Event::Closed)
				window.close();

			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
				window.close();

		}
		window.clear();
		window.draw(MapDraw);
		window.display();
	}
}