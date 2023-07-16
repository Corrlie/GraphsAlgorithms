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

	return (int)verticesSet.size();
}


std::vector<bool> CGraph::createIniVisitedVerticesList() {
	int numberOfGraphNodes = getNumberOfGraphNodes();
	std::vector<bool> createIniVisitedVerticesList(numberOfGraphNodes, false);
	return createIniVisitedVerticesList;
}

std::vector<int> CGraph::runDepthFirstSearchAlgorithms()
{
	std::vector<int> verticesList;
	std::vector<bool> visitedVerticesVector = createIniVisitedVerticesList();

	depthFirstSearch(0, &visitedVerticesVector, &verticesList);
	
	return verticesList;
}

std::stack<int> CGraph::prepareTopSortStack()
{
	std::stack<int> topSortStack;
	std::vector<bool> visitedVerticesVector = createIniVisitedVerticesList();
	int numberOfVertices = (int)visitedVerticesVector.size();

	for (int currentIndex = 0;
		currentIndex < numberOfVertices;
		currentIndex++) {
		if (!visitedVerticesVector[currentIndex]) {
			sortTopologicalUtil(currentIndex, &visitedVerticesVector, &topSortStack);
		}
	}
	return topSortStack;
}

std::vector<int> CGraph::sortTopological()
{
	std::vector<int> sortedVertices;
	std::stack<int> topSortStack = prepareTopSortStack();

	while (!topSortStack.empty()) {
		sortedVertices.push_back(topSortStack.top());
		topSortStack.pop();
	}

	return sortedVertices;
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

std::vector<int> CGraph::calculateShortestPathForDAGGraph()
{
	std::vector<int> calculatedShortestPathsForDAG;
	int startVertex = 0;
	std::stack<int> topSortStack = prepareTopSortStack();
	int numberOfNodes = (int)topSortStack.size();
	std::vector<int> distances(numberOfNodes, INFINITY_HEX);
	distances[startVertex] = 0;

	for (int currentVertexIndex = 0;
		currentVertexIndex < numberOfNodes;
		currentVertexIndex++) {
		std::vector<CEdge> edgesList = m_oGraph[currentVertexIndex];
		for (CEdge edge : edgesList) {
			int newDist = distances[currentVertexIndex] + edge.getEdgeWeight();
			if (distances[edge.getEndVertex()] == INFINITY_HEX) distances[edge.getEndVertex()] = newDist;
			else distances[edge.getEndVertex()] = distances[edge.getEndVertex()] < newDist ? distances[edge.getEndVertex()] : newDist;
		}
	}

	for (int distance : distances) {
		calculatedShortestPathsForDAG.push_back(distance);
	}
	
	return calculatedShortestPathsForDAG;
}



std::pair<std::unordered_map<int, std::vector<int>>,
	std::vector<int>> CGraph::dijkstraAlgorithm(int iStartPoint)
{
	if (iStartPoint > getNumberOfGraphNodes()) assert(false);
	std::pair<std::unordered_map<int, std::vector<int>>,
		std::vector<int>> pathsAndShortestDistancePair;
	priorityQueueDijkstraAlg priorityQueueDistanceVertex;
	int numberOfNodes = getNumberOfGraphNodes();
	std::vector<int> distances(numberOfNodes, INFINITY_HEX);
	std::vector<bool> visitedList(numberOfNodes, false);
	std::unordered_map<int, std::vector<int>> shortestPathsMap;
	std::vector<CEdge> edgesPerVertex;
	priorityQueueDistanceVertex.push(std::make_pair(0, iStartPoint));
	distances[iStartPoint] = 0;
		
	while (!(DataStructuresTools::areAllVectorElementsTrue(visitedList)) && !(priorityQueueDistanceVertex.empty()))
	{
		int currentVertexIndex = priorityQueueDistanceVertex.top().second;
		visitedList[currentVertexIndex] = true;
		priorityQueueDistanceVertex.pop();

		edgesPerVertex = m_oGraph[currentVertexIndex];

		for (CEdge singleEdge : edgesPerVertex) {
			if (distances[singleEdge.getEndVertex()] > distances[singleEdge.getStartVertex()] + singleEdge.getEdgeWeight()) {
				distances[singleEdge.getEndVertex()] = distances[singleEdge.getStartVertex()] + singleEdge.getEdgeWeight();
				priorityQueueDistanceVertex.push(std::make_pair(distances[singleEdge.getEndVertex()], singleEdge.getEndVertex()));
				shortestPathsMap[singleEdge.getEndVertex()] = shortestPathsMap[currentVertexIndex];
				shortestPathsMap[singleEdge.getEndVertex()].push_back(currentVertexIndex);
			}
		}
	}

	pathsAndShortestDistancePair.first = shortestPathsMap;
	pathsAndShortestDistancePair.second = distances;

	return pathsAndShortestDistancePair;
 }

void CGraph::depthFirstSearch(const int& iStartPoint,
	std::vector<bool>* pVisitedVerticesVector,
	std::vector<int>* pVerticesVector)
{
	if (pVisitedVerticesVector == nullptr || 
		pVerticesVector == nullptr) assert(false);
	if (!(*pVisitedVerticesVector)[iStartPoint]) {
		(*pVisitedVerticesVector)[iStartPoint] = true;
		pVerticesVector->push_back(iStartPoint);
		std::vector<CEdge> edgesList = m_oGraph[iStartPoint];
		for (CEdge edge : edgesList) {
			depthFirstSearch(edge.getEndVertex(), pVisitedVerticesVector, pVerticesVector);
		}
	}
}
