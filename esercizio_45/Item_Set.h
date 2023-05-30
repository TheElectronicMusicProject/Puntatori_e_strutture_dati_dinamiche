typedef struct item *Item;
typedef int Key;

int KEYeq(Key k1, Key k2);
int KEYless(Key k1, Key k2);

Key key(Item);

int ITEMeq(Item data1, Item data2);
int ITEMless(Item data1, Item data2);
