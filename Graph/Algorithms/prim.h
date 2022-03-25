#ifndef PRIM_H
#define PRIM_H

#include <climits>
#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../graph.h"
#include "../UndirectedGraph.h"

#define MAX 0xFFFFFF

using namespace std;

template <typename TV, typename TE>
class Prim {
    protected:
        UnDirectedGraph<TV, TE> Graph;
        string nodeSource;
        Vertex<TV, TE>* srcVertex;
        UnDirectedGraph<TV, TE> MSTgraph;
    
    private:
        static bool compare_nocase(const Edge<TV, TE>* first, const Edge<TV, TE>* second);
        void printMST(unordered_map<Vertex<TV, TE>*, Vertex<TV, TE>*> par);
        void fillMST(unordered_map<Vertex<TV, TE>*, Vertex<TV, TE>*> par);
        Vertex<TV, TE>* minKey(unordered_map<Vertex<TV, TE>*, TE> key, unordered_map<Vertex<TV, TE>*, bool> mstSet) ;

    public:
        Prim(UnDirectedGraph<TV, TE>* Graph, string nodeSource);
        UnDirectedGraph<TV, TE> apply();
};

template <typename TV, typename TE>
Prim<TV, TE>::Prim(UnDirectedGraph<TV, TE>* Graph, string nodeSource) 
{
    this->Graph = *Graph;
    this->nodeSource = nodeSource;
    this->srcVertex = Graph->findVertex(nodeSource);
    // cout << "Prim init" << endl;
}

template <typename TV, typename TE>
bool Prim<TV, TE>::compare_nocase(const Edge<TV, TE>* first, const Edge<TV, TE>* second) {
    return first->weight < second->weight;
}

template <typename TV, typename TE>
void Prim<TV, TE>::fillMST(unordered_map<Vertex<TV, TE>*, Vertex<TV, TE>*> par) {
    for (auto e : par) {
        string id1 = this->Graph.findByVertex(e.first);
        string id2 = this->Graph.findByVertex(e.second);
        TE w = this->Graph.getweigthEdge(id1, id2);
        this->MSTgraph.createEdge(id1, id2, w);
    }
}

template <typename TV, typename TE>
Vertex<TV, TE>* Prim<TV, TE>::minKey(unordered_map<Vertex<TV, TE>*, TE> key, unordered_map<Vertex<TV, TE>*, bool> mstSet) {

    TE min = 10000000.0;
    Vertex<TV, TE>* min_index;

    for (auto x : key) {
        Vertex<TV, TE>* v = x.first;
        if (mstSet[v] == false && key[v] < min) {
            min = key[v], min_index = v;
        }
    }
    return min_index;
}


template <typename TV, typename TE>
UnDirectedGraph<TV, TE> Prim<TV, TE>::apply() {

    unordered_map<Vertex<TV, TE>*, Vertex<TV, TE>*> parent;

    unordered_map<Vertex<TV, TE>*, TE> key;

    unordered_map<Vertex<TV, TE>*, bool> mstSet;

    auto vertexesGraph = this->Graph.getVertexesMST();
    for (auto it : vertexesGraph ) {
        mstSet[it.second] = false;
        key[it.second] = (int)MAX;
        
        this->MSTgraph.insertVertex(it.first, it.second->data);
    }

    
    key[this->srcVertex] = 0;

    
    vertexesGraph = this->Graph.getVertexesMST();
    for (auto itr : vertexesGraph) {
        
        Vertex<TV, TE>* u = minKey(key, mstSet);

        mstSet[u] = true;

        for (auto e : u->edges) {
            Vertex<TV, TE>* v = e->vertexes[1];
            if (mstSet[v] == false && e->weight < key[v]) {
                parent[v] = u, key[v] = e->weight;
            }
        }
    }

    fillMST(parent);
    
    return this->MSTgraph;
}

#endif