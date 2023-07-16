This repository is for learning about graphs and the algorithms that can be performed on them. In the project you can find an implementation of the algorithms DepthFirstSearch, TopologicalSort, finding the shortest path for an acyclic directed graph, as well as finding the shortest path using the dijksra algorithm.
In this project I have placed a sub-project showing what the dijkstra's algorithm can be useful for. This sub-project consists in finding the fastest way from the starting point to the final point in the Polish capital of the Tatra Mountains - Zakopane. Some of the trail connections in the Polish Tatra Mountains are presented as a graph. And so - you can, for example, check what is the fastest way (in minutes) from Kuźnice to Giewont and what characteristic points will be passed along the way.
Both the project and the sub-project are not finished and will be developed further - for example other graphs algorithms or developing sub-project.

After starting the program, the results of individual algorithms will be displayed in the console:


![ProjectConsole](https://github.com/Corrlie/GraphsAlgorithms/assets/63510085/e0635671-9d85-406c-9461-a0559338297e)


The graph for which the algorithms are performed:


![sampleGraphDiagram](https://github.com/Corrlie/GraphsAlgorithms/assets/63510085/1b80be7a-36a5-4ed3-bdeb-b1067abcee97)


The described sub-project is also launched immediately. The sub-project concerning the trails in Zakopane has its own graph for which calculations are made. This graph is shown below. 


![sampleZakopaneHikingTrails](https://github.com/Corrlie/GraphsAlgorithms/assets/63510085/bab98dba-691f-4a21-a8aa-53aeb16e3306)


It is a graph built on the basis of maps of trails in the Tatra Mountains. Individual vertices of the graph are characteristic points - eg peaks, shelters, graph's edges are trails, while weights at the edges - times of arrival for individual trails.
For a sub-project, you can use the legend below to read through which characteristic points you will have to pass.


![ZakopaneHikingTrailPointsLegend](https://github.com/Corrlie/GraphsAlgorithms/assets/63510085/410c2cc4-8fe7-4cd6-bf29-372f5069e51a)


For the sub-project, the console shows the fastest trail (time and its characteristic points) for the hiking starting from Kuźnice and ending at the peak - Giewont.
From the console we can see that the planned hiking time is 200 minutes, and we will pass through: Kuźnice, Klasztor Albertynek, Polana Kalatówki, Schronisko Hala Kondratowa, Kondracka Przełęcz, Wyżnia Kondracka Przełęcz.
