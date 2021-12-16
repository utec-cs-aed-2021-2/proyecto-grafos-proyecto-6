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
bool insertVertex(string id, V data); // Crea un nuevo vertice en el grafo con data y un ID

bool createEdge(string start, string end, E data); // Crea un nuevo arista en el grafo

bool deleteVertex(string id); // Elimina el vertice identificado por id

bool deleteEdge(string start, string end); // Elimina una arista del grafo

E &operator()(string start, string end); // Obtiene el valor de la arista  de id start y end

float density() const; // Calcula la densidad del grafo

bool isDense(float threshold = 0.5) const; // Determina si el grafo es denso, dependiendo del threshold de entrada

bool isConnected(); // Detecta si el grafo es conexo

bool isStronglyConnected() throw(); // Detecta si el grafo es fuertemente conexo (solo para grafos directos)

bool empty(); // Si el grafo esta vacío

void clear(); // Limpia el grafo
```

### Algorithms:
```cpp
//Dado el grafo
UndirectedGraph<char, int> graph;

//1- Genera un grafo con un  arbol de expansion minima(MST)  usando el algoritmo Kruskal (solo para grafos no dirigidos)
Kruskal<char, int> kruskal(&graph);
UndirectedGraph<char, int> result = kruskal.apply();//retorna el MST como grafo

//2- Genera un grafo con un  arbol de expansion minima(MST)  usando el algoritmo Prim (solo para grafos no dirigidos)
Prim<char, int> prim(&graph, "A");
UndirectedGraph<char, int> result = prim.apply();//retorna el MST como grafo

//Dado el grafo
UnDirectedGraph<char, int> *graph = new UnDirectedGraph<char, int>;

//3- Genera el camino más corto entre dos vertices usando el algoritmo A*
unordered_map<string, double> heuristic;
Astar<string, double>* AStar = new Astar<string, double>(graph,"A","Z", heuristic);
UndirectedGraph<char, int> result = AStar->apply();

//Dado el grafo
Graph<char, int> *graph = new DirectedGraph<char, int>;

//4- Genera un Vector con los elementos recorridos de un grafo segun el algoritmo de busqueda BFS
BFS<char, int> bfs(graph, "A");
vector<Vertex<TV, TE> *> result = bfs.apply_bfs();

//5- Genera un Vector con los elementos recorridos de un grafo segun el algoritmo de busqueda DFS
DFS<char, int> dfs(graph, "A");
vector<Vertex<TV,TE>*> result = dfs.apply_dfs();

//6- Genera un hash donde el key es el id de cada vertice y cada key apunta a una lista ordenada con el camino minimo desde un start_id hasta el vertice key siguiendo el algoritmo  Bellman Ford.
Bellman_Ford<char, int>* bellF = new Bellman_Ford<char, int>(graph, "A");
unordered_map<std::string, list<string>> result = bellF->apply();
bellF->display();

//Given the graph
DirectedGraph<char, int> *graph = new DirectedGraph<char, int>; 

//7- Genera una matriz de distancias minimas para cada destino posible utilizando el algortimo Floyd Warshall.
floyd_warshall<char, int>* floyd = new floyd_warshall<char, int>(graph);
floyd->display();


```


## JSON file parser
* Construye un grafo a partir de una archivo JSON de aereopuertos del mundo. 


### Methods:
```cpp
void clear(); // Limpia los atributos del parser

void readJSON(string pathFile); // lee un archivo json y lo almacena en la clase

void uGraphMake(UndirectedGraph<string, double> &tempGraph); // Convierte el json interpretado a un grafo no dirigido

void dGraphMake(DirectedGraph<string, double> &tempGraph); // Convierte el json interpretado a un grafo dirigido

unordered_map<string, double> getHeuristic(string id_target) // Retorna un hash con las distancias euclideanadas de cada vertice hacia el vertice objetivo
```

