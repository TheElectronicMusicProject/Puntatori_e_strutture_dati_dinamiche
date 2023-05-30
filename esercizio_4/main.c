#include <stdio.h>

int
main (void)
{
	int l = 1;
	int r = 4;
	int dati[6] = { 0 };
	int * p_v = NULL;
	int n = r - l;
	
	p_v = &dati[l];
	
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", p_v + i);
	}
	
	for (int i = 0; i < n; ++i)
	{
		printf("%d", *(p_v + i));
	}
	
	return (0);
}	/* main() */

/*** End of file ***/
