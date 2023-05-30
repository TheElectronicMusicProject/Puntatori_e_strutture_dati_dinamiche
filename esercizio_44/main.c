#include <stdio.h>
#include "item.h"

int
main (void)
{
    Item var1 = NULL;
    Item var2 = ITEMnew();
    
    var1 = ITEMscan1();
    ITEMscan2(var2);
    
    ITEMshow(var1);
    ITEMshow(var2);
    
    if (ITEMless(var1, var2) > 0)
    {
        printf("var1 < var2\n");
    }
    else
    {
        printf("var1 > var2\n");
    }
    
    ITEMfree(var1);
    ITEMfree(var2);
    
	return (0);
}	/* main() */

/*** End of file ***/
