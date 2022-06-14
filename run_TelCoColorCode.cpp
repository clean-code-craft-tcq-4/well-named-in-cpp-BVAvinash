#include "run_TelCoColorCoder.hpp"
#include "print_ColorCodeManual.hpp"

namespace TelCoColorCoder {
	ColorPair GetColorFromPairNumber(int pairNumber)
	{
		int zeroBasedPairNumber = pairNumber - 1;
		MajorColor majorColor = (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
		MinorColor minorColor = (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
		return ColorPair(majorColor, minorColor);
	}

	int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
		return major * numberOfMinorColors + minor + 1;
	}
}

void testNumberToPair(int pairNumber, TelCoColorCoder::MajorColor expectedMajor, TelCoColorCoder::MinorColor expectedMinor)
{
	TelCoColorCoder::ColorPair colorPair = TelCoColorCoder::GetColorFromPairNumber(pairNumber);
	std::cout << "Got pair " << colorPair.ToString() << std::endl;
	assert(colorPair.getMajor() == expectedMajor);
	assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(TelCoColorCoder::MajorColor major, TelCoColorCoder::MinorColor minor, int expectedPairNumber)
{
	int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
	std::cout << "Got pair number " << pairNumber << std::endl;
	assert(pairNumber == expectedPairNumber);
}

int main()
{
	testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
	testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

	testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
	testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);

	std::cout << "Color Coding Reference Manual: " << std::endl;
	std::cout << "Pair No. \t Color_Pair" << std::endl;
	for (int pair_number = 1; pair_number <= 25; pair_number++)
	{
		printManual(pair_number);
	}
	return 0;
}