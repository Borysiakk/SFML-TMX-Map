#pragma once
#include "TextureManager.hpp"
#include "Tileset.hpp"

#include <vector>
#include <memory>
#include <SFML\Graphics.hpp>
class MapsDrawable :public sf::Drawable
{
public:
	MapsDrawable(std::vector<Tileset::Ptr> & tileset);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	void loadtexture();
	TextureManager TextureManager;
	std::vector<Tileset::Ptr> & vTileset;
};
