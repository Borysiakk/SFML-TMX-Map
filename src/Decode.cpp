#include "Decode.hpp"

Decode::Decode(xml_text text, TypeDecode type):mtype(type),mtext(std::move(text))
{

}

std::vector<std::uint16_t> Decode::operator()()
{
	return data;
}

Decode::~Decode()
{
}
