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
} creatura_t;

punto_t puntoScan(FILE *fp) {
  punto_t p;
  scanf("%d %d", &p.X, &p.Y);
  return p;
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

creatura_t creaturaNew(char *nome, punto_t punto) {
  creatura_t cr;
  strcpy(cr.nome,nome);
  cr.posizione = punto;
  return cr;
}

creatura_t creaturaSposta(creatura_t cr, punto_t p) {
  cr.posizione = p;
  return cr;
}

int main(void) {
  char nome[MAXS];
  punto_t punto;
  creatura_t cr;
  int fine=0;
  float d, distanzaTotale = 0.0;

  printf("Nome della creatura : "); 
  scanf("%s", nome);
  printf("punto iniziale      : "); 
  punto = puntoScan(stdin);
  cr = creaturaNew(nome,punto);

  while (!fine) {
    printf("nuova posizione     : "); 
    punto = puntoScan(stdin);
    if (puntoFuori(punto)) {
      fine = 1;
    }
    else {
      distanzaTotale += puntoDistanza(cr.posizione, punto);
      cr = creaturaSposta(cr,punto);
      printf ("%s e' nel punto: ", cr.nome);
      puntoPrint(stdout,punto); 
      printf("\n");
    }
  }
  printf("%s ha percorso la distanza: %f\n",cr.nome, distanzaTotale);
  return 0;
}
