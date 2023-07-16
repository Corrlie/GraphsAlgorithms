#include "UIGraphs.h"

void UIGraphs::printGraphIndices(const std::vector<int>& vectorToPrint)
{
	std::cout << "Graph Indices: " << std::endl;

	for (int vertexIndex = 0; vertexIndex < vectorToPrint.size(); vertexIndex++) {
		std::cout << vertexIndex << " ";

	}

	std::cout << std::endl;
}

void UIGraphs::printResultGraph(const std::vector<int>& vectorToPrint)
{
	std::cout << "Operation result: " << std::endl;

	for (int vectorElement : vectorToPrint) {
		std::cout << vectorElement << " ";
	}
	
	std::cout << std::endl;
}

void UIGraphs::printResults(const std::vector<int>& vectorToPrint)
{
	printGraphIndices(vectorToPrint);
	printResultGraph(vectorToPrint);
}

void UIGraphs::printDijskstraAlgorithmResults(std::pair<std::unordered_map<int, std::vector<int>>, 
	std::vector<int>> resultPathsAndShortestDistancePair)
{
	printGraphIndices(resultPathsAndShortestDistancePair.second);

	for (int i = 0; i < resultPathsAndShortestDistancePair.second.size(); i++) {
		std::cout << "Vertex: " << i;
		std::cout << " Distance:" << resultPathsAndShortestDistancePair.second[i] << std::endl;
		std::vector<int> pathsForVertex = resultPathsAndShortestDistancePair.first[i];
		if (pathsForVertex.size() > 0) {
			std::cout << "Path: ";
			for (int singleStepForPath : pathsForVertex) {
				std::cout << singleStepForPath << " ";
			}
		}
		else {
			if (resultPathsAndShortestDistancePair.second[i] == 0) {
				std::cout << "The path is not needed. You are already at your destination";
			}
			else {
				std::cout << "The path is not available...";
			}
		}
		std::cout<<std::endl;
	}

}

void UIGraphs::printDijskstraAlgorithmResultEndPointOnly(std::pair<std::unordered_map<int, std::vector<int>>,
	std::vector<int>> resultPathsAndShortestDistancePair, int iEndPoint)
{
	std::cout << "Vertex: " << iEndPoint;
	std::cout << " Distance:" << resultPathsAndShortestDistancePair.second[iEndPoint] << std::endl;
	std::vector<int> pathsForVertex = resultPathsAndShortestDistancePair.first[iEndPoint];
	if (pathsForVertex.size() > 0) {
		std::cout << "Path: ";
		for (int singleStepForPath : pathsForVertex) {
			std::cout << singleStepForPath << " ";
		}
	}
	else {
		if (resultPathsAndShortestDistancePair.second[iEndPoint] == 0) {
			std::cout << "The path is not needed. You are already at your destination";
		}
		else {
			std::cout << "The path is not available...";
		}
	}
	std::cout << std::endl;

}
