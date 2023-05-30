#ifndef ITEM_H
#define ITEM_H

#define ADT_TYPE1

#ifdef ADT_TYPE1

typedef int Item;
typedef int Key;

Key KEYget(Item val);

#elif defined(ADT_TYPE2)

typedef char * Item;
typedef char * Key;

Key KEYget(Item val);

#elif defined(ADT_TYPE3)

#define MAXC 30
typedef struct item
{
    char name[MAXC];
    int num;
} Item;

typedef char * Key;

Key KEYget(Item * pval);

#elif defined(ADT_TYPE4)

typedef struct item
{
    char * name;
    int num;
} Item;

typedef char * Key;

Key KEYget(Item * pval);

#endif

int KEYcompare(Key k1, Key k2);
Key KEYscan();
Item ITEMscan();
void ITEMshow(Item val);
int ITEMless(Item val1, Item val2);
int ITEMgreater(Item val1, Item val2);
int ITEMcheckvoid(Item val);
Item ITEMsetvoid();
#endif /* ITEM_H */

/*** End of file ***/
