/* Programmer: Abbas Engineer
     Cruz ID : Afengine
     Version : 1.0
  Description: Graph Shortest Path and Distance using BFS
                Graph.c
  Prof. Tantalo PA4


*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "Graph.h"

#define WHITE 00
#define GRAY  01
#define BLACK 10

typedef struct GraphObj{
    List* List;
    int * theMark;  // mark vertices white as unvisited
    int   numV;     // number of vertices
    int   numE;     // number of edges
    int * dist;     // dist between vertices
    int   src;      // src vertex
    int * parent;

}GraphObj;
typedef struct GraphObj* Graph;
/////*-------Construct/Destructors-------*/
////newGraph() function creates new graph of size n
Graph newGraph(int n){
    Graph g = malloc(sizeof(GraphObj));
    g->List = calloc(n+1, sizeof(List));
    g->theMark = calloc(n+1, sizeof(int));
    g->numV = n;
    g->numE= 0;
    g->dist = calloc(n+1, sizeof(int));
    g->parent = calloc(n+1, sizeof(int));
    int i;
    for(i=1; i <= n; i++ ){
        g->List[i]= newList();
        g->theMark[i]= WHITE;
        g->dist[i]= INF;
        g->parent[i] = NIL;
    }
    g->src = NIL;
    return g;
}

//freeGraph() frees all memory allocated by the Graph
void freeGraph(Graph* pG){

	if(pG != NULL && *pG != NULL){
		for(int i = 1; i <= (*pG)->numV; i++){
            freeList(&(*pG)->List[i]);
		}
        free((*pG)->List);
        free((*pG)->theMark);
		free((*pG)->dist);
		free((*pG)->parent);

		free(*pG);
		*pG = NULL;

    }
}

////*********ACCESS FUNCTIONS***************//
bool outRangeU(Graph G, int u){
    if(u < 1 || u > getOrder(G))
        return true;
    else{
        return false;
    }

}

bool outRangeV(Graph G, int v){
    if(v < 1 || v > getOrder(G))
        return true;
    else{
        return false;
    }

}

bool sExist(Graph G){
if(getSource(G) != NIL)
    {
        return true;
}
else{
    return false;
}
}

//getOrder() return number of vertices numV
int getOrder(Graph G){
    if(G==NULL){
        printf("Graph ERROR: getOrder() could not access NULL Graph");
        exit(1);
    }
    return G->numV;
}

//getSize - returns number of edges  numE
int getSize(Graph G){
    if(G==NULL){
        printf("Graph ERROR: getSize() could not access NULL Graph\n");
        exit(1);
    }
    return G->numE;
}

// getSource() returns source vertex  src
int getSource(Graph G){
    if(G==NULL){
        printf("Graph ERROR: getSource() could not access NULL Graph\n");
        exit(1);
    }
    else{
         return G->src;
    }

}

////getParent() return parent of graph
int getParent(Graph G, int u){
    if(G==NULL){
        printf("Graph ERROR: getParent() could not access NULL Graph\n");
        exit(1);
    }
    if(outRangeU(G, u)){
        printf("Graph ERROR: getParent() - u out of range\n");
        exit(1);
    }
    return G->parent[u];
}

//getDist returns dist between src and parent
int getDist(Graph G, int u){
    if(G==NULL){
        printf("Graph ERROR: getDist() could not access NULL Graph\n");
        exit(1);
    }

    if(outRangeU(G, u)){
        printf("Graph ERROR: getDist() - u out of range\n");
        exit(1);
    }
    else{
        return G->dist[u];
    }
}
//
//
//////getPath - returns path from parent to source
void getPath(List L, Graph G, int u){
    if(G==NULL){
        printf("Graph ERROR: getPath() could not access NULL Graph");
        exit(1);
    }
    if(!sExist(G)){
        printf("Graph ERROR: getPath() could not access NULL Graph");
        exit(1);
    }
    if(outRangeU(G, u)){
        printf("Graph ERROR: getPath() could not access NULL Graph");
        exit(1);
    }
   if (G->src == u)
    {
        append(L, getSource(G));
    }
    else if (getParent(G, u) == NIL)
    {
        append(L, NIL);
    }
    else
    {
        getPath(L, G, getParent(G, u));
        append(L, u);
    }
}

//
////*****************MANIPULATION *************//
void unvisitAll(Graph G){
    for (int i = 1; i <= getOrder(G); i++)
    {
        G->theMark[i] = WHITE;
        G->parent[i] = NIL;
        G->dist[i] = INF;

    }
}

////makeNULL delete all edges
void makeNull(Graph G){
     if(G==NULL){
        printf("Graph ERROR: makeNull() could not access NULL Graph");
        exit(1);
    }
    else{
    G->numE = 0;
    int i;
    for(i = 1; i<= getOrder(G); i++ ){
        clear(G->List[i]);
    }
    }
}


// bidirectional edge v added to u and u added to v
void addEdge(Graph G, int u, int v){
    if(G==NULL){
        printf("Graph ERROR: addEdge() could not access NULL Graph");
        exit(1);
    }
    if(outRangeU(G, u) || outRangeV(G, v)){
        printf("Graph ERROR: addEdge() could not access NULL Graph");
        exit(1);
    }
    G->numE--;
    addArc(G, v, u);
    addArc(G, u, v);


}

//directed edge v added to u
void addArc(Graph G, int u, int v){
    if(G==NULL){
        printf("Graph ERROR: addArc() could not access NULL Graph");
        exit(1);
    }
    if(outRangeU(G, u) || outRangeV(G, v)){
        printf("Graph ERROR: addArc() - u or v out of range\n");
        exit(1);
    }
    moveFront(G->List[u]);
    while(indexNotNull(G->List[u])){

        if (v < get(G->List[u]))
        {
            insertBefore(G->List[u], v);
            break;
        }
        else{moveNext(G->List[u]);}

    }
    G->numE++;
    if (index(G->List[u]) == -1)
    {
        append(G->List[u], v);
    }
}

//perform BFS on G with source s.
void BFS(Graph G, int s){
    if(G==NULL){
        printf("Graph ERROR: BFS() could not access NULL Graph");
        exit(1);
    }
    if(s<1 || s>getOrder(G) ){
        printf("Graph ERROR: BFS() could not access NULL Graph");
        exit(1);
    }
    unvisitAll(G);
    List L = newList();

    G->src = s;
    G->theMark[s]=GRAY;
    G->parent[s]=NIL;
    G->dist[s]=0;

    append(L, s);
    while(notEmpty(L)){
        int i = front(L);
        deleteFront(L);
        if(notEmpty(G->List[i])){
            moveFront(G->List[i]);
        }
        while(indexNotNull(G->List[i])){
            int j = get(G->List[i]);
            if(G->theMark[j]==WHITE){
                G->theMark[j]= GRAY;
                G->parent[j]= i;
                G->dist[j] = G->dist[i] +1;
                append(L,j);
            }
            moveNext(G->List[i]);
        }
        G->theMark[i] = BLACK;

    }
    freeList(&L);
}


///*** Other operations ***/

void printGraph(FILE* out, Graph G){
    if(G==NULL){
        printf("Graph ERROR: getDist() could not access NULL Graph");
        exit(1);
    }
	for(int i=1; i<= G->numV; i++){
            List L = G->List[i];
		fprintf(out,"%d:",i);
		printList(out,L);
		fprintf(out,"\n");
	}
}
