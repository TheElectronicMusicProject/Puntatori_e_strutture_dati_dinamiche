#include <stdio.h>
#include <string.h>

#define MAXS		256
#define MAXN		200

typedef struct studente
{
	char cognome[MAXS];
	char nome[MAXN];
	int matricola;
	float media;
} studente_t;

int
leggiStudenti (char * nomeFile, studente_t * el, int nmax)
{
	int n = 0;
    FILE * fp = fopen(nomeFile, "r");
    
    for (n = 0; n < nmax; ++n)
    {
        if (fscanf(fp, "%s%s%d%f", el[n].nome, el[n].cognome, &el[n].matricola,
            &el[n].media) == EOF)
        {
            break;
        }
    }
    
    fclose(fp);
	
	return n;
}	/* leggiStudenti() */

void
scriviRifStudenti (char * nomeFile, studente_t ** el, int n)
{
	int i = 0;
    FILE * fp = fopen(nomeFile, "w");
    
    for (i = 0; i < n; ++i)
    {
        fprintf(fp, "%s %s %d %f\n", el[i]->nome, el[i]->cognome,
                el[i]->matricola, el[i]->media);
    }
    
    fclose(fp);
	
	return;
}	/* scriviRifStudenti() */

void
lavoroSuElencoRifOrdinato (studente_t * el[], int n)
{
    return;
}   /* lavoroSuElencoRifOrdinato() */

static int
confrontaMatricolaByRef (studente_t * ps1, studente_t * ps2)
{
    return ps1->matricola - ps2->matricola;
}   /* confrontaMatricolaByRef() */

void
ordinaRifStudentiPerMatricola (studente_t ** elR, int n)
{
    studente_t * temp;
    int i = 0, j = 0, imin = 0;
    
    for (i = 0; i < n - 1; ++i)
    {
        imin = i;
        for (j = i + 1; j < n; ++j)
        {
            if (confrontaMatricolaByRef(elR[j], elR[imin]) < 0)
            {
                imin = j;
            }
        }
        
        temp = elR[i];
        elR[i] = elR[imin];
        elR[imin] = temp;
    }
    
	return;
}	/* ordinaRifStudentiPerMatricola() */

int
main (int argc, char * argv[])
{
	studente_t elenco[MAXN] = { 0 };
    studente_t * elencoRif[MAXN];
    int i = 0;
	int ns = leggiStudenti(argv[1], elenco, MAXN);
    
    for (i = 0; i < ns; ++i)
    {
        elencoRif[i] = &elenco[i];
    }
    
    ordinaRifStudentiPerMatricola(elencoRif, ns);
    lavoroSuElencoRifOrdinato(elencoRif, ns);
    scriviRifStudenti(argv[2], elencoRif, ns);
	
	return (0);
}	/* main() */

/*** End of file ***/
