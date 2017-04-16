#pragma once
#include <memory>
#include <string>
#include <pugixml.hpp>
#include <SFML\System\Vector2.hpp>
using namespace pugi;
enum class TypeLayer
{
	Tile = 0,
	Object = 1,
};
class Layer
{
public:
	using Ptr = std::shared_ptr<Layer>;

	TypeLayer getType();
	void setType(TypeLayer type);
	virtual void load(xml_node * node) = 0;
private:
	TypeLayer mtype;
};

