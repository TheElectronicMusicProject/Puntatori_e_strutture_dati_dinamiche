#include <stdlib.h>

typedef struct {
  // Dati interni...
} Item;


typedef struct nodo_ {
  Item val;
  struct nodo_ *next;
} nodo;

typedef struct {
  nodo *head, *tail;
} LISTA;

nodo *newNode(Item val, nodo* next);

void listWrapperInsTailFast(LISTA *l, Item val) {
  if (l->head==NULL)
    l->head = l->tail = newNode(val, NULL);
  else {
    l->tail->next = newNode(val, NULL);
    l->tail = l->tail->next;
  }
}
