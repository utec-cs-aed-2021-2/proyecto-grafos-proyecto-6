#ifndef FLOYD_W
#define FLOYD_W

#include "../graph.h"
#include "../DirectedGraph.h"
#include "../UndirectedGraph.h"
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits>



template <typename TV, typename TE>
class floyd_warshall{
    DirectedGraph<TV,TE>* floyd ;

public:
    bool check_key(unordered_map<string,TE> m, string key){
        return m.find(key) != m.end();
    }
    TE MAX_VALUE = std::numeric_limits<TE>::max();
    
    unordered_map<string,unordered_map<string,TE>> dist;

    floyd_warshall();
    floyd_warshall(DirectedGraph<TV,TE>* &grafo){


        for(auto &i : grafo->getVertexes(grafo)){
            unordered_map<string,TE> temp;
            for (auto &o: i.second->edges){
                temp[o->vertexes[1]->id] = o->weight;
            }
            for (auto &v : grafo->getVertexes(grafo)) {
                if (!check_key(temp,v.first)){
                    temp[v.first] = MAX_VALUE;
                }
            }

            dist[i.first] = temp;     
        }

        auto y = grafo;
        for(auto &a :grafo->getVertexes(grafo)){
            auto k = a.first;
            for(auto &b :grafo->getVertexes(grafo)){
                auto  i = b.first;
                if (k == i) 
                   dist[k][i] = 0;
                for(auto &c :grafo->getVertexes(grafo)){
                    auto j = c.first;
                    if(dist[i][j] > dist[i][k] + dist[k][j]
                        && dist[k][j] != MAX_VALUE
                        && dist[i][k] != MAX_VALUE ) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        //floyd->createEdge(i,j,dist[i][j]);
                    }
                    
                }
            }
        }
    }

/*
    DirectedGraph<TV,TE>* apply(){
        
    }
*/
    //display all pretty floyd graph
    void display(){
        for(auto &i : dist){
            cout << i.first << ": ";
            for(auto &j : i.second){

                cout << j.first << "(W: ";
                if (j.second == MAX_VALUE)
                    cout<< " INF ) ";
                else
                    cout<< j.second << ") ";
            }
            cout << endl;
        }
    }



};



#endif