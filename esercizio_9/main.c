#include <stdio.h>

int
strcmp0 (char s0[], char s1[])
{
	int i = 0;
	
	while ((s0[i] == s1[i]) && (s0[i] != '\0'))
	{
		++i;
	}
	
	return (s0[i] - s1[i]);
}

int
strcmp1 (char * s0, char * s1)
{
	while ((*s0 == *s1) && (*s0 != '\0'))
	{
		++s0;
		++s1;
	}
	
	return (*s0 - *s1);
}

int
strncmp0 (char s0[], char s1[], int n)
{
	int i = 0;
	
	while ((s0[i] == s1[i]) && (s0[i] != '\0'))
	{
		if (i < n)
		{
			++i;
		}
		else
		{
			return 0;
		}
	}
	
	return (s0[i] - s1[i]);
}

int
strncmp1 (char * s0, char * s1, int n)
{
	char * p = s0;
	
	while ((*s0 == *s1) && (*s0 != '\0'))
	{
		if ((s0 - p) < n)
		{
			++s0;
			++s1;
		}
		else
		{
			return 0;
		}
	}
	
	return (*s0 - *s1);
}

int
main (void)
{
	char * stringa1 = "Amico caro come stai?";
	char * stringa2 = "Amico caro come stai?";
	
	printf("caso 1 e' %d\n", strcmp0(stringa1, stringa2));
	printf("caso 2 e' %d\n", strncmp0(stringa1, stringa2, 5));
	printf("caso 3 e' %d\n", strcmp1(stringa1, stringa2));
	printf("caso 4 e' %d\n", strncmp1(stringa1, stringa2, 5));
	
	return (0);
}	/* main() */

/*** End of file ***/
