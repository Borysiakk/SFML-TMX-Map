#pragma once
#include <SFML\Graphics.hpp>
#include <memory>
using TexturePtr = std::shared_ptr<sf::Texture>;

struct TextureID
{
	TexturePtr texture;
	sf::FloatRect rect;
};
class TextureAtlas
{
public:
	TextureAtlas(std::string source,int16_t count,sf::Vector2i Size);
	~TextureAtlas();

private:
	sf::Vector2i Size;
	std::string msource;
	TexturePtr texture;
};

