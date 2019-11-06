### SFML-TMX-Map


Supports tmx maps up to 0.18.2 with CSV,base64 and XML 

| Library       | Version       |
| ------------- |:-------------:|
| SFML          | 2.4  		|
| Pugi          | 1.8           |

It supports:<br>
-Draw Tiled<br>
-Draw Object

Example
```sh
#include <Map.hpp>
#include <MapDrawable.hpp>
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
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
		}
		window.clear();
		window.draw(MapDraw);
		window.display();
	}
}

