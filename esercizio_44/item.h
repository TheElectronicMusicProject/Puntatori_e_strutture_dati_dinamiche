#ifndef ITEM_H
#define ITEM_H

#define ADT_TYPE3

typedef struct item * Item;
typedef char * Key;

#define MAXC 30

Key KEYget(Item pval);
int KEYcompare(Key k1, Key k2);
Key KEYscan();
Item ITEMscan();
void ITEMshow(Item val);
int ITEMless(Item val1, Item val2);
int ITEMgreater(Item val1, Item val2);
int ITEMcheckvoid(Item val);
Item ITEMsetvoid();
Item ITEMnew();
void ITEMfree(Item val);
Item ITEMscan1();
void ITEMscan2(Item val);
#endif /* ITEM_H */

/*** End of file ***/
