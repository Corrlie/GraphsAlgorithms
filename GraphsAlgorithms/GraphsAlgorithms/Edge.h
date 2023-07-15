#pragma once

class CEdge
{
	int m_iStartVertexIndex;
	int m_iEndVertexIndex;
	int m_iEdgeWeight;

public:
	CEdge(int iStartVertexIndex, int iEndVertexIndex, int iEdgeWeight) :
		m_iStartVertexIndex(iStartVertexIndex),
		m_iEndVertexIndex(iEndVertexIndex),
		m_iEdgeWeight(iEdgeWeight) {}

	int getStartVertex() const { return m_iStartVertexIndex; }
	int getEndVertex() const { return m_iEndVertexIndex; }
	int getEdgeWeight() const { return m_iEdgeWeight; }
};
