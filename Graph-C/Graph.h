/* Programmer: Abbas Engineer
     Cruz ID : Afengine
     Version : 1.0
  Description: Graph Shortest Path and Distance using BFS
                FindPath.c
  Prof. Tantalo PA4


*/

#ifndef _GRAPH_H_INCLUDE_
#define _GRAPH_H_INCLUDE_
#define INF -1
#define NIL -4
#include"List.h"

typedef struct GraphObj* Graph; // exported type

/*** Constructors-Destructors ***/
Graph newGraph(int n);
void freeGraph(Graph* pG);

/*** Access functions ***/
bool outRangeV(Graph G, int v);
bool outRangeU(Graph G, int u);
bool sExist(Graph G);
int getOrder(Graph G);
int getSize(Graph G);
int getSource(Graph G);
int getParent(Graph G, int u);
int getDist(Graph G, int u);
void getPath(List L, Graph G, int u);
/*** Manipulation procedures ***/
void unvisitAll(Graph G);
void makeNull(Graph G);
void addEdge(Graph G, int u, int v);
void addArc(Graph G, int u, int v);
void BFS(Graph G, int s);
/*** Other operations ***/

void printGraph(FILE* out, Graph G);

#endif
