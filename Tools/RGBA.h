/*
ICode Library:RGBA.h
This library implements RGBA(Red Green Blue Alpha) image conversion algorithm.
*/

#ifndef ICODE_RGBA__
#define ICODE_RGBA__

#if __cplusplus < 201103L
#error "should use C++11 implementation"
#endif 

#include <iosfwd>
#include <regex>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

namespace ICode
{
	static int parseHex(const std::string& str)
	{
		return static_cast<int>(strtoul(str.c_str(),nullptr,16));		
	}
	
	class RGBA
	{
	public:
		RGBA():red(0),green(0),blue(0),alpha(255){}
		RGBA(int red,int green,int blue,int alpha=255):red(red),green(green),blue(blue),alpha(alpha){}

		bool hasAlpha() const
		{
			return alpha!=255;
		}
		
		RGBA operator=(std::string value)
		{
			static const std::regex reg(
				"^([0-9A-Fa-f]{2})([0-9A-Fa-f]{2})([0-9A-Fa-f]{2})([0-9A-Fa-f]{2})?$"
			);
	
			std::smatch match;
	
			if(std::regex_match(value,match,reg))
			{
				red=parseHex(match[1].str());
				green=parseHex(match[2].str());
				blue=parseHex(match[3].str());
	
				if(match[4].matched)
					alpha=parseHex(match[4].str());
			}
			else
				throw std::runtime_error("Invalid color value");
			
			return *this;			
		}
		
		friend std::istream& operator>>(std::istream& is,RGBA& rgba)
		{
			std::string value;
			is>>value;
	
			rgba=value;
	
			return is;
		}

	public:
		int red;
		int green;
		int blue;
		int alpha;
	};
}

#endif
