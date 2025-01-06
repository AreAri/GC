#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//ecuacion x^2+y^2+z^2-6x-4x+2y=2
//posibles funciones
int centro (int i, int j, int k);
int radio (int i, int j, int k, int A);
int main ()
{
	int x,y,z, R;
	printf("~~Programa para calcular el centro y radio de una esfera~~\n");
	printf ("Ingrese los valores de x, y, z:\n");
	printf ("x: ");
	scanf ("%d", &x);
	printf ("y: ");
	scanf ("%d", &y);
	printf ("z: ");
	scanf ("%d", &z);
	printf ("Ingrese el valor del resultado de la ecuacion: \n");
	scanf ("%d", &R);
	centro (x,y,z);
	radio (x,y,z,R);
	return 0;
}
//calcular centro
int centro (int i, int j, int k)
{
	int x,y,z;
	x= i/2;
	y= j/2;
	z= k/2;
//comprobando signo
	if (x<0 | x>0)
	{
		x= x*(-1);
	}
	if (y<0 | y>0)
	{
		y= y*(-1);
	}
		if (z<0 | z>0)
	{
		z= z*(-1);
	}
	printf ("El centro es: (%d, %d, %d)\n", x, y, z);
	return 0;
}
//calcular radio
int radio (int i, int j, int k, int A)
{
	float R;
	R= sqrt (pow((i/2),2)+pow((j/2),2)+pow((k/2),2)+A);
	printf ("El radio es: %.2f\n", R);
	return 0;
}
