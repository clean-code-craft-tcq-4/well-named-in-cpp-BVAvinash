#include "stdafx.h"
#include "telCoColorCoder_colorPair.hpp"

const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};

int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

MajorColor TelCoColorCoder::ColorPair::getMajor() {
	return majorColor;
}

MinorColor TelCoColorCoder::ColorPair::getMinor() {
	return minorColor;
}

std::string TelCoColorCoder::ColorPair::ToString() {
	std::string colorPairStr = MajorColorNames[majorColor];
	colorPairStr += " ";
	colorPairStr += MinorColorNames[minorColor];
	return colorPairStr;
}

TelCoColorCoder::ColorPair TelCoColorCoder::GetColorFromPairNumber(int pairNumber) {
	int zeroBasedPairNumber = pairNumber - 1;
	MajorColor majorColor =
		(MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
	MinorColor minorColor =
		(MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
	return ColorPair(majorColor, minorColor);
}

int TelCoColorCoder::GetPairNumberFromColor(MajorColor major, MinorColor minor) {
	return major * numberOfMinorColors + minor + 1;
}