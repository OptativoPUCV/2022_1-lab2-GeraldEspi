#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
     List* lista = (List *) calloc(1,sizeof(List));
     lista->head = NULL;
     lista->current = NULL;
     lista->tail = NULL;
     return lista;  

}

void * firstList(List * list) {
    list->current = list->head;
    if(list->current == NULL)
    {return NULL;}
    else
    {return list->current->data;}
}

void * nextList(List * list) { 
    if(list->current == NULL)
    {return NULL;}
    if(list->current->next == NULL)
    {return NULL;}
    list->current = list->current->next;
    return list->current->data;
    
  
}

void * lastList(List * list) {
    list->current = list->tail;
    if(list->current == NULL)
    {return NULL;}
    else
    {return list->current->data;}
}

void * prevList(List * list) {
   if(list->current == NULL)
    {return NULL;}
    if(list->current->prev == NULL)
    {return NULL;}
    list->current = list->current->prev;
    return list->current->data;
}

void pushFront(List * list, void * data) {
  Node *n= createNode(data);
  if(list->head==NULL)
  {list->head = n;
   list->current = n;
   list->tail= n;}
  else {n->next = list->head;
        n->prev = NULL;
        list->head->prev = n; // el anterior al principio de mi lista pasa a ser el nodo
        list->head = n; // hago que mi nodo sea la cabeza
    }
  
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  Node* n = createNode(data);
  if(list->current->next == NULL)
  {
    n->prev = list->current;
    n->next = NULL;
    list->current->next = n; // el siguiente a mi current pasa a ser el nodo
    list->tail = n;
  }
  else{
       n->prev = list->current;
       n->next = list->current->next;
       list->current->next = n;}
  
    
  }
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}