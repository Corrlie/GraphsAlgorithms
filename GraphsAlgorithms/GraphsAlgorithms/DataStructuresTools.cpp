#include "DataStructuresTools.h"
#include <algorithm>

bool DataStructuresTools::areAllVectorElementsTrue(const std::vector<bool>& vectorToCheck)
{
	bool areVisited = false;
	if (std::all_of(vectorToCheck.begin(), vectorToCheck.end(), [](bool state) {return state; })) {
		areVisited = true;
	}
	return areVisited;


	//return std::all_of(vectorToCheck.begin(), vectorToCheck.end(), [](bool state) {return state;});
}
