/* Programmer: Abbas Engineer
     Cruz ID : Afengine
     Version : 1.0
  Description: Graph module to find the strongly connected components of a digraph
                Graph.h
  Prof. Tantalo PA5


*/

#ifndef _GRAPH_H_INCLUDE_
#define _GRAPH_H_INCLUDE_
#define UNDEF -1
#define INF -2
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
bool pDNE(Graph G, int u);
//int getDist(Graph G, int u);
//void getPath(List L, Graph G, int u);

int getDiscover(Graph G, int u); /* Pre: 1<=u<=n=getOrder(G) */
int getFinish(Graph G, int u); /* Pre: 1<=u<=n=getOrder(G) */

/*** Manipulation procedures ***/
void unvisitAll(Graph G);
void makeNull(Graph G);
void addEdge(Graph G, int u, int v);
void addArc(Graph G, int u, int v);
void BFS(Graph G, int s);
int getSCC(Graph G);

void DFS(Graph G, List S); /* Pre: length(S)==getOrder(G) */

/* Other Functions */
Graph transpose(Graph G);
Graph copyGraph(Graph G);

void printGraph(FILE* out, Graph G);

#endif
