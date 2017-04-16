#pragma once
#include <SFML\Graphics.hpp>
#include <pugixml.hpp>
#include <vector>

#include "Tileset.hpp"
#include "Layer.hpp"

#include "TileLayer.hpp"
#include "ObjectGroup.hpp"
using namespace pugi;

enum class RenderOrder
{
	RightDown = 0,
	RightUp = 1,
	LeftDown = 2,
	LeftUp = 3,
};

struct MapData
{
	std::string orientation;
	RenderOrder Render;
	sf::Vector2i SizeMap;
	sf::Vector2i SizeTile;
	std::string backgroundcolor;
};

class Map
{
public:
	using Ptr = std::shared_ptr<Map>;

	Map();
	Map(std::string name);

	void load(std::string maps);
	const MapData & getData() { return data; }
	std::vector<Layer::Ptr> getLayer() { return vLayer; }
	std::vector<Tileset::Ptr> getTilset() { return vTileset; }
private:
	std::vector<Tileset::Ptr> vTileset;
	std::vector<Layer::Ptr> vLayer;

	xml_document document;
	MapData data;
};

