#include <stdlib.h>
#include "ADT_L.h"

typedef struct node *link;
struct node { Item val; link next; } ;
struct list  { link head; int N; };

//funzione interna al modulo
link newNode(Item val, link next){
	link l= (link)malloc(sizeof(struct node));
	if (l==NULL) return NULL;
	l->val=val;
	l->next=next;
	return l;
}

void LISTinsHead (LIST l, Item val) {
  l->head = newNode(val,l->head);
}

Item listSearch(LIST l, Key k)
{
    link x;
    
    for (x = l->head; x != NULL; x = x->next)
    {
        if (0 == KEYcompare(l->head->val, k))
        {
            return x->val;
        }
    }
    
    return NULL;
}

void listDelKey(LIST l, Key k)
{
    link x, p;
    
    if (l->head == NULL)
    {
        return NULL;
    }
    
    for (x = l->head, p = NULL; x != NULL; p = x, x = x->next)
    {
        if (0 == KEYcompare(x->val, k))
        {
            if (x == l->head)
            {
                l->head = x->next;
            }
            else
            {
                p->next = x->next;
            }
            
            free(x);
            break;
        }
    }
}

//implementazione delle altre funzioni