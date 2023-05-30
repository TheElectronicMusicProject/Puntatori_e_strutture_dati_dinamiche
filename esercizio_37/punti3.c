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

int main(void) {
  punto_t *A, *B;
  int fine=0;
  float lunghezza;

  A = puntoCrea();
  B = puntoCrea();
  while (!fine) {
    printf("primo   estremo: "); 
    puntoScan(stdin, A);
    printf("secondo estremo: "); 
    puntoScan(stdin, B);
    lunghezza = puntoDistanza(A,B);
    printf("Il segmento "); puntoPrint(stdout,A); 
    printf("-"); puntoPrint(stdout,B);
    printf(" ha lunghezza: %f\n", lunghezza);
    fine = (lunghezza==0);
  }
  puntoLibera(A);
  puntoLibera(B);
  return 0;
}
