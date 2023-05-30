#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ADT_Item.h"

#define MAXC 30
static char buf[MAXC];

//definizione della struct 
struct item{
	Key name;
	int num;
	//ulteriori campi della struct...
};

Key KEYget(Item data) {
  return (data->name);
}

int KEYcompare (Key k1, Key k2) {
  return (strcmp(k1, k2));
}

void ITEMshow(Item data) {
  printf("%s %d", data->name, data->num);
}

int ITEMless(Item data1, Item data2) {
  return (strcmp(KEYget(data1),KEYget(data2))<0);
}