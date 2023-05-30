#include <stdio.h>

int
main (void)
{
	int a[3] = {1, 9, 2};
	char b[5] = {'a', 'e', 'i', 'o', 'u'};
	int * p_a = &a[0];
	char * p_b = &b[0];
	
	printf("a[0] = *p_a = %d, p_a = %p\n", a[0], p_a);
	printf("a[0] = *p_a = %d, p_a = %p\n", a[1], p_a + 1);
	
	printf("b[0] = *p_b = %c, p_b = %p\n", b[0], p_b);
	printf("b[3] = *p_b = %c, p_b = %p\n", b[3], p_b + 3);
	
	return (0);
}	/* main() */