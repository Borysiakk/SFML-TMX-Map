#pragma once
#include "Layer.hpp"
#include <vector>
#include <SFML\Graphics\Rect.hpp>
struct ObjectData
{
	std::int16_t id;
	std::int16_t gid;
	sf::IntRect rect;
};
class ObjectGroup :public Layer
{
public:
	ObjectGroup();
	void load(xml_node * node);
	const std::vector<ObjectData> & getObject();
	~ObjectGroup();
private:
	std::vector<ObjectData> vObject;
};

