#include <stdio.h>
#include <string.h>

#define NR	4
#define NC	5

int
main (void)
{
	float M[NR][NC] = { 0 };
	int idxr = 0;
	int idxc = 0;
	float dato = 1.23;
	
	for (idxr = 0; idxr < NR; ++idxr)
	{
		for (idxc = 0; idxc < NC; ++idxc)
		{
			M[idxr][idxc] = dato;
			++dato;
		}
	}
	
	printf("Dimensione matrice: %d\n", sizeof(M));
	printf("Dimensione riga: %d\n", sizeof(M[0]));
	printf("Dimensione elemento: %d\n", sizeof(M[0][0]));
	
	return (0);
}	/* main() */

/*** End of file ***/
