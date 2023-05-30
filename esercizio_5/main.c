#include <stdio.h>

#define NR	4
#define NC	3

int
main (void)
{
	float M[NR][NC] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1.1, 1.5, 5.6}};
	float V[NC] = {0, 1, 2};
	float Prod[NR] = { 0 };
	int r = 0;
	int c = 0;
	
#if 0
	for (r = 0; r < NR; r++)
	{
		Prod[r] = 0.0;
		
		for (c = 0; c < NC; c++)
		{
			Prod[r] = Prod[r] + M[r][c] * V[c];
		}
		
		printf("Prod[%d] = %f\n", r, Prod[r]);
	}
#else
	float * p_riga = NULL;

	for (r = 0; r < NR; r++)
	{
		Prod[r] = 0.0;
		p_riga = M[r];
		
		for (c = 0; c < NC; c++)
		{
			Prod[r] = Prod[r] + p_riga[c] * V[c];
		}
		
		printf("Prod[%d] = %f\n", r, Prod[r]);
	}
#endif
	
	return (0);
}	/* main() */

/*** End of file ***/
