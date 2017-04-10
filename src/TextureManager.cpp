#include "TextureManager.hpp"
#include <iostream>


TextureManager::TextureManager()
{
	id = 0;
}

void TextureManager::AddTextureID(std::string source,sf::Vector2i Size)
{
	TextureID data;
	sf::IntRect rect(sf::Vector2i(0, 0), sf::Vector2i(Size.x, Size.y));
	std::shared_ptr<sf::Texture> textureptr = std::make_shared<sf::Texture>();
	data.texture = textureptr;
	mTexture[id] = data;
	id++;
}

void TextureManager::AddTexturesID(std::string source, sf::Vector2i Size, int16_t count, int16_t columns)
{
	TextureID data;
	sf::IntRect rect(sf::Vector2i(0, 0), sf::Vector2i(Size.x, Size.y));
	std::shared_ptr<sf::Texture> textureptr = std::make_shared<sf::Texture>();
	if (textureptr->loadFromFile(source) != true)
	{
		std::cout << "Error texture load \n";
	}
	data.texture = textureptr;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			mTexture[i + id] = data;
			rect.top += Size.y;
		}
		rect.left += Size.x;
	}
	id += count;
}

const TextureID & TextureManager::getTextureID(int16_t index)
{
	return mTexture[index];
}
