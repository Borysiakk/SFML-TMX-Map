#include "TileLayer.hpp"
#include "Decode.hpp"

#include <iostream>
#include <sstream>
TileLayer::TileLayer()
{
	setType(TypeLayer::Tile);
}

void TileLayer::load(xml_node * node)
{
	std::string encoding;
	std::string compression;
	Data.name = node->attribute("name").value();
	Data.offset = sf::Vector2i(node->attribute("width").as_int(), node->attribute("height").as_int());
	auto && data = node->child("data");
	encoding = data.attribute("encoding").value();
	compression = data.attribute("compression").value();
	if (encoding.empty() == true)
	{
		auto && vTile = data.child("tile");

	}
	else if (encoding == "csv")
	{
		Decode decode(data.text, TypeDecode::CSV);
		std::cout << "csv\n";
	}
	else if (encoding == "base64" && compression.empty() == true)
	{
		Decode decode(data.text, TypeDecode::BASE64);
		std::cout << "base64\n";
	}
	else if (encoding == "base64" && compression == "zlib")
	{
		Decode decode(data.text, TypeDecode::BASE64_ZLIB);
		std::cout << "base64 zlib\n";
	}
	else if (encoding == "base64" && compression == "gzip")
	{
		Decode decode(data.text, TypeDecode::BASE64_GZIP);
		std::cout << "base64 gzip\n";
	}

}
