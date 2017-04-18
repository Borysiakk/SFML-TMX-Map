#pragma once
#include <vector>
#include <SFML\System\Vector2.hpp>
#include <memory>
#include <pugixml.hpp>
using namespace pugi;
namespace tmx
{
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
		using Ptr = std::shared_ptr<Tileset>;

		Tileset();
		Tileset(const Tileset && tileset);
		void load_tileset(xml_node * node);
		const TilesetData & getData() { return Data; }
		const std::vector<Image> & getImges() { return vImage; }
		~Tileset();
	private:
		TilesetData Data;
		std::vector<Image> vImage;
	};
}
