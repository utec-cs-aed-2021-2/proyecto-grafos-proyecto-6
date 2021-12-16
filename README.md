[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=6129269&assignment_repo_type=AssignmentRepo)
# Algoritmos y Estructura de Datos
## Proyecto sobre Grafos
--------

## Integrantes
- Noe Salvatierra
- Jorge Flores
- Fabio Torres

----
## Alcance entrega Proyecto 1
Se implementaron todas las funciones internas para los grafos dirigos y no dirigidos. Además se implementaron todos los algoritmos pedidos BFS,DFS, PRIM y Kruskal.
La función display por el momento muestra las lista de adyacencia de cada grafo.
* Las pruebas de las funciones y algoritmos se hicieron directamente en el main.


----

El proyecto del curso consiste en implementar una estructura de datos de grafo y un file parser. La estructura debe soportar los métodos y algoritmos descritos a continuacion:  


## Graph data structure

* El grafo debe ser dinámico (inserciones. eliminaciones, búsquedas, ...)
* Se debe implementar los dos tipos de grafos: dirigidos y no-dirigidos.
* No considerar loops ni multi-arista. 


### Methods:
```cpp
bool insertVertex(string id, V data); // Creates a new vertex in the graph with some data and an ID

bool createEdge(string start, string end, E data); // Creates a new edge in the graph with some data

bool deleteVertex(string id); // Deletes a vertex in the graph

bool deleteEdge(string start, string end); // Deletes an edge in the graph, it is not possible to search by the edge value, since it can be repeated

E &operator()(string start, string end); // Gets the value of the edge from the start and end vertexes

float density() const; // Calculates the density of the graph

bool isDense(float threshold = 0.5) const; // Calculates the density of the graph, and determine if it is dense dependening on a threshold value

bool isConnected(); // Detect if the graph is connected

bool isStronglyConnected() throw(); // Detect if the graph is strongly connected (only for directed graphs)

bool empty(); // If the graph is empty

void clear(); // Clears the graph
```

### Algorithms:
```cpp
//Given the graph
UndirectedGraph<char, int> graph;

//1- Generates a MST graph using the Kruskal approach (only for undirected graphs)
Kruskal<char, int> kruskal(&graph);
UndirectedGraph<char, int> result = kruskal.apply();//return a tree

//2- Generates a MST graph using the Prim approach (only for undirected graphs)
Prim<char, int> prim(&graph, "A");
UndirectedGraph<char, int> result = prim.apply();//return a tree

//Given the graph
UnDirectedGraph<char, int> *graph = new UnDirectedGraph<char, int>;

//3- A *
unordered_map<string, double> heuristic;
Astar<string, double>* AStar = new Astar<string, double>(graph,"A","Z", heuristic);
UndirectedGraph<char, int> result = AStar->apply();

//Given the graph
Graph<char, int> *graph = new DirectedGraph<char, int>;

//4- BFS
BFS<char, int> bfs(graph, "A");
vector<Vertex<TV, TE> *> result = bfs.apply_bfs();

//5- DFS
DFS<char, int> dfs(graph, "A");
vector<Vertex<TV,TE>*> result = dfs.apply_dfs();

//6- Bellman Ford
Bellman_Ford<char, int>* bellF = new Bellman_Ford<char, int>(graph, "A");
bellF->apply();
bellF->display();

//Given the graph
DirectedGraph<char, int> *graph = new DirectedGraph<char, int>; 

//7- Floyd Warshall 
floyd_warshall<char, int>* floyd = new floyd_warshall<char, int>(graph);
floyd->display();


```


## JSON file parser
* Construye un grafo a partir de una archivo JSON de aereopuertos del mundo. 


### Methods:
```cpp
void clear(); // Clears parser saved atributes

void readJSON(); // Parses JSON file and saves data into class
// NOTE: each derived class has its own readJSON method

void uGraphMake(UndirectedGraph<string, double> &tempGraph); // Adds the parsed data into the specified undirected graph

void dGraphMake(DirectedGraph<string, double> &tempGraph); // Adds the parsed data into the specified directed graph
```

## [Git Karma Guidelines](http://karma-runner.github.io/5.2/dev/git-commit-msg.html)

```
<type>(<scope>): <subject>

<body>
```

### Allowed ```<type>``` values

* feat (new feature for the user, not a new feature for build script)
* fix (bug fix for the user, not a fix to a build script)
* docs (changes to the documentation)
* style (formatting, missing semi colons, etc)
* refactor (refactoring production code, eg. renaming a variable)
* test (adding missing tests, refactoring tests)
* chore (updating grunt tasks etc)

### Allowed ```<scope>``` values

* graph
* directedGraph
* undirectedGraph
* parser
* main
* tester


> **PD:** Puntos extras sobre Evaluación Continua si se implementa una GUI.
