#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Estructura para un punto en 3D
struct Punto {
    float x, y, z;
};

// Estructura para un triángulo
struct Triangulo {
    struct Punto p1, p2, p3;
};

// Variables globales
struct Punto* puntos;
struct Triangulo* triangulos;
int num_puntos_x = 10;
int num_puntos_y = 10;
int total_puntos;
int total_triangulos;

// Función para calcular la altura de la superficie
float calcular_altura(float x, float y) {
    return 5 * sin(x * 0.3) * cos(y * 0.3);
}

// Función para crear los puntos y triángulos
void crear_malla() {
    total_puntos = num_puntos_x * num_puntos_y;
    total_triangulos = (num_puntos_x - 1) * (num_puntos_y - 1) * 2;

    // Corregido: Añadido cast explícito a (struct Punto*)
    puntos = (struct Punto*)malloc(sizeof(struct Punto) * total_puntos);
    // Corregido: Añadido cast explícito a (struct Triangulo*)
    triangulos = (struct Triangulo*)malloc(sizeof(struct Triangulo) * total_triangulos);

    // Crear puntos
    int i, j, idx = 0;
    for (i = 0; i < num_puntos_x; i++) {
        for (j = 0; j < num_puntos_y; j++) {
            float x = i * 10.0 - 50;
            float y = j * 10.0 - 50;
            puntos[idx].x = x;
            puntos[idx].y = y;
            puntos[idx].z = calcular_altura(x, y);
            idx++;
        }
    }

    // Crear triángulos
    idx = 0;
    for (i = 0; i < num_puntos_x - 1; i++) {
        for (j = 0; j < num_puntos_y - 1; j++) {
            int p1 = i * num_puntos_y + j;
            int p2 = p1 + 1;
            int p3 = (i + 1) * num_puntos_y + j;
            int p4 = p3 + 1;

            triangulos[idx].p1 = puntos[p1];
            triangulos[idx].p2 = puntos[p2];
            triangulos[idx].p3 = puntos[p3];
            idx++;

            triangulos[idx].p1 = puntos[p2];
            triangulos[idx].p2 = puntos[p4];
            triangulos[idx].p3 = puntos[p3];
            idx++;
        }
    }
}

// Función para dibujar los puntos
void dibujar_puntos() {
    glPointSize(5.0);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    int i;
    for (i = 0; i < total_puntos; i++) {
        glVertex3f(puntos[i].x, puntos[i].y, puntos[i].z);
    }
    glEnd();
}

// Función para dibujar los triángulos
void dibujar_triangulos() {
    glColor3f(0.0, 1.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    int i;
    for (i = 0; i < total_triangulos; i++) {
        glBegin(GL_TRIANGLES);
        glVertex3f(triangulos[i].p1.x, triangulos[i].p1.y, triangulos[i].p1.z);
        glVertex3f(triangulos[i].p2.x, triangulos[i].p2.y, triangulos[i].p2.z);
        glVertex3f(triangulos[i].p3.x, triangulos[i].p3.y, triangulos[i].p3.z);
        glEnd();
    }
}

// Función principal de dibujo
void dibujar() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(0, 0, 150, 0, 0, 0, 0, 1, 0);

    dibujar_triangulos();
    dibujar_puntos();

    glutSwapBuffers();
}

// Función de inicialización
void inicializar() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
}

// Función principal
int main(int argc, char** argv) {
    crear_malla();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Malla Triangular Simple");

    inicializar();
    glutDisplayFunc(dibujar);

    glutMainLoop();
    return 0;
}