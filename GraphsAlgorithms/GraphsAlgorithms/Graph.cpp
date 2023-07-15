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

std::stack<int> CGraph::prepareTopSortStack()
{
	std::stack<int> topSortStack;
	std::vector<bool> visitedVerticesVector = createIniVisitedVerticesList();
	int numberOfVertices = visitedVerticesVector.size();

	for (int currentIndex = 0;
		currentIndex < numberOfVertices;
		currentIndex++) {
		if (!visitedVerticesVector[currentIndex]) {
			sortTopologicalUtil(currentIndex, &visitedVerticesVector, &topSortStack);
		}
	}
	return topSortStack;
}

void CGraph::sortTopological()
{
	std::stack<int> topSortStack = prepareTopSortStack();

	while (!topSortStack.empty()) {
		std::cout << topSortStack.top() << " ";
		topSortStack.pop();
	}
}

void CGraph::sortTopologicalUtil(int currentIndex, std::vector<bool>* pVisitedVector, std::stack<int>* pTopSortStack)
{
	(*pVisitedVector)[currentIndex] = true;
	std::vector<CEdge> edgesList = m_oGraph[currentIndex];
	for (CEdge edge : edgesList) {
		if (!(*pVisitedVector)[edge.getEndVertex()])
		{
			sortTopologicalUtil(edge.getEndVertex(), pVisitedVector, pTopSortStack);
		}
	}
	pTopSortStack->push(currentIndex);

}

void CGraph::calculateShortestPathForDAGGraph()
{
	int startVertex = 0;
	std::stack<int> topSortStack = prepareTopSortStack();
	int numberOfNodes = topSortStack.size();
	std::vector<int> distances(numberOfNodes, 9999);
	distances[startVertex] = 0;

	for (int currentVertexIndex = 0;
		currentVertexIndex < numberOfNodes;
		currentVertexIndex++) {
		std::vector<CEdge> edgesList = m_oGraph[currentVertexIndex];
		for (CEdge edge : edgesList) {
			int newDist = distances[currentVertexIndex] + edge.getEdgeWeight();
			if (distances[edge.getEndVertex()] == 9999) distances[edge.getEndVertex()] = newDist;
			else distances[edge.getEndVertex()] = distances[edge.getEndVertex()] < newDist ? distances[edge.getEndVertex()] : newDist;
		}
	}

	for (int dist : distances) {
		std::cout << dist << " ";
	}
}

void CGraph::depthFirstSearch(const int& iStartPoint, std::vector<bool>* pVisitedVerticesVector)
{
	if (pVisitedVerticesVector == nullptr) assert(false);
	if (!(*pVisitedVerticesVector)[iStartPoint]) {
		(*pVisitedVerticesVector)[iStartPoint] = true;
		std::cout << iStartPoint << " ";
		std::vector<CEdge> edgesList = m_oGraph[iStartPoint];
		for (CEdge edge : edgesList) {
			depthFirstSearch(edge.getEndVertex(), pVisitedVerticesVector);
		}
	}
}
