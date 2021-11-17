#include <iostream>
#include "Graph/DirectedGraph.h"
#include "Graph/UndirectedGraph.h"
#include "Graph/Algorithms/bfs.h"
#include "Graph/Algorithms/dfs.h"
#include "Graph/Algorithms/kruskal.h"
#include "Graph/Algorithms/prim.h"
//#include "Tester/tester.h"
//#include "Parser/parser.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "================================================" <<endl;
    cout << "MENU GRAPH TESTER" << std::endl;
    cout << "================================================" <<endl;
    cout <<"\n\n\n"<<endl;
    cout << "Grafo de entrada: DIRIGIDO" << std::endl;
    cout << "================================================" <<endl;

    Graph<int, int> *dgraph = new DirectedGraph<int, int>;
    dgraph->insertVertex("A", 0);
    dgraph->insertVertex("B", 1);
    dgraph->insertVertex("C", 2);
    dgraph->insertVertex("D", 3);
    dgraph->insertVertex("E", 4);
    dgraph->insertVertex("F", 5);
    dgraph->insertVertex("G", 6);
    dgraph->insertVertex("H", 7);

    dgraph->createEdge("A", "B", 1);
    dgraph->createEdge("A", "D", 1);
    dgraph->createEdge("C", "B", 1);
    dgraph->createEdge("C", "F", 1);
    dgraph->createEdge("D", "F", 1);
    dgraph->createEdge("F", "D", 1);
    dgraph->createEdge("F", "G", 1);
    dgraph->createEdge("E", "G", 1);
    dgraph->createEdge("H", "G", 1);

    cout << endl;
    cout <<"G1: " <<endl;
    cout << endl;
    dgraph->display();
    cout <<"\n\n\n"<<endl;
    cout << "Método BFS para el Grafo G1 "<<endl;
    cout << endl;
    cout << "Resultado: ";
    BFS<int, int> bfs(dgraph, "A");
    auto resultBFS = bfs.apply_bfs();
    for (auto vertex : resultBFS)
    {
        cout << vertex->id << " ";
    }

    cout <<"\n\n\n"<<endl;
    cout << "Método DFS para el Grafo G1 "<<endl;
    cout << endl;
    cout << "Resultado: ";
    DFS<int, int> dfs(dgraph, "A");
    auto resultDFS = dfs.apply_dfs();
    for (auto vertex : resultDFS)
    {
        cout << vertex->id << " ";
    }
    cout <<"\n\n\n"<<endl;

    cout << "Grafo de entrada: NO DIRIGIDO" << std::endl;
    cout << "================================================" <<endl;
    UnDirectedGraph<char, int> udgraph;
    //Creación del Grafo
    udgraph.insertVertex("0", 0);
    udgraph.insertVertex("1", 1);
    udgraph.insertVertex("2", 2);
    udgraph.insertVertex("3", 3);
    udgraph.insertVertex("4", 4);
    udgraph.insertVertex("5", 5);
    udgraph.insertVertex("6", 6);
    udgraph.insertVertex("7", 7);

    udgraph.createEdge("0", "1", 2);
    udgraph.createEdge("1", "3", 1);
    udgraph.createEdge("1", "5", 8);
    udgraph.createEdge("3", "5", 5);
    udgraph.createEdge("5", "7", 9);
    udgraph.createEdge("7", "6", 1);
    udgraph.createEdge("6", "4", 1);
    udgraph.createEdge("4", "2", 6);
    udgraph.createEdge("2", "0", 4);
    cout << endl;
    cout <<"G2: " <<endl;
    cout << endl;
    udgraph.display();
    cout <<"\n\n\n"<<endl;
    cout << "Arbol de Minima expansión: Método Kruskal para el Grafo G2 "<<endl;
    cout <<"\n\n\n"<<endl;

    Kruskal<char, int> kruskal(udgraph);

    UnDirectedGraph<char, int> result = kruskal.apply();

    cout << "Resultado: "<<endl;
    cout << endl;

    result.display();

    cout <<"\n\n\n"<<endl;


    cout << "Densidad: " << result.density() << endl;

    cout << "Es un grafo denso? : ";
    if (result.isDense()) cout<<"Sí";
    else cout<<"No";
    cout << endl;

    cout << "Se verifica que el resultado del Metodo kruskal es un grafo conexo? : ";
    if (result.isConnected()) cout<<"Sí";
    else cout<<"No";
 
    cout <<"\n\n\n"<<endl;
    cout << "================================================" <<endl;
    cout << "Arbol de Minima expansión: Método PRIM para el Grafo G2 "<<endl;
    
    Prim<char, int> prim(udgraph, "0");
    UnDirectedGraph<char, int> resultPRIM = prim.apply();
    cout << "Resultado: "<<endl;
    cout << endl;
    resultPRIM.display();

    cout <<"\n\n\n"<<endl;
    cout << "Densidad: " << resultPRIM.density() << endl;

    cout << "Es un grafo denso? : ";
    if (resultPRIM.isDense()) cout<<"Sí";
    else cout<<"No";
    cout << endl;

    cout << "Se verifica que el resultado del Metodo PRIM es un grafo conexo? : ";
    if (resultPRIM.isConnected()) cout<<"Sí";
    else cout<<"No";
    cout << endl;
    return EXIT_SUCCESS;
}