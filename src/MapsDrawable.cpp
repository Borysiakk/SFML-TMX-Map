#include "MapsDrawable.hpp"
#include <iostream>
#include <experimental\xutility>
MapsDrawable::MapsDrawable(std::vector<Tileset::Ptr> & vtileset):vTileset(vtileset)
{
	loadtexture();
}

void MapsDrawable::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
}

void MapsDrawable::loadtexture()
{
	int size;
	int tilecount;
	for (auto && tile : vTileset)
	{
		size = tile->getImges().size();
		tilecount = tile->getData().tilecount;
		if ((size == 1) && (tilecount != 1))
		{
			TextureManager.AddTexturesID(tile->getImges()[0].source, tile->getData().SizeTile,tilecount, tile->getData().columns);
		}
		else if ((size != 1) && (tilecount != 1))
		{
			for (auto && data : tile->getImges())
			{
				TextureManager.AddTextureID(data.source, data.Size);
			}
		}
	}
}
