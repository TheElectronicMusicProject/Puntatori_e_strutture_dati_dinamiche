#include <stdio.h>
#include <string.h>

#define MAX		20

struct esame
{
    int scritto;
    int orale;
};

struct studente
{
	char cognome[MAX];
	char nome[MAX];
	int matricola;
	int crediti;
	float media;
    struct esame * es;
};

struct studente
leggiStudente (struct esame * voti)
{
	struct studente s;
	
	printf("Inserire nome e cognome: ");
	scanf("%s %s", s.cognome, s.nome);
	printf("Inserire matricola e crediti: ");
	scanf("%d %d", &s.matricola, &s.crediti);
	printf("Inserire la media: ");
	scanf("%f", &s.media);
    printf("Inserire voto scritto e orale: ");
	scanf("%d %d", &(voti->scritto), &(voti->orale));
    
    s.es = voti;
	
	return s;
}	/* leggiStudente() */

void
stampaStudente (struct studente studente)
{
	printf("%s, %s, %d, %d, %f; %d %d\n", studente.cognome, studente.nome,
		   studente.matricola, studente.crediti, studente.media,
           studente.es->scritto, studente.es->orale);
	
	return;
}	/* stampaStudente() */

void
ordinaStudenti (struct studente dati_stud[], int num)
{
    struct studente tmp;
    int i = 0, j = 0, min = 0;
    
    for (i = 0; i < num - 1; ++i)
    {
        min = i;
        for (j = i + 1; j < num; ++j)
        {
            if (dati_stud[min].media > dati_stud[j].media)
            {
                min = j;
            }
        }
        
        tmp = dati_stud[i];
        dati_stud[i] = dati_stud[min];
        dati_stud[min] = tmp;
    }
    
	return;
}	/* ordinaStudenti() */

int
main (int argc, char * argv[])
{
#if 0
	struct studente s, t;
	
	printf("Inserire nome e cognome: ");
	scanf("%s %s", s.cognome, s.nome);
	printf("Inserire matricola e crediti: ");
	scanf("%d %d", &s.matricola, &s.crediti);
	printf("Inserire la media: ");
	scanf("%f", &s.media);
	
	printf("%s, %s, %d, %d, %f", s.cognome, s.nome, s.matricola, s.crediti,
		   s.media);
#endif
	struct studente elenco[MAX];
    struct esame es_elenco[MAX];
	int i, n;
	
	printf("quanti studenti(max %d)?", MAX);
	scanf("%d", &n);
	
	for (i = 0; i < n; ++i)
	{
		elenco[i] = leggiStudente(&es_elenco[i]);
	}
	
	ordinaStudenti(elenco, n);
	
	for (i = 0; i < n; ++i)
	{
		stampaStudente(elenco[i]);
	}
	
	return (0);
}	/* main() */

/*** End of file ***/
