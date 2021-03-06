#include "Map.hpp"
#include "TileLayer.hpp"
#include "ObjectGroup.hpp"
#include <iostream>
#include <algorithm>
using namespace tmx;

Map::Map()
{
}

Map::Map(std::string name)
{
	load(name);
}

void Map::load(std::string name)
{
	auto result = document.load_file(name.c_str());
	if (!result)
	{
		std::cout << "Error load map\n";
	}
	auto map = document.child("map");
	data.orientation = map.attribute("orientation").value();
	std::string render = map.attribute("renderorder").value();

	if (render == "right-down")data.Render = RenderOrder::RightDown;
	else if (render == "right-up")data.Render = RenderOrder::RightUp;
	else if (render == "left-down")data.Render = RenderOrder::LeftDown;
	else if (render == "left-up")data.Render = RenderOrder::LeftUp;

	data.SizeMap = sf::Vector2i(map.attribute("width").as_int(), map.attribute("height").as_int());
	data.SizeTile = sf::Vector2i(map.attribute("tilewidth").as_int(), map.attribute("tileheight").as_int());
	data.backgroundcolor = map.attribute("backgroundcolor").value();
	auto && tileset = map.children("tileset");
	for (auto && tile : tileset)
	{
		vTileset.push_back(std::make_shared<Tileset>());
		vTileset[vTileset.size() - 1]->load_tileset(&tile);
	}
	auto && vlayer = map.children("layer");
	for (auto && layer : vlayer)
	{
		vLayer.push_back(std::make_shared<TileLayer>());
		vLayer[vLayer.size() - 1]->load(&layer);
	}

	auto && vobjectgroup = map.children("objectgroup");
	for (auto && objectgroup : vobjectgroup)
	{
		vLayer.push_back(std::make_shared<ObjectGroup>());
		vLayer[vLayer.size() - 1]->load(&objectgroup);
	}
}
