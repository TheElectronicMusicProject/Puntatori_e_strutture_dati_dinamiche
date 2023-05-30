#include <stdio.h>

#define MAX		100

static int leggi(int v[], int maxdim);
static void scrivi(int * v, int n);

int
main (void)
{
	int n = 0, dati[MAX] = { 0 };
	n = leggi(dati, MAX);
	scrivi(dati, n);
	
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

static void
scrivi (int * v, int n)
{
	int i = 0;
	
	for (i = 0; i < n; ++i)
	{
		printf("v[%d]: %d\n", i, v[i]);
	}
	
	return;
}

/*** End of file ***/
