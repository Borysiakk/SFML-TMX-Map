#include <iostream>
#include "Map.hpp"
#include "MapDrawable.hpp"
using namespace tmx;

int main()
{
	tmx::Map map("tree.tmx");
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "TMX SFML");
	window.setFramerateLimit(60);
	tmx::MapDrawable MapDraw(map);

	const auto & vLayer = map.getLayer();
	for (auto & layer : vLayer)
	{
		if (layer->getType() == TypeLayer::Tile)
		{
			TileLayer::Ptr obj = std::dynamic_pointer_cast<TileLayer>(layer);
		}
		else if (layer->getType() == TypeLayer::Object)
		{
			ObjectGroup::Ptr obj = std::dynamic_pointer_cast<ObjectGroup>(layer);
		}
	}

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