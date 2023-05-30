#include <stdio.h>
#include <stdlib.h>

typedef float Item;

Item ** malloc2dR(int nr, int nc);
void malloc2dP(Item *** mp, int nr, int nc);
void free2d(Item ** m, int nr);

int
main ()
{
	Item ** matr = NULL;
    int nr, nc, i, j;
    
    printf("Dimensioni (NR NC): ");
    scanf("%d%d", &nr, &nc);
    
#if 0
    matr = malloc2dR(nr, nc);
#else
    malloc2dP(&matr, nr, nc);
#endif
    
    if (matr == NULL)
    {
        exit(1);
    }
    
    /* input */
    for (i = 0; i < nr; ++i)
    {
        printf("Inserisci riga %d\n", i);
        
        if (matr[i] == NULL)
            exit(1);
        
        for (j = 0; j < nc; ++j)
        {
            scanf("%f", &(matr[i][j]));
        }
    }
    
    /* output */
    printf("Matrice trasposta\n");
    for (j = 0; j < nc; ++j)
    {
        for (i = 0; i < nr; ++i)
        {
            printf("%6.2f", matr[i][j]);
        }
        
        printf("\n");
    }
    
    free2d(matr, nr);
    
	return (0);
}	/* main() */

Item **
malloc2dR (int nr, int nc)
{
    Item ** m = NULL;
    int i = 0;
    
    m = (Item **) malloc(nr * sizeof(Item *));
    
    for (i = 0; i < nr; ++i)
    {
        m[i] = (Item *) malloc(nc * sizeof(Item));
    }
    
    return m;
}   /* malloc2dR() */

void
malloc2dP (Item *** mp, int nr, int nc)
{
    Item ** m = NULL;
    int i = 0;
    
    m = (Item **) malloc(nr * sizeof(Item *));
    
    for (i = 0; i < nr; ++i)
    {
        m[i] = (Item *) malloc(nc * sizeof(Item));
    }
    
    *mp = m;
    
    return;
}   /* malloc2dP() */

void
free2d (Item ** m, int nr)
{
    int i = 0;
    
    for (i = 0; i < nr; ++i)
    {
        free(m[i]);
    }
    free(m);
    
    return;
}   /* free2d() */

/*** End of file ***/
