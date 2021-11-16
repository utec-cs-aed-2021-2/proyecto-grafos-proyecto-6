#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include "graph.h"

template<typename TV, typename TE>
class UnDirectedGraph : public Graph<TV, TE>{
    private: 
    public:
        bool insertVertex(string id, TV vertex);   
        bool createEdge(string id1, string id2, TE w);     
        bool deleteVertex(string id);     
        bool deleteEdge(string id1, string id2);   
        TE &operator()(string start, string end);  
        float density();
        bool isDense(float threshold = 0.5);
        bool isConnected() {return true;};
        bool isStronglyConnected() {return true;};
        bool empty();
        void clear();  
        void displayVertex(string id);
        bool findById(string id);
        void display();
};

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::insertVertex(string id, TV vertex) {
    Vertex<TV, TE>* newVertex = new Vertex<TV, TE>;

    if (this->findById(id))
        return false;
    
    newVertex->id = id;
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
    this->edgesSize++;
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
//eliminar arista de memeoria
        list<Edge<TV, TE>*> edges = this->vertexes[id1]->edges;
        for (auto& i :edges) {
            if ((*i).vertexes[0] == this->vertexes[id2] || (*i).vertexes[1] == this->vertexes[id2]) {
                this->vertexes[id1]->edges.remove(i);
            }
            
        }
        

        edges = this->vertexes[id2]->edges;
        
        for (auto& j :edges) {
            //cout<<(*j).weight<<endl;
            if ((*j).vertexes[0] == this->vertexes[id1] || (*j).vertexes[1] == this->vertexes[id1]) {
                this->vertexes[id2]->edges.remove(j);
            }
            
        }
        this->edgesSize--;
        return true;
    }
    return false;
}
/*
template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteEdge(string id1, string id2) {
    if (findById(id1) && findById(id2)) {
       
        list<Edge<TV, TE>*> edges = this->vertexes[id1]->edges;
        
        for (auto it= edges.begin(); it!=edges.end(); it++){
            cout<<"llego"<<endl;
            if ((*it)->vertexes[0] == this->vertexes[id2] || (*it)->vertexes[1] == this->vertexes[id2]){
                this->vertexes[id1]->edges.erase(it);
            }
        }
        
        edges = this->vertexes[id2]->edges;
        for (auto it= edges.begin(); it!=edges.end(); it++){
            if ((*it)->vertexes[0] == this->vertexes[id1] || (*it)->vertexes[1] == this->vertexes[id1]){
                auto tempAdd = *it;
                this->vertexes[id2]->edges.erase(it);
                delete tempAdd;
            }
        }
        return true;
        
    } else return false;
}
*/
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

        cout<<"Edges: { ";
        list<Edge<TV, TE>*> edges = this->vertexes[id]->edges;
        for (auto it = edges.begin(); it!=edges.end(); it++) {
            cout<<"("<< (*it)->vertexes[0]->id <<", "<< (*it)->vertexes[1]->id << "), ";
        }
        cout<<" }"<<endl;

    } else
        throw("ERROR: The vertex does not exist");         
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::findById(string id) {
    return !(this->vertexes.find(id) == this->vertexes.end());
}


template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::display() {
    for (auto it = this->vertexes.begin(); it != this->vertexes.end(); it++) {
        cout<<"ID: " << (*it).first <<endl;
        cout<<"Data: " << (*it).second->data <<endl;
        cout<<"Edges: { ";
        list<Edge<TV, TE>*> edges = (*it).second->edges;
        for (auto it = edges.begin(); it!=edges.end(); it++) {
            cout<<"("<< (*it)->vertexes[0]->id <<", "<< (*it)->vertexes[1]->id << "), ";
        }
        cout<<" }"<<endl;
    }

}

template<typename TV, typename TE>
float UnDirectedGraph<TV, TE>::density() {
    if( this->empty() ) throw "Graph is empty";
    
    float E = 0.0, V = 0.0;
    E = this->edgesSize;
    V = this->vertexes.size();
    return 2*E/(V*(V-1));
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::isDense(float threshold) {
    return (density() >= threshold);
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::empty() {
    return (this->vertexes.size() == 0);
}

template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::clear() {
    while (!this->vertexes.empty()) {
        auto i = *this->vertexes.begin();
        deleteVertex(i.first);

    }
}

#endif