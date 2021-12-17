#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <bits/stdc++.h>
#include "../graph.h"
#include <limits>
#include "../DirectedGraph.h"
#include "../UndirectedGraph.h"
#include <vector>
template <typename TV, typename TE>
class Dijkstra{
public:
    typedef pair<TE, string> simpleEdge;
    Graph<TV, TE> *graph;
    std::unordered_map<std::string, Vertex<TV, TE> *> vertexes;
    string start_id;
    unordered_map<std::string, TE> distances;
    unordered_map<std::string, list<string>> paths;

    Dijkstra(Graph<TV, TE> *graph, string start_id) {
        this->vertexes = graph->getVertexes(graph);
        this->start_id = start_id;
    };
    
    unordered_map<std::string, TE>  apply() {
        int V = this->vertexes.size();
        TE MAX_VALUE = std::numeric_limits<TE>::max();
        unordered_map<std::string, TE> dist;
        unordered_map<std::string, bool> visited;

        for (auto& v : this->vertexes) {
            dist[v.first] = MAX_VALUE; 
            visited[v.first] = false;
        }
        dist[start_id] = 0;

        for (int count = 0; count < V - 1; count++) {

            TE minVal = MAX_VALUE;
            string u;
            for (auto& v : this->vertexes) {
                if (visited[v.first] == false && dist[v.first] <= minVal){
                    minVal = dist[v.first];
                    u = v.first;
                }
            }    
            
            visited[u] = true;
    
            // Update dist value of the adjacent vertices of the picked vertex.
            for (auto& v : this->vertexes){
                TE weight = 0;
                for (auto& e : this->vertexes[u]->edges){
                    if (e->vertexes[1]->id == v.first){
                        weight = e->weight;
                        break;
                    }
                }
                if (!visited[v.first] && weight && dist[u] != MAX_VALUE  
                    && dist[u] + weight < dist[v.first])
                    dist[v.first] = dist[u] + weight;
            }
        }

        this->distances = dist;
        return dist;
    }

    void display() {
        cout<<"id   "<<"Min. distance "<<endl;
        for (auto& d : this->distances) {
            cout<< d.first <<" : "<< d.second;
            cout<<endl;
        }
    }
};
#endif