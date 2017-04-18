#include "TileLayer.hpp"
#include "Decode.hpp"

#include <iostream>
using namespace tmx;

TileLayer::TileLayer()
{
	setType(TypeLayer::Tile);
}

const std::vector<uint16_t>& TileLayer::getTile() const
{
	return vTile;
}

void TileLayer::load(xml_node * node)
{
	std::string encoding;
	std::string compression;
	Data.name = node->attribute("name").value();
	Data.size = sf::Vector2i(node->attribute("width").as_int(), node->attribute("height").as_int());
	auto && data = node->child("data");
	encoding = data.attribute("encoding").value();
	compression = data.attribute("compression").value();
	if (encoding.empty() == true)
	{
		vTile.reserve(Data.size.x * Data.size.y);
		auto && vID = data.children("tile");
		for (auto && id : vID)
		{
			vTile.push_back(id.attribute("gid").as_uint());
		}
	}
	else if (encoding == "csv")
	{
		Decode decode(data.text(), TypeDecode::CSV);
		vTile = decode();
	}
	else if (encoding == "base64" && compression.empty() == true)
	{
		Decode decode(data.text(), TypeDecode::BASE64);
		vTile = decode();
	}
	else if (encoding == "base64" && compression == "zlib")
	{
		Decode decode(data.text(), TypeDecode::BASE64_ZLIB);
		std::cout << "base64 zlib no support \n";
	}
	else if (encoding == "base64" && compression == "gzip")
	{
		Decode decode(data.text(), TypeDecode::BASE64_GZIP);
		std::cout << "base64 gzip no support \n";
	}

}
