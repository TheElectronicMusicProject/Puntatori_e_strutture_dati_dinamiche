#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CASO_3

/* Contenuto del nodo */
typedef float Item;
/* Chiave (altro contenuto del nodo, dove si opera) */
typedef int Key;

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
link newNode(Item val, link next);
link listInsHead(link h, Item val);
void listInsHeadP(link * hp, Item val);
link listInsTail(link h, Item val);
void listInsTailP(link * hp, Item val);
void listInsTailFast(link * hp, link * tp, Item val);
link listDelHead(link h);
Item listExtrHeadP(link * hp);
Item listSearch(link h, Key k);
link listDelKey(link h, Key k);
link listDelKeyR(link x, Key k);
Item listExtrKeyP(link * hp, Key k);
link SortListIns(link h, Item val);
Item SortListSearch(link h, Key k);
link SortListDel(link h, Key k);

static Key
KEYget (Item d)
{
    return (round(d));
}

static int
KEYeq (Key k1, Key k2)
{
    return k1 == k2 ? 1 : 0;
}

static int
KEYless (Key k1, Key k2)
{
    return k1 < k2 ? 1 : 0;
}

static int
KEYgreater (Key k1, Key k2)
{
    return k1 > k2 ? 1 : 0;
}

int
main (void)
{
    /* Puntatore al primo elemento della lista (nessuno all'inizio) */
    link head = NULL;
    link x = NULL;
    link t = NULL;
    link z = NULL;
    Item d = 0;

    /* lista ordinata */
    listInsHeadP(&t, 2);
    x = t;
    listInsHeadP(&x, 1);
    head = x;
    listInsHeadP(&head, 0);
    listInsTailP(&head, 3);
    
    head = SortListIns(head, 4);
    
    printf("elemento con 3: %f\n", SortListSearch(head, 3));
    
    head = SortListDel(head, 3);
    
    printf("elemento con 3: %f\n", SortListSearch(head, 3));

    listTravR(head);
    
	return (0);
}	/* main() */

/* Inserisco un nodo come predecessore */
link
newNode (Item val, link next)
{
    link x = malloc(sizeof(struct node));
    if (NULL == x)
        return NULL;
    x->val = val;
    x->next = next;
    
    return x;
}

/* Inserzione in testa caso 1 */
link
listInsHead (link h, Item val)
{
    h = newNode(val, h);
    return h;
}

/* Inserzione in testa caso 2 */
void
listInsHeadP (link * hp, Item val)
{
    *hp = newNode(val, *hp);
    return;
}

link
listInsTail (link h, Item val)
{
    link x;
    if (h == NULL)
        return newNode(val, NULL);
    
    /* ricerca ultimo nodo */
    for (x = h; x->next != NULL; x = x->next);
    x->next = newNode(val, NULL);
    
    return h;
}

void
listInsTailP (link * hp, Item val)
{
    link x = *hp;
    
    if (NULL == x)
        *hp = newNode(val, NULL);
    
    /* ricerca ultimo elemento */
    for (x = *hp; x->next != NULL; x = x->next);
    x->next = newNode(val, NULL);
    
    return;
}

void
listInsTailFast (link * hp, link * tp, Item val)
{
    if (*hp == NULL)
        *hp = *tp = newNode(val, NULL);
    else
    {
        (*tp)->next = newNode(val, NULL);
        *tp = (*tp)->next;
    }
    
    return;
}

link
listDelHead (link h)
{
    link t = h;
    
    if (NULL == h)
        return NULL;
    
    h = h->next;
    free(t);
    
    return h;
}

Item
listExtrHeadP (link * hp)
{
    link t = *hp;
    Item tmp;
    
    if (t == NULL)
        return 0;
    
    tmp = (*hp)->val;
    *hp = t->next;
    free(t);
    
    return tmp;
}

Item
listSearch (link h, Key k)
{
    link x;
    
    for (x = h; x != NULL; x = x->next)
    {
        if (KEYeq(KEYget(x->val), k))
            return x->val;
    }
    
    return 0;
}

link
listDelKey (link h, Key k)
{
    link x, p;
    
    if (NULL == h)
        return NULL;
    
    for (x = h, p = NULL; x != NULL; p = x, x = x->next)
    {
        if (KEYeq(KEYget(x->val), k))
        {
            if (x == h)
                h = x->next;
            else
                p->next = x->next;
            
            free(x);
            break;
        }
    }
    
    return h;
}

link
listDelKeyR (link x, Key k)
{
    link t;
    
    if (x == NULL)
        return NULL;
    
    if (KEYeq(KEYget(x->val), k))
    {
        t = x->next;
        free(x);
        return t;
    }
    x->next = listDelKeyR(x->next, k);
    return x;
}

Item
listExtrKeyP (link * hp, Key k)
{
    link * xp, t;
    Item i = 0;
    
    for (xp = hp; (*xp) != NULL; xp = &((*xp)->next))
    {
        if (KEYeq(KEYget((*xp)->val), k))
        {
            t = *xp;
            *xp = (*xp)->next;
            i = t->val;
            free(t);
            break;
        }
    }
    
    return i;
}

link
SortListIns (link h, Item val)
{
    link x, p;
    Key k = KEYget(val);
    
    /* inserimento in testa */
    if (h == NULL || KEYgreater(KEYget(h->val), k))
        return newNode(val, h);
    
    /* cerca posizione */
    for (x = h->next, p = h; x != NULL && KEYgreater(k, KEYget(x->val));
         p = x, x = x->next);
         
    p->next = newNode(val, x);
    
    return h;
}

Item
SortListSearch (link h, Key k)
{
    link x;
    
    for (x = h; x != NULL; x = x->next)
    {
        if (KEYeq(KEYget(x->val), k))
            return x->val;
    }
    
    return 0;
}

link
SortListDel (link h, Key k)
{
    link x, p;
    
    if (NULL == h)
        return NULL;
    
    for (x = h, p = NULL; x != NULL; p = x, x = x->next)
    {
        if (KEYeq(KEYget(x->val), k))
        {
            if (x == h)
            {
                h = x->next;
            }
            else
            {
                p->next = x->next;
            }
            
            free(x);
            break;
        }
    }
    
    return h;
}

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
