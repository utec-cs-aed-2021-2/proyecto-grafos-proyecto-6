#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <iostream>
#include <algorithm>
#include <vector>       

#include "../../disjointset-noerato14/ds.h"
#include "../../disjointset-noerato14/dsarray.h"
#include "../graph.h"
#include "../UndirectedGraph.h"

using namespace std;

template <typename TV, typename TE>
class Kruskal {
    public:
        UnDirectedGraph<TV, TE> *graph;
        UnDirectedGraph<TV, TE> *MSTgraph;
        DisjoinSet<Vertex<TV, TE> *>* ds;
        
        unordered_map<Vertex<TV, TE>*, int> vertexesIndex;
        vector< pair<TE, Edge<TV, TE>*>> edges;


        Kruskal(UnDirectedGraph<TV, TE>& graph) {
            this->graph = &graph;
            this->MSTgraph = new UnDirectedGraph<TV, TE>;

            vector<Vertex<TV, TE>*> vertexes;

            auto graph_vertexes = this->graph->getVertexesMST();
            
            int idx = 0; 
            for (auto& v : graph_vertexes){
                this->MSTgraph->insertVertex(v.second->id, v.second->data);
                vertexes.push_back(v.second);
                vertexesIndex[v.second] = idx;
                idx++; 
            }

            this->ds = new DisjoinSetArray<Vertex<TV, TE>*>(vertexes);

            
            for (auto& v : this->vertexesIndex){
                ds->MakeSet(v.second);
                for (auto& le : v.first->edges){
                    this->edges.push_back(make_pair((*le).weight, &(*le)));
                }
            }

            sort(this->edges.begin(), this->edges.end());
            this->edges.erase(unique(this->edges.begin(), this->edges.end()), this->edges.end());
        }

        UnDirectedGraph<TV, TE> apply() {
            
            for (auto& e : this->edges) {
                int v1 = vertexesIndex[(e.second)->vertexes[0]];
                int v2 = vertexesIndex[(e.second)->vertexes[1]];
                if (this->ds->Find(v1) != this->ds->Find(v2)){
                    this->ds->Union(v1,v2);
                    MSTgraph->createEdge((e.second)->vertexes[0]->id, (e.second)->vertexes[1]->id, e.first);
                }
            }
            return *(this->MSTgraph);
        }
};


#endif