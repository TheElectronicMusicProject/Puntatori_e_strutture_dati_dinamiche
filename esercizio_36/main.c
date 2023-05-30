#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* Contenuto del nodo */
typedef char Item;
/* Chiave (altro contenuto del nodo, dove si opera) */
typedef int Key;

typedef struct canzone_s
{
    char * titolo;
    int id_cantante;
} canzone_t;

typedef struct cantante_s
{
    char * nome;
    int * lista;
    int n_canzoni;
} cantante_t;

void stampaElenchi(cantante_t * cantanti, int n_cantanti, canzone_t * canzoni);
void generaElenchi(cantante_t * cantanti, int n_cantanti, canzone_t * canzoni,
                   int n_canzoni);

int
main (void)
{
    canzone_t bello[5];
    cantante_t cantanti[3];

    cantanti[0].nome = "Giulio";
    cantanti[1].nome = "Grazio";
    cantanti[2].nome = "pesta";
    
    bello[0].titolo = "Ciao";
    bello[0].id_cantante = 1;
    
    bello[1].titolo = "Canzone di Giulio";
    bello[1].id_cantante = 0;
    
    bello[2].titolo = "Grande ciao";
    bello[2].id_cantante = 2;
    
    bello[3].titolo = "Amicoane";
    bello[3].id_cantante = 1;
    
    bello[4].titolo = "Bella fratella";
    bello[4].id_cantante = 1;
    
    
    generaElenchi(cantanti, 3, bello, 5);
    
    stampaElenchi(cantanti, 3, bello);
    
	return (0);
}	/* main() */

void
generaElenchi (cantante_t * cantanti, int n_cantanti, canzone_t * canzoni,
               int n_canzoni)
{
    int i, id_c;
    
    
    for (i = 0; i < n_cantanti; ++i)
    {
        cantanti[i].n_canzoni = 0;
    }
    
    for (i = 0; i < n_canzoni; ++i)
    {
        cantanti[canzoni[i].id_cantante].n_canzoni++;
    }
    
    for (i = 0; i < n_cantanti; ++i)
    {
        cantanti[i].lista = malloc(cantanti[i].n_canzoni * sizeof(int));
        
        if(cantanti[i].lista == NULL)
        {
            exit(-1);
        }
        
        cantanti[i].n_canzoni = 0;
    }
    
    for (i = 0; i < n_canzoni; ++i)
    {
        id_c = canzoni[i].id_cantante;
        cantanti[id_c].lista[cantanti[id_c].n_canzoni] = i;
        cantanti[id_c].n_canzoni++;
    }
}

void
stampaElenchi (cantante_t * cantanti, int n_cantanti, canzone_t * canzoni)
{
    int x;
    int i = 0;
    
    for (i = 0; i < n_cantanti; ++i)
    {
        printf("canzoni del cantante %s\n", cantanti[i].nome);
        for (x = 0; x < cantanti[i].n_canzoni; x++)
        {
            printf("%s\n", canzoni[cantanti[i].lista[x]].titolo);
        }
    }
    
    return;
}

/*** End of file ***/
