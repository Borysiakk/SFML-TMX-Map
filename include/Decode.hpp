#pragma once
#include <vector>
#include <zlib.h>
#include <pugixml.hpp>
using namespace pugi;
enum class TypeDecode
{
	NONE = 0,
	CSV = 1,
	BASE64 = 2,
	BASE64_ZLIB = 3,
	BASE64_GZIP = 4,
};
class Decode
{
public:
	Decode(xml_text text,TypeDecode type);
	std::vector<std::uint16_t> operator()();
	~Decode();
private:
	xml_text mtext;
	TypeDecode mtype;
	std::vector<std::uint16_t> data;
};

