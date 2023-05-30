#include <stdio.h>

int
main (void)
{
    int tail = 0;
    
    for (int i = 0; i < 10; ++i)
    {
        printf("tail = %d, valore di resto %d\n", tail, tail % 6);
        ++tail;
    }
    
	return (0);
}	/* main() */

/*** End of file ***/
