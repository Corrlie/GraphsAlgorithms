#pragma once

#include<unordered_map>
#include <vector>
#include "Edge.h"
#include <cassert>

typedef std::unordered_map<int, std::vector<CEdge>> graphType;

class CGraph
{
	graphType m_oGraph;

public:
	const graphType getGraph() { return m_oGraph; }
	void addEdge(const CEdge& oEdge);

	void depthFirstSearch(const int& iStartPoint, 
		std::vector<bool>* pVisitedVerticesList);
};

