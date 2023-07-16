#pragma once

#define INFINITY_HEX 0x3f3f3f3f
typedef std::unordered_map<int, std::vector<CEdge>> graphType;
typedef std::pair<int, int> weightVertexPair;
typedef std::priority_queue<weightVertexPair, std::vector<weightVertexPair>, std::greater<weightVertexPair>> priorityQueueDijkstraAlg;
