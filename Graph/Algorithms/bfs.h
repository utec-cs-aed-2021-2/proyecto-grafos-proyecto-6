#ifndef BFS_H
#define BFS_H

#include "../graph.h"
#include <queue>
template <typename TV, typename TE> class BFS{
    public: 
    Graph<TV, TE> *graph;
    std::unordered_map<std::string, Vertex<TV, TE>*> vertexes;
    string start_id;
    BFS(Graph<TV, TE> *graph, string id){
        vertexes = graph->getVertexes(graph);
        this->graph = graph;
        this->start_id = id;
    };

    vector<Vertex<TV,TE>*> apply_bfs(){

        vector<Vertex<TV,TE>*> result;
        unordered_map<Vertex<TV,TE>*,bool> visited;
        auto it = this->vertexes.begin();
        for(it; it != this->vertexes.end();it++){
            visited[it->second] =false;
        }






};






#endif