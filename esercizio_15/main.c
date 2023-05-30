#include <stdio.h>
#include <string.h>

static void
ordinaMatrice (char m[][51], int n)
{
	int i = 0, j = 0, min = 0;
	char tmp[51] = { 0 };
	
	for (i = 0; i < n - 1; ++i)
	{
		min = i;
		for (j = i + 1; j < n; ++j)
		{
			if (strcmp(m[min], m[j]) > 0)
			{
				min = j;
			}
		}
		
		strcpy(tmp, m[i]);
		strcpy(m[i], m[min]);
		strcpy(m[min], tmp);
	}
	
	return;
}

static void
ordinaVettore (char * v[], int n)
{
	int i = 0, j = 0, min = 0;
	char * tmp = NULL;
	
	for (i = 0; i < n - 1; ++i)
	{
		min = i;
		for (j = i + 1; j < n; ++j)
		{
			printf("v[j] = %s\n", v[j]);
			if (strcmp(v[min], v[j]) > 0)
			{
				min = j;
			}
		}
		
		tmp = v[i];
		v[i] = v[min];
		v[min] = tmp;
	}
	
	return;
}

#if 0
int
main (int argc, char * argv[])
{
	int i, ns;
	char m[20][51] = { 0 };
	
	printf("Scrivi stringhe:\n");
	
	for (ns = 0; ns < 20; ++ns)
	{
		gets(m[ns]);
		if (strlen(m[ns]) == 0)
		{
			break;
		}
	}
	
	ordinaMatrice(m, ns);
	printf("stringhe ordinate:\n");
	
	for (i = 0; i < ns; ++i)
	{
		printf("%s\n", m[i]);
	}
	
	return (0);
}	/* main() */
#endif

#if 1
int
main (int argc, char * argv[])
{
	int i, ns;
	char * v[20], buf[520];
	
	printf("Scrivi stringhe:\n");
	
	for (ns = i = 0; ns < 20; ++ns)
	{
		v[ns] = buf + i;
		gets(v[ns]);
		if (strlen(v[ns]) == 0)
		{
			break;
		}
		i += strlen(v[ns]) + 1;
	}
	
	ordinaVettore(v, ns);
	printf("stringhe ordinate:\n");
	
	for (i = 0; i < ns; ++i)
	{
		printf("%s\n", v[i]);
	}
	
	return (0);
}	/* main() */
#endif

/*** End of file ***/
