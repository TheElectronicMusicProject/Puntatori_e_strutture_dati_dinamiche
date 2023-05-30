#include "Item_Set.h"

#define MAXC 30
static char buf[MAXC];

struct item{
	Key key;
	char* data;
};

int KEYeq(Key k1, Key k2) {
  return (k1==k2);
}

int KEYless(Key k1, Key k2) {
  return (k1<k2);
}

Key key(Item data){
	return data->key;
}

int ITEMeq(Item data1, Item data2) {
  return KEYeq(key(data1),key(data2));
}

int ITEMless(Item data1, Item data2) {
  return KEYless(key(data1),key(data2));
}