#include <stdlib.h>
#include <stdio.h>
#include <math.h>



int myexp(double * a,  size_t dim)
{
  int i;  

  for( i = 0; i < dim; i++ ){
    a[i] = exp( a[i] * i );
  }
  return 0;
}


int mysqrt(double * a,  size_t dim)
{
  int i;  
  for( i = 0; i < dim; i++ ){
    
    a[i] = sqrt( a[i] * i );
  }
  return 0;
}

int mysin(double * a,  size_t dim)
{
  int i;  
  for( i = 0; i < dim; i++ ){
    
    a[i] = sin( a[i] * i );
  }
  return 0;
}


int main( int argc, char * argv[] )
{

  double * a, * b, * c;
  double alpha;

  int i;
  
  size_t dim;
  
  if(argc<2)
  {
    printf( "please give me at least 1 parameter\n");
    return 0;
  }
  dim = atoi(argv[1]);
 
  a = (double *) malloc( dim * sizeof( double ) );
  b = (double *) malloc( dim * sizeof( double ) );
  c = (double *) malloc( dim * sizeof( double ) );

  for( i = 0; i < dim; i++ ){

    a[i] = 1.0;
    b[i] = 2.0;
    c[i] = 3.0;
  }

  myexp(a,dim);
  mysqrt(a,dim);
  mysin(a,dim);

  alpha = 0.0;
  for( i = 0; i < dim; i++ ){
    alpha += a[i] + b[i] + c[i];
  }


//  for( i = 0; i < dim; i++ ){
 //      printf( "%d\t%g\t%g\t%g\n", i,a[i],b[i],c[i]);
//  }

  printf( "%e", alpha );

  free( a );
  free( b );
  free( c );

  return 0;
}
    
