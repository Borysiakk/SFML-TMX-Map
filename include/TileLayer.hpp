#pragma once
#include "Layer.hpp"
#include <pugixml.hpp>
#include <memory>
using namespace pugi;
struct LayerData
{
	bool visible;
	float opacity;
	std::string name;
	sf::Vector2i offset;
};

class TileLayer :public Layer
{
public:
	using Ptr = std::unique_ptr<Layer>;

	TileLayer();
     void load(xml_node * node);
private:
	LayerData Data;
};

