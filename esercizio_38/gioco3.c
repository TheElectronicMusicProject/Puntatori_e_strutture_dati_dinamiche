#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define MAXS 100

typedef struct
{
  int X, Y;
} punto_t;

typedef struct
{
  char *nome;
  punto_t *posizione;
  float percorsoTotale;
} creatura_t;

void puntoScan(FILE *fp, punto_t *pP)
{
  scanf("%d %d", &pP->X, &pP->Y);
}

void puntoPrint(FILE *fp, punto_t *pP)
{
  printf("%d %d", pP->X, pP->Y);
}

float puntoDistanza (punto_t *p0P, punto_t *p1P)
{
  int d2 = (p1P->X-p0P->X)*(p1P->X-p0P->X) + (p1P->Y-p0P->Y)*(p1P->Y-p0P->Y);
  return ((float) sqrt((double)d2));
}

void creaturaNew(creatura_t *cp, char *nome, punto_t *puntoP)
{
  cp->nome = nome;
  cp->posizione = puntoP;
  cp->percorsoTotale = 0.0;
}

void creaturaSposta(creatura_t *cp, punto_t *pP)
{
  cp->percorsoTotale += puntoDistanza(cp->posizione,pP);
  cp->posizione = pP;
}

int main(void)
{
  char *nome;
  creatura_t cr;
  int fine=0, i, np;
  char *nomi_a_scelta[5]={"Spiderman","Superman","Batman","Ironman","Hulk"};
  punto_t *punti_ammessi;

  printf("Nome della creatura e' a scelta tra:\n");
  
  for(i=0; i<5; i++)
    printf("%d) %s\n", i+1, nomi_a_scelta[i]);

  printf("Indicare l'indice (1..5) del nome scelto: "); 
  scanf("%d", &i); i--; // si riporta l'indice nell'intervallo 0..4
  
  nome = nomi_a_scelta[i];
  printf("Con quanti punti vuoi far giocare %s? ", nome); scanf("%d", &np);
  
  punti_ammessi = malloc(np*sizeof(punto_t));
  
  for (i=0; i<np; i++)
  {
    printf("punto %d) ", i+1);
    puntoScan(stdin,&punti_ammessi[i]);
  }
  
  printf("I punto possibili sono (per sceglierne uno occorre l'indice (1..np):\n");
  
  for (i=0; i<np; i++)
  {
    printf("%d) ", i+1);
    puntoPrint(stdout,&punti_ammessi[i]);
    printf("\n");
  }
  
  printf("punto iniziale      : "); 
  scanf("%d", &i); i--; // si riporta l'indice nell'intervallo 0..np-1
  creaturaNew(&cr,nome,&punti_ammessi[i]);
  
  while (!fine)
  {
    printf("nuova posizione (<=0 per terminare) : "); 
    scanf("%d", &i); i--; // si riporta l'indice nell'intervallo 0..np-1
    if (i<0) 
      fine = 1;
    else
    {
      creaturaSposta(&cr,&punti_ammessi[i]);
      printf ("%s e' nel punto: ", cr.nome);
      puntoPrint(stdout,&punti_ammessi[i]); 
      printf("\n");
    }
  }
  
  printf("%s ha percorso la distanza: %f\n", cr.nome, cr.percorsoTotale);
  return 0;
}
