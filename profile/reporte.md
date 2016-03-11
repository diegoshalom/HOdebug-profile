#profile_me_1.c

Asi como esta no corre, porque se llena la memoria stack. Hay que correr ulimit -s unlimited para agrandar el stack y que entre. Esto solo es necesario si los vectores y matrices son estaticos. si alocaramos con malloc, esto no seria necesario.

Al correr el gprof, vemos que first_assign tarda como 10 veces mas que second_assign. esto se debe a que en la primera, recorremos el vector a los saltos, 0 5000 10000 15000 ..... 1 5001 10001 15001, mientras que la segunda recorre de manera secuencial, ordenada. 

Al compilar con -o0 no funciona, porque -o es el output. hay que ponerlo con mayusculas -O

Al compilar con -O2 o mas, el tiempo se reduce a ser no medible por gprof. Parece que lo que esta pasando es que se da cuenta de que no usa nada de las cosas que estabamos calculando, y simplemente las saca. no las ejecuta. 

Para que las ejecute, lo que hicimos fue poner un printf, que lo muestre, y ahi si, tarda un rato, porque lo debe ejecutar igual.


#profile_me_2.c

Utilizando argc y argv le tengo que pasar un numero como parametro, que va a ser la dim.


