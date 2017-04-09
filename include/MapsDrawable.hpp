#pragma once
#include "Map.hpp"
#include "TextureAtlas.hpp"
#include <vector>
#include <memory>
#include <experimental\unordered_map>
#include <SFML\Graphics.hpp>
class MapsDrawable :public sf::Drawable
{
public:
	MapsDrawable();
	~MapsDrawable();
private:
	std::unordered_map<int16_t,TextureID> x;//int16_t gid = local id;
};

