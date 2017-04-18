#include "TextureManager.hpp"
#include <iostream>

using namespace tmx;

TextureManager::TextureManager()
{
	id = 1;
}

const TextureID & TextureManager::operator[](int index)
{
	return umTexture[index];
}

TextureID & TextureManager::at(int index)
{
	return umTexture[index];
}

size_t TextureManager::getCount()
{
	return umTexture.size();
}

void TextureManager::AddTextureID(std::string source,sf::Vector2i rect)
{
	TextureID data;
	data.rect = sf::IntRect(sf::Vector2i(0, 0), rect);
	data.texture = std::make_shared<sf::Texture>();
	if (data.texture->loadFromFile(source) != true)
	{
		std::cout << "Error texture load \n";
	}
	umTexture.insert(std::make_pair(id, std::move(data)));
	id++;
}

void TextureManager::AddTexturesID(std::string source, sf::Vector2i Size, int16_t count, int16_t columns)
{
	int gid = id;
	TextureID data;
	sf::IntRect rect(sf::Vector2i(0, 0),Size);
	data.texture = std::make_shared<sf::Texture>();
	if (data.texture->loadFromFile(source) != true)
	{
		std::cout << "Error texture load \n";
	}
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < count/columns; j++)
		{
			data.rect = rect;
			umTexture.insert(std::make_pair(gid, std::move(data)));
			rect.left += Size.x;
			gid++;
		}
		rect.left = 0;
		rect.top += Size.y;
	}
	data.texture = nullptr;
	id += count;
}

