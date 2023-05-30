#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char buf[MAXC];

#ifdef ADT_TYPE3

struct item
{
    char name[MAXC];
    int num;
};

#elif defined(ADT_TYPE4)

struct item
{
    char * name;
    int num;
};

#endif

Key
KEYget (Item pval)
{
    return pval->name;
}

int
KEYcompare (Key k1, Key k2)
{
    return strcmp(k1, k2);
}

void
ITEMshow (Item val)
{
    printf("%s %d\n", val->name, val->num);
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

#ifdef ADT_TYPE3

Item
ITEMnew()
{
    Item val = (Item) malloc(sizeof(struct item));
    
    if (val != NULL)
    {
        val->name[0] = '\0';
        val->num = 0;
    }
    
    return val;
}

void
ITEMfree (Item val)
{
    free(val);
}

Item
ITEMscan1()
{
    Item val = ITEMnew();
    if (val != NULL)
    {
        scanf("%s %d", buf, &val->num);
#if 0
        for (int i = 0; i < MAXC; ++i)
        {
            val->name[i] = buf[i];
            
            if (buf[i] == '\0')
            {
                break;
            }
        }
#endif
        strcpy(val->name, buf);
    }
    return val;
}

void
ITEMscan2(Item val)
{
    scanf("%s %d", buf, &val->num);
#if 0
    for (int i = 0; i < MAXC; ++i)
    {
        val->name[i] = buf[i];
        
        if (buf[i] == '\0')
        {
            break;
        }
    }
#endif
    strcpy(val->name, buf);
}

#elif defined(ADT_TYPE4)

Item
ITEMnew()
{
    Item val = (Item) malloc(sizeof(struct item));
    
    if (val != NULL)
    {
        val->name = NULL;
        val->num = 0;
    }
    
    return val;
}

void
ITEMfree (Item val)
{
    if (val->name != NULL)
        free(val->name);
    free(val);
}

Item
ITEMscan1()
{
    Item val = ITEMnew();
    if (val != NULL)
    {
        scanf("%s %d", buf, &val->num);
        val->name = strdup(buf);
    }
    return val;
}

void
ITEMscan2(Item val)
{
    scanf("%s %d", buf, &val->num);
    val->name = strdup(buf);
}

#endif

/*** End of file ***/
