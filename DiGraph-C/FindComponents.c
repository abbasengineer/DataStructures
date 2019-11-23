/* Programmer: Abbas Engineer
     Cruz ID : Afengine
     Version : 1.0
  Description: Graph module to find the strongly connected components of a digraph
                FindComponent.c
  Prof. Tantalo PA5


*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include "Graph.h"
#define MAX_LEN 333

int main(int argc, char* argv[])
{

    FILE *in, *out;
    char line[MAX_LEN];
    int x = 0;
    int a = 0;
    int b = 0;
    Graph g, gTpose ;
    List L = newList();

   if( argc != 3 ){
      printf("Usage: %s <input file> <output file>\n", argv[0]);
      exit(1);
   }

   in = fopen(argv[1], "r");
   out = fopen(argv[2], "w");
   if( in==NULL ){
      printf("Unable to open file %s for reading\n", argv[1]);
      exit(1);
   }
   if( out==NULL ){
      printf("Unable to open file %s for writing\n", argv[2]);
      exit(1);
   }

    fscanf(in, "%d", &x);

   for(int i = 1; i <= x; i++)
   {
       append(L, i);
   }

   g = newGraph(x);

   while( fgets(line, MAX_LEN, in) != NULL)  {

      fscanf(in, "%d %d", &a, &b);
      if(a == 0 && b == 0)
         break;
      addArc(g, a, b);
   }

   DFS(g, L);
   gTpose = transpose(g);
   DFS(gTpose, L);
   if(notEmpty(L)){
       moveFront(L);
   }

   int sccCount = getSCC(gTpose);

   List stackSCC[sccCount];

   for(int i = 0; i < sccCount; i++)
   {
      stackSCC[i] = newList();
   }

  int size = sccCount;

  fprintf(out, "Adjacency list representation of G: \n");
  printGraph(out, g);

  if(notEmpty(L)){
       moveFront(L);
   }

   while(iNEmpty(L))
    {
        int val = get(L);
    if(pDNE(gTpose, val)){
         size--;
      }
      append(stackSCC[size], val);
      moveNext(L);
   }

   fprintf(out, "\nG contains %d strongly connected components: ", sccCount);
   for( int j = 0; j < sccCount; j++)
   {
        int k = j+1;
        fprintf(out, "\nComponent %d: ", k);
        printList(out, stackSCC[j]);
        fprintf(out, "\n");
        freeList(&(stackSCC[j]));
   }

     /**** close files ****/
   fclose(in);
   fclose(out);
   freeList(&L);
   freeGraph(&g);
   freeGraph(&gTpose);

   return(0);
}
