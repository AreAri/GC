#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
//codigo creado con la base de la primera actividad de graficacion (hace un año), utilizando mi  codigo de arboles (del semestre pasado)

struct Vertices 
{
    int id;
    float x, y, z;
};

struct triangulo //he aqui tenemos una lista
{
    struct Vertices *v1, *v2, *v3; // Apuntadores a los tres vértices
    struct triangulo *sig;
};

struct Arbol //agregamos vertices que vienen siendo los nodos del arbol
{
    struct Vertices dato; 
    struct Arbol *izq;
    struct Arbol *der; 
};

struct Vertices* ultimos_vertices[3];
int num_vertices = 0; 

// Funciones del árbol 
struct Arbol *crear_arbol(struct Vertices num);
int arbol_seco(struct Arbol *raiz);
void agregar(struct Arbol **raiz, struct Vertices num, struct triangulo **triangulos);
void viento(struct Arbol *raiz);

// Funciones del mallado
void agregar_triangulo(struct triangulo **triangulo, struct Vertices *v1, struct Vertices *v2, struct Vertices *v3);
void mostrar_mallado(struct triangulo *triangulo);//solo muestra los triangulos con sus vertices
bool triangulo_igual(struct Vertices *v1, struct Vertices *v2, struct Vertices *v3, struct Vertices *t1, struct Vertices *t2, struct Vertices *t3);
bool triangulo_existe(struct triangulo *triangulos, struct Vertices *v1, struct Vertices *v2, struct Vertices *v3);

void menu(struct Arbol **raiz, struct triangulo **triangulos);

int main() 
{
    struct Arbol *raiz = NULL;
    struct triangulo *triangulos = NULL;
    
    menu(&raiz, &triangulos);

    viento(raiz); // Liberamos memoria
    return 0;
}

// Estructura del arbol
struct Arbol *crear_arbol(struct Vertices num) 
{
    struct Arbol *nuevo = (struct Arbol*)malloc(sizeof(struct Arbol));
    if (nuevo == NULL) 
    {
        puts("Error al asignar memoria");
        return 0;
    }
    nuevo->dato = num;
    nuevo->izq = nuevo->der = NULL;
    return nuevo;
}

int arbol_seco(struct Arbol *raiz) 
{
    return raiz == NULL;
}

void agregar(struct Arbol **raiz, struct Vertices num, struct triangulo **triangulos) 
{
    if (arbol_seco(*raiz)) 
    {
        *raiz = crear_arbol(num);
    }
    else if (num.id < (*raiz)->dato.id) 
    {
        agregar(&(*raiz)->izq, num, triangulos);
    }
    else if (num.id > (*raiz)->dato.id) 
    {
        agregar(&(*raiz)->der, num, triangulos);
    } 
    else 
    {
        printf("\nEse vertice ya existe\n");
        return;
    }

    ultimos_vertices[num_vertices % 3] = &(*raiz)->dato;
    num_vertices++;

    if (num_vertices >= 3) 
    {
        //basicamente me permite identificar los 3 vertices para formar el triangulo
    /*siendo sincera pedi ayuda a chatgpt debido a que se me formaban los triangulos pero obligatoriamente tenia que poner el usuario sus vertices
     chatgpt me dio una opcion similar a la que se muestra y la acople a manera para entenderlo, aun asi tengo errores en esta parte */
        if (!triangulo_existe(*triangulos, ultimos_vertices[0], ultimos_vertices[1], ultimos_vertices[2]))
        {
            agregar_triangulo(triangulos, ultimos_vertices[0], ultimos_vertices[1], ultimos_vertices[2]);
            printf("Triangulo con los vertices %d, %d, %d\n",
                   ultimos_vertices[0]->id, ultimos_vertices[1]->id, ultimos_vertices[2]->id);
        }
        else
        {
            printf("Triangulo con los vertices %d, %d, %d ya existe.\n",
                   ultimos_vertices[0]->id, ultimos_vertices[1]->id, ultimos_vertices[2]->id);
        }
    }
}

// Función para liberar el árbol (intentare no olvidarme de liberar memoria siempre)
void viento(struct Arbol *raiz) 
{
    if (arbol_seco(raiz)) return;
    viento(raiz->izq);
    viento(raiz->der);
    free(raiz);
}

void agregar_triangulo(struct triangulo **triangulo, struct Vertices *v1, struct Vertices *v2, struct Vertices *v3) 
{
    struct triangulo *nuevo = (struct triangulo*)malloc(sizeof(struct triangulo));
    if (nuevo == NULL) 
    {
        printf("No se puede ingresar memoria para tu triangulo.\n");
        return; 
    }
    nuevo->v1 = v1;
    nuevo->v2 = v2;
    nuevo->v3 = v3;
    nuevo->sig = *triangulo;
    *triangulo = nuevo;
}
bool triangulo_igual(struct Vertices *v1, struct Vertices *v2, struct Vertices *v3, struct Vertices *t1, struct Vertices *t2, struct Vertices *t3)
/* debido a que tuve problemas con el hecho de que se me repetian 3 veces un triangulo opte por la forma mas sencilla de arreglar ese error, con un booleano
    puede que solo tengan que validar algo del codigo.. pero se me hizo mas facil esto */
{
    return (v1 == t1 && v2 == t2 && v3 == t3) || (v1 == t1 && v2 == t3 && v3 == t2) || (v1 == t2 && v2 == t1 && v3 == t3) || (v1 == t2 && v2 == t3 && v3 == t1) || (v1 == t3 && v2 == t1 && v3 == t2) || (v1 == t3 && v2 == t2 && v3 == t1);
}

bool triangulo_existe(struct triangulo *triangulos, struct Vertices *v1, struct Vertices *v2, struct Vertices *v3)
{
    while (triangulos != NULL) 
    {
        if (triangulo_igual(v1, v2, v3, triangulos->v1, triangulos->v2, triangulos->v3))
        {
            return true;  // si el triangulo ya existe
        }
        triangulos = triangulos->sig;
    }
    return false;  
}

void mostrar_mallado(struct triangulo *triangulo) 
{
    int cont = 1; //para tener en cuenta el numero d4e triangulos que se crean
    while (triangulo != NULL) 
    {
        printf("Triangulo %d: V1(%.2f, %.2f, %.2f), V2(%.2f, %.2f, %.2f), V3(%.2f, %.2f, %.2f)\n",cont, triangulo->v1->x, triangulo->v1->y, triangulo->v1->z, triangulo->v2->x, triangulo->v2->y, triangulo->v2->z,triangulo->v3->x, triangulo->v3->y, triangulo->v3->z);
        triangulo = triangulo->sig;
        cont++;
    }
}

void menu(struct Arbol **raiz, struct triangulo **triangulos) 
{
    int opcion;
    do 
    {
        printf("\n~~~~~~ Menu: ~~~~~~\n");
        printf("1. Agregar vertice\n");
        printf("2. Mostrar mallado\n");
        printf("0. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) 
        {
            case 1: 
                struct Vertices nuevo_ver;
                printf("Introduce el ID del vertice: ");
                scanf("%d", &nuevo_ver.id);
                printf("Introduce la coordenada X: ");
                scanf("%f", &nuevo_ver.x);
                printf("Introduce la coordenada Y: ");
                scanf("%f", &nuevo_ver.y);
                printf("Introduce la coordenada Z: ");
                scanf("%f", &nuevo_ver.z);
                agregar(raiz, nuevo_ver, triangulos);
                break;

            case 2: 
                mostrar_mallado(*triangulos);
                break;

            case 0:
                printf("Saliendo...\n");
                break;

            default:
                printf("La lista de opciones va del 0 al 2 -_-\n");
                break;
        }
    } while (opcion != 0);
}

