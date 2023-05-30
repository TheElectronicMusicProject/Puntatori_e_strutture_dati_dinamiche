#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {
  int X, Y;
} punto_t;

punto_t *puntoCrea(void) {
  punto_t *pp = (punto_t*) malloc(sizeof(punto_t));
  return pp;
}

punto_t *puntoDuplica(punto_t *pp) {
  punto_t *pp2 = puntoCrea();
  *pp2 = *pp;
  return pp2;
}

void puntoLibera(punto_t *pp) {
  free(pp);
}

void puntoScan(FILE *fp, punto_t *pp) {
  scanf("%d%d", &pp->X, &pp->Y);
}

void puntoPrint(FILE *fp, punto_t *pp) {
  printf("(%d,%d)", pp->X, pp->Y);
}

float puntoDistanza (punto_t *pp0, punto_t *pp1) {
  int d2 = (pp1->X-pp0->X)*(pp1->X-pp0->X) + (pp1->Y-pp0->Y)*(pp1->Y-pp0->Y);
  return ((float) sqrt((double)d2));
}

punto_t *puntoMaggiore(punto_t *pp0, punto_t *pp1) {
  punto_t origine = {0,0};
  float d0 = puntoDistanza(&origine,pp0);
  float d1 = puntoDistanza(&origine,pp1);
  if (d0>d1) return puntoDuplica(pp0);
  else return puntoDuplica(pp1);
}

int main(void) {
  punto_t *A, *B;

  A = puntoCrea();
  B = puntoCrea();

  printf("primo   punto: "); 
  puntoScan(stdin, A);
  printf("secondo punto: "); 
  puntoScan(stdin, B);
  
  // problema: qui si perde (senza fare free) il dato puntato da A
  A = puntoMaggiore(A,B); 
  
  printf("Il punto piu' lontano dall'origine e': "); puntoPrint(stdout,A); 

  puntoLibera(A);
  puntoLibera(B);
  return 0;
}
