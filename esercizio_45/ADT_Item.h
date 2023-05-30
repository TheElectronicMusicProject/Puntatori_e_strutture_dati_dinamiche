typedef struct item *Item;
typedef char *Key;

Key  KEYget(Item data);
Key  KEYscan();
int  KEYcompare(Key k1, Key k2);

void ITEMshow(Item data);
int  ITEMless(Item data1, Item data2);
int  ITEMgreater(Item data1, Item data2);
int  ITEMcheckvoid(Item data);
Item ITEMsetvoid();
