#ifndef A_STAR
#define A_STAR

#include "../graph.h"
#include "../DirectedGraph.h"
#include "../UndirectedGraph.h"
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>

template<typename TV, typename TE>
struct cmp{
    bool operator()(const pair<Vertex<TV,TE>*,TE>& Fa, const pair<Vertex<TV,TE>*,TE>& Fb){
        if(Fa.second > Fb.second){
            return true;
        }
        return false;
    }
};

template<typename TV,typename TE>
class Astar{
private:
    deque<string> path;
    UnDirectedGraph<TV,TE>* Fgraph;
    map<string, string> parents;
public:
        Astar(UnDirectedGraph<TV,TE>* graph, string start_id, string end_id, unordered_map<string,TE> heuristic){

            std::priority_queue<pair<Vertex<TV,TE>*, TE>,vector<pair<Vertex<TV,TE>*,TE>>, cmp<TV,TE>> openSet;
            std::unordered_set<string> openSet1;
            std::unordered_set<string> closedSet;
            std::unordered_map<std::string, Vertex<TV, TE>*> vertexes;
            vertexes = graph->getVertexes(graph);
            
        map<string, TE> gscore;
        gscore[start_id] = 0;
        map<string, TE> fscore;
        fscore[start_id] = heuristic[start_id];

        openSet.push(make_pair(vertexes[start_id], fscore[start_id]));
        while (openSet.empty() == false){
            Vertex<TV,TE>* current = openSet.top().first;
            openSet.pop();
            if(current->id == end_id){
                create_graph(current->id,graph,start_id);
                return;
            }
            closedSet.insert(current->id);
            for(auto i = current->edges.begin(); i != current->edges.end(); i++){
                Vertex<TV,TE>* neighbor = (*i)->vertexes[1];
                if(closedSet.find(neighbor->id) != closedSet.end()){
                    continue;
                }
                TE tentative_gscore = gscore[current->id] + (*i)->weight;
                if(openSet1.find(neighbor->id) == openSet1.end()){
                    openSet1.insert(neighbor->id);
                    openSet.push(make_pair(neighbor,tentative_gscore + heuristic[neighbor->id]));
                    parents[neighbor->id] = current->id;
                }
                else if(tentative_gscore >= gscore[neighbor->id]){
                    continue;
                }
                gscore[neighbor->id] = tentative_gscore;
                fscore[neighbor->id] = gscore[neighbor->id] + heuristic[neighbor->id];
            }
        }
    }
    void create_graph(string current, Graph<TV,TE>* graph, const string& start_id){
        path.push_back(current);
        Fgraph = new UnDirectedGraph<TV,TE>;
        while (parents.find(current) != parents.end() && current!=start_id){

            Vertex<TV,TE>* n1 = graph->getVertexes(graph)[current];

            Fgraph->insertVertex(n1->id,n1->data);

            current = parents[current];

            Vertex<TV,TE>* n2 = graph->getVertexes(graph)[current];
            Fgraph->insertVertex(n2->id,n2->data);
            TE Weight=0;
            for(auto i = n1->edges.begin(); i!=n1->edges.end();i++){
                if(current == (*i)->vertexes[1]->id){
                    Weight = (*i)->weight;
                }
            }
            Fgraph->createEdge(n1->id,n2->id,Weight);
            path.push_front(current);
        }
    }

    void display_path(){
        cout<<endl;
        for(auto & i : path){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    UnDirectedGraph<TV,TE>* apply(){
        return Fgraph;
    }

};





#endif