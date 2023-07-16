#pragma once

#include<unordered_map>
#include <vector>
#include <set>
#include <cassert>
#include <stack>
#include <queue>
#include "Edge.h"
#include "macros.h"
#include "DataStructuresTools.h"


class CGraph
{
	graphType m_oGraph;

public:
	const graphType getGraph() { return m_oGraph; }
	
	void addEdge(const CEdge& oEdge);
	
	int getNumberOfGraphNodes();

	void depthFirstSearch(const int& iStartPoint, 
		std::vector<bool>* pVisitedVerticesList);

	std::vector<bool> createIniVisitedVerticesList(); 

	void runDepthFirstSearchAlgorithms();

	std::stack<int> prepareTopSortStack();
	void sortTopological();
	void sortTopologicalUtil(int currentIndex, std::vector<bool>* pVisitedVector, std::stack<int>* pTopSortStack);
	
	void calculateShortestPathForDAGGraph();

	void dijkstraAlgorithm(int iStartPoint);
};

