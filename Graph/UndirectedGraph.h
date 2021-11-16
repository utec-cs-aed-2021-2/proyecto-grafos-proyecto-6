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
        float density() {return 0.0;};
        bool isDense(float threshold = 0.5){return true;};
        bool isConnected() {return true;};
        bool isStronglyConnected() {return true;};
        bool empty() {return true;};
        void clear() {};  
        void displayVertex(string id);
        bool findById(string id);
        void display();
};

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::insertVertex(string id, TV vertex) {
    Vertex<TV, TE>* newVertex = new Vertex<TV, TE>;

    if (this->findById(id))
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
    newEdge->vertexes[0] = this->vertexes[id1];
    newEdge->vertexes[1] = this->vertexes[id2];
    newEdge->weight = w;

    this->vertexes[id1]->edges.push_back(newEdge);
    this->vertexes[id2]->edges.push_back(newEdge);
    
    return true; 
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteVertex(string id) {
    list<Edge<TV, TE>*> edges = this->vertexes[id]->edges;
    if (findById(id)) { 
        for (auto &e : edges)
            deleteEdge((*e).vertexes[0]->id,(*e).vertexes[1]->id); 
            
        this->vertexes.erase(id); 
        return true; 

    } return false; 
    /*if (findById(id)) {
        list<Edge<TV, TE>*> edges = this->vertexes[id]->edges;
        for (auto edge=edges.begin(); edge!=edges.end(); edge++){
            //deleteEdge(*it->vertexes[0], *it->vertexes[1]); 
            list<Edge<TV, TE>*> temp;

            if ((*edge)->vertexes[0] != this->vertexes[id])
                temp = (*edge)->vertexes[0]->edges;

            else if ((*edge)->vertexes[1] != this->vertexes[id])
                temp = (*edge)->vertexes[1]->edges;
        
            Edge<TV, TE>* tempAdd = nullptr;
            for (auto it=temp.begin(); it!=temp.end(); it++){
                if ((*it)->vertexes[0] == this->vertexes[id] || (*it)->vertexes[1] == this->vertexes[id]){
                    tempAdd = *it;
                    temp.erase(it);
                } 
            }
            edges.erase(edge);

            if (tempAdd!=nullptr) delete tempAdd;
        }
            
        this->vertexes.erase(id); 
        return true; 

    } else return false; */
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteEdge(string id1, string id2) {
    if (findById(id1) && findById(id2)) {
       
        list<Edge<TV, TE>*> edges = this->vertexes[id1]->edges;
        cout<<"llego"<<endl;
        for (auto it= edges.begin(); it!=edges.end(); it++){
            if ((*it)->vertexes[0] == this->vertexes[id2] || (*it)->vertexes[1] == this->vertexes[id2]){
                this->vertexes[id1]->edges.remove(it);
            }
        }
        
        edges = this->vertexes[id2]->edges;
        for (auto it= edges.begin(); it!=edges.end(); it++){
            if ((*it)->vertexes[0] == this->vertexes[id1] || (*it)->vertexes[1] == this->vertexes[id1]){
                auto tempAdd = *it;
                this->vertexes[id2]->edges.remove(it);
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

    list<Edge<TV, TE>*> edges = this->vertexes[start]->edges;

    for (auto i= edges.begin(); i!=edges.end(); i++){
        if ((*i)->vertexes[0] == this->vertexes[end] || (*i)->vertexes[1] == this->vertexes[end]) 
            return (*i)->weight;
    }
    throw("ERROR: The vertex does not exist"); 
}

template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::displayVertex(string id) {
    if (findById(id)){
        Vertex<TV, TE>* vertex = this->vertexes[id];
        cout<<"ID: " << id <<endl;
        cout<<"Data: " << vertex->data <<endl;
/*
        cout<<"Edges: { ";
        list<Edge<TV, TE>*> edges = this->vertexes[id]->edges;
        for (auto it = edges.begin(); it!=edges.end(); it++) {
            cout<<"("<< (*it)->vertexes[0]->data <<", "<< (*it)->vertexes[1]->data << "), ";
        }
        cout<<" }"<<endl;
*/
    } else
        throw("ERROR: The vertex does not exist");         
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::findById(string id) {
    return !(this->vertexes.find(id) == this->vertexes.end());
}


template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::display() {

}

#endif