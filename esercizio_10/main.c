#include <stdio.h>
#include <string.h>

char *
strstr0 (char s[], char c[])
{
	int i, lun_s, lun_c;
	
	lun_s = strlen(s);
	lun_c = strlen(c);
	
	for (i = 0; i < (lun_s - lun_c + 1); ++i)
	{
		if (0 == strncmp(s + i, c, lun_c))
		{
			return (&s[i]);
		}
	}
	
	return NULL;
}

int
main (void)
{
	char * stringa1 = "Amico caro come stai?";
	char * stringa2 = "sta7";
	
	if (strstr0(stringa1, stringa2) == NULL)
	{
		printf("Sottostringa non esistente\n");
	}
	else
	{
		printf("Sottostringa trovata\n");
	}
	
	return (0);
}	/* main() */

/*** End of file ***/
