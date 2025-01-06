/* 
	programa sencillo: Imprime un triangulo con*

	Desde consola le debemos pedir la altura
*/
#include <stdio.h>
#include <stdlib.h>
void dibujar_trian(int *); //lista de parametros, un elemento, altura....
int main (int argc , char const *argv[])
{
	int alt;

	//utilizar argc y argv[0]
	//imprimir al usuario el formato
	if (argc !=2)
	{
		//printf("Formato esperado: ./a.out altura");
		printf("Formato esperado: %s altura\n", argv[0]); //imprime el formato como en la linea 14
	}
	alt = atoi(argv[1]); //atoi permite cambiar un caracter a un entero
	dibujar_trian(&alt); //dato obtenido desde consola
	return 0;
}

void dibujar_trian(int *altura)
{
	//int i, j esta se declara y se inializa dentro del for, excepto si es DevC++
	if (*altura<=1)
	{
		puts ("La altura debe ser mayor a 1, por favor"); //solo texto y da un salto de linea automatico
	}
	else
	{
		for (int i=0 ; i <= *altura; i++)
		{
			for (int j=0; j<*altura-i; j++)
			{
				printf("   ");
			}
			for (int j=0; j<i ; j++)
			{
				printf (" * ");
			}
			printf("\n");
		}
	}
}
/*
	argc - contador donde a.out lo cuenta como 1 y tomar el 8 es decir cuenta la cantidad de datos que se ingresan desde consola
	si argc es diferente de 2 significa que el formato no es correcto 
*/
//AreAri _ Areli Arisai Meza Rendon