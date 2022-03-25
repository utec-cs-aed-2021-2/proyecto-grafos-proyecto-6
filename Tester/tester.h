#ifndef TESTER
#define TESTER

#include "../Graph/DirectedGraph.h"
#include "../Graph/UndirectedGraph.h"
#include "../Graph/Algorithms/bfs.h"
#include "../Graph/Algorithms/dfs.h"
#include "../Graph/Algorithms/kruskal.h"
#include "../Graph/Algorithms/prim.h"
#include "../Graph/Algorithms/astar.h"
#include "../Graph/Algorithms/bell.h"
#include "../Graph/Algorithms/floyd.h"
#include "../Graph/Algorithms/best.h"
#include "../Graph/Algorithms/dijkstra.h"
#include "../Parser/parser.h"

using namespace std;

namespace Tester{

void MenuParser(){

int opcion;
    cout<< "Se tienen 2 grafos de ejemplo" <<endl;
    cout<< "Escoja que grafo desea probar" <<endl;
    cout<< "1. Grafo Aereopuertos PERU" <<endl;
    cout<< "2. Grafo Aereopuertos INTERNACIONALES" <<endl;
    cout<< "3. Salir" <<endl;
    cin>>opcion;

    switch(opcion){
        case 1: {
            Parser newParser = Parser();
            DirectedGraph<string, double>* airportGraph = new DirectedGraph<string, double>();
            newParser.readJSON("./Parser/Data/pe.json");
            newParser.dGraphMake(airportGraph);
            int opcion;
            do{
                cout <<"\n-------------------------"<<endl;
                cout << "Seleccione una opción" <<endl;
                cout << "1. Display del Grafo" <<endl;
                cout << "2. Mostrar Densidad" <<endl;
                cout << "3. Mostrar si es Conexo" <<endl;
                cout << "4. Mostrar si es Fuertemente conexo" <<endl;
                cout << "Algoritmos: " <<endl;
                cout << "--------------" <<endl;
                cout << "5. BFS" <<endl;
                cout << "6. DFS" <<endl;
                cout << "7. Kruskal" <<endl;
                cout << "8. Prim" <<endl;
                cout << "9. A*" <<endl;
                cout << "10. Bellman" <<endl;
                cout << "11. Floyd" <<endl;
                cout << "12. Best BFS" <<endl;
                cout << "13. Dijkstra" <<endl;
                cout << "14. Salir" <<endl;
                cin >> opcion;

                switch(opcion){
                    case 1: {
                        cout << "Grafo G1" <<endl;
                        cout << "--------" <<endl;
                        airportGraph->display();
                        break;
                    }
                    case 2: {
                        cout << "Densidad del Grafo G1" <<endl;
                        cout << "------------------------" <<endl;
                        cout << airportGraph->density() <<endl;
                        break;
                    }
                    case 3: {
                        cout << "¿Es el grafo conexo?" <<endl;
                        cout << "----------------------" <<endl;
                        if(airportGraph->isConnected()){
                            cout << "Verdadero" << endl;
                        } else {
                            cout << "Falso" << endl;
                        }
                        break;
                    }
                    case 4: {
                        cout << "¿Es el grafo fuertemente conexo?" <<endl;
                        cout << "---------------------------------" <<endl;
                        if(airportGraph->isConnected()){
                            cout << "Verdadero" << endl;
                        } else {
                            cout << "Falso" << endl;
                        }
                        break;
                    }
                    case 5: {
                        cout << "BFS" <<endl;
                        cout << "----" <<endl;
                        BFS<string,double> bfs(airportGraph,"2789");
                        auto resultBFS = bfs.apply_bfs();
                        for(auto it : resultBFS){
                            cout << it->id << " ";
                        }
                        break;
                    }
                    case 6: {
                        cout << "DFS" <<endl;
                        cout << "----" <<endl;
                        DFS<string,double> dfs(airportGraph,"2789");
                        auto resultDFS = dfs.apply_dfs();
                        for(auto it : resultDFS){
                            cout << it->id << " ";
                        }
                        break;
                    }
                    case 7: {
                        cout << "Kruskal" <<endl;
                        cout << "--------" <<endl;
                        cout<<"NO APLICA PARA GRAFOS DIRIGIDOS"<<endl;
                        break;
                    }
                    case 8: {
                        cout << "Prim" <<endl;
                        cout << "-----" <<endl;
                        cout<<"NO APLICA PARA GRAFOS DIRIGIDOS"<<endl;
                    }
                    case 9: {
                        cout << "A*" <<endl;
                        cout << "---" <<endl;
                        Astar<string,double>* astar = new Astar<string,double>(airportGraph, "2789", "2812", newParser.getHeuristic("2812"));
                        astar->display_path();
                        break;
                    }
                    case 10: {
                        cout << "Bellman" <<endl;
                        cout << "--------" <<endl;
                        
                        Bellman_Ford<string,double>* bell_ford = new Bellman_Ford<string, double>(airportGraph,"2789");
                        bell_ford->apply();
                        bell_ford->display();
                        break;
                    }
                    case 11: {
                        cout << "Floyd" <<endl;
                        cout << "-------" <<endl;
                        floyd_warshall<string,double>* floyd = new floyd_warshall<string,double>(airportGraph);
                        floyd->display();
                        break;
                    }
                    case 12: {
                        cout << "Best BFS" <<endl;
                        cout << "----------" <<endl;
                        BestFirstSearch<string,double>* best= new BestFirstSearch<string, double>(airportGraph,"2789","2812");
                        best->apply();
                        best->display();
                        break;
                    }
                    case 13: {
                        cout << "Dijkstra" <<endl;
                        cout << "----------" <<endl;
                        Dijkstra<string,double>* dijkstra = new Dijkstra<string, double>(airportGraph,"2789");
                        dijkstra->apply();
                        dijkstra->display();
                        break;
                    }
                    case 14: {
                        cout << "Salir" <<endl;
                        break;
                    }
                    default: {
                        cout << "Opcion no valida" <<endl;
                        break;
                    }
                }

            } while(opcion != 14);
            break;
        }
        case 2: {
            Parser newParser1 = Parser();
            DirectedGraph<string, double>* airportGraph1 = new DirectedGraph<string, double>();
            newParser1.readJSON("./Parser/Data/airports.json");
            newParser1.dGraphMake(airportGraph1);
            int opcion;
            do{
                cout <<"\n-------------------------"<<endl;
                cout << "Seleccione una opción" <<endl;
                cout << "1. Display del Grafo" <<endl;
                cout << "2. Mostrar Densidad" <<endl;
                cout << "3. Mostrar si es Conexo" <<endl;
                cout << "4. Mostrar si es Fuertemente conexo" <<endl;
                cout << "Algoritmos: " <<endl;
                cout << "--------------" <<endl;
                cout << "5. BFS" <<endl;
                cout << "6. DFS" <<endl;
                cout << "7. Kruskal" <<endl;
                cout << "8. Prim" <<endl;
                cout << "9. A*" <<endl;
                cout << "10. Bellman" <<endl;
                cout << "11. Floyd" <<endl;
                cout << "12. Best BFS" <<endl;
                cout << "13. Dijkstra" <<endl;
                cout << "14. Salir" <<endl;
                cin >> opcion;

                switch(opcion){
                    case 1: {
                        cout << "Grafo G1" <<endl;
                        cout << "--------" <<endl;
                        airportGraph1->display();
                        break;
                    }
                    case 2: {
                        cout << "Densidad del Grafo G1" <<endl;
                        cout << "------------------------" <<endl;
                        cout << airportGraph1->density() <<endl;
                        break;
                    }
                    case 3: {
                        cout << "¿Es el grafo conexo?" <<endl;
                        cout << "----------------------" <<endl;
                        if(airportGraph1->isConnected()){
                            cout << "Verdadero" << endl;
                        } else {
                            cout << "Falso" << endl;
                        }
                        break;
                    }
                    case 4: {
                        cout << "¿Es el grafo fuertemente conexo?" <<endl;
                        cout << "---------------------------------" <<endl;
                        if(airportGraph1->isConnected()){
                            cout << "Verdadero" << endl;
                        } else {
                            cout << "Falso" << endl;
                        }
                        break;
                    }
                    case 5: {
                        cout << "BFS" <<endl;
                        cout << "----" <<endl;
                        BFS<string,double> bfs(airportGraph1,"2789");
                        auto resultBFS = bfs.apply_bfs();
                        for(auto it : resultBFS){
                            cout << it->id << " ";
                        }
                        break;
                    }
                    case 6: {
                        cout << "DFS" <<endl;
                        cout << "----" <<endl;
                        DFS<string,double> dfs(airportGraph1,"2789");
                        auto resultDFS = dfs.apply_dfs();
                        for(auto it : resultDFS){
                            cout << it->id << " ";
                        }
                        break;
                    }
                    case 7: {
                        cout << "Kruskal" <<endl;
                        cout << "--------" <<endl;
                        cout<<"NO APLICA PARA GRAFOS DIRIGIDOS"<<endl;
                        break;
                    }
                    case 8: {
                        cout << "Prim" <<endl;
                        cout << "-----" <<endl;
                        cout<<"NO APLICA PARA GRAFOS DIRIGIDOS"<<endl;
                        break;
                    }
                    case 9: {
                        cout << "A*" <<endl;
                        cout << "---" <<endl;
                        Astar<string,double>* astar = new Astar<string,double>(airportGraph1, "2789", "5422", newParser1.getHeuristic("5422"));
                        astar->display_path();
                        break;
                    }
                    case 10: {
                        cout << "Bellman" <<endl;
                        cout << "--------" <<endl;
                        
                        Bellman_Ford<string,double>* bell_ford = new Bellman_Ford<string, double>(airportGraph1,"2789");
                        bell_ford->apply();
                        bell_ford->display();
                        break;
                    }
                    case 11: {
                        cout << "Floyd" <<endl;
                        cout << "-------" <<endl;
                        floyd_warshall<string,double>* floyd = new floyd_warshall<string,double>(airportGraph1);
                        floyd->display();
                        break;
                    }
                    case 12: {
                        cout << "Best BFS" <<endl;
                        cout << "----------" <<endl;
                        BestFirstSearch<string,double>* best= new BestFirstSearch<string, double>(airportGraph1,"2789","5422");
                        best->apply();
                        best->display();
                        break;
                    }
                    case 13: {
                        cout << "Dijkstra" <<endl;
                        cout << "----------" <<endl;
                        Dijkstra<string,double>* dijkstra = new Dijkstra<string, double>(airportGraph1,"2789");
                        dijkstra->apply();
                        dijkstra->display();
                    }
                    case 14: {
                        cout << "Salir" <<endl;
                        break;
                    }
                    default: {
                        cout << "Opcion no valida" <<endl;
                        break;
                    }
                }

            } while(opcion != 14);
            break;
        }
    
}




















}

void EjemploNoDirigido(){
    int opcion;
    cout<< "Se tienen 2 grafos de ejemplo" <<endl;
    cout<< "Escoja que grafo desea probar" <<endl;
    cout<< "1. Grafo G1" <<endl;
    cout<< "2. Grafo G2" <<endl;
    cout<< "3. Salir" <<endl;
    cin>>opcion;

    switch(opcion){
        case 1: {
            UnDirectedGraph<char,int>* udgraph1 = new UnDirectedGraph<char,int>();

            udgraph1->insertVertex("A", 0);
            udgraph1->insertVertex("B", 1);
            udgraph1->insertVertex("C", 2);
            udgraph1->insertVertex("D", 3);
            udgraph1->insertVertex("E", 4);
            udgraph1->insertVertex("F", 5);
            udgraph1->insertVertex("G", 6);
            udgraph1->insertVertex("H", 7);

            udgraph1->createEdge("A", "B", 2);
            udgraph1->createEdge("A", "F", 1);
            udgraph1->createEdge("B", "C", 2);
            udgraph1->createEdge("B", "D", 2);
            udgraph1->createEdge("D", "F", 3);
            udgraph1->createEdge("D", "E", 4);
            udgraph1->createEdge("B", "E", 4);
            udgraph1->createEdge("F", "G", 5);
            udgraph1->createEdge("C", "E", 3);
            udgraph1->createEdge("E", "G", 7);
            udgraph1->createEdge("C", "H", 1);
            udgraph1->createEdge("H", "G", 3);

            int opcion;
            do{
                cout <<"\n-------------------------"<<endl;
                cout << "Seleccione una opción" <<endl;
                cout << "1. Display del Grafo" <<endl;
                cout << "2. Mostrar Densidad" <<endl;
                cout << "3. Mostrar si es Conexo" <<endl;
                cout << "4. Mostrar si es Fuertemente conexo" <<endl;
                cout << "Algoritmos: " <<endl;
                cout << "--------------" <<endl;
                cout << "5. BFS" <<endl;
                cout << "6. DFS" <<endl;
                cout << "7. Kruskal" <<endl;
                cout << "8. Prim" <<endl;
                cout << "9. A*" <<endl;
                cout << "10. Bellman" <<endl;
                cout << "11. Floyd" <<endl;
                cout << "12. Best BFS" <<endl;
                cout << "13. Dijkstra" <<endl;
                cout << "14. Salir" <<endl;
                cin >> opcion;

                switch(opcion){
                    case 1: {
                        cout << "Grafo G1" <<endl;
                        cout << "--------" <<endl;
                        udgraph1->display();
                        break;
                    }
                    case 2: {
                        cout << "Densidad del Grafo G1" <<endl;
                        cout << "------------------------" <<endl;
                        cout << udgraph1->density() <<endl;
                        break;
                    }
                    case 3: {
                        cout << "¿Es el grafo conexo?" <<endl;
                        cout << "----------------------" <<endl;
                        if(udgraph1->isConnected()){
                            cout << "Verdadero" << endl;
                        } else {
                            cout << "Falso" << endl;
                        }
                        break;
                        break;
                    }
                    case 4: {
                        cout << "¿Es el grafo fuertemente conexo?" <<endl;
                        cout << "---------------------------------" <<endl;
                        if(udgraph1->isConnected()){
                            cout << "Verdadero" << endl;
                        } else {
                            cout << "Falso" << endl;
                        }
                        break;
                    }
                    case 5: {
                        cout << "BFS" <<endl;
                        cout << "----" <<endl;
                        BFS<char,int> bfs(udgraph1,"A");
                        auto resultBFS = bfs.apply_bfs();
                        for(auto it : resultBFS){
                            cout << it->id << " ";
                        }
                        break;
                    }
                    case 6: {
                        cout << "DFS" <<endl;
                        cout << "----" <<endl;
                        DFS<char,int> dfs(udgraph1,"A");
                        auto resultDFS = dfs.apply_dfs();
                        for(auto it : resultDFS){
                            cout << it->id << " ";
                        }
                        break;
                    }
                    case 7: {
                        cout << "Kruskal" <<endl;
                        cout << "--------" <<endl;
                        Kruskal<char,int> kruskal(udgraph1);
                        UnDirectedGraph<char,int> resultKruskal = kruskal.apply();
                        resultKruskal.display();
                        break;
                    }
                    case 8: {
                        cout << "Prim" <<endl;
                        cout << "-----" <<endl;
                        Prim<char,int> prim(udgraph1, "A");
                        UnDirectedGraph<char,int> resultPrim = prim.apply();
                        resultPrim.display();
                        break;
                    }
                    case 9: {
                        cout << "A*" <<endl;
                        cout << "---" <<endl;
                        unordered_map<string, int> heuristic;
                            heuristic["A"] = 20;
                            heuristic["B"] = 8;
                            heuristic["C"] = 5;
                            heuristic["D"] = 7;
                            heuristic["E"] = 3;
                            heuristic["F"] = 6;
                            heuristic["G"] = 5;
                            heuristic["H"] = 10;
                        Astar<char,int>* astar = new Astar<char,int>(udgraph1, "A", "H", heuristic);
                        astar->display_path();
                        break;
                    }
                    case 10: {
                        cout << "Bellman" <<endl;
                        cout << "--------" <<endl;
                        cout << "NO APLICA ESTE ALGORITMO"<<endl;
                        break;
                    }
                    case 11: {
                        cout << "Floyd" <<endl;
                        cout << "-------" <<endl;
                        floyd_warshall<char,int>* floyd = new floyd_warshall<char,int>(udgraph1);
                        floyd->display();
                        break;
                    }
                    case 12: {
                        cout << "Best BFS" <<endl;
                        cout << "----------" <<endl;
                        BestFirstSearch<char,int>* best= new BestFirstSearch<char, int>(udgraph1,"A","H");
                        best->apply();
                        best->display();
                        break;
                    }
                    case 13: {
                        cout << "Dijkstra" <<endl;
                        cout << "----------" <<endl;
                        cout << "NO APLICA ESTE ALGORITMO"<<endl;
                        break;
                    }
                    case 14: {
                        cout << "Salir" <<endl;
                        break;
                    }
                    default: {
                        cout << "Opcion no valida" <<endl;
                        break;
                    }
                }

            } while(opcion != 14);
            break;
        }
        case 2: {
            cout << "Grafo G2" <<endl;
            cout << "--------" <<endl;
            UnDirectedGraph<char,int>* udgraph2 = new UnDirectedGraph<char,int>();
            udgraph2->insertVertex("A", 0);
            udgraph2->insertVertex("B", 1);
            udgraph2->insertVertex("C", 2);
            udgraph2->insertVertex("D", 3);
            udgraph2->insertVertex("E", 4);
            udgraph2->insertVertex("F", 5);

            udgraph2->createEdge("A", "B", 2);
            udgraph2->createEdge("A", "C", 4);
            udgraph2->createEdge("B", "C", 6);
            udgraph2->createEdge("B", "E", 8);
            udgraph2->createEdge("B", "D", 12);
            udgraph2->createEdge("C", "D", 9);
            udgraph2->createEdge("E", "D", 18);
            udgraph2->createEdge("C", "E", 14);
            int opcion;
            do{
                cout <<"\n-------------------------"<<endl;
                cout << "Seleccione una opción" <<endl;
                cout << "1. Display del Grafo" <<endl;
                cout << "2. Mostrar Densidad" <<endl;
                cout << "3. Mostrar si es Conexo" <<endl;
                cout << "4. Mostrar si es Fuertemente conexo" <<endl;
                cout << "Algoritmos: " <<endl;
                cout << "--------------" <<endl;
                cout << "5. BFS" <<endl;
                cout << "6. DFS" <<endl;
                cout << "7. Kruskal" <<endl;
                cout << "8. Prim" <<endl;
                cout << "9. A*" <<endl;
                cout << "10. Bellman" <<endl;
                cout << "11. Floyd" <<endl;
                cout << "12. Best BFS" <<endl;
                cout << "13. Dijkstra" <<endl;
                cout << "14. Salir" <<endl;
                cout << "-------------------------"<<endl;
                cin >> opcion;
                switch(opcion){
                    case 1: {
                        cout << "Display del Grafo" <<endl;
                        cout << "-------------------" <<endl;
                        udgraph2->display();
                        break;
                    }
                    case 2: {
                        cout << "Densidad del Grafo G2" <<endl;
                        cout << "------------------------" <<endl;
                        cout << udgraph2->density() <<endl;
                        break;
                    }
                    case 3: {
                        cout << "¿Es el grafo conexo?" <<endl;
                        cout << "----------------------" <<endl;
                        if(udgraph2->isConnected()){
                            cout << "Verdadero" << endl;
                        } else {
                            cout << "Falso" << endl;
                        }
                        break;
                    }
                    case 4: {
                        cout << "¿Es el grafo fuertemente conexo?" <<endl;
                        cout << "---------------------------------" <<endl;
                        if(udgraph2->isConnected()){
                            cout << "Verdadero" << endl;
                        } else {
                            cout << "Falso" << endl;
                        }
                        break;
                    }
                    case 5: {
                        cout << "BFS" <<endl;
                        cout << "----" <<endl;
                        BFS<char,int> bfs(udgraph2,"A");
                        auto resultBFS = bfs.apply_bfs();
                        for(auto it : resultBFS){
                            cout << it->id << " ";
                        }
                        break;
                    }
                    case 6: {
                        cout << "DFS" <<endl;
                        cout << "----" <<endl;
                        DFS<char,int> dfs(udgraph2,"A");
                        auto resultDFS = dfs.apply_dfs();
                        for(auto it : resultDFS){
                            cout << it->id << " ";
                        }
                        break;
                    }
                    case 7: {
                        cout << "Kruskal" <<endl;
                        cout << "--------" <<endl;
                        Kruskal<char,int> kruskal(udgraph2);
                        UnDirectedGraph<char,int> resultKruskal = kruskal.apply();
                        resultKruskal.display();
                        break;
                    }
                    case 8: {
                        cout << "Prim" <<endl;
                        cout << "-----" <<endl;
                        cout<< "NO APLICA"<<endl;
                        break;
                    }
                    case 9: {
                        unordered_map<string,int> heuristic;
                            heuristic["A"] = 10;
                            heuristic["B"] = 14;
                            heuristic["C"] = 16;
                            heuristic["D"] = 18;
                            heuristic["E"] = 8;
                            heuristic["F"] = 11;
                        Astar<char,int>* astar = new Astar<char,int>(udgraph2, "A", "D", heuristic);
                        astar->display_path();
                        break;
                    }
                    case 10: {
                        cout << "Bellman" <<endl;
                        cout << "--------" <<endl;  
                        cout<< "NO APLICA ESTE ALGORITMO" <<endl;
                        break;
                    }
                    case 11: {
                        cout << "Floyd" <<endl;
                        cout << "------" <<endl;
                        floyd_warshall<char,int> floyd(udgraph2);
                        floyd.display();
                        break;
                    }
                    case 12: {
                        cout << "Best BFS" <<endl;
                        cout << "----------" <<endl;
                        BestFirstSearch<char,int>* best= new BestFirstSearch<char, int>(udgraph2,"A","D");
                        best->apply();
                        best->display();
                        break;
                    }
                    case 13: {
                        cout << "Dijkstra" <<endl;
                        cout << "----------" <<endl; 
                        cout << "NO APLICA ESTE ALGORITMO"<<endl;
                        break;
                    }
                    case 14: {
                        cout << "Salir" <<endl;
                        break;
                    }
                    default: {
                        cout << "Opcion no valida" <<endl;
                        break;
                    }
                }

            } while(opcion != 14);
            break;
        }
    
}
}


void EjemploDirigido(){
    int opcion;
    cout<< "Se tienen 2 grafos de ejemplo" <<endl;
    cout<< "Escoja que grafo desea probar" <<endl;
    cout<< "1. Grafo G1" <<endl;
    cout<< "2. Grafo G2" <<endl;
    cout<< "3. Salir" <<endl;
    cin>>opcion;

    switch(opcion){
        case 1: {
            DirectedGraph<char,int>* dgraph1 = new DirectedGraph<char,int>();

            dgraph1->insertVertex("A", 0);
            dgraph1->insertVertex("B", 1);
            dgraph1->insertVertex("C", 2);
            dgraph1->insertVertex("D", 3);
            dgraph1->insertVertex("E", 4);

            dgraph1->createEdge("A", "C", 4);
            dgraph1->createEdge("C", "E", 6);
            dgraph1->createEdge("E", "D", 13);
            dgraph1->createEdge("D", "B", 15);
            dgraph1->createEdge("B", "A", 5);
            dgraph1->createEdge("D", "C", 8);
            dgraph1->createEdge("B", "E", 10);
            int opcion;
            do{
                cout <<"\n-------------------------"<<endl;
                cout << "Seleccione una opción" <<endl;
                cout << "1. Display del Grafo" <<endl;
                cout << "2. Mostrar Densidad" <<endl;
                cout << "3. Mostrar si es Conexo" <<endl;
                cout << "4. Mostrar si es Fuertemente conexo" <<endl;
                cout << "Algoritmos: " <<endl;
                cout << "--------------" <<endl;
                cout << "5. BFS" <<endl;
                cout << "6. DFS" <<endl;
                cout << "7. Kruskal" <<endl;
                cout << "8. Prim" <<endl;
                cout << "9. A*" <<endl;
                cout << "10. Bellman" <<endl;
                cout << "11. Floyd" <<endl;
                cout << "12. Best BFS" <<endl;
                cout << "13. Dijkstra" <<endl;
                cout << "14. Salir" <<endl;
                cin >> opcion;

                switch(opcion){
                    case 1: {
                        cout << "Grafo G1" <<endl;
                        cout << "--------" <<endl;
                        dgraph1->display();
                        break;
                    }
                    case 2: {
                        cout << "Densidad del Grafo G1" <<endl;
                        cout << "------------------------" <<endl;
                        cout << dgraph1->density() <<endl;
                        break;
                    }
                    case 3: {
                        cout << "¿Es el grafo conexo?" <<endl;
                        cout << "----------------------" <<endl;
                        cout<< "NO APLICA EN GRAFOS DIRIGIDOS"<<endl;
                        break;
                    }
                    case 4: {
                        cout << "¿Es el grafo fuertemente conexo?" <<endl;
                        cout << "---------------------------------" <<endl;
                        if(dgraph1->isStronglyConnected()){
                            cout << "Verdadero" << endl;
                        } else {
                            cout << "Falso" << endl;
                        }
                        break;
                    }
                    case 5: {
                        cout << "BFS" <<endl;
                        cout << "----" <<endl;
                        BFS<char,int> bfs(dgraph1,"A");
                        auto resultBFS = bfs.apply_bfs();
                        for(auto it : resultBFS){
                            cout << it->id << " ";
                        }
                        break;
                    }
                    case 6: {
                        cout << "DFS" <<endl;
                        cout << "----" <<endl;
                        DFS<char,int> dfs(dgraph1,"A");
                        auto resultDFS = dfs.apply_dfs();
                        for(auto it : resultDFS){
                            cout << it->id << " ";
                        }
                        break;
                    }
                    case 7: {
                        cout << "Kruskal" <<endl;
                        cout << "--------" <<endl;
                        cout<< "NO APLICA EN GRAFOS DIRIGIDOS"<<endl;
                        break;
                    }
                    case 8: {
                        cout << "Prim" <<endl;
                        cout << "-----" <<endl;
                        cout<< "NO APLICA EN GRAFOS DIRIGIDOS"<<endl;
                        break;
                    }
                    case 9: {
                        cout << "A*" <<endl;
                        cout << "---" <<endl;
                        unordered_map<string, int> heuristic;
                            heuristic["A"] = 15;
                            heuristic["B"] = 8;
                            heuristic["C"] = 12;
                            heuristic["D"] = 20;
                            heuristic["E"] = 25;
                        Astar<char,int>* astar = new Astar<char,int>(dgraph1, "A", "D", heuristic);
                        astar->display_path();
                        break;
                    }
                    case 10: {
                        cout << "Bellman" <<endl;
                        cout << "--------" <<endl;
                        Bellman_Ford<char,int>* bell_ford = new Bellman_Ford<char, int>(dgraph1,"A");
                        bell_ford->apply();
                        bell_ford->display();
                        break;
                    }
                    case 11: {
                        cout << "Floyd" <<endl;
                        cout << "-------" <<endl;
                        floyd_warshall<char,int>* floyd = new floyd_warshall<char,int>(dgraph1);
                        floyd->display();
                        break;
                    }
                    case 12: {
                        cout << "Best BFS" <<endl;
                        cout << "----------" <<endl;
                        BestFirstSearch<char,int>* best= new BestFirstSearch<char, int>(dgraph1,"A","B");
                        best->apply();
                        best->display();
                        break;
                    }
                    case 13: {
                        cout << "Dijkstra" <<endl;
                        cout << "----------" <<endl;
                        Dijkstra<char,int>* dijkstra = new Dijkstra<char, int>(dgraph1,"A");
                        dijkstra->apply();
                        dijkstra->display();
                        break;
                    }
                    case 14: {
                        cout << "Salir" <<endl;
                        break;
                    }
                    default: {
                        cout << "Opcion no valida" <<endl;
                        break;
                    }
                }

            } while(opcion != 14);
            break;
        }
        case 2: {
            cout << "Grafo G2" <<endl;
            cout << "--------" <<endl;
            DirectedGraph<char,int>* dgraph2 = new DirectedGraph<char,int>();
            dgraph2->insertVertex("A", 0);
            dgraph2->insertVertex("B", 1);
            dgraph2->insertVertex("C", 2);
            dgraph2->insertVertex("D", 3);
            dgraph2->insertVertex("E", 4);
            dgraph2->insertVertex("F", 5);
            dgraph2->insertVertex("G", 6);
            dgraph2->insertVertex("H", 7);

            dgraph2->createEdge("A", "B", 5);
            dgraph2->createEdge("D", "B", 4);
            dgraph2->createEdge("B", "C", 3);
            dgraph2->createEdge("C", "B", 3);
            dgraph2->createEdge("C", "E", 6);
            dgraph2->createEdge("C", "F", 9);
            dgraph2->createEdge("F", "B", 13);
            dgraph2->createEdge("E", "G", 7);
            dgraph2->createEdge("G", "H", 2);
            dgraph2->createEdge("D", "H", 14);
            dgraph2->createEdge("F", "H", 5);
            dgraph2->createEdge("H", "F", 5);
            int opcion;
            do{
                cout <<"\n-------------------------"<<endl;
                cout << "Seleccione una opción" <<endl;
                cout << "1. Display del Grafo" <<endl;
                cout << "2. Mostrar Densidad" <<endl;
                cout << "3. Mostrar si es Conexo" <<endl;
                cout << "4. Mostrar si es Fuertemente conexo" <<endl;
                cout << "Algoritmos: " <<endl;
                cout << "--------------" <<endl;
                cout << "5. BFS" <<endl;
                cout << "6. DFS" <<endl;
                cout << "7. Kruskal" <<endl;
                cout << "8. Prim" <<endl;
                cout << "9. A*" <<endl;
                cout << "10. Bellman" <<endl;
                cout << "11. Floyd" <<endl;
                cout << "12. Best BFS" <<endl;
                cout << "13. Dijkstra" <<endl;
                cout << "14. Salir" <<endl;
                cout << "-------------------------"<<endl;
                cin >> opcion;
                switch(opcion){
                    case 1: {
                        cout << "Grafo G2" <<endl;
                        cout << "--------" <<endl;
                        dgraph2->display();
                        break;
                    }
                    case 2: {
                        cout << "Densidad del Grafo G2" <<endl;
                        cout << "------------------------" <<endl;
                        cout << dgraph2->density() <<endl;
                        break;
                    }
                    case 3: {
                        cout << "¿Es el grafo conexo?" <<endl;
                        cout << "----------------------" <<endl;
                        cout<< "NO APLICA EN GRAFOS DIRIGIDOS"<<endl;
                        break;
                    }
                    case 4: {
                        cout << "¿Es el grafo fuertemente conexo?" <<endl;
                        cout << "---------------------------------" <<endl;
                        if(dgraph2->isStronglyConnected()){
                            cout << "Verdadero" << endl;
                        } else {
                            cout << "Falso" << endl;
                        }
                        break;
                    }
                    case 5: {
                        cout << "BFS" <<endl;
                        cout << "----" <<endl;
                        BFS<char,int> bfs(dgraph2,"A");
                        auto resultBFS = bfs.apply_bfs();
                        for(auto it : resultBFS){
                            cout << it->id << " ";
                        }
                        break;
                    }
                    case 6: {
                        cout << "DFS" <<endl;
                        cout << "----" <<endl;
                        DFS<char,int> dfs(dgraph2,"A");
                        auto resultDFS = dfs.apply_dfs();
                        for(auto it : resultDFS){
                            cout << it->id << " ";
                        }
                        break;
                    }
                    case 7: {
                        cout << "Kruskal" <<endl;
                        cout << "--------" <<endl;
                        cout<< "NO APLICA EN GRAFOS DIRIGIDOS"<<endl;
                        break;
                    }
                    case 8: {
                        cout << "Prim" <<endl;
                        cout << "-----" <<endl;
                        cout<< "NO APLICA EN GRAFOS DIRIGIDOS"<<endl;
                        break;
                    }
                    case 9: {
                        cout << "A*" <<endl;
                        cout << "---" <<endl;
                        unordered_map<string, int> heuristic;
                            heuristic["A"] = 15;
                            heuristic["B"] = 8;
                            heuristic["C"] = 12;
                            heuristic["D"] = 20;
                            heuristic["E"] = 25;
                            heuristic["F"] = 10;
                            heuristic["G"] = 5;
                            heuristic["H"] = 14;

                        Astar<char,int>* astar = new Astar<char,int>(dgraph2, "A", "D", heuristic);
                        astar->display_path();
                        break;
                    }
                    case 10: {
                        cout << "Bellman" <<endl;
                        cout << "--------" <<endl;
                        Bellman_Ford<char,int>* bell_ford = new Bellman_Ford<char, int>(dgraph2,"A");
                        bell_ford->apply();
                        bell_ford->display();
                        break;
                    }
                    case 11: {
                        cout << "Floyd" <<endl;
                        cout << "-------" <<endl;
                        floyd_warshall<char,int>* floyd = new floyd_warshall<char,int>(dgraph2);
                        floyd->display();
                        break;
                    }
                    case 12: {
                        cout << "Best BFS" <<endl;
                        cout << "----------" <<endl;
                        BestFirstSearch<char,int>* best= new BestFirstSearch<char, int>(dgraph2,"A","B");
                        best->apply();
                        best->display();
                        break;
                    }
                    case 13: {
                        cout << "Dijkstra" <<endl;
                        cout << "----------" <<endl;
                        Dijkstra<char,int>* dijkstra = new Dijkstra<char, int>(dgraph2,"A");
                        dijkstra->apply();
                        dijkstra->display();
                        break;
                    }
                    case 14: {
                        cout << "Salir" <<endl;
                        break;
                    }
                    default: {
                        cout << "Opcion no valida" <<endl;
                        break;
                    }
                }
            } while(opcion != 14);
            break;
        }
    
}

}

void Ejemplos(){
    int opcion;
    do{
        cout<<"================================================"<<endl;
        cout<<"MENU EJEMPLOS"<<endl;
        cout<<"================================================"<<endl;
        cout<<"1. Grafos No Dirigidos"<<endl;
        cout<<"2. Grafos Dirigidos"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"Ingrese una opción: ";
        cin>>opcion;
        switch(opcion){
            case 1:
                EjemploNoDirigido();
                break;
            case 2:
                EjemploDirigido();
                break;
            case 3:
                return;
            default:
                cout<<"Opción inválida"<<endl;
        }

    }while(opcion != 3);
    
}


void Menu(){
int opcion;
do{
    cout << "==========================================================" <<endl;
    cout << "Menu: " << endl;
    cout << "1. Grafos de Ejemplos" << endl;
    cout << "2. Grafos del Parser" << endl;
    cout << "3. Salir" << endl;
    cout << "==========================================================" <<endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    switch(opcion){
        case 1:
            Ejemplos();
            break;
        case 2:
            MenuParser();
            break;
        case 3:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
    }
}while(opcion != 3);

}

} 



#endif