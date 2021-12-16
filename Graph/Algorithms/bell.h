#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H
#include <bits/stdc++.h>
#include "../graph.h"

template <typename TV, typename TE>
class Bellman_Ford {
public:
    Graph<TV, TE> *graph;
    std::unordered_map<std::string, Vertex<TV, TE> *> vertexes;
    string start_id;
    Bellman_Ford(Graph<TV, TE> *graph, string id)
    {
        vertexes = graph->getVertexes(graph);
        this->graph = graph;
        this->start_id = id;
    };

    unordered_map<std::string, TE> apply() {
        int V = vertexes.size();
        unordered_map<std::string, TE> dist;
        for (auto& v : vertexes)
            dist[v.first] = INT_MAX;
        dist[start_id] = 0;

        for (int i = 1; i <= V - 1; i++) {
            for (int j = 0; j < E; j++) {
                int u = graph->edge[j].src;
                int v = graph->edge[j].dest;
                int weight = graph->edge[j].weight;
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                    dist[v] = dist[u] + weight;
            }
        }
    }
};
#endif