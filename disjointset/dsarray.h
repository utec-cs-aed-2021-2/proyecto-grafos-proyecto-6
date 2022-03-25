#ifndef DSARRAY_H
#define DSARRAY_H

#include "ds.h"

template <typename T>
class DisjoinSetArray: public DisjoinSet<T>
{
private:
    T* data;
    int* parent;
    int* rank;

    int n;
    int unionCounter;

public:
    DisjoinSetArray(vector<T> data) {
        
        this-> n = data.size();
        this->unionCounter = 0;

        this->data = new T[data.size()];
        this->rank = new int[data.size()];
        this->parent = new int[data.size()];

        for (int i = 0; i < data.size(); i++)
            this->data[i] = data[i];

        MakeSet();
    }

    //MakseSet the element with index x
    void MakeSet(int x){
        this->parent[x] = x;
        this->rank[x] = 0;
    }

    //MakseSet all elements
    void MakeSet(){

        for (int i = 0; i < n; i++){
            this->parent[i] = i;
            this->rank[i] = 0;
        }
    }
    //Find the root of x (with optimization)
    int Find(int x){
        if(x < 0 || x >= this->n) throw("Error");

        if (x == parent[x]) return x;
        return Find(parent[x]);
    }

    //Union two sets represented by x and y (apply rank)
    void Union(int x, int y){
        int xrep = Find(x); 
        int yrep = Find(y);

        if (xrep == yrep) return; 
        
        if (rank[xrep] < rank[yrep])
            parent[xrep] = yrep; 

        else if (rank[xrep] > rank[yrep])
            parent[yrep] = xrep;

        else { 
            parent[yrep] = xrep; 
            rank[xrep]++; 
        } 
        unionCounter++;
    }
    
    //check whether there is a path between x and y
    bool isConnected(int x, int y) {
        return (Find(x) == Find(y));
    }
    
    //total number of elements
    int size() {
        return n;
    }
    
    //number of sets
    int sets(){
        return (n- unionCounter);
    }
    
    //total number of elements that belong to the set of x
    int size(int x){

        int localSize = 0;
        for (int i = 0; i < n; i++){
            if (x == parent[i])
                localSize++;
        }

        return localSize;
    }
    
    //add the element to the set of x
    void add(T element, int x) {
        return;
    }
    
    //return all elements that belong to the set of x
    vector<T> getElementsSet(int x) {
        vector<T> sets;
        int xrep = Find(x);

        for (int i = 0; i < n; i++) {
            if (xrep == parent[i])
                sets.push_back(data[i]);
        }
        return sets;
    }
};

#endif