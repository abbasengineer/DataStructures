/* Programmer: Abbas Engineer
     Cruz ID : Afengine
     Version : 1.0
  Description: Graph Shortest Path and Distance using BFS
                List.c
  Prof. Tantalo PA4


*/

#include<stdio.h>
#include<stdlib.h>
#include "List.h"

// struct is same as public class Node in java
typedef struct NodeObj
{
    int data;
    struct NodeObj* next;
    struct NodeObj* prev;

}NodeObj;

typedef NodeObj* Node; // private Node type

typedef struct ListObj
{
    Node front;
    Node back;
    int length;
    Node cursor;
    int index;
}ListObj;


Node newNode(int data)
{
  //  Node N = NULL;
    Node N = malloc(sizeof(NodeObj));
    N->data = data;
    N->next = NULL;
    N->prev = NULL;
    return (N);
}


void freeNode(Node* pN)
{
    if (pN != NULL && *pN != NULL)
    {
        free(*pN);
        *pN = NULL;
    }
}

// newList()
// equivalent to List class constructor
List newList(void)
{
    //List L = NULL;
   List L = malloc(sizeof(ListObj));
    L->front = NULL;
    L->back = NULL;
    L->cursor = NULL;
    L->length = 0;
    L->index = -1;

    return (L);
}

bool notEmpty(List L){
if(length(L)>0) {return true;}
return false;
}

bool indexNotNull(List L){
if(index(L) != -1) {return true;}
return false;
}

bool cFront(List L){
if(L->cursor == L->front){return true;}
else{
    return false;
}
}

// freeList()
// frees all heap memory associated with List *pL
// and sets *pL to NULL
void freeList(List* pL)
{
    //printf("List.c: freeList() called\n");
    if (pL != NULL && *pL!= NULL)
    {

      while (notEmpty(*pL))
      {
          //printf("List.c: freeList(): deleteFront() called\n");
          clear(*pL);
      }
      //printf("!!List.c: freeList(): free(*pL) called for List\n");
      free(*pL);
      *pL = NULL;
    }
}

// Access functions ---------------------------------------

// length()
// returns the number of elements in this List
int length(List L) {

    if( L==NULL ){
      printf("List error: List already empty \n");
      exit(1);
   }
    return L->length;
}

// index()
// returns the index of the cursor of the list
int index(List L)
{
    //printf("List.c: index() is called.\n");
    if (L == NULL)
    {
        printf("List Error: calling index() on NULL List reference\n");
        exit(1);
    }
    if (!notEmpty(L))
    {
        return -1;
    }
    return L->index;
}

// front()
// returns the front element. pre: length() > 0
int front(List L)
{
    if (L == NULL)
    {
        printf("List Error: calling front() on NULL List reference\n");
        exit(1);
    }
    if (!notEmpty(L))
    {
        printf("List: front() Empty List \n");
        return -1;
    }
    return L->front->data;
}

// back()
// returns the back element. pre: length() > 0
int back(List L)
{
    if (L == NULL)
    {
        printf("List Error: calling back() on NULL List reference\n");
        exit(1);
    }
    if (!notEmpty(L))
    {
        printf("List: back() Empty List \n");
        return -1;
    }
    return L->back->data;
}

// get()
// returns the cursor element. pre: length() > 0 and index() > 0
int get(List L) {
   if( !notEmpty(L) ){
      printf("List error: List already empty \n");
      exit(1);
   }
   if(L == NULL){
    printf("List error: Null List Reference");
   }
   if (L->cursor == NULL || L->index < 0){
    printf("List error: undefined cursor ");
   }

    return L->cursor->data;
}



bool noIndex(List L){
if(index(L) == 0){return true;}
else{
    return false;
}
}
// equals
// returns 1 if this List and L are the
// same integer sequence.
//the cursor is ignored in both lists.
int equals(List A, List B) {

    if( A==NULL || B==NULL )
   {
      printf("List Error: calling equals() on NULL List reference\n");
      return true;
   }
    Node b = B->front;
    Node a = A->front;
    for (;a != NULL && b != NULL; a = a->next, b = b->next) {
        if (a->data != b->data){
            break;
        }

    }
    if (a != NULL || b != NULL){
        return 0;
    }
   return 1;
}

// Manipulation procedures ------------------------------------------------

// clear()
// resets this List to its original empty state
void clear(List L) {
    if (L == NULL){
        printf("List Error: List is NULL \n");
        exit(1);
    }

    if (L->front == NULL && L->back == NULL)
        return;
    while (notEmpty(L)) {

  deleteFront(L);
    }
}

void moveFront(List L){
if (L == NULL)
    {
        printf("List Error: calling moveFront() on a NULL List reference\n");
        exit(1);
    }
//    if (!notEmpty(L))
//    {
//      printf("List Error: calling moveFront() on empty List \n");
//    }
    else{
        L->index = 0;
        L->cursor = L->front;

    }
}
void moveBack(List L){
if (L == NULL)
    {
        printf("List Error: calling moveFront() on a NULL List reference\n");
        exit(1);
    }
    if (!notEmpty(L))
    {
      printf("List Error: calling moveFront() on empty List \n");
    }
    else{

        L->index = L->length - 1;
        L->cursor = L->back;
    }
}
void movePrev(List L){
if (L == NULL)
    {
        printf("List Error: calling moveFront() on a NULL List reference\n");
        exit(1);
    }
    if (!notEmpty(L))
    {
      printf("List Error: calling moveFront() on empty List \n");
    }
    if (L->cursor == L->front){

        L->cursor = NULL;
        L->index = -1;
    }
    else
    {
        L->cursor = L->cursor->prev;
        L->index--;
    }
}
void moveNext(List L){
if (L == NULL)
    {
        printf("List Error: calling moveFront() on a NULL List reference\n");
        exit(1);
    }
    if (!notEmpty(L))
    {
      printf("List Error: calling moveFront() on empty List \n");
    }
    if (L->cursor == L->back){

        L->cursor = NULL;
        L->index = -1;
    }
    else
    {
        L->cursor = L->cursor->next;
        L->index++;
    }
}
void prepend(List L, int data){
Node N = newNode(data);

   if( L==NULL ){
      printf("List Error: calling append() on NULL List reference\n");
      exit(1);
   }
   if( !notEmpty(L) ) {
      L->front = L->back = N;
   }else{
    if(L->cursor != NULL){
        L->index++;
    }
      L->front->prev = N;
      N->next = L->front;
      L->front = N;
      N->prev = NULL;
   }
   L->length++;
}
void append(List L, int data){

   Node N = newNode(data);

   if( L==NULL ){
      printf("List Error: calling append() on NULL List reference\n");
      exit(1);
   }
   if( !notEmpty(L) ) {
      L->front = L->back = N;
   }else{
      L->back->next = N;
      N->prev = L->back;
      L->back = N;
      N->next = NULL;
   }
   L->length++;

}

void insertBefore(List L, int data){

    if (L == NULL)
    {
        printf("List Error: calling on a NULL List reference\n");
        exit(1);
    }
    if (L->cursor == NULL)
    {
        printf("List Error: cannot insertBefore()  if cursor is undefined\n");
    }
    if (cFront(L))
    {
        prepend(L, data);
    }
    else
    {
        Node N = newNode(data);
        Node pN = L->cursor->prev;

            N->prev = pN;
            N->next = L->cursor;
            pN->next = N;
            L->cursor->prev = N;

            L->length++;
            L->index++;
    }
}

bool cBack(List L){
if(L->cursor == L->back){return true;}
else{
    return false;
}
}

bool curNull(List L){
if(L->cursor == NULL){return true;}
else{
    return false;
}
}

void insertAfter(List L, int data){
    if (L == NULL)
    {
        printf("List Error: a NULL List reference\n");
        exit(1);
    }
    if (!notEmpty(L))
    {
        printf("List Error: insertAfter() called on empty List\n");
    }
    if (cBack(L))
    {
        append(L, data);
    }
    else
    {
        Node N = newNode(data);
        Node nN = L->cursor->next;

            N->next = nN;
            N->prev = L->cursor;
            nN->prev = N;
            L->cursor->next = N;
            L->length++;
    }
}

void deleteFront(List L){
   if( !notEmpty(L) ){
      printf("List error: List already empty \n");

   }
   if(L == NULL){
    printf("List error: Null List Reference");
    exit(1);
   }
    if (length(L) > 1)      {
          Node N = L->front;
          L->front = L->front->next;
          L->front->prev = NULL;
          if (!curNull(L))
          {
              L->index--;
          }
          freeNode(&N);
   }
   else if(length(L) == 1){
        Node N = L->front;
        freeNode(&N);
        L->front = NULL;
        L->back = NULL;
        L->index = -1;
        L->cursor = NULL;

   }
   L->length--;

}

void deleteBack(List L){
    if (L == NULL)
    {
        printf("List Error: cannot deleteBack() on NULL List reference\n");
    }
    if (!notEmpty(L))
    {
        printf("List Error: cannot deleteBack() empty List\n");
    }

        if (L->length > 1)
        {
            if (index(L) == length(L) -1)
            {
                L->index = -1;
            }
            Node N = L->back;
            L->back = L->back->prev;
            L->back->next = NULL;
            freeNode(&N);
        }

        else if (L->length == 1)
        {
            Node N = L->back;
            freeNode(&N);
            L->front = NULL;
            L->back = NULL;
            L->index = -1;
            L->cursor = NULL;
        }
        L->length--;
}

void delete(List L){
    if( !notEmpty(L) ){
        printf("List error: List already empty \n");
        exit(1);
   }
   if(L == NULL){
        printf("List error: Null List Reference");
        exit(1);
   }
    if(L->front == L->cursor){
        deleteFront(L);
    }
    else if(L->back == L->cursor){
        deleteBack(L);
    }
    else{
        if(L->cursor->next != NULL){
            L->cursor->next->prev = L->cursor->prev;
        }
        if(L->cursor->prev != NULL){
            L->cursor->prev->next = L->cursor->next;
        }
        L->cursor = NULL;
        L->length--;
        L->index = -1;
    }


}


void printList(FILE* out, List L){
    Node N = NULL;
    if(L == NULL)
    {
        printf("List error: printList() called on NULL List reference\n");
        exit(1);
    }
    for (N = L->front; N != NULL; N = N->next)
    {
        fprintf(out, "%d", N->data);
        fprintf(out, " ");
    }
}


List copyList(List L){
    List C = newList();
    if (length(L) > 0)
    {
        Node N = L->front;
        while (N != NULL)
        {
            append(C, N->data);
            N = N->next;
        }
    }
    C->cursor = NULL;
    C->index = -1;
    return C;
}
