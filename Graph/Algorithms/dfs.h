#ifndef DFS_H
#define DFS_H

#include "../graph.h"
#include <stack>
template<typename TV, typename TE> class DFS{
    public:
    Graph<TV, TE> *graph;
    string start_id;
    std::unordered_map<std::string, Vertex<TV, TE>*> vertexes;
    DFS(Graph<TV, TE> *graph, string start_id){
        vertexes = graph->getVertexes(graph);
        this->graph = graph;
        this->start_id = start_id;
    };
    
    vector<Vertex<TV,TE>*> apply_dfs(){
        //DFS implementation
        vector<Vertex<TV,TE>*> result;
        unordered_map<Vertex<TV,TE>*,bool> visited;

        auto it = this->vertexes.begin();

        for(it; it != this->vertexes.end();it++){
            visited[it->second] =false;
        } 
        std::stack<Vertex<TV,TE>*> stack;

        stack.push(this->vertexes[this->start_id]);

        while(!stack.empty()){
            Vertex<TV, TE> *s = stack.top();
            stack.pop();

            if(!visited[s]){
                result.push_back(s);
                visited[s] = true;
            }

            for(auto it2 = s->edges.begin(); it2 !=s->edges.end(); it2++){

                if(!visited[(*it2)->vertexes[1]])
                    stack.push((*it2)->vertexes[1]);

                if(!visited[(*it2)->vertexes[0]])
                    stack.push((*it2)->vertexes[0]);
            }
        }
        return result;
    };
    
};

        #endif