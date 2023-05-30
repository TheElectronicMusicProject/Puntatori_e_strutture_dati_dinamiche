#include <stdlib.h>
#include "Item_Set.h"
#include "Set.h"

struct set { Item *v; int N; };

SET SETinit(int maxN) {
  SET s = malloc(sizeof *s);
  s->v = malloc(maxN*sizeof(Item));
  s->N=0;
return s;
}


int SETsearch(SET s, Key k) {
  int l, m, r;
  l = 0;
  r = s->N -1;
  while (l <= r) {
    m =  l + (r-l)/2;
    if (KEYeq(key(s->v[m]), k))
      return 1;
    if (KEYless(key(s->v[m]), k))
      l = m+1;
    else
      r = m-1;
  }
  return 0;
}

SET SETunion(SET s1, SET s2) {
  int i=0, j=0, k=0, size1=SETsize(s1), size2=SETsize(s2);
  SET s;

  s = SETinit(size1+size2);

  for(k = 0; k < size1+size2 ; k++)
    if (i >= size1)
      s->v[k] = s2->v[j++];
    else if (j >= size2)
      s->v[k] = s1->v[i++];
    else if (ITEMless(s1->v[i], s2->v[j]))
      s->v[k] = s1->v[i++];
    else if (ITEMless(s2->v[j], s1->v[i]))
      s->v[k] = s2->v[j++];
    else {
      s->v[k] = s1->v[i++];
      j++;
    }
  s->N = k;
  return s;
}

int min (int x, int y){
  if (x <= y)
    return x;
  return y;
}

SET SETintersection(SET s1, SET s2) {
  int i=0, j=0, k=0, size1=SETsize(s1), size2=SETsize(s2), minsize;
  SET s;
  minsize = min(size1, size2);

  s = SETinit(minsize);

  while ((i < size1) && (j < size2)) {
    if (ITEMeq(s1->v[i], s2->v[j])) {
      s->v[k++] = s1->v[i++];
      j++;
    }
    else if (ITEMless(s1->v[i], s2->v[j]))
      i++;
    else
      j++;
  }
  s->N = k;
  return s;
}

int  SETsize(SET s){
  return s->N;
}