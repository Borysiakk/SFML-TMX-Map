#pragma once
#include <memory>
#include <pugixml.hpp>
#include <SFML\System\Vector2.hpp>
using namespace pugi;
namespace tmx
{
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
}
