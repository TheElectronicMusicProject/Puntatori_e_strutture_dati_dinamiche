#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define MAXS 100

typedef struct {
  int X, Y;
} punto_t;

typedef struct {
  char nome[MAXS];
  punto_t posizione;
  float percorsoTotale;
} creatura_t;

void puntoScan(FILE *fp, punto_t *pp) {
  scanf("%d %d", &pp->X, &pp->Y);
}

void puntoPrint(FILE *fp, punto_t p) {
  printf("%d %d", p.X, p.Y);
}

int puntoFuori(punto_t p) {
  return (p.X<0 || p.Y<0);
}

float puntoDistanza (punto_t p0, punto_t p1) {
  int d2 = (p1.X-p0.X)*(p1.X-p0.X) + (p1.Y-p0.Y)*(p1.Y-p0.Y);
  return ((float) sqrt((double)d2));
}

void creaturaNew(creatura_t *cp, char *nome, punto_t punto) {
  strcpy(cp->nome,nome);
  cp->posizione = punto;
  cp->percorsoTotale = 0.0;
}

void creaturaSposta(creatura_t *cp, punto_t p) {
  cp->percorsoTotale += puntoDistanza(cp->posizione,p);
  cp->posizione = p;
}

int main(void) {
  char nome[MAXS];
  punto_t punto;
  creatura_t cr;
  int fine=0;
  float distanzaTotale = 0.0;

  printf("Nome della creatura : "); scanf("%s", nome);
  printf("punto iniziale      : "); 
  puntoScan(stdin,&punto);
  creaturaNew(&cr,nome,punto);

  while (!fine) {
    printf("nuova posizione     : "); 
    puntoScan(stdin,&punto);
    if (puntoFuori(punto)) {
      fine = 1;
    }
    else {
      creaturaSposta(&cr,punto);
      printf ("%s e' nel punto: ", cr.nome);
      puntoPrint(stdout,punto); 
      printf("\n");
    }
  }
  printf("%s ha percorso la distanza: %f\n", cr.nome, cr.percorsoTotale);
  return 0;
}
