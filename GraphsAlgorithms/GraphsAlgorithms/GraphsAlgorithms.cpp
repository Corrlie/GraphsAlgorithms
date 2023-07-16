// GraphsAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Graph.h"

int main()
{
	CGraph graph;
	graph.addEdge(CEdge(0, 1, 3));
	graph.addEdge(CEdge(0, 2, 2));
	graph.addEdge(CEdge(0, 5, 3));
	graph.addEdge(CEdge(1, 3, 1));
	graph.addEdge(CEdge(1, 2, 6));
	graph.addEdge(CEdge(2, 3, 1));
	graph.addEdge(CEdge(2, 4, 10));
	graph.addEdge(CEdge(3, 4, 5));
	graph.addEdge(CEdge(5, 4, 7));

	std::cout << "\nDepth First Search Algorithm: " << std::endl;
	graph.runDepthFirstSearchAlgorithms();

	std::cout << "\nTopological sort: " << std::endl;
	graph.sortTopological();

	std::cout << "\nShortest Path DAG: " << std::endl;
	graph.calculateShortestPathForDAGGraph();

	std::cout << "\nShortest Path Dijkstra Algoritm: " << std::endl;
	graph.dijkstraAlgorithm(0);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
