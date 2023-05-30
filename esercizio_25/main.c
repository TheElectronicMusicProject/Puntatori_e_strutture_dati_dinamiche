#include <stdio.h>
#include <stdlib.h>

int
main ()
{
    float * v = NULL;
    int nr, nc, i, j;
    
    printf("Dimensioni (NR NC): ");
    scanf("%d%d", &nr, &nc);
   
    v = malloc(nr * nc * sizeof(float));
    
    if (v == NULL)
    {
        exit(1);
    }
    
    /* input */
    for (i = 0; i < nr; ++i)
    {
        printf("Inserisci riga %d\n", i);
        for (j = 0; j < nc; ++j)
        {
            scanf("%f", &v[nc * i + j]);
        }
    }
    
    /* output */
    printf("Matrice trasposta\n");
    for (j = 0; j < nc; ++j)
    {
        for (i = 0; i < nr; ++i)
        {
            printf("%6.2f", v[nc * i + j]);
        }
        
        printf("\n");
    }
    
    /* libera memoria dinamica */
    free(v);
	
	return (0);
}	/* main() */

/*** End of file ***/
