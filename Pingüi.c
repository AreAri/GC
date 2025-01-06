/* Areli Arisai Meza Rendon- AreAri
    Experimento 1: crear una especie de pingüino*/
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

void display() {
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    //parabola cuerpo
    glLineWidth(3); //definir grosor de la linea 
    glColor3f(0.0, 0.0,0.0); // negro contorno

    glBegin(GL_LINE_STRIP); //poder dibujar una tira de lineas conectadas (contornos o trayectorias)
    for (float x = -1.0; x <= 1.0; x += 0.01) 
    {
        float y = -2.0* pow(x,2);
        glVertex2f(x, y);
    }
    glEnd();
    glColor3f(0.0f, 0.5f, 0.5f); // azul verdoso fondo
    glBegin(GL_POLYGON);
    for (float x = -1.0; x <= 1.0; x += 0.01) 
    {
        float y = -2.0* pow(x,2);
        glVertex2f(x, y);
    }
    glEnd();

    //panza
    glColor3f(1.0, 1.0, 1.0); // blanco
    glBegin(GL_POLYGON);
    for (float x = -1.0; x <= 1.0; x += 0.01)
    {
        float y = -1.0* pow(x,2) -0.75; 
        /*-.75 para poder bajar la porabola*/
        glVertex2f(x, y);
    }
    glEnd();

    // Pico
    glColor3f(0.0, 0.0, 0.0); //contorno
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.3, -0.6); // Vértice inferior izquierdo
        glVertex2f(0.3, -0.6);  // Vértice inferior derecho
        glVertex2f(0.0, -0.8);   // Vértice inferior
    glEnd();
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f); // Color del triángulo
    //Relleno
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.3, -0.6); // Vértice inferior izquierdo
        glVertex2f(0.3, -0.6);  // Vértice inferior derecho
        glVertex2f(0.0, -0.8);   // Vértice inferior
    glEnd();

    //sombrero
    glColor3f(0.0,0.0,0.0);
    //copa
    glBegin (GL_POLYGON);
        glVertex2f(-0.1, 0.0);//inferior izquierda
        glVertex2f (0.1,0.0);//inferior derecha
        glVertex2f(0.1, 0.2);//superior derecha
        glVertex2f (-0.1, 0.2);//superior izquierda
    glEnd();
    glBegin (GL_POLYGON); //cualquier poligono
        //base
        glVertex2f(-0.2, -0.02);
        glVertex2f (0.2,-0.02);
        glVertex2f(0.2, 0.01);
        glVertex2f (-0.2, 0.01);
    glEnd();

    //orejas del moño
    glColor3f(0.0,0.0,0.0);
    //glBegin (GL_TRIANGLE_STRIP); triangulos conectados de un vertice
        glBegin (GL_TRIANGLES); 
        glVertex2f(-0.2, -0.93);
        glVertex2f (0.0, -0.88);//puntas
        glVertex2f(-0.2, -0.84);
        glVertex2f(0.2, -0.93);
        glVertex2f (0.0, -0.88);//puntas
        glVertex2f(0.2, -0.84);
    glEnd();
    //nudo del moño
    glBegin(GL_POLYGON);
        glVertex2f(-0.05, -0.9); // Esquina inferior izquierda
        glVertex2f(0.05, -0.9);  // Esquina inferior derecha
        glVertex2f(0.05, -0.86);  // Esquina superior derecha
        glVertex2f(-0.05, -0.86); // Esquina superior izquierda
    glEnd();

    //ojos
    glColor3f(1.0,1.0,1.0);
    //izquierdo
    glBegin(GL_POLYGON);
        glVertex2f(-0.25, -0.5); // Esquina inferior izquierda
        glVertex2f(-0.05, -0.5);  // Esquina inferior derecha
        glVertex2f(-0.05, -0.2);  // Esquina superior derecha
        glVertex2f(-0.25, -0.2); // Esquina superior izquierda
    glEnd();
    //pupila
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(-0.15, -0.5); // Esquina inferior izquierda
        glVertex2f(-0.07, -0.5);  // Esquina inferior derecha
        glVertex2f(-0.07, -0.3);  // Esquina superior derecha
        glVertex2f(-0.15, -0.3); // Esquina superior izquierda
    glEnd();
    //contorno
     glLineWidth(1); //definir grosor de la linea 
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.25, -0.5); // Esquina inferior izquierda
        glVertex2f(-0.05, -0.5);  // Esquina inferior derecha
        glVertex2f(-0.05, -0.2);  // Esquina superior derecha
        glVertex2f(-0.25, -0.2); // Esquina superior izquierda
    glEnd();
    //derecho
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(0.25, -0.5); // Esquina inferior izquierda
        glVertex2f(0.05, -0.5);  // Esquina inferior derecha
        glVertex2f(0.05, -0.2);  // Esquina superior derecha
        glVertex2f(0.25, -0.2); // Esquina superior izquierda
    glEnd();
    //pupila
     glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(0.15, -0.5); // Esquina inferior izquierda
        glVertex2f(0.07, -0.5);  // Esquina inferior derecha
        glVertex2f(0.07, -0.3);  // Esquina superior derecha
        glVertex2f(0.15, -0.3); // Esquina superior izquierda
    glEnd();
    //contorno
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.25, -0.5); // Esquina inferior izquierda
        glVertex2f(0.05, -0.5);  // Esquina inferior derecha
        glVertex2f(0.05, -0.2);  // Esquina superior derecha
        glVertex2f(0.25, -0.2); // Esquina superior izquierda
    glEnd();
    
    //alas
    //Izquierda
    glColor3f(0.0f, 0.5f, 0.5f); 
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.55, -0.6),
        glVertex2f (-0.96, -0.48),
        glVertex2f(-0.71, -1.0),
    glEnd();
    glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
        glVertex2f(-0.55, -0.6),
        glVertex2f (-0.96, -0.48),
        glVertex2f(-0.71, -1.0),
    glEnd();

    //derecha
    glColor3f(0.0f, 0.5f, 0.5f); 
    glBegin(GL_TRIANGLES);
        glVertex2f(0.55, -0.6),
        glVertex2f (1.0, -1.2),
        glVertex2f(0.71, -1.0),
    glEnd();
    glColor3f(0.0, .0, 0.0); 
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.55, -0.6),
        glVertex2f (1.0, -1.2),
        glVertex2f(0.71, -1.0),
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Pingui");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}