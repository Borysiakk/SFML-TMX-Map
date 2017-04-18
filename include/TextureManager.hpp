#pragma once
#include <unordered_map>
#include <memory>
#include <SFML\Graphics.hpp>
namespace tmx
{
	struct TextureID
	{
		TextureID()
		{

		}
		TextureID(TextureID && textureid) :texture(textureid.texture), rect(textureid.rect)
		{
			textureid.rect = sf::IntRect(0, 0, 0, 0);
		}
		std::shared_ptr<sf::Texture> texture;
		sf::IntRect rect;
	};
	class TextureManager
	{
	public:
		TextureManager();
		const TextureID & operator[](int index);
		TextureID & at(int index);
		size_t getCount();
		void AddTextureID(std::string source, sf::Vector2i rect);
		void AddTexturesID(std::string source, sf::Vector2i Size, int16_t count, int16_t columns);
	private:
		int16_t id;
		std::unordered_map<int, TextureID> umTexture;
	};
}
