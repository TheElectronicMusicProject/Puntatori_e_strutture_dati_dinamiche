#include <stdio.h>

static void
swap1 (int x, int y)
{
	printf("x = %d \t y = %d\n", x, y);
	int tmp = 0;
	
	tmp = x;
	x = y;
	y = tmp;
	
	printf("x = %d \t y = %d\n", x, y);
	
	return;
}	/* swap1() */

static void
swap2 (int * px, int * py)
{
	printf("px = %d \t py = %d\n", *px, *py);
	int tmp = 0;
	
	tmp = *px;
	*px = *py;
	*py = tmp;
	
	printf("px = %d \t py = %d\n", *px, *py);
	
	return;
}	/* swap2() */

static void
sum (int a, int b, int * pc)
{
	*pc = a + b;
	
	return;
}	/* sum() */

int
main (void)
{
	int par1 = 2;
	int par2 = 3;
	int result = 0;
	
	swap2(&par1, &par2);
	
	printf("par1 = %d \t par2 = %d\n", par1, par2);
	
	sum(par1, par2, &result);
	
	printf("%d + %d = %d\n", par1, par2, result);
	
	return (0);
}	/* main() */

/*** End of file ***/
