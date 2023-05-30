#include <stdio.h>
#include <stdlib.h>

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
scriviIndiciStudenti (char * nomeFile, studente_t * el, int *elI, int n)
{
	int i = 0;
    FILE * fp = fopen(nomeFile, "w");
    
    for (i = 0; i < n; ++i)
    {
        fprintf(fp, "%s %s %d %f\n", el[elI[i]].nome, el[elI[i]].cognome,
                el[elI[i]].matricola, el[elI[i]].media);
    }
    
    fclose(fp);
	
	return;
}	/* scriviIndiciStudenti() */

static int
confrontaMatricolaPerIndice (studente_t * el, int id1, int id2)
{
    return el[id1].matricola - el[id2].matricola;
}   /* confrontaMatricolaPerIndice() */

void
ordinaIndiciStudentiPerMatricola (studente_t * el, int * elI, int n)
{
    int i, j, imin, temp;
    
    for (i = 0; i < n - 1; ++i)
    {
        imin = i;
        for (j = i + 1; j < n; ++j)
        {
            if (confrontaMatricolaPerIndice(el, elI[j], elI[imin]) < 0)
            {
                imin = j;
            }
        }
        
        temp = elI[i];
        elI[i] = elI[imin];
        elI[imin] = temp;
    }
    
    return;
}   /* ordinaIndiciStudentiPerMatricola() */

int
filtraPerMediaConIndici (studente_t * el, int * elI, int n, float s)
{
    int n2, i;
    
    for (i = n2 = 0; i < n; ++i)
    {
        if (el[elI[i]].media >= s)
        {
            elI[n2++] = i;
        }
    }
    
    return n2;
}   /* filtraPerMediaConIndici() */

int
main (int argc, char * argv[])
{
	studente_t elenco[MAXN];
    int elencoIndici[MAXN], filtraIndici[MAXN];
    int i, ns, ns2;
    float soglia = atof(argv[4]);
    
    ns = leggiStudenti(argv[1], elenco, MAXN);
    for (i = 0; i < ns; ++i)
    {
        elencoIndici[i] = filtraIndici[i] = i;
    }
    
    ordinaIndiciStudentiPerMatricola(elenco, elencoIndici, ns);
    ns2 = filtraPerMediaConIndici(elenco, filtraIndici, ns, soglia);
    scriviIndiciStudenti(argv[2], elenco, elencoIndici, ns);
    scriviIndiciStudenti(argv[3], elenco, filtraIndici, ns2);
	
	return (0);
}	/* main() */

/*** End of file ***/
