#include <stdio.h>

void
inverti (int N)
{
    int i = 0;
    float v[N];
    
    printf("Inserisci da tastiera %d elementi\n", N);
    
    for (i = 0; i < N; ++i)
    {
        printf("Elemento %d: ", i);
        scanf("%f", &v[i]);
    }
    
    printf("Dati in ordine inverso\n");
    
    for (i = N - 1; i >= 0; --i)
    {
        printf("Elemento %d: %f\n", i, v[i]);
    }
    
    return;
}

int
main (void)
{
    inverti(4);
	return (0);
}	/* main() */

/*** End of file ***/
