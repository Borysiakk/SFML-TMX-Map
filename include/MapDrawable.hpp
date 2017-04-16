#pragma once
#include "TextureManager.hpp"
#include "Map.hpp"

#include <unordered_map>
#include <memory>
#include <SFML\Graphics\Drawable.hpp>

class MapDrawable :public sf::Drawable
{
public:
	MapDrawable(Map & mmap);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	Map & map;
	void loadtexture();
	void createvertex();
	mutable TextureManager TextureManager;
	std::unordered_map<int,sf::VertexArray> mArrayVertex;
	std::vector<std::pair<int, sf::VertexArray>> vVertexArray;
};
