#pragma once
#include <memory>
#include <string>
#include <SFML\System\Vector2.hpp>

struct LayerData
{
	bool visible;
	float opacity;
	std::string name;
	sf::Vector2i offset;
};
class Layer
{
public:
	using Ptr = std::unique_ptr<Layer>;
	Layer();

	const sf::Vector2i & getOffset()const;
	const std::string & getName()const;
	bool getVisible();
	float getOpacity();

private:
	LayerData Data;
};

