#pragma once
#include <map>
#include <string>
#include "MacrosHikingTrailsZakopane.h"
#include "Graph.h"


class HikingTrailsZakopane
{
	std::map<int, std::string> m_oHikingTrailsPoints;
	CGraph m_oHikingTrailsGraph;
	void prepareHikingTrailsMap();
	void prepareHikingGraph();

public:
	HikingTrailsZakopane();
	CGraph getHikingTrailsGraph() { return m_oHikingTrailsGraph; }

	//static std::vector<std::string> decodeVerticesNames(const std::vector<int>& vectorToDecode);

};

