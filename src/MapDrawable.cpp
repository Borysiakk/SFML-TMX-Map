#include "MapDrawable.hpp"
#include <iostream>

#include "TileLayer.hpp"
#include "ObjectGroup.hpp"

MapDrawable::MapDrawable(Map & mmap):map(mmap)
{
	loadtexture();
	createvertex();
}

void MapDrawable::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	
	for (auto obj : vVertexArray)
	{
		states.texture = TextureManager[obj.first].texture.get();
		target.draw(obj.second,states);
	}
}

void MapDrawable::loadtexture()
{
	int size;
	int tilecount;
	for (auto && tile : map.getTilset())
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
				TextureManager.AddTextureID(data.source,data.Size);
			}
		}
	}
}

void MapDrawable::createvertex()
{
	int size = 0;
	sf::Vector2i MapSize = map.getData().SizeMap;
	sf::Vector2i TileSize = map.getData().SizeTile;
	sf::Vector2f Position(0,0 - TileSize.y);
	sf::VertexArray array(sf::VertexArray(sf::Quads, 4));
	for (auto obj : map.getLayer())
	{
		if (obj->getType() == TypeLayer::Tile)
		{
			TileLayer::Ptr tilesptr = std::dynamic_pointer_cast<TileLayer>(obj);
			for (int i = 0; i < tilesptr->getTile().size();i++)
			{

				if (i % MapSize.x == 0)
				{
					Position += sf::Vector2f(0, TileSize.y);
					Position.x = 0;
				}
				if (tilesptr->getTile()[i] != 0)
				{
					array[0].position = Position;
					array[1].position = sf::Vector2f(Position.x, Position.y + TileSize.y);
					array[2].position = sf::Vector2f(Position.x + TileSize.x, Position.y + TileSize.y);
					array[3].position = sf::Vector2f(Position.x + TileSize.x, Position.y);

					sf::IntRect rect = TextureManager[tilesptr->getTile()[i]].rect;
					array[0].texCoords = sf::Vector2f(rect.left, rect.top);
					array[1].texCoords = sf::Vector2f(rect.left, rect.top + rect.height);
					array[2].texCoords = sf::Vector2f(rect.left + rect.width, rect.top + rect.height);
					array[3].texCoords = sf::Vector2f(rect.left + rect.width, rect.top);
					vVertexArray.push_back(std::make_pair(tilesptr->getTile()[i], array));
				}
				Position += sf::Vector2f(TileSize.x,0);
			}
		}
		else
		{
			ObjectGroup::Ptr object = std::dynamic_pointer_cast<ObjectGroup>(obj);
		}
	}
}
