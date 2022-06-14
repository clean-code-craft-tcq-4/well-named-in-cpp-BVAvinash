#include "run_TelCoColorCoder.hpp"

void printManual(int pairNumber) 
{
	TelCoColorCoder::ColorPair colorPair = TelCoColorCoder::GetColorFromPairNumber(pairNumber);
	std::cout << pairNumber << " \t " << colorPair.ToString() << std::endl;
}