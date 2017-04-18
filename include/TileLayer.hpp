#pragma once
#include "Layer.hpp"

#include <pugixml.hpp>
#include <memory>
#include <vector>

using namespace pugi;
namespace tmx
{
	struct LayerData
	{
		bool visible;
		float opacity;
		std::string name;
		sf::Vector2i size;
	};

	class TileLayer :public Layer
	{
	public:
		using Ptr = std::shared_ptr<TileLayer>;

		TileLayer();
		const std::vector<uint16_t> & getTile()const;
		void load(xml_node * node);
	private:
		LayerData Data;
		std::vector<uint16_t> vTile;
	};
}

