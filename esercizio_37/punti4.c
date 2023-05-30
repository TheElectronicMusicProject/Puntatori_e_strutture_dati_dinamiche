#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {
  int X, Y;
} *ppunto_t;

ppunto_t puntoCrea(void) {
  ppunto_t pp = (ppunto_t) malloc(sizeof *pp);
  return pp;
}

void puntoLibera(ppunto_t pp) {
  free(pp);
}
void puntoScan(FILE *fp, ppunto_t pp) {
  scanf("%d%d", &pp->X, &pp->Y);
}
void puntoPrint(FILE *fp, ppunto_t pp) {
  printf("(%d,%d)", pp->X, pp->Y);
}
float puntoDistanza (ppunto_t pp0, ppunto_t pp1) {
  int d2 = (pp1->X-pp0->X)*(pp1->X-pp0->X) + (pp1->Y-pp0->Y)*(pp1->Y-pp0->Y);
  return ((float) sqrt((double)d2));
}

int main(void) {
  ppunto_t A, B;
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
    printf("Il segmento "); puntoPrint(stdout, A); 
    printf("-"); puntoPrint(stdout, B);
    printf(" ha lunghezza: %f\n", lunghezza);
    fine = lunghezza==0;
  }
  puntoLibera(A);
  puntoLibera(B);
  return 0;
}
