#include <stdio.h>
#include <stdlib.h>

int
main ()
{
    float * v = NULL;
    int N, i;
    
    printf("Quanti elementi vuoi inserire?\n");
    scanf("%d", &N);
    
    /* Alloca il vettore */
    v = malloc(N * sizeof(float));
    
    if (v == NULL)
    {
        exit(1);
    }
    
    /* Input */
    printf("Inserisci %d elementi\n", N);
    
    for (i = 0; i < N; ++i)
    {
        printf("Elemento %d: ", i);
        scanf("%f", &v[i]);
    }
    
    /* Output */
    printf("Dati in ordine inverso\n");
    
    for (i = N - 1; i >= 0; --i)
    {
        printf("Elemento %d: %f\n", i, v[i]);
    }
    
    /* Libera memoria dinamica */
    free(v);
	
	return (0);
}	/* main() */

/*** End of file ***/
