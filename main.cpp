#include <iostream>
#include "Graph/DirectedGraph.h"
//#include "Graph/UndirectedGraph.h"
//#include "Tester/tester.h"
//#include "Parser/parser.h"

using namespace std;

int main(int argc, char *argv[]) {
    std::cout << "================================================" << std::endl;
    std::cout << "MENU GRAPH TESTER" << std::endl;
    std::cout << "================================================" << std::endl;
    
    Graph<int, int>* dgraph = new DirectedGraph<int, int>;

    dgraph->insertVertex("a", 24);
    dgraph->insertVertex("b", 44);
    dgraph->insertVertex("c", 46);

    dgraph->createEdge("b","a", 2);
    dgraph->createEdge("b","c", 5);
    dgraph->deleteVertex("a");

    dgraph->displayVertex("b");

    //Tester::executeExamples();
    //Tester::executeParser();
    
    return EXIT_SUCCESS;
}