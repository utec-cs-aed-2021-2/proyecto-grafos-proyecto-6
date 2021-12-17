#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H
#include <bits/stdc++.h>
#include "../graph.h"
#include <limits>
#include "../DirectedGraph.h"
#include "../UndirectedGraph.h"

template <typename TV, typename TE>
class Bellman_Ford {
public:

    TE MAX_VALUE = std::numeric_limits<TE>::max();
    Graph<TV, TE> *graph;
    std::unordered_map<std::string, Vertex<TV, TE> *> vertexes;
    string start_id;
    unordered_map<std::string, TE> distances;
    unordered_map<std::string, list<string>> paths;
    Bellman_Ford(Graph<TV, TE> *graph, string id)
    {
        vertexes = graph->getVertexes(graph);
        this->graph = graph;
        this->start_id = id;
    };
    
    void apply() {
        int V = vertexes.size();
        unordered_map<std::string, TE> dist;
        unordered_map<std::string, list<string>> path;
        for (auto& v : vertexes){
            dist[v.first] = MAX_VALUE;
            list<string> temp;
            temp.push_back(start_id);
            path[v.first] = temp;
        }
            
        dist[start_id] = 0.0;

        for (int i = 1; i <= V - 1; i++) {

            for (auto& v : vertexes){
                for(auto& e : (v.second)->edges){
                    string u = e->vertexes[0]->id;
                    string v = e->vertexes[1]->id;
                    TE weight = e->weight;
                    if (dist[u] != MAX_VALUE && dist[u] + weight < dist[v]){
                        dist[v] = dist[u] + weight;
                        path[v].push_back(u);
                    }
                }
            }
        }
        for (auto& p : path){
            if (dist[p.first] != MAX_VALUE)
                p.second.push_back(p.first);
        }
        this->distances = dist;
        this->paths = path;
    }

    void display() {
        cout<<"id   "<<"distance    "<<"path"<<endl;
        for (auto& d : this->distances) {
            cout<< d.first <<" : ";if (d.second == MAX_VALUE)
                    cout<< "INF: ";
                else cout<<d.second <<" : ";

            for (auto& p : this->paths[d.first]) 
                cout<< p <<", ";
            cout<<endl;
        }
        
    }
};
#endif