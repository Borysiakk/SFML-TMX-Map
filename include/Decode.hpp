#pragma once
#include <vector>
#include <zlib.h>
#include <pugixml.hpp>
using namespace pugi;
enum class TypeDecode
{
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
    void decodeBase64(std::string text);
	void decodeCSV(std::string text);
	void decodeZlib(std::string text);

	std::vector<std::uint16_t> data;
};

