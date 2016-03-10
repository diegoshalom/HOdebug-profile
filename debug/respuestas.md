#FPE
##¿Qué función requiere agregar -DTRAPFPE? ¿Cómo pueden hacer que el programa linkee adecuadamente?

Agregar -DTRAPFPE define la macro TRAPFPE, que es leida por el preprocesador. Al estar definida, podemos cambiar que algunas cosas esten definidas o no (#ifdef), en el header y en el main.

La funcion set_fpe_x87_sse_() dice que active mensajes de error o chequeos de error por Overfloat, divide by zero y valor invalido.

Para que linkee adecuadamente, hay que agregar #include <math.h> y compilar con: 
	gcc -lm  test_fpe3.c ./fpe_x87_sse/fpe_x87_sse.c -o test_fpe3b.e -DTRAPFPE -I./fpe_x87_sse



##Para cada uno de los ejecutables, ¿qué hace agregar la opción -DTRAPFPE al compilar? ¿En qué se diferencian los mensajes de salida con y sin esa opción?

Al no tener activada esta opcion, opera "normalmente" si divido por cero o si los numeros son mas grandes que lo aceptable (inf y overflow).
Al tener la opcion activada, salta un error al detectar una de estas operaciones raras de punto flotante. 

#valgrind
Lo que sucede es que estaba alocando varias veces, y no estaba liberando. 
Hace falta agregar free(a) adentro del loop, para que se vaya liberando lo que se va alocando:
  for(i=0; i<last; i++)
    {
      mysub(&a, mydim);
	  printf("a = %f \n", a[0]);
      free(a);
    }

#sigsegv
La memoria del stack que da el sistema operativo por default no alcanza, y hay que correr ulimit para agrandarla y que entre en el stack. Si pongo unlimited se puede colgar todo.

#funny
Al compilar con -DDEBUG habilita los pedazos de codigo en #ifdef. En definitiva, habilita la presentacion en pantalla del mensaje. 

El error ocurre porque estoy asignando valores 1000 lugares mas alla de lo que aloque. en mi compu esto no fallaba (virtual machine), pero en la compu de mis compas si fallaba. el fallo es independiente de la opcion -DDEBUG, proque el malloc no asigna lugares consecutivos necesariamente. por lo que los 1024 de errormsg no necesariamte estan a continuacion de a.

