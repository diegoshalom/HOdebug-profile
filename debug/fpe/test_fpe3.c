#include <stdlib.h>
#include <stdio.h>
#ifdef TRAPFPE
#include "fpe_x87_sse.h"
#endif
#include <math.h>

int main(int argc, char *argv[])
{
  float a, b, c, tmp;

#ifdef TRAPFPE
  set_fpe_x87_sse_();
#endif

  printf("Insert a, b \n");
  scanf("%f",&a);
  scanf("%f",&b);

  tmp = sqrtf(a / b);
  
  if(tmp > 2.)
    {
      c = +1.;
    }
  else
    {
      c = -1.;
    }

  printf("c = %f \n", c);
  printf("tmp = %f \n", tmp);

  
  return(EXIT_SUCCESS);
}
