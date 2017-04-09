#include "ObjectGroup.hpp"
#include "ObjectGroup.hpp"
#include <iostream>


ObjectGroup::ObjectGroup()
{
	setType(TypeLayer::Object);
}

void ObjectGroup::load(xml_node * node)
{
	ObjectData data;
	name = node->attribute("name").as_string();
	auto && vobject = node->children("object");
	vObject.reserve(std::distance(vobject.begin(), vobject.end()));
	for (auto && obj : vobject)
	{
		data.id = obj.attribute("id").as_int();
		data.gid = obj.attribute("gid").as_int();
		data.rect = sf::FloatRect(obj.attribute("x").as_float(), obj.attribute("y").as_float(), obj.attribute("width").as_int(), obj.attribute("height").as_int());
		data.rotation = obj.attribute("rotation").as_float();
		data.name = obj.attribute("name").as_string();
		data.type = obj.attribute("type").as_string();
		vObject.push_back(data);
	}

}

const std::string & ObjectGroup::getName() const
{
	return name;
}

const std::vector<ObjectData>& ObjectGroup::getObject()
{
	return vObject;
}


ObjectGroup::~ObjectGroup()
{
}
