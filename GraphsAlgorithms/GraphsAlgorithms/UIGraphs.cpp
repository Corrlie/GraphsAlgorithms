#include "UIGraphs.h"

void UIGraphs::printResultVector(const std::vector<int>& vectorToPrint)
{
	std::cout << std::endl;
	for (int vectorElement : vectorToPrint) {
		std::cout << vectorElement << " ";
	}
	std::cout << std::endl;
}
