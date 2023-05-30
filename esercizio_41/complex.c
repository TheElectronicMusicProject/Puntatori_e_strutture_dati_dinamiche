#include "complex.h"

struct complex_s
{
    float Re;
    float Im;
};

Complex
crea (float re, float im)
{
    Complex c = (Complex) malloc(sizeof *c);
    c->Re = re;
    c->Im = im;
    
    return c;
}   /* crea() */

void
distruggi (Complex c)
{
    free(c);
    return;
}   /* distruggi() */

Complex
prod (Complex c1, Complex c2)
{
    Complex c = crea();;
    c->Re = c1->Re * c2->Re - c1->Im * c2->Im;
    c->Im = c1->Re * c2->Im + c2->Re * c1->Im;

    return c;
}   /* prod() */

/*** End of file ***/
