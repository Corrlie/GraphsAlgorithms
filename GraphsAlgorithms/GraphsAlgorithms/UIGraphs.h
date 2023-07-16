#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
class UIGraphs
{
	UIGraphs() = delete;
	static void printGraphIndices(const std::vector<int>& vectorToPrint);
	static void printResultGraph(const std::vector<int>& vectorToPrint);
public:
	static void printResults(const std::vector<int>& vectorToPrint);
	static void printDijskstraAlgorithmResults(std::pair<std::unordered_map<int, std::vector<int>>,
		std::vector<int>>);
};

