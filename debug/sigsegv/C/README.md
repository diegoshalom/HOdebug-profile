#valgrind

Lo que sucede es que estaba alocando varias veces, y no estaba liberando. 
Hace falta agregar free(a) adentro del loop, para que se vaya liberando lo que se va alocando.


  for(i=0; i<last; i++)
    {
      mysub(&a, mydim);
	  printf("a = %f \n", a[0]);
      free(a);
    }
