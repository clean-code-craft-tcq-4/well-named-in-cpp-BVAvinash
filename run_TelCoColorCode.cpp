#include "colorCode_Enum.hpp"
#include "telCoColorCoder_colorPair.hpp"

void testNumberToPair(int pairNumber, MajorColor expectedMajor, MinorColor expectedMinor)
{
	TelCoColorCoder::ColorPair colorPair = TelCoColorCoder::GetColorFromPairNumber(pairNumber);
	std::cout << "Got pair " << colorPair.ToString() << std::endl;
	assert(colorPair.getMajor() == expectedMajor);
	assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(MajorColor major, MinorColor minor, int expectedPairNumber)
{
	int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
	std::cout << "Got pair number " << pairNumber << std::endl;
	assert(pairNumber == expectedPairNumber);
}

void printColorCodeManual() 
{
	std::cout << "Color Coding Reference Manual: " << std::endl;
	std::cout << "Pair No." << "    " << "Color_Pair" << std::endl;
	for (int pairNumber = 1; pairNumber <= 25; pairNumber++)
	{
		TelCoColorCoder::ColorPair colorPair = TelCoColorCoder::GetColorFromPairNumber(pairNumber);
		std::cout << pairNumber << "    " << colorPair.ToString() << std::endl;
	}
}

int main()
{
	printColorCodeManual();

	testNumberToPair(4, WHITE, BROWN);
	testNumberToPair(5, WHITE, SLATE);

	testPairToNumber(BLACK, ORANGE, 12);
	testPairToNumber(VIOLET, SLATE, 25);

	return 0;
}
