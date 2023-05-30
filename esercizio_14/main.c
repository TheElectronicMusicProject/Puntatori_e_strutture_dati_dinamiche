#include <stdio.h>
#include <string.h>

#define NR	6
#define NC	5

int
main (int argc, char * argv[])
{
	int i, g;
#if 0
	char giorni[7][10] = {"lunedi", "martedi", "mercoledi", "giovedi", "venerdi", "sabato", "domenica"};
#endif
	char * giorni[7] = {"lunedi", "martedi", "mercoledi", "giovedi", "venerdi", "sabato", "domenica"};
	
	printf("Quale carattere da 1 a 9?");
	scanf("%d", &i);
	
	for (g = 0; g < 7; ++g)
	{
		if (i <= strlen(giorni[g]))
		{
			printf("%c", giorni[g][i - 1]);
		}
		else
		{
			printf("_ ");
		}
	}
	
	printf("\n");
	
	return (0);
}	/* main() */

/*** End of file ***/
