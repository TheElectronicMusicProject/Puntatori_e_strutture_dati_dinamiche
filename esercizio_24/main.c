#include <stdio.h>
#include <stdlib.h>

int
main ()
{
    float * v = NULL;
    int N = 1, i = 0;
    float d = 0;

#if 0
    /* allocazione iniziale */
    v = malloc(N * sizeof(float));
    /* input */
    printf("Inserisci elementi\n");
    printf("Elemento 0: ");
    
    while(scanf("%f", &d) > 0)
    {
        if (i == N)
        {
            N = N + 1;
            v = realloc(v, N * sizeof(float));
        }
        v[i++] = d;
        printf("Elemento %d: ", i);
    }
#endif

    int MAXN = 1;
    
    /* allocazione iniziale */
    v = malloc(MAXN * sizeof(float));
    /* input */
    printf("Inserisci elementi\n");
    printf("Elemento 0: ");
    
    while(scanf("%f", &d) > 0)
    {
        if (i == MAXN)
        {
            MAXN *= 2;
            v = realloc(v, MAXN * sizeof(float));
        }
        v[i++] = d;
        printf("Elemento %d: ", i);
    }
    
    N = i;
    
    printf("FINE");
	
	return (0);
}	/* main() */

/*** End of file ***/
