#include <iostream>
#include "Map.hpp"
#include "MapDrawable.hpp"
int main()
{
	Map map("tree.tmx");
	sf::RenderWindow oknoAplikacji(sf::VideoMode(800, 600, 32), "TMX SFML");
	oknoAplikacji.setFramerateLimit(60);
	MapDrawable MapDraw(map);

	while (oknoAplikacji.isOpen())
	{
		sf::Event zdarzenie;
		while (oknoAplikacji.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == sf::Event::Closed)
				oknoAplikacji.close();

			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
				oknoAplikacji.close();

		}
		oknoAplikacji.clear();
		oknoAplikacji.draw(MapDraw);
		oknoAplikacji.display();
	}
}