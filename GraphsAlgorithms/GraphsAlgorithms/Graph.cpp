#include <iostream>
#include "Graph.h"


void CGraph::addEdge(const CEdge& oEdge)
{
	m_oGraph[oEdge.getStartVertex()].push_back(oEdge);
}

void CGraph::depthFirstSearch(const int& iStartPoint, std::vector<bool>* pVisitedVerticesVector)
{
	if (pVisitedVerticesVector == nullptr) assert(false);
	if (!(*pVisitedVerticesVector)[iStartPoint]) {
		(*pVisitedVerticesVector)[iStartPoint] = true;
		std::cout << iStartPoint << std::endl;
		std::vector<CEdge> edgesList = m_oGraph[iStartPoint];
		for (CEdge edge : edgesList) {
			depthFirstSearch(edge.getEndVertex(), pVisitedVerticesVector);
		}

	}



}
