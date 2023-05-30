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
    struct canzone_s * next;
} canzone_t;

typedef struct cantante_s
{
    char * nome;
    struct canzone_s * head;
} cantante_t;

void stampaElenchi(cantante_t * cantanti, int n_cantanti);
void generaElenchi(cantante_t * cantanti, int n_cantanti, canzone_t * canzoni,
                   int n_canzoni);

int
main (void)
{
    canzone_t bello[3];
    cantante_t cantanti[3];

    cantanti[0].nome = "Giulio";
    cantanti[1].nome = "Grazio";
    cantanti[2].nome = "pesta";
    
    bello[0].titolo = "Ciao";
    bello[0].id_cantante = 1;
    
    bello[1].titolo = "Grande ciao";
    bello[1].id_cantante = 2;
    
    bello[2].titolo = "Amicoane";
    bello[2].id_cantante = 1;
    
    generaElenchi(cantanti, 3, bello, 3);
    
    stampaElenchi(cantanti, 3);
    
	return (0);
}	/* main() */

void
generaElenchi (cantante_t * cantanti, int n_cantanti, canzone_t * canzoni,
               int n_canzoni)
{
    int i, id_c;
    //nodo_t * nuovo_nodo = NULL;
    
    for (i = 0; i < n_cantanti; ++i)
    {
        cantanti[i].head = NULL;
    }
    
    for (i = 0; i < n_canzoni; ++i)
    {
        id_c = canzoni[i].id_cantante;
        canzoni[i].next = cantanti[id_c].head;
        cantanti[id_c].head = &canzoni[i];
    }
}

void
stampaElenchi (cantante_t * cantanti, int n_cantanti)
{
    canzone_t * x;
    int i = 0;
    
    for (i = 0; i < n_cantanti; ++i)
    {
        printf("canzoni del cantante %s\n", cantanti[i].nome);
        for (x = cantanti[i].head; x != NULL; x = x->next)
        {
            printf("%s\n", x->titolo);
        }
    }
    
    return;
}

/*** End of file ***/
