#ifndef DSTREE_H
#define DSTREE_H

#include "ds.h"

template <typename T>
struct Node {
    T data;
    Node* parent;
    int rank;

    Node() { 
        parent = this;
        rank = 0;
    }
    Node(T value) {
        data = value;
        parent = this;
        rank = 0;
    }
    void killSelf() {
        if (parent != nullptr){
            parent->killSelf();
            delete parent;
        }        
    }
};

template <typename T>
class DisjoinSetTree: public DisjoinSet<T> {
    private:
        int n;
        int unionCounter;
        Node<T>* Nodes;

    public:
        DisjoinSetTree(vector<T> data) {
            this-> n = data.size();
            this->unionCounter = 0;
            this->Nodes = new Node<T>[n];

            for (int i = 0; i < data.size(); i++)
                this->Nodes[i].data = data[i];

            MakeSet();
        } 
        void MakeSet(int x) {
            this->Nodes[x].rank = 0;
            this->Nodes[x].parent = &Nodes[x];
        }

        void MakeSet(){
            for (int i = 0; i < n; i++) {
                this->Nodes[i].rank = 0;
                this->Nodes[i].parent = &Nodes[i];
                
            }
        }

        int Find(int x){
            if(x < 0 || x >= this->n) throw("Error");

            if (Nodes[x].data == Nodes[x].parent->data){
                return x;
            }

            // Converting the char to index  EX: char(a) -> 0
            // "a"->97
            int ind = (int)Nodes[x].parent->data - 97;
            return Find(ind);
        }

        void Union(int x, int y){
            int xrep = Find(x); 
            int yrep = Find(y); 
    
            if (xrep == yrep) return; 
            
            if ((Nodes[xrep].rank) < (Nodes[yrep].rank))
                Nodes[xrep].parent = &Nodes[yrep]; 
            
            else if ((Nodes[xrep].rank) > (Nodes[yrep].rank))
                Nodes[yrep].parent = &Nodes[xrep]; 
            
            else { 
                Nodes[yrep].parent = &Nodes[xrep]; 
                Nodes[xrep].rank++; 
            } 
            unionCounter++;
        }

        bool isConnected(int x, int y) { return Find(x) == Find(y);}

        int size() { return n; }

        int sets() { return (n - unionCounter); }

        int size(int x){
            int localSize = 0;

            for (int i = 0; i < n; i++){
                if (Nodes[x].data == Nodes[i].parent->data)
                    localSize++;
            }
            return localSize;
        }

        void add(T element, int x){
            return;
        }

        vector<T> getElementsSet(int x){
            vector<T> sets;
            int xrep = Find(x);
            for (int i=0; i<n; i++){
                if (Nodes[xrep].data == Nodes[i].parent->data)
                    sets.push_back(Nodes[i].data);
            }
            return sets;
        }
};

#endif