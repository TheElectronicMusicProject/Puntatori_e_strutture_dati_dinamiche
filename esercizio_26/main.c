#include <stdio.h>
#include <stdlib.h>

int
main ()
{
    float ** v = NULL;
    int nr, nc, i, j;
    
    printf("Dimensioni (NR NC): ");
    scanf("%d%d", &nr, &nc);
   
    v = (float **) malloc(nr * sizeof(float *));
    
    if (v == NULL)
    {
        exit(1);
    }
    
    /* input */
    for (i = 0; i < nr; ++i)
    {
        printf("Inserisci riga %d\n", i);
        v[i] = malloc(nc * sizeof(float));
        
        if (v[i] == NULL)
            exit(1);
        
        for (j = 0; j < nc; ++j)
        {
            scanf("%f", &(v[i][j]));
        }
    }
    
    /* output */
    printf("Matrice trasposta\n");
    for (j = 0; j < nc; ++j)
    {
        for (i = 0; i < nr; ++i)
        {
            printf("%6.2f", v[i][j]);
        }
        
        printf("\n");
    }
    
    /* libera memoria dinamica */
    for (i = 0; i < nr; ++i)
    {
        free(v[i]);
    }
    free(v);
	
	return (0);
}	/* main() */

/*** End of file ***/
