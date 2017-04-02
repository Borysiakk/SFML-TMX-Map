#include "Tileset.hpp"
#include <iostream>

Tileset::Tileset()
{

}

void Tileset::load_tileset(xml_node * node)
{
	Image data;
	Data.firstgid = node->attribute("firstgid").as_int();
	Data.name = node->attribute("name").as_string();
	Data.SizeTile = sf::Vector2i(node->attribute("tilewidth").as_int(), node->attribute("tileheight").as_int());
	Data.tilecount = node->attribute("tilecount").as_int();
	Data.columns = node->attribute("columns").as_int();
	auto image = node->child("image");
	if (image == NULL)
	{
		for (xml_node tile = node->child("tile"); tile; tile = tile.next_sibling("tile"))
		{
			data.id = tile.attribute("id").as_int();
			auto && DataImage = tile.child("image");
			data.Size = sf::Vector2i(DataImage.attribute("width").as_int(), DataImage.attribute("height").as_int());
			data.source = DataImage.attribute("source").value();
			vImage.push_back(std::move(data));
		}
	}
	else
	{
		vImage.resize(1);
		data.id = 0;
		data.Size = sf::Vector2i(image.attribute("width").as_int(), image.attribute("height").as_int());
		data.source = image.attribute("source").value();
		vImage[0] = std::move(data);
	}
}


Tileset::~Tileset()
{
}
