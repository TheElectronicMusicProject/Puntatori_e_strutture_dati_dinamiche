#include <stdlib.h>
#include <stdio.h>

typedef struct {
  int X, Y;
} punto_t;

int main(void) {
  punto_t A, B;
  int fine=0;
  float lunghezza;

  while (!fine) {
    printf("coordinate primo   estremo: "); 
    scanf ("%d%d", &A.X, &A.Y);
    printf("coordinate secondo estremo: "); 
    scanf ("%d%d", &B.X, &B.Y);

    lunghezza = (B.X-A.X)*(B.X-A.X) + (B.Y-A.Y)*(B.Y-A.Y); 

    printf("Il segmento (%d,%d)-(%d,%d) ha lunghezza^2: %f\n", 
           A.X,A.Y,B.X,B.Y,lunghezza);

    fine = lunghezza==0;
  }
  return 0;
}
