#include <stdio.h>

#define DIM1	100
#define DIM2	20

static int leggi(int v[], int maxdim);

int
main (void)
{
	int v1[DIM1] = { 0 };
	int v2[DIM2] = { 0 };
	
	int n1, n2;
	
	n1 = leggi(v1, DIM1);
	n2 = leggi(v2, DIM2);
	
	for (int i = 0; i < n1; i++)
	{
		printf("%d", *(v1 + i));
	}
	
	printf("\n\n");
	
	for (int i = 0; i < n2; i++)
	{
		printf("%d", *(v2 + i));
	}
	
	return (0);
}	/* main() */

static int
leggi (int v[], int maxdim)
{
	int i = 0;
	int fine = 0;
	
	for (i = 0; !fine && i < maxdim; ++i)
	{
		printf("v[%d] (0 per terminare): ", i);
		scanf("%d", &v[i]);
		if (0 == v[i])
		{
			fine = 1;
			i--;
		}
	}
	
	return i;
}

/*** End of file ***/
