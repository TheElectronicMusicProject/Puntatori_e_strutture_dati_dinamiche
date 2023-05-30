#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX		20
#define ERR_ATTACK

struct stud
{
	char cognome[MAX];
	char nome[MAX];
	int matricola;
};

struct stud * p_stud = NULL;

int
main ()
{
    struct stud * p_vet = NULL;
	p_stud = (struct stud *) malloc(sizeof(struct stud));
    p_stud = malloc(sizeof(*p_stud));
    p_stud = malloc(sizeof *p_stud);
    p_vet = (struct stud *) malloc(128 * sizeof(struct stud));
    
#ifdef ERR_DIM
    double * pd = NULL;
    struct stud * ps;
    struct stud * v;
    int n = 10;
    
    /* Tipo errato */
    pd = malloc(sizeof(int));
    /* Tipo errato (con cast si vede meglio l'errore) */
    pd = (double *) malloc(sizeof(int));
    /* Alloca spazio per un puntatore */
    ps = (struct stud *) malloc(sizeof(struct stud *));
    /* In realtà si voleva (n * sizeof *v) */
    v = malloc(sizeof *v);
    /* Si ha n ma non la dimensione del tipo base */
    v = (struct stud *) malloc(n);
#elif defined(ERR_POINT)
    struct stud ** ps;
    int * pi;
    
    /* Tipo errato */
    ps = malloc(sizeof(struct stud));
    /* Tipo errato (errore) */
    ps = (struct stud *) malloc(sizeof(struct stud));
    /* Variabile errata */
    pi = malloc(sizeof(struct stud));
    /* Variabile errata (errore) */
    pi = (struct stud *) malloc(sizeof(struct stud));
#elif defined(ERR_OVERFLOW)
    char buf[8] = { 0 };
    gets(buf);
    printf("%s\n", buf);
#elif defined(ERR_ATTACK)
    char buffer[15] = { 0 };
    int accesso = 0;
    printf("Inserire la password: \n");
    gets(buffer);
    if (strcmp(buffer, "password"))
    {
        printf("Errore!\n");
    }
    else
    {
        printf("OK\n");
        accesso = 1;
    }
    
    if (accesso)
    {
        printf("Accesso avvenuto con successo...\n");
    }
#endif
	
	return (0);
}	/* main() */

/*** End of file ***/
