#pragma once
#include <vector>
#include <SFML\System\Vector2.hpp>
#include <memory>
#include <pugixml.hpp>
using namespace pugi;

struct TilesetData
{
	uint16_t columns;
	uint16_t firstgid;
	uint16_t tilecount;
	std::string name;
	sf::Vector2i SizeTile;
};
struct Image
{
	uint16_t id;
	sf::Vector2i Size;
	std::string source;
};
class Tileset
{
public:
	using Ptr = std::unique_ptr<Tileset>;

	Tileset();
	void load_tileset(xml_node * node);
	~Tileset();
private:
	TilesetData Data;
	std::vector<Image> vImage;
};

