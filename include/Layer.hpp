#pragma once
#include <memory>
#include <string>
#include <pugixml.hpp>
#include <SFML\System\Vector2.hpp>
using namespace pugi;
enum class TypeLayer
{
	Tile = 0,
	Oject = 1,
};
class Layer
{
public:
	using Ptr = std::unique_ptr<Layer>;

	Layer();
	TypeLayer getType();
	void setType(TypeLayer type);
	virtual void load(xml_node * node) = 0;
private:
	TypeLayer mtype;
};

