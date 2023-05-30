#include <stdlib.h>
#include "qADT_S.h"

static Item *s;
static int N;

void STACKinit(int maxN) { 
  s = malloc(maxN*sizeof(Item));
  N=0; 
}

int STACKempty() { return N == 0; }

void STACKpush(Item val) { s[N++] = val; }

Item STACKpop() { return s[--N]; }
