#include <GL/freeglut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

double vector1[4] = {90, 0, 0, 1};  // Primer segmento (hombro y húmero)
double vector2[4] = {0, 90, 0, 1};  // Segundo segmento (codo y radio)
// Registro que representa un segmento del brazo
typedef struct Segmento 
{
    double vector[4];         // Vector que representa el segmento en el espacio (x, y, z, 1)
    struct Segmento *siguiente; // Puntero al siguiente segmento (para listas enlazadas)
} Segmento;

// Centro de rotación del primer segmento
double center[2] = {250, 250};

// Puntero al primer segmento (hombro)
Segmento *inicio = NULL;

/* Multiplicación de una matriz 4x4 por un vector de longitud 4. */
void Matriz_X_Vector(double matrix[4][4], double vector[4], double *c) {
    for (int i = 0; i < 4; i++) 
    {
        c[i] = matrix[i][0] * vector[0] +
               matrix[i][1] * vector[1] +
               matrix[i][2] * vector[2] + matrix[i][3] * vector[3];
    }
}

/* Función para rotar el vector de un segmento en un ángulo dado. */
void rotar(double *vector, double angle) {
    double seno = sin(angle);
    double coseno = cos(angle);
    double vectortemp[4];
    
    // Matriz de rotación en 2D (alrededor del eje Z)
    double matrizRot[4][4] = {{coseno, -seno, 0, 0}, 
                              {seno,  coseno, 0, 0},
                              {   0,       0, 1, 0},
                              {   0,       0, 0, 1}};
                              
    Matriz_X_Vector(matrizRot, vector, vectortemp);
    for (int i = 0; i < 4; i++) {
        vector[i] = vectortemp[i];
    }
}

/* Función para trasladar el vector de un segmento, con respecto al centro de rotación. */
void trasladar(double *vector, double *vectorout, double center[2]) {
    // Matriz de traslación
    double matrizTras[4][4] = {{1, 0, 0, center[0]},
                               {0, 1, 0, center[1]},
                               {0, 0, 1, 0},
                               {0, 0, 0, 1}};
                               
    Matriz_X_Vector(matrizTras, vector, vectorout);
}

/* Función para agregar un nuevo segmento al brazo. */
void agregarSegmento(Segmento **inicio, double vector[4]) {
    Segmento *nuevo = (Segmento*)malloc(sizeof(Segmento));
    for (int i = 0; i < 4; i++) {
        nuevo->vector[i] = vector[i];
    }
    nuevo->siguiente = *inicio; // El nuevo segmento apunta al inicio actual
    *inicio = nuevo;            // El inicio ahora es el nuevo segmento
}

/* Función para dibujar los segmentos del brazo. */
static void display01(void) {
    glClear(GL_COLOR_BUFFER_BIT);  // Limpiar la pantalla
    glColor3f(128, 0.0, 128.0);    // Color morado para hombro y húmero

    double centerActual[2] = {center[0], center[1]}; // Centro inicial en el hombro
    Segmento *actual = inicio; // Apuntamos al primer segmento de la lista
    double vectortemp[4];

    // Iteramos sobre la lista de segmentos para dibujarlos
    while (actual != NULL) {
        trasladar(actual->vector, vectortemp, centerActual);
        
        // Dibujar el segmento como una línea
        glBegin(GL_LINES);
            glVertex3f(centerActual[0], centerActual[1], 0); // Punto de inicio (centro)
            glVertex3f(vectortemp[0], vectortemp[1], vectortemp[2]); // Punto final
        glEnd();
        
        // Actualizar el centro para el siguiente segmento
        centerActual[0] = vectortemp[0];
        centerActual[1] = vectortemp[1];
        
        // Moverse al siguiente segmento
        actual = actual->siguiente;
    }

    glFlush();
    glutSwapBuffers(); // Intercambiar buffers de visualización
    glutPostRedisplay(); // Refrescar la ventana
}

/* Función para ajustar la vista cuando la ventana cambia de tamaño. */
static void reshape01(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}

/* Función para manejar eventos del teclado. */
static void keyboard01(unsigned char key, int x, int y) {
    if ((key == 0x1b) || (key == 'q') || (key == 'Q'))
        exit(0); // Terminar programa
    else if ((key == 't') || (key == 'T')) {
        rotar(inicio->vector, 0.1); 
    }
    else if ((key == 'R') || (key == 'r')) {
        rotar(inicio->vector, 0.1); // Rotar el primer segmento (hombro y húmero)
        rotar(inicio->siguiente->vector, -0.1);
    } else if ((key == 'H') || (key == 'h')) {
        if (inicio->siguiente != NULL) {
            rotar(inicio->siguiente->vector, 0.1); // Rotar el segundo segmento (codo y radio)
        }
    } else if ((key == 'I') || (key == 'i')) {
        if (inicio->siguiente != NULL) {
            rotar(inicio->siguiente->vector, -0.1); // Rotar el segundo segmento en sentido inverso
        }
    }
    glutSwapBuffers();
    glutPostRedisplay();
}

/* Función principal. */
int main(int argc, char *argv[]) {

    // Crear la lista de segmentos
    agregarSegmento(&inicio, vector2);  // Agregar el segundo segmento
    agregarSegmento(&inicio, vector1);  // Agregar el primer segmento

    // Inicialización de OpenGL
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(300, 200);
    glutCreateWindow("Brazo Robótico con Listas Enlazadas");
    glClearColor(1.0, 1.0, 1.0, 0.0);  // Color de borrado (fondo blanco)
    glShadeModel(GL_FLAT);             // Sombreado plano

    const GLubyte* renderer = glGetString(GL_RENDERER);
    const GLubyte* version = glGetString(GL_VERSION);
    printf("Renderer: %s\n", renderer);
    printf("Versión de OpenGL que soporta: %s\n", version);

    // Registrar funciones de eventos
    glutDisplayFunc(display01);
    glutReshapeFunc(reshape01);
    glutKeyboardFunc(keyboard01);

    // Iniciar loop principal
    glutMainLoop();
    return 0;
}
