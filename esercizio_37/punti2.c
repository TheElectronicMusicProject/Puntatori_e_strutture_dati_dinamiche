#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {
  int X, Y;
} punto_t;

void puntoScan(FILE *fp, punto_t *pp) {
  scanf("%d%d", &(pp->X), &(pp->Y));
}
void puntoPrint(punto_t p) {
  printf("(%d,%d)", p.X, p.Y);
}
float puntoDistanza (punto_t p0, punto_t p1) {
  int d2 = (p1.X-p0.X)*(p1.X-p0.X) + (p1.Y-p0.Y)*(p1.Y-p0.Y);
  return ((float) sqrt((double)d2));
}

int main(void) {
  punto_t A, B;
  int fine=0;
  float lunghezza;

  while (!fine) {
    printf("primo   estremo: "); 
    puntoScan(stdin, &A);
    printf("secondo estremo: "); 
    puntoScan(stdin, &B);

    lunghezza = puntoDistanza(A,B);

    printf("Il segmento "); puntoPrint(A); 
    printf("-"); puntoPrint(B);
    printf(" ha lunghezza: %f\n", lunghezza);

    fine = lunghezza==0;
  }
  return 0;
}
