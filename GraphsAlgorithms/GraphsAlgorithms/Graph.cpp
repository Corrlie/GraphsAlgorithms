#include <iostream>
#include "Graph.h"


void CGraph::addEdge(const CEdge& oEdge)
{
	m_oGraph[oEdge.getStartVertex()].push_back(oEdge);
}

int CGraph::getNumberOfGraphNodes()
{
	std::set<int> verticesSet;
	std::vector<CEdge> edgesPerVertex;

	for(graphType::iterator it = m_oGraph.begin(); it != m_oGraph.end(); it++)
	{
		edgesPerVertex = it->second;

		for (CEdge singleEdge : edgesPerVertex) {
			verticesSet.insert(singleEdge.getStartVertex());
			verticesSet.insert(singleEdge.getEndVertex());
		}
	}

	return verticesSet.size();
}


std::vector<bool> CGraph::createIniVisitedVerticesList() {
	int numberOfGraphNodes = getNumberOfGraphNodes();
	std::vector<bool> createIniVisitedVerticesList(numberOfGraphNodes, false);
	return createIniVisitedVerticesList;
}

void CGraph::runDepthFirstSearchAlgorithms()
{
	std::vector<bool> visitedVerticesVector = createIniVisitedVerticesList();
	depthFirstSearch(0, &visitedVerticesVector);
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
