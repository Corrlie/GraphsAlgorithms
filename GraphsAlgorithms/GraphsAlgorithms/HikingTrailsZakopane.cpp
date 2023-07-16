#include "HikingTrailsZakopane.h"
#include "Graph.h"

void HikingTrailsZakopane::prepareHikingTrailsMap()
{
    m_oHikingTrailsPoints.insert(std::make_pair(KUZNICE, "Kuünice"));
    m_oHikingTrailsPoints.insert(std::make_pair(MYSLENICKIE_TURNIE, "Myúlenickie Turnie"));
    m_oHikingTrailsPoints.insert(std::make_pair(KASPROWY_WIERCH, "Kasprowy wierch"));
    m_oHikingTrailsPoints.insert(std::make_pair(KLASZTOR_ALBERTYNEK, "Klasztor Albertynek"));
    m_oHikingTrailsPoints.insert(std::make_pair(POLANA_KALATOWKI, "Polana Kalatowki"));
    m_oHikingTrailsPoints.insert(std::make_pair(SCHRONISKO_KALATOWKI, "Schronisko Kalatowki"));
    m_oHikingTrailsPoints.insert(std::make_pair(SCHRONISKO_HALA_KONDRATOWA, "Schronisko Hala Kondratowa"));
    m_oHikingTrailsPoints.insert(std::make_pair(KONDRACKA_PRZELECZ, "Kondracka Przelecz"));
    m_oHikingTrailsPoints.insert(std::make_pair(WYZNIA_KONDRACKA_PRZELECZ, "Wyznia Kondracka Przelecz"));
    m_oHikingTrailsPoints.insert(std::make_pair(GIEWONT, "Giewont"));
    m_oHikingTrailsPoints.insert(std::make_pair(PRZELECZ_W_GRZYBOWCU, "Przelecz w Grzybowcu"));
    m_oHikingTrailsPoints.insert(std::make_pair(POLANA_STRAZYSKA, "Polana Strazyska"));
    m_oHikingTrailsPoints.insert(std::make_pair(DOLINA_STRAZYSKA, "Dolina Strazyska"));
}

HikingTrailsZakopane::HikingTrailsZakopane()
{
    prepareHikingGraph();
}

void HikingTrailsZakopane::prepareHikingGraph()
{
    prepareHikingTrailsMap();

    m_oHikingTrailsGraph.addEdge(CEdge(KUZNICE, MYSLENICKIE_TURNIE, 80));
    m_oHikingTrailsGraph.addEdge(CEdge(MYSLENICKIE_TURNIE, KASPROWY_WIERCH, 190));
    m_oHikingTrailsGraph.addEdge(CEdge(KUZNICE, KLASZTOR_ALBERTYNEK, 15));
    m_oHikingTrailsGraph.addEdge(CEdge(KLASZTOR_ALBERTYNEK, POLANA_KALATOWKI, 30));
    m_oHikingTrailsGraph.addEdge(CEdge(POLANA_KALATOWKI, SCHRONISKO_HALA_KONDRATOWA, 50));
    m_oHikingTrailsGraph.addEdge(CEdge(SCHRONISKO_HALA_KONDRATOWA, KONDRACKA_PRZELECZ, 75));
    m_oHikingTrailsGraph.addEdge(CEdge(KONDRACKA_PRZELECZ, WYZNIA_KONDRACKA_PRZELECZ, 15));
    m_oHikingTrailsGraph.addEdge(CEdge(WYZNIA_KONDRACKA_PRZELECZ, GIEWONT, 15));
    m_oHikingTrailsGraph.addEdge(CEdge(PRZELECZ_W_GRZYBOWCU, WYZNIA_KONDRACKA_PRZELECZ, 90));
    m_oHikingTrailsGraph.addEdge(CEdge(POLANA_STRAZYSKA, PRZELECZ_W_GRZYBOWCU, 50));
    m_oHikingTrailsGraph.addEdge(CEdge(DOLINA_STRAZYSKA, POLANA_STRAZYSKA, 40));
    m_oHikingTrailsGraph.addEdge(CEdge(KASPROWY_WIERCH, GIEWONT, 150));
}
