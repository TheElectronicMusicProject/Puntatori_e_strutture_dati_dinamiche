#include <stdio.h>
#include <stdlib.h>

#define CASO_3

/* Contenuto del nodo */
typedef float Item;
/* Chiave (altro contenuto del nodo, dove si opera) */
typedef int Key;

Key KEYget(Item d);
int KEYeq(Key k1, Key k2);
int KEYless(Key k1, Key k2);
int KEYgreater(Key k1, Key k2);

#if defined(CASO_1)
struct node
{
    Item val;
    struct node * next;
};

#elif defined(CASO_2)
typedef struct node
{
    Item val;
    struct node * next;
} node_t, * link;

#elif defined(CASO_3)
typedef struct node * link;

struct node
{
    Item val;
    link next;
};

#elif defined(CASO_4)
typedef struct node node_t;

struct node
{
    Item val;
    node_t * next;
};

#elif defined(CASO_5)
typedef struct node * link, node_t;

struct node
{
    Item val;
    link next;
};
#endif

void listTravR(link h);
void listRevTravR(link h);

int
main (void)
{
    /* Puntatore al primo elemento della lista (nessuno all'inizio) */
    link head = NULL;
    link x = NULL, t = NULL;
    
    link point, pred;
    int i = 0;
    
    /* Allocazione tipo 1 */
    /*x = (link) malloc(sizeof(*x));*/
    /* Allocazione tipo 2 */
    head = (link) malloc(sizeof(struct node));
    x = (link) malloc(sizeof(struct node));
    t = (link) malloc(sizeof(struct node));
    
    /* x diventa successore di head */
    head->next = x;
    x->next = NULL;
    
    /* t viene interposto tra head e x */
    t->next = x;
    head->next = t;
    
    /* t viene eliminato modo 1 */
    /*head->next = head->next->next;*/
    /* t viene eliminato modo 2 */
    /*head->next = t->next;*/
    
    for (point = head, i = 0; point != NULL; point = point->next, ++i)
    {
        point->val = i;
    }
    
    for (pred = head; pred != NULL && pred->next != NULL; pred = pred->next)
    {
        pred->val += 0.1;
    }
    
    i = 0;
    
    for (point = head, pred = NULL; point != NULL; point = point->next)
    {
        printf("Al nodo corrente, Item = %f\n", point->val);
        if (i != 0)
        {
            printf("Al nodo precedente, Item = %f\n", pred->val);
        }
        pred = point;
        ++i;
    }
    
    printf("\n");
    
    listTravR(head);
    
    printf("\n");
    
    listRevTravR(head);
    
    free(t);
    free(x);
    free(head);
    
	return (0);
}	/* main() */

void
listTravR (link h)
{
    if (h == NULL)
    {
        return;
    }
    printf("%f\t", h->val);
    listTravR(h->next);
}

void
listRevTravR (link h)
{
    if (h == NULL)
    {
        return;
    }
    listRevTravR(h->next);
    printf("%f\t", h->val);
}

/*** End of file ***/
