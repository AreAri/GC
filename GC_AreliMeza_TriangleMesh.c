/*Areli Arisai Meza Rendon - AreAri
    Coordenadas de vertices*/
#include <stdio.h>
#include <stdlib.h>

//estructura para los vertices
typedef struct
{
    float x, y, z;
}vertice;

//estructura para formar un triangulo
typedef struct
{
    vertice v[3];
}triangulo;

int main(int argc, char const *argv[])
{
    int numTriangulos;
    printf("Cuantos triangulos va a ingresar?\n");
    scanf("%d", &numTriangulos);

    triangulo triangle[numTriangulos];

    for (int i=0; i<numTriangulos; i++)
    {
        printf("Ingresa las coordenadas de cada vertice del triangulo %d\n", i+1);
        for(int j=0; j<3; j++)
        {
            printf("Vertice %d (x y z): ",j+1);
            scanf("%f %f %f", &triangle[i].v[j].x, &triangle[i].v[j].y, &triangle[i].v[j].z);
        }
    }

    printf("\n~~~Se han ingresado %d triangulos~~~\n", numTriangulos);
    for (int i = 0; i < numTriangulos; ++i)
    {
        printf ("\nTriangulo %d: \n", i+1);
        for (int j=0; j < 3; ++j)
        {
            printf ("V%d: (%.2f, %.2f, %.2f) ", j+1, triangle[i].v[j].x, triangle[i].v[j].y, triangle[i].v[j].z);
        }
        printf("\n");
    }
    return 0;
}