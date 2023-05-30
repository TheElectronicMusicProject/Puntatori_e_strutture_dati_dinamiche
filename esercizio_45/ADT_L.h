#include "ADT_Item.h"

typedef struct list *LIST;

void listInsHead (LIST l, Item val);
Item listSearch(LIST l, Key k);
void listDelKey(LIST l, Key k);
