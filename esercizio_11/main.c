#include <stdio.h>
#include <string.h>

#define MAX	100

int
main (void)
{
	int i, x, cnt = 0;
	float somma = 0.0;
	char riga[MAX] = { 0 }, * s = NULL;
	
	fgets(riga, MAX, stdin);
	s = riga;
	
	while (sscanf(s, "%d%n", &x, &i) > 0)
	{
		s = s + i;
		somma += x;
		cnt++;
	}
	
	printf("La media e': %f\n", somma/cnt);
	
	return (0);
}	/* main() */

/*** End of file ***/
