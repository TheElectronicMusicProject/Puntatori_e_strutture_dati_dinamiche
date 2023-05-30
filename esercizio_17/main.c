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
scriviStudenti (char * nomeFile, studente_t * el, int n)
{
	int i = 0;
    FILE * fp = fopen(nomeFile, "w");
    
    for (i = 0; i < n; ++i)
    {
        fprintf(fp, "%s %s %d %f\n", el[i].nome, el[i].cognome, el[i].matricola,
                el[i].media);
    }
    
    fclose(fp);
	
	return;
}	/* scriviStudenti() */

void
lavoroSuElencoOrdinato (studente_t * el, int n)
{
    return;
}   /* lavoroSuElencoOrdinato() */

static int
confrontaMatricola (studente_t s1, studente_t s2)
{
    return s1.matricola - s2.matricola;
}   /* confrontaMatricola() */

#if 0
void
ordinaStudentiPerMatricola (studente_t * el, int n)
{
    studente_t temp;
    int i = 0, j = 0, imin = 0;
    
    for (i = 0; i < n - 1; ++i)
    {
        imin = i;
        for (j = i + 1; j < n; ++j)
        {
            if (confrontaMatricola(el[j], el[imin]) < 0)
            {
                imin = j;
            }
        }
        
        temp = el[i];
        el[i] = el[imin];
        el[imin] = temp;
    }
    
	return;
}	/* ordinaStudentiPerMatricola() */
#endif

static int
confrontaMatricolaByRef (studente_t * ps1, studente_t * ps2)
{
    return ps1->matricola - ps2->matricola;
}   /* confrontaMatricolaByRef() */

void
ordinaStudentiPerMatricola (studente_t * el, int n)
{
    studente_t temp;
    int i = 0, j = 0, imin = 0;
    
    for (i = 0; i < n - 1; ++i)
    {
        imin = i;
        for (j = i + 1; j < n; ++j)
        {
            if (confrontaMatricolaByRef(&el[j], &el[imin]) < 0)
            {
                imin = j;
            }
        }
        
        temp = el[i];
        el[i] = el[imin];
        el[imin] = temp;
    }
    
	return;
}	/* ordinaStudentiPerMatricola() */

int
main (int argc, char * argv[])
{
	studente_t elenco[MAXN] = { 0 };
	int ns = leggiStudenti(argv[1], elenco, MAXN);
    ordinaStudentiPerMatricola(elenco, ns);
    lavoroSuElencoOrdinato(elenco, ns);
    scriviStudenti(argv[2], elenco, ns);
	
	return (0);
}	/* main() */

/*** End of file ***/
