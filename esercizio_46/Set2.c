#include <stdlib.h>
#include "Item_Set.h"
#include "Set.h"

typedef struct SETnode *link;

struct set { link head; int N; };

struct SETnode{
  Item val;
  struct SETnode* next;
};

SET SETinit(int maxN) {
  SET s = malloc(sizeof *s);
  s->head = NULL;
  s->N = 0;
  return s;
}

int SETsearch(SET s, Key k) {
  link x;
  x = s->head;
  while (x != NULL) {
    if (KEYeq(key(x->val), k))
      return 1;
    x = x->next;
  }
  return 0;
}

SET SETunion(SET s1, SET s2) {
  link x1, x2;
  int founds2, counts2 =0;
  SET s;
  s = SETinit(s1->N + s2->N);

  x1 = s1->head;
  while (x1 != NULL) {
    SETfill(s, x1->val);
    x1 = x1->next;
  }

  x2 = s2->head;
  while (x2 != NULL) {
    x1 = s1->head;
    founds2 = 0;
    while (x1 != NULL) {
      if (ITEMeq(x1->val, x2->val))
        founds2 = 1;
      x1 = x1->next;
    }
    if (founds2 == 0) {
      SETfill(s, x2->val);
      counts2++;
    }
    x2 = x2->next;
  }

  s->N = s1->N + counts2;
  return s;
}

SET SETintersection(SET s1, SET s2) {
  link x1, x2;
  int counts=0;
  SET s;
  s = SETinit(s1->N + s2->N);

  x1 = s1->head;
  while (x1 != NULL) {
    x2 = s2->head;
    while (x2 != NULL) {
      if (ITEMeq(x1->val, x2->val)) {
        SETfill(s, x1->val);
        counts++;
      }
      x2 = x2->next;
    }
    x1 = x1->next;
  }
  s->N = counts;
  return s;
}

void SETfill(SET s, Item val){
  //da implementare, come visto nel capitolo 4 sezione 4.1.3
}