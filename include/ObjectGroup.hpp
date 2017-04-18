#pragma once
#include "Layer.hpp"

#include <vector>
#include <SFML\Graphics\Rect.hpp>
#include <memory>
namespace tmx
{
	struct ObjectData
	{
		int16_t id;
		int16_t gid;
		float rotation;
		std::string name;
		std::string type;
		sf::FloatRect rect;
	};
	class ObjectGroup :public Layer
	{
	public:
		using Ptr = std::shared_ptr<ObjectGroup>;

		ObjectGroup();
		void load(xml_node * node);
		const std::string & getName()const;
		const std::vector<ObjectData> & getObject();
	private:
		std::string name;
		std::vector<ObjectData> vObject;
	};
}
