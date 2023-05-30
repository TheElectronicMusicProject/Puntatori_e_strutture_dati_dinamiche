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
    int id_next;        // -1 elemento nullo
} canzone_t;

typedef struct cantante_s
{
    char * nome;
    int id_testa;
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
    
    for (i = 0; i < n_canzoni; ++i)
    {
        canzoni[i].id_next = -1;
    }
    
    for (i = 0; i < n_cantanti; ++i)
    {
        cantanti[i].id_testa = -1;
    }
    
    for (i = 0; i < n_canzoni; ++i)
    {
        if (canzoni[i].id_next == -1)
        {
            id_c = canzoni[i].id_cantante;
            
            if (cantanti[id_c].id_testa == -1)
            {
                cantanti[id_c].id_testa = i;
                //printf("cantante %d ha testa %d\n", id_c, i);
            }
            else
            {
                canzoni[i].id_next = cantanti[id_c].id_testa;
                cantanti[id_c].id_testa = i;
                //printf("cantante %d ha nuova testa %d\n", id_c, i);
                //printf("canzone %d ha successivo %d\n\n", id_c, canzoni[id_c].id_next);
            }
        }
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
        for (x = cantanti[i].id_testa; x != -1; x = canzoni[x].id_next)
        {
            printf("%s\n", canzoni[x].titolo);
        }
    }
    
    return;
}

/*** End of file ***/
