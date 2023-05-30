#include <stdio.h>

int
main (void)
{
	int n = 41223;
	int * p = NULL;
	
	printf("indirizzo di n: %p\n", &n);
	printf("contenuto di n: %d\n", n);
	printf("inserire nuovo valore di n: ");
	scanf("%d", &n);
	printf("ho letto: %d\n", n);

	p = &n;
	printf("indirizzo di n (come dato puntato da p) = %p\n", p);
	printf("contenuto di n (come dato puntato da p) = %d\n", *p);
	printf("inserire nuovo valore di n (come dato puntato da p): ");
	scanf("%d", p);
	printf("ho letto: %d\n", *p);
	
	printf("indirizzo di p = %p\n", &p);
	
	return (0);
}	/* main() */