#include <stdio.h>

int
strlen0 (char s[])
{
	int cnt = 0;
	
	while (s[cnt] != '\0')
	{
		++cnt;
	}
	
	return cnt;
}

int
strlen1 (char s[])
{
	int cnt = 0;
	char * p = &s[0];
	
	while (*p != '\0')
	{
		++cnt;
		++p;
	}
	
	return cnt;
}

int
strlen2 (char * s)
{
	int cnt = 0;
	
	while (*s++ != '\0')
	{
		++cnt;
	}
	
	return cnt;
}

int
strlen3 (char * s)
{
	char * p = s;
	
	while (*p++ != '\0')
	{
		/* Attesa del terminatore */
	}
	
	return (p - s - 1);
}

int
main (void)
{
	char * stringa = "Amico caro come stai?";
	
	printf("con strlen0 e' %d\n", strlen0(stringa));
	printf("con strlen1 e' %d\n", strlen1(stringa));
	printf("con strlen2 e' %d\n", strlen2(stringa));
	printf("con strlen3 e' %d\n", strlen3(stringa));
	
	return (0);
}	/* main() */

/*** End of file ***/
