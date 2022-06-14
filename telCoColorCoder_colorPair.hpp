#ifndef TELCOCOLORCODER_COLORPAIR
#define TELCOCOLORCODER_COLORPAIR

#include <iostream>
#include <assert.h>
#include <string>
#include "colorCode_Enum.hpp"

namespace TelCoColorCoder
{
	class ColorPair {
	private:
		MajorColor majorColor;
		MinorColor minorColor;
	public:
		ColorPair(MajorColor major, MinorColor minor) :
			majorColor(major), minorColor(minor)
		{}
		MajorColor getMajor();
		MinorColor getMinor();
		std::string ToString();
	};

	ColorPair GetColorFromPairNumber(int pairNumber);
	int GetPairNumberFromColor(MajorColor major, MinorColor minor);
}

#endif // !TELCOCOLORCODER_COLORPAIR