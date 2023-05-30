#include <stdio.h>
#include <string.h>

#define NR	6
#define NC	5

int
main (void)
{
	float R0[NC], R1[NC], R2[NC], R3[NC], R4[NC], R5[NC];
	float * VP[NR] = {R0, R1, R2, R3, R4, R5};
	int idxr = 0;
	int idxc = 0;
	float dato = 1.23;
	
	for (idxr = 0; idxr < NR; ++idxr)
	{
		for (idxc = 0; idxc < NC; ++idxc)
		{
			VP[idxr][idxc] = dato;
			++dato;
		}
	}
	
	printf("Dimensione matrice: %d\n", sizeof(VP));
	printf("Dimensione riga: %d\n", sizeof(VP[0]));
	printf("Dimensione elemento: %d\n", sizeof(VP[0][0]));
	
	return (0);
}	/* main() */

/*** End of file ***/
