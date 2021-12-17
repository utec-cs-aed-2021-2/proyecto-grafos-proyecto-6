#ifndef BEST_H
#define BEST_H
#include <bits/stdc++.h>
#include "../graph.h"
#include <limits>
#include "../DirectedGraph.h"
#include "../UndirectedGraph.h"
#include <vector>
template <typename TV, typename TE>
class BestFirstSearch{
public:
    typedef pair<TE, string> simpleEdge;
    Graph<TV, TE> *graph;
    std::unordered_map<std::string, Vertex<TV, TE> *> vertexes;
    string start_id;
    string end_id;
    vector<string> path;

    BestFirstSearch(Graph<TV, TE> *graph, string start_id, string end_id) {
        this->vertexes = graph->getVertexes(graph);
        this->start_id = start_id;
        this->end_id = end_id;
    };
    
    vector<string> apply() {

        unordered_map<string, bool> visited;
        for (auto& v : this->vertexes)
            visited[v.first] = false;
        visited[start_id] = true;    
        vector<string> result;
        priority_queue<simpleEdge, vector<simpleEdge>, greater<simpleEdge> > priorityQueue;
        priorityQueue.push(make_pair(0, start_id));

        while (!priorityQueue.empty()) {
            string poppedID = priorityQueue.top().second;
            result.push_back(poppedID);
            priorityQueue.pop();
            if (poppedID == end_id)
                break;

            for(auto& e : this->vertexes[poppedID]->edges){
                if (!visited[e->vertexes[1]->id]) {
                    visited[e->vertexes[1]->id] = true;
                    priorityQueue.push(make_pair(e->weight,e->vertexes[1]->id));
                }
            }
        }
        this->path = result;
        return result;
    }

    void display() {
        for(auto& v : this->path)
            cout<<v<<", ";
        cout<<endl;
    }
};
#endif