#include <iostream>
#include "Graph/DirectedGraph.h"
#include "Graph/UndirectedGraph.h"
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
    dgraph->insertVertex("c", 54);
    dgraph->createEdge("a", "b", 1);
    dgraph->createEdge("b", "c", 2);
    dgraph->createEdge("c", "a", 3);

    /*dgraph->insertVertex("c", 46);
    dgraph->insertVertex("d", 45);
    dgraph->insertVertex("e", 4);
    dgraph->insertVertex("f", 8);

    dgraph->createEdge("b","a", 2);
    dgraph->createEdge("b","c", 5);
    //cout<<dgraph->operator()("c", "b")<<endl;///
    dgraph->createEdge("b","d", 8);
    //dgraph->createEdge("e","b", 9);
    dgraph->createEdge("e","f", 10);

    dgraph->deleteVertex("a");
    cout<<"test"<<endl;



    dgraph->deleteEdge("c","b");
    //dgraph->deleteEdge("b","c");
    //dgraph->displayVertex("b");
    
    cout<<dgraph->operator()("b", "d")<<endl;///
    //int temp = dgraph->operator()("b", "d");
    //cout<<dgraph->operator()("b", "d")<<endl;
    
    //dgraph->displayVertex("b");
    
    */
    cout<<"Density: "<<dgraph->density()<<endl;
    //Tester::executeExamples();
    //Tester::executeParser();
    cout<<"is Dense? : "<<dgraph->isDense(0.3)<<endl;
    
    cout<<"is Connected? : "<<dgraph->isStronglyConnected()<<endl;
    cout<<"vacio? : "<<dgraph->empty()<<endl;
    dgraph->clear();
    cout<<"vacio? : "<<dgraph->empty()<<endl;
    dgraph->display();
    return EXIT_SUCCESS;
}