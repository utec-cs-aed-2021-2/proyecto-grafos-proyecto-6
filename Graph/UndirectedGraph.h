#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include "graph.h"

template<typename TV, typename TE>
class UnDirectedGraph : public Graph<TV, TE>{
    public:
        bool insertVertex(string id, TV vertex);   
        bool createEdge(string id1, string id2, TE w);     
        bool deleteVertex(string id);     
        bool deleteEdge(string id1, string id2);   
        TE &operator()(string start, string end);  
        float density();
        bool isDense(float threshold = 0.5);
        bool isConnected();
        bool isStronglyConnected();
        bool empty();
        void clear();  
        void displayVertex(string id);
        bool findById(string id);
        void display();
};

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::insertVertex(string id, TV vertex) {
    Vertex<TV, TE>* newVertex = new Vertex<TV, TE>;

    if (!findById(id))
        return false;
    
    newVertex->data = vertex;
    newVertex->edges;//revisar si se debe inicializar
    this->vertexes[id] = newVertex;
    return true;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::createEdge(string id1, string id2, TE w) {

    if (!findById(id1) || !findById(id2))
        return false;

    Edge<TV, TE>* newEdge = new Edge<TV, TE>;
    newEdge->vertexes[0] = vertexes[id1];
    newEdge->vertexes[1] = vertexes[id2];
    newEdge->weight = w;

    vertexes[id1]->edges.push_back(newEdge);
    vertexes[id2]->edges.push_back(newEdge);
    
    return true; 
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteVertex(string id) {
    if (findById(id)) {
        list<Edge<TV, TE>*> edges = this->vertexes[id]->edges;
        for (auto edge=edges.begin(); edge!=edges.end(); edge++){
            //deleteEdge(*it->vertexes[0], *it->vertexes[1]); 
            list<Edge<TV, TE>*> temp;
            if (*edge->vertexes[0] != this->vertexes[id])
                temp = *edge->vertexes[1]->edges;
            else 
                temp = *edge->vertexes[0]->edges;
        
            Edge<TV, TE>* tempAdd = nullptr;
            for (auto it=temp.begin(); it!=temp.end(); it++){
                if (*it->vertexes[0] == this->vertexes[id] || *it->vertexes[1] == this->vertexes[id]){
                    tempAdd = *it;
                    temp.erase(it);
                } 
            }
            edges.erase(edge);

            if (tempAdd!=nullptr) delete tempAdd;
        }
            
        this->vertexes.erase(id); 
        return true; 

    } else return false; 
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteEdge(string id1, string id2) {
    if (findById(id1) && findById(id2)) {
        list<Edge<TV, TE>*> edges = vertexes[id1]->edges;
        for (auto it= edges.begin(); it!=edges.end(); it++){
            if (*it->vertexes[0] == this->vertexes[id2] || *it->vertexes[1] == this->vertexes[id2]){
                edges.erase(it);
            }
        }

        edges = vertexes[id2]->edges;
        for (auto it= edges.begin(); it!=edges.end(); it++){
            if (*it->vertexes[0] == this->vertexes[id1] || *it->vertexes[1] == this->vertexes[id1]){
                auto tempAdd = *it;
                edges.erase(it);
                delete tempAdd;
            }
        }
        return true;
        
    } else return false;
}

template<typename TV, typename TE>
TE &UnDirectedGraph<TV, TE>::operator()(string start, string end) {
    if (!findById(start) || !findById(end)) 
        throw("ERROR: ID of some vertex does not exist");

    list<Edge<TV, TE>*> edges = vertexes[start]->edges;
    for (auto i= edges.begin(); i!=edges.end(); i++){
        if (*i->vertexes[1].data == end)
            return *i->weight;
    }
    throw("ERROR: The vertex does not exist"); 
}

template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::displayVertex(string id) {
    if (findById(id)){
        Vertex<TV, TE>* vertex = this->vertexes[id];
        cout<<"ID: " << id <<endl;
        cout<<"Data: " << vertex->data <<endl;

        cout<<"Edges: { ";
        list<Edge<TV, TE>*> edges = vertexes[id]->edges;
        for (auto it = edges.begin(); it!=edges.end(); it++) {
            cout<<"("<< *it->vertexes[0]->data <<", "<< *it->vertexes[1]->data << "), ";
        }
        cout<<" }"<<endl;

    } else
        throw("ERROR: The vertex does not exist");         
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::findById(string id) {
    return !(this->vertexes.find(id) == this->vertexes.end()) 
}


template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::display() {

}

#endif