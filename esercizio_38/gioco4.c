#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define MAXS 100

typedef struct {
  int X, Y;
} punto_t;

typedef struct {
  char *nome;
  punto_t *posizione;
  float percorsoTotale;
} creatura_t;

punto_t *puntoCrea(void) {
  punto_t *pp = (punto_t*) malloc (sizeof(punto_t));
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
  scanf("%d %d", &pp->X, &pp->Y);
}

void puntoPrint(FILE *fp, punto_t *pp) {
  printf("(%d,%d)", pp->X, pp->Y);
}

int puntoFuori(punto_t *pp) {
  return (pp->X<0 || pp->Y<0);
}

float puntoDistanza (punto_t *pp0, punto_t *pp1) {
  int d2 = (pp1->X-pp0->X)*(pp1->X-pp0->X) + (pp1->Y-pp0->Y)*(pp1->Y-pp0->Y);
  return ((float) sqrt((double)d2));
}

creatura_t *creaturaNew(char *nome, punto_t *punto) {
  creatura_t *cp = malloc (sizeof(creatura_t));
  cp->nome = strdup(nome);
  cp->posizione = puntoDuplica(punto);
  cp->percorsoTotale = 0.0;
  
  return cp;
}

void creaturaLibera(creatura_t *cp) {
  free(cp->nome);
  puntoLibera(cp->posizione);
  free(cp);
}

void creaturaSposta(creatura_t *cp, punto_t *pp) {
  cp->percorsoTotale += puntoDistanza(cp->posizione,pp);
  *(cp->posizione) = *pp;
}

int main(void) {
  char nome[MAXS];
  punto_t punto;
  creatura_t *crp;
  int fine=0;
  float distanzaTotale = 0.0;

  printf("Nome della creatura : "); scanf("%s", nome);
  printf("punto iniziale      : "); 
  puntoScan(stdin,&punto);
  crp = creaturaNew(nome,&punto);

  while (!fine) {
    printf("nuova posizione     : "); 
    puntoScan(stdin,&punto);
    if (puntoFuori(&punto)) {
      fine = 1;
    }
    else {
      creaturaSposta(crp,&punto);
      printf ("%s e' nel punto: ", crp->nome);
      puntoPrint(stdout,&punto); 
      printf("\n");
    }
  }
  printf("%s ha percorso la distanza: %f\n", crp->nome, crp->percorsoTotale);
  creaturaLibera(crp);
  return 0;
}
