[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=6129269&assignment_repo_type=AssignmentRepo)

----
# Proyecto del curso Algoritmos y Estructura de Datos

## Integrantes
- Noe Salvatierra
- Jorge Flores
- Fabio Torres

----
## Descripción del Proyecto
El proyecto del curso consiste en implementar una estructura de datos de grafo y un json file parser. La estructura debe contener los métodos y algoritmos descritos en la sección **_Graph data structure_**. Las estructuras de grafos deben estar basados en lista de adayacencia.

## Objetivos

- Implementar las estructuras, métodos y algortimos que se piden.
- Implementar un JSON parser.
- Implementar una interfase de usuario.

## Desarrollo del proyecto

El desarrollo del proyecto se dividió en dos etapas. Las estructura y algoritmos que se implementaron en la primera etapa se mencionan a continuación:

- Estructuras
    - Grafos dirigidos
    - Grafos no dirigidos
- Algoritmos
    - MST Prim
    - MST Kruskal
    - Breadth-first Search
    - Depth-first Search

En la segunda etapa del proyecto se implementó las funcionalidades que se mencionan a continuación:

- Algoritmos
    - Dijkstra
    - Best First Search
    - A*
    - Floyd-Warshall
    - Bellman-Ford
- Funcionalidad
    - JSON parser
    - Carga de grafos desde un archivo JSON

## Logros

- Se implementó las estructuras, métodos y algortimos pedidos para grafos dirigidos y no dirigidos por lista de adyacencia. Los métodos _display()_ para los algoritmos muestra en consola la secuencia de nodos o la lista de adyacencia del grago, según sea el caso.
- Se implementó un JSON parser. Además, se genera un grafo empleando como entrada la información que se obtiene del JSON parser.
- Se implementó una interfase de usuario en consolada. Esta interface consiste en un menú donde se puede elegir el tipo de grado (dirigido o no dirigido), desde donde crear el grafo (archivo JSON o valores precargados) y el algoritmo que se desee aplicar sobre el grafo creado.


********
# Graph data structure

* El grafo es dinámico por lista de adyacencia
* Se Implemento dos tipos de grafos: dirigidos y no-dirigidos.
* No considera loops ni multi-arista. 


## Métodos:
```cpp
// Crea un nuevo vertice en el grafo con data y un ID 
bool insertVertex(string id, V data); 

// Crea un nuevo arista en el grafo
bool createEdge(string start, string end, E data); 

// Elimina el vertice identificado por id
bool deleteVertex(string id); 

// Elimina una arista del grafo
bool deleteEdge(string start, string end); 

// Obtiene el valor de la arista  de id start y end
E &operator()(string start, string end); /

// Calcula la densidad del grafo
float density() const; 

// Determina si el grafo es denso, dependiendo del threshold de entrada
bool isDense(float threshold = 0.5) const; 

// Detecta si el grafo es conexo
bool isConnected(); 

// Detecta si el grafo es fuertemente conexo (solo para grafos directos)
bool isStronglyConnected() throw(); 

// Verifica si el grafo esta vacío
bool empty(); 

// Limpia el grafo
void clear(); 
```

## Algoritmos:
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

//Dado el grafo
DirectedGraph<char, int> *graph = new DirectedGraph<char, int>; 

//7- Genera una matriz de distancias minimas para cada destino posible utilizando el algortimo Floyd Warshall.
floyd_warshall<char, int>* floyd = new floyd_warshall<char, int>(graph);
floyd->display();

//8- Genera un hash donde el key es el id de cada vertice y cada key apunta al costo que toma llegar desde vertice start_id hasta cada uno de los vertices del grafo siguiendo el algoritmo  Dijkstra.
Dijkstra<char,int>* dijkstra = new Dijkstra<char, int>(dgraph,"A");
dijkstra->apply();
dijkstra->display();

//9- Genera un Vector con los elementos recorridos de un grafo desde start_id hacia end_id segun el algoritmo de busqueda Best First Search
BestFirstSearch<char,int>* best= new BestFirstSearch<char, int>(dgraph,"A","B");
best->apply();
best->display();
```


****
# JSON file parser
Construye un grafo a partir de una archivo JSON de aereopuertos del mundo. Este archivo se encuentra dentro del directorio °Parser/Data/°.

## Instalación de la librería jsoncpp

A continuación se muestra cómo se puede instalar la librería **jsoncpp** según el sistema operativo.

### Ubuntu Linux OS
```
$ sudo apt-get install libjsoncpp-dev
```

### Mac OS
```
$ ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)" < /dev/null 2> /dev/null
$ brew install jsoncpp
```

### Wndows 10
Antes de instalar el paquete, se debe tene [vcpkg](https://github.com/Microsoft/vcpkg/)
```
$ git clone https://github.com/Microsoft/vcpkg.git
$ cd vcpkg
$ ./bootstrap-vcpkg.sh
$ ./vcpkg integrate install
$ ./vcpkg install jsoncpp
```


## Métodos:
```cpp
void clear(); // Limpia los atributos del parser

void readJSON(string pathFile); // lee un archivo json y lo almacena en la clase

void uGraphMake(UndirectedGraph<string, double> &tempGraph); // Convierte el json interpretado a un grafo no dirigido

void dGraphMake(DirectedGraph<string, double> &tempGraph); // Convierte el json interpretado a un grafo dirigido

unordered_map<string, double> getHeuristic(string id_target) // Retorna un hash con las distancias euclideanadas de cada vertice hacia el vertice objetivo
```

****
# Modo de uso

Teniendo la librería jsoncpp instalada se puede proceder a compilar el programa **main.cpp** y ejecutarlo.

```bash
# Para compilar
$ g++ -o <output_name_file> main.cpp -ljsoncpp

# Para ejecutar el programa
$ ./<output_name_file>

# Donde:
#   output_name_file : nombre del archivo con el que se generará el ejecutable
```