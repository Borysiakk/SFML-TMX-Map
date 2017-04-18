#include "Decode.hpp"
#include <iostream>
#include <array>
#include <unordered_map>
#include <bitset>
#include <algorithm>
#include <memory>
using namespace tmx;

Decode::Decode(xml_text xmltext, TypeDecode type)
{
	std::string text = xmltext.as_string();
	std::string result;
	std::copy_if(text.begin() + 1, text.end(), std::back_inserter(result), [](const char x) {return (x != ' ' &&  x!= '\n'); });// xText[0] = '\n'
	switch (type)
	{
	case TypeDecode::BASE64:
		decodeBase64(result);
	break;
	case TypeDecode::CSV:
		decodeCSV(result);
	break;
	case TypeDecode::BASE64_ZLIB:
		decodeZlib(result);
	break;
	case TypeDecode::BASE64_GZIP:

	break;
	}
}

std::vector<std::uint16_t> Decode::operator()()
{
	return data;
}

Decode::~Decode()
{
}

void Decode::decodeBase64(std::string text)
{
	static std::unordered_map<unsigned char, unsigned char> mChars
	{

		{ 'A', 0 },{ 'B',1 },{ 'C',2 },{ 'D',3 },{ 'E',4 },{ 'F',5 },{ 'G',6 },{ 'H',7 },{ 'I',8 },{ 'J',9 },{ 'K',10 },{ 'L',11 },{ 'M',12 },{ 'N',13 },{ 'O',14 },{ 'P',15 },
		{ 'Q',16 },{ 'R',17 },{ 'S',18 },{ 'T',19 },{ 'U',20 },{ 'V',21 },{ 'W',22 },{ 'X',23 },{ 'Y',24 },{ 'Z',25 },{ 'a',26 },{ 'b',27 },{ 'c',28 },{ 'd',29 },{ 'e',30 },{ 'f',31 },
		{ 'g',32 },{ 'h',33 },{ 'i',34 },{ 'j',35 },{ 'k',36 },{ 'l',37 },{ 'm',38 },{ 'n',39 },{ 'o',40 },{ 'p',41 },{ 'q',42 },{ 'r',43 },{ 's',44 },{ 't',45 },{ 'u',46 },{ 'v',47 },
		{ 'w',48 },{ 'x',49 },{ 'y',50 },{ 'z',51 },{ '0',52 },{ '1',53 },{ '2',54 },{ '3',55 },{ '4',56 },{ '5',57 },{ '6',58 },{ '7',59 },{ '8',60 },{ '9',61 },{ '+',62 },{ '/',63 },{ '=',64 }
	};

	size_t size = text.size();
	std::vector < std::bitset<8>> vText;
	if (text[size - 1] == '=' && text[size - 2] == '=')size -= 3;
	else if (text[size - 1] == '=')size -= 2;
	for (size_t i = 0; i < size; i++)
	{
		vText.push_back(mChars[text[i]]);
	}
	size = 0;
	short movement = 0;
	std::vector < std::bitset<8>> vDecode;
	for (size_t i = 0; i < vText.size(); i++)
	{
		if (movement == 8)movement = 0;

		if (movement == 0)
		{
			vDecode.push_back(std::bitset<8>());
			size = vDecode.size() - 1;
			for (int j = 0; j<5; j++)
				vDecode[size].set(j + 2, vText[i][j]);
		}
		else if (movement == 2)
		{
			vDecode[size].set(1, vText[i][5]);
			vDecode[size].set(0, vText[i][4]);
			vDecode.push_back(std::bitset<8>());
			size = vDecode.size() - 1;
			vDecode[size].set(7, vText[i][3]);
			vDecode[size].set(6, vText[i][2]);
			vDecode[size].set(5, vText[i][1]);
			vDecode[size].set(4, vText[i][0]);
		}
		else if (movement == 4)
		{
			vDecode[size].set(3, vText[i][5]);
			vDecode[size].set(2, vText[i][4]);
			vDecode[size].set(1, vText[i][3]);
			vDecode[size].set(0, vText[i][2]);

			vDecode.push_back(std::bitset<8>());
			size = vDecode.size() - 1;
			vDecode[size].set(7, vText[i][1]);
			vDecode[size].set(6, vText[i][0]);
		}
		else if (movement == 6)
		{
			for (int j = 0; j<5; j++)
				vDecode[size].set(j, vText[i][j]);
		}
		movement += 2;
	}
	for (std::vector<std::bitset<8>>::iterator it = vDecode.begin(); it != vDecode.end(); it += 4)
	{
		data.push_back(static_cast<int16_t>(it->to_ulong()));
	}
}

void Decode::decodeCSV(std::string text)
{
	for (auto && obj : text)if (obj != ',')data.push_back(atoi(&obj));
}

void Decode::decodeZlib(std::string _text)
{

}