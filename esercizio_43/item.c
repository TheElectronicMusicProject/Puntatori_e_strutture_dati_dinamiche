#include "item.h"

#ifdef ADT_TYPE1

Key
KEYget (Item val)
{
    return val;
}

int
KEYcompare (Key k1, Key k2)
{
    return k1 - k2;
}

Item
ITEMscan()
{
    Item val;
    
    scanf("%d", &val);
    return val;
}

void
ITEMshow (Item val)
{
    printf("%d", val);
}

int
ITEMless (Item val1, Item val2)
{
    return (KEYget(val1) < KEYget(val2));
}

int
ITEMgreater (Item val1, Item val2)
{
    return (KEYget(val1) > KEYget(val2));
}

#elif defined(ADT_TYPE2)

static char buf[MAXC];

Key
KEYget (Item val)
{
    return val;
}

int
KEYcompare (Key k1, Key k2)
{
    return strcmp(k1, k2);
}

Item
ITEMscan()
{
    scanf("%s", buf);
    return strdup(buf);
}

void
ITEMshow (Item val)
{
    printf("%s", val);
}

int
ITEMless (Item val1, Item val2)
{
    return (strcmp(KEYget(val1), KEYget(val2)) < 0);
}

int
ITEMgreater (Item val1, Item val2)
{
    return (strcmp(KEYget(val1), KEYget(val2)) > 0);
}

#elif defined(ADT_TYPE3)

Key
KEYget (Item * pval)
{
    return pval->name;
}

int
KEYcompare (Key k1, Key k2)
{
    return strcmp(k1, k2);
}

Item
ITEMscan()
{
    Item val;
    
    scanf("%s %d", val.name, &(val.num));
    return val;
}

void
ITEMshow (Item val)
{
    printf("%s %d", val.name, val.num);
}

int
ITEMless (Item val1, Item val2)
{
    return (strcmp(KEYget(&val1), KEYget(&val2)) < 0);
}

int
ITEMgreater (Item val1, Item val2)
{
    return (strcmp(KEYget(&val1), KEYget(&val2)) > 0);
}

#elif defined(ADT_TYPE4)

static char buf[MAXC];

Key
KEYget (Item * pval)
{
    return pval->name;
}

int
KEYcompare (Key k1, Key k2)
{
    return strcmp(k1, k2);
}

Item
ITEMscan()
{
    Item val;
    
    scanf("%s %d", buf, &(val.num));
    val.name = strdup(buf);
    return val;
}

void
ITEMshow (Item val)
{
    printf("%s %d", val.name, val.num);
}

int
ITEMless (Item val1, Item val2)
{
    return (strcmp(KEYget(&val1), KEYget(&val2)) < 0);
}

int
ITEMgreater (Item val1, Item val2)
{
    return (strcmp(KEYget(&val1), KEYget(&val2)) > 0);
}

#endif

/*** End of file ***/
