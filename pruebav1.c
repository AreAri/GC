#include <GL/glut.h>  
#include <stdio.h>     
#include <stdlib.h>    
#include <math.h>      

// Estructura para representar un vértice 3D
typedef struct Vertice {
    float x;            // Coordenada X del vértice
    float y;            // Coordenada Y del vértice
    float z;            // Coordenada Z del vértice
    struct Vertice* next; // Puntero al siguiente vértice en la lista enlazada
} Vertice;

// Estructura para representar una cara del triangulo
typedef struct Cara {
    Vertice* v1;        // Primer vértice del triángulo
    Vertice* v2;        // Segundo vértice del triángulo
    Vertice* v3;        // Tercer vértice del triángulo
    struct Cara* next;  // Puntero a la siguiente cara en la lista enlazada
} Cara;

/* Variables globales */

Vertice* listaVertices = NULL; // Puntero al inicio de la lista de vértices
Cara* listaCaras = NULL;       // Puntero al inicio de la lista de caras (triángulos)

int numVerticesX = 20; // Número de vértices en el eje X
int numVerticesY = 20; // Número de vértices en el eje Y


// Función que crea un nuevo vértice con las coordenadas dadas
Vertice* createV(float x, float y, float z) {
    Vertice* nuevoVertice = (Vertice*)malloc(sizeof(Vertice)); // Reserva memoria para un nuevo vértice
    nuevoVertice->x = x;  // Asigna la coordenada X
    nuevoVertice->y = y;  // Asigna la coordenada Y
    nuevoVertice->z = z;  // Asigna la coordenada Z
    nuevoVertice->next = NULL; // Inicializa el puntero al siguiente vértice como NULL
    return nuevoVertice;  // Devuelve el puntero al nuevo vértice
}

// Función que añade un vértice al final de la lista de vértices
void añadirVertice(Vertice** cabeza, float x, float y, float z) {
    Vertice* nuevoVertice = createV(x, y, z);  // Crea un nuevo vértice con las coordenadas dadas
    if (*cabeza == NULL) {
        *cabeza = nuevoVertice;  // Si la lista está vacía, el nuevo vértice es la cabeza de la lista
    }
    else {
        Vertice* actual = *cabeza;  // Si no está vacía, recorre la lista hasta el final
        while (actual->next != NULL) {
            actual = actual->next;
        }
        actual->next = nuevoVertice;  // Añade el nuevo vértice al final de la lista
    }
}

// Función que crea una nueva cara (triángulo) con los tres vértices dados
Cara* createC(Vertice* v1, Vertice* v2, Vertice* v3) {
    Cara* nuevaCara = (Cara*)malloc(sizeof(Cara)); // Reserva memoria para una nueva cara
    nuevaCara->v1 = v1;  // Asigna el primer vértice
    nuevaCara->v2 = v2;  // Asigna el segundo vértice
    nuevaCara->v3 = v3;  // Asigna el tercer vértice
    nuevaCara->next = NULL; // Inicializa el puntero a la siguiente cara como NULL
    return nuevaCara;  // Devuelve el puntero a la nueva cara
}

// Función que añade una cara al final de la lista de caras
void añadirCara(Cara** cabeza, Vertice* v1, Vertice* v2, Vertice* v3) {
    Cara* nuevaCara = createC(v1, v2, v3);  // Crea una nueva cara con los vértices dados
    if (*cabeza == NULL) {
        *cabeza = nuevaCara;  // Si la lista está vacía, la nueva cara es la cabeza de la lista
    }
    else {
        Cara* actual = *cabeza;  // Si no está vacía, recorre la lista hasta el final
        while (actual->next != NULL) {
            actual = actual->next;
        }
        actual->next = nuevaCara;  // Añade la nueva cara al final de la lista
    }
}

/* Función para calcular la altura de la superficie ondulada en base a X y Y */
float superficieOndulada(float x, float y) {
    // Calcula una ondulación usando las funciones seno y coseno
    return 10 * sin(x * 0.2) * cos(y * 0.2);
}

/* Función para inicializar los datos de la malla */
void inicializarDatos() {
    float stepX = 100.0 / (numVerticesX - 1); // Distancia entre vértices en el eje X
    float stepY = 100.0 / (numVerticesY - 1); // Distancia entre vértices en el eje Y

    // Generar los vértices de la superficie
    for (int i = 0; i < numVerticesX; i++) {
        for (int j = 0; j < numVerticesY; j++) {
            float x = -50 + i * stepX;  // Coordenada X
            float y = -50 + j * stepY;  // Coordenada Y
            float z = superficieOndulada(x, y);  // Coordenada Z basada en la función ondulada
            añadirVertice(&listaVertices, x, y, z);  // Añadir el vértice a la lista
        }
    }

    // Generar las caras de los triangulos conectando los vértices
    Vertice* vertices[numVerticesX][numVerticesY];  // Arreglo 2D para almacenar los punteros a vértices
    Vertice* v = listaVertices;  // Puntero temporal para recorrer la lista de vértices
    for (int i = 0; i < numVerticesX; i++) {
        for (int j = 0; j < numVerticesY; j++) {
            vertices[i][j] = v;  // Almacena el vértice en el arreglo 2D
            v = v->next;  // Avanza al siguiente vértice en la lista
        }
    }

    // Crear triángulos conectando los vértices
    for (int i = 0; i < numVerticesX - 1; i++) {
        for (int j = 0; j < numVerticesY - 1; j++) {
            // Crear dos triángulos por cada cuadrado de la malla
            añadirCara(&listaCaras, vertices[i][j], vertices[i + 1][j], vertices[i][j + 1]); // Primer triángulo
            añadirCara(&listaCaras, vertices[i + 1][j], vertices[i + 1][j + 1], vertices[i][j + 1]); // Segundo triángulo
        }
    }
}

/* Función para dibujar los vértices */
void dibujarVertices() {
    glPointSize(5.0);  // Define el tamaño de los puntos que representan los vértices
    glBegin(GL_POINTS);  // Comienza a dibujar puntos
    glColor3f(1.0, 0.0, 0.0);  // Define el color rojo para los vértices
    Vertice* v = listaVertices;  // Puntero temporal para recorrer la lista de vértices
    while (v != NULL) {
        glVertex3f(v->x, v->y, v->z);  // Dibuja cada vértice
        v = v->next;  // Avanza al siguiente vértice en la lista
    }
    glEnd();  // Termina de dibujar
}

/* Función para dibujar las caras (triángulos) */
void dibujarTriangulos() {
    glColor3f(0.0, 0.0, 0.0);  // Define el color verde para los triángulos
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);  // Dibuja solo los contornos de los triángulos
    Cara* caraActual = listaCaras;  // Puntero temporal para recorrer la lista de caras
    while (caraActual != NULL) {
        glBegin(GL_TRIANGLES);  // Comienza a dibujar triángulos
        glVertex3f(caraActual->v1->x, caraActual->v1->y, caraActual->v1->z);  // Dibuja el primer vértice del triángulo
        glVertex3f(caraActual->v2->x, caraActual->v2->y, caraActual->v2->z);  // Dibuja el segundo vértice del triángulo
        glVertex3f(caraActual->v3->x, caraActual->v3->y, caraActual->v3->z);  // Dibuja el tercer vértice del triángulo
        glEnd();  // Termina de dibujar
        caraActual = caraActual->next;  // Avanza a la siguiente cara en la lista
    }
}

/* Función de dibujo principal */
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Limpia el buffer de color y el buffer de profundidad
    glLoadIdentity();  // Resetea la matriz de transformación actual

    // Configura la cámara
    gluLookAt(0, 0, 150,   // Posición de la cámara
        0, 0, 0,     // Punto al que la cámara mira
        0, 1, 0);    // Vector "arriba" de la cámara

    // Llama a las funciones de dibujo
    dibujarTriangulos();  // Dibuja los triángulos
    dibujarVertices();    // Dibuja los vértices

    glutSwapBuffers();  // Intercambia los buffers (doble buffering)
}

/* Inicialización de parámetros de OpenGL */
void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);  // Establece el color de fondo (negro)
    glEnable(GL_DEPTH_TEST);  // Habilita el test de profundidad para ocultar partes traseras de los objetos
    glMatrixMode(GL_PROJECTION);  // Cambia a la matriz de proyección para definir la perspectiva
    glLoadIdentity();  // Resetea la matriz de proyección
    gluPerspective(45, 1, 1, 1000);  // Configura la proyección en perspectiva
    glMatrixMode(GL_MODELVIEW);  // Cambia de nuevo a la matriz de modelado
}

/* Función que maneja el redimensionamiento de la ventana */
void reshape(int w, int h) {
    glViewport(0, 0, w, h);  // Define el área de visualización de la ventana
    glMatrixMode(GL_PROJECTION);  // Cambia a la matriz de proyección
    glLoadIdentity();  // Resetea la matriz de proyección
    gluPerspective(45, (float)w / h, 1, 1000);  // Ajusta la proyección en perspectiva según el nuevo tamaño de la ventana
    glMatrixMode(GL_MODELVIEW);  // Cambia de nuevo a la matriz de modelado
}

/* Función principal */
int main(int argc, char** argv) {
    inicializarDatos();  // Inicializa la malla de vértices y triángulos

    glutInit(&argc, argv);  // Inicializa GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  // Habilita el doble buffering, RGB y test de profundidad
    glutInitWindowSize(800, 600);  // Establece el tamaño de la ventana
    glutInitWindowPosition(100, 100);  // Establece la posición inicial de la ventana
    glutCreateWindow("Malla Triangular con OpenGL - Vértices y Aristas");  // Crea la ventana con el título dado

    init();  // Llama a la función de inicialización de OpenGL
    glutDisplayFunc(display);  // Establece la función de dibujo principal
    glutReshapeFunc(reshape);  // Establece la función que manejará el redimensionamiento de la ventana

    glutMainLoop();  // Inicia el bucle principal de GLUT
    return 0;
}
