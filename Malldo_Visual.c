#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int x, y; // Coordenadas del nodo
    struct Nodo *arriba, *abajo, *izquierda, *derecha; // Conexiones adyacentes
    struct Nodo *anteriorN, *siguienteN; // Conexiones en la misma fila
} Nodo;

Nodo*** malla;
int n = 3, m = 3; //dimensiones de la malla

// Crear un nuevo nodo
Nodo* VerticeNodo(int x, int y) {
    Nodo* nNodo = (Nodo*)malloc(sizeof(Nodo));
    nNodo->x = x;
    nNodo->y = y;
    nNodo->arriba = nNodo->abajo = nNodo->izquierda = nNodo->derecha = NULL;
    nNodo->anteriorN = nNodo->siguienteN = NULL;
    return nNodo;
}

// Crear la malla de nodos
Nodo*** crearMalla(int n, int m) {
    Nodo*** malla = (Nodo***)malloc(n * sizeof(Nodo**));
    for (int i = 0; i < n; i++) {
        malla[i] = (Nodo**)malloc(m * sizeof(Nodo*));
        for (int j = 0; j < m; j++) {
            malla[i][j] = VerticeNodo(i * 50, j * 50); // Separar los nodos para mejor visualización
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0) malla[i][j]->arriba = malla[i - 1][j];
            if (i < n - 1) malla[i][j]->abajo = malla[i + 1][j];
            if (j > 0) malla[i][j]->izquierda = malla[i][j - 1];
            if (j < m - 1) malla[i][j]->derecha = malla[i][j + 1];
            if (j > 0) malla[i][j]->anteriorN = malla[i][j - 1];
            if (j < m - 1) malla[i][j]->siguienteN = malla[i][j + 1];
        }
    }
    return malla;
}

// Función de visualización para GLUT
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT); // Limpiar el buffer de color
    glColor3f(0.0, 1.0, 0.0); // Asignar color verde a las figuras

    // Dibujar los segmentos de línea en la malla
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            Nodo *actual = malla[i][j];

            // Primer lado
            glBegin(GL_LINES); 
                glVertex2f(actual->x, actual->y); // Primer vértice
                glVertex2f(actual->derecha->x, actual->derecha->y); // Segundo vértice
            glEnd();
            
            // Segundo lado
            glBegin(GL_LINES); 
                glVertex2f(actual->derecha->x, actual->derecha->y); // Segundo vértice
                glVertex2f(actual->abajo->x, actual->abajo->y); // Tercer vértice
            glEnd();

            // Tercer lado
            glBegin(GL_LINES); 
                glVertex2f(actual->abajo->x, actual->abajo->y); // Tercer vértice
                glVertex2f(actual->x, actual->y); // Primer vértice
            glEnd();

            // Segundo triángulo
            glBegin(GL_LINES); 
                glVertex2f(actual->derecha->x, actual->derecha->y); // Primer vértice
                glVertex2f(actual->abajo->derecha->x, actual->abajo->derecha->y); // Segundo vértice
            glEnd();
            
            // Cuarto lado
            glBegin(GL_LINES); 
                glVertex2f(actual->abajo->derecha->x, actual->abajo->derecha->y); // Segundo vértice
                glVertex2f(actual->abajo->x, actual->abajo->y); // Tercer vértice
            glEnd();
            
            // Quinto lado
            glBegin(GL_LINES); 
                glVertex2f(actual->abajo->x, actual->abajo->y); // Tercer vértice
                glVertex2f(actual->derecha->x, actual->derecha->y); // Primer vértice
            glEnd();
        }
    }

    glFlush(); // Limpiar el buffer
}

// Función de inicialización

int main(int argc, char **argv) {
    malla = crearMalla(n, m); // Crear la malla de nodos

    glutInit(&argc, argv); // Inicializar GLUT

    // Establecer el modo de visualizacion
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Usar un buffer simple con colores RGB
    glutInitWindowSize(500, 500); // Tamaño de la ventana
    glutInitWindowPosition(100, 100); // Posición de la ventana en la pantalla
    glutCreateWindow("Malla de Triángulos"); // Crear la ventana con título

     gluOrtho2D(0.0, 200.0, 0.0, 200.0);

    glutDisplayFunc(display); // Registrar la funcion de visualización

    glutMainLoop(); // Iniciar el ciclo de eventos de GLUT

    return 0;
}
