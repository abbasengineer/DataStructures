/* Programmer: Abbas Engineer
     Cruz ID : Afengine
     Version : 1.0
  Description: Graph Shortest Path and Distance using BFS
                List.h
  Prof. Tantalo PA4


*/
#ifndef _LIST_H_INCLUDE_
#define _LIST_H_INCLUDE_
#include <stdbool.h>

typedef struct ListObj* List;

// constructors-destructors ----------------------
List newList(void);
void freeList(List* pL);

// access functions ------------------------------
int length(List L);
int index(List L);
int front(List L);
int back(List L);
int get(List L);
int equals(List A, List B);
bool notEmpty(List L);
bool noIndex(List L);
bool cBack(List L);
bool cFront(List L);
bool indexNotNull(List L);
// manipulation procedures ------------------------
void clear(List L);
void moveFront(List L);
void moveBack(List L);
void movePrev(List L);
void moveNext(List L);
void prepend(List L, int data);
void append(List L, int data);
void insertBefore(List L, int data);
void insertAfter(List L, int data);
void deleteFront(List L);
void deleteBack(List L);
void delete(List L);


// other operations ----------------------------------

void printList(FILE* out, List L);
List copyList(List L);

#endif
