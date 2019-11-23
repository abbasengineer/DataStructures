/* Programmer: Abbas Engineer
     Cruz ID : Afengine
     Version : 1.0
  Description: Graph Shortest Path and Distance using BFS
                FindPath.c
  Prof. Tantalo PA4


*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Graph.h"
#define MAX_LEN 300
int main(int argc, char* argv[])
{
    int x;
    FILE *in, *out;
    char line[MAX_LEN];
     Graph g;
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

    x = 0;
    fscanf(in, "%d", &x);
    int src1 = 0;
    int dst1 = 0;
    g = newGraph(x);
    while (fgets(line, MAX_LEN, in) != NULL)
    {
        fscanf(in, "%d %d", &src1, &dst1 );

        if (dst1 == 0 && src1 == 0)
        {
            break;
        }
        else{
            addEdge(g, src1, dst1);
        }

    }
    printGraph(out, g);
    fprintf(out, "\n");

    int s = 0;
    int d = 0;

    while (fgets(line, MAX_LEN, in) != NULL)
    {
        List list = newList();
        fscanf(in, "%d %d", &s, &d);
        if (s == 0 && d == 0)
        {
            break;
        }

        BFS(g, s);
        getPath(list, g, d);
       // fprintf(out, "The distance from %d to %d is ");

        if (getDist(g, d) == INF)
        {
             fprintf(out,"The distance from %d to %d is infinity\n", s, d);
             fprintf(out, "No %d-%d path exists ", s, d);

        }
        else
        {
            int dist= length(list) - 1;
            fprintf(out, "The distance from %d to %d is %d\n", s, d, dist);
            fprintf(out, "A shortest %d-%d path is: ", s, d);
            printList(out, list);

        }
        fprintf(out, "\n\n");
        freeList(&list);
    }

    freeGraph(&g);

    fclose(in);
    fclose(out);

    return(0);
}

