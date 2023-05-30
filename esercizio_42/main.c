#include <stdio.h>
#include "complex.h"

int
main (void)
{
	Complex res;
    
    Complex var1 = {.Re = 2.3, .Im = 6.23};
    Complex var2 = {.Re = -4.1205, .Im = 8.6};
    
    res = prod(var1, var2);
    
    printf("(%f +i%f) x (%f + i%f) = %f + i%f\n", var1.Re, var1.Im, var2.Re,
           var2.Im, res.Re, res.Im); 
	
	return (0);
}	/* main() */

/*** End of file ***/
