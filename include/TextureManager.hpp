#pragma once
#include <unordered_map>
#include <memory>
#include <SFML\Graphics.hpp>
struct TextureID
{
	std::shared_ptr<sf::Texture> texture;
	sf::FloatRect rect;
};
class TextureManager
{
public:
	TextureManager();

	void AddTextureID(std::string source, sf::Vector2i Size);
	void AddTexturesID(std::string source,sf::Vector2i Size, int16_t count, int16_t columns);

	const TextureID & getTextureID(int16_t index);
private:
	int16_t id;
	std::unordered_map<int16_t,TextureID> mTexture;
};

