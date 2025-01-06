// era mi persoj¿naje principal pero el tiempo no me dio 
#include <GL/glut.h>
#include <GL/glut.h>
#include <stdio.h>

void display() 
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,1.0,0.0);
    //esto solo era para ubicar mi campo en el plano (identificar las coordenadas mas facil)
    /*glPointSize(10.0f); 
    glBegin(GL_POINTS);
    glVertex3f(0.0,0.0,0.0);  // O glVertex3f(x, y, z) si es en 3D
    glEnd();

    glBegin(GL_POINTS);
    glVertex3f(0.99,0.0,0.0);  // O glVertex3f(x, y, z) si es en 3D
    glEnd();
glBegin(GL_POINTS);
    glVertex3f(-0.9,0.0,0.0);  // O glVertex3f(x, y, z) si es en 3D
    glEnd();
glBegin(GL_POINTS);
    glVertex3f(0.0,1.0,0.0);  // O glVertex3f(x, y, z) si es en 3D
    glEnd();*/

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_QUADS); //torso
        glVertex3f(-0.2,-0.2,0.0);
        glVertex3f(-0.6,-0.2,0.0);
        glVertex3f(-0.6,0.1,0.0);
        glVertex3f(-0.2,0.1,0.0);
    glEnd();

    glBegin(GL_QUADS); //cabeza
        glVertex3f(-0.2,0.5,0.0);
        glVertex3f(-0.8,0.5,0.0);
        glVertex3f(-0.8,0.1,0.0);
        glVertex3f(-0.2,0.1,0.0);
    glEnd();

    glBegin(GL_QUADS);//mano
        glVertex3f(-0.75,-0.1,0.0);
        glVertex3f(-0.85,-0.1,0.0);
        glVertex3f(-0.85,0.0,0.0);
        glVertex3f(-0.75,0.0,0.0);
    glEnd();

    glBegin(GL_QUADS);//pata
        glVertex3f(-0.2,-0.2,0.0);
        glVertex3f(-0.33,-0.2,0.0);
        glVertex3f(-0.33,-0.3,0.0);
        glVertex3f(-0.2,-0.3,0.0);
    glEnd();

     glBegin(GL_QUADS);//otra pata
        glVertex3f(-0.53,-0.2,0.0);
        glVertex3f(-0.4,-0.2,0.0);
        glVertex3f(-0.4,-0.3,0.0);
        glVertex3f(-0.53,-0.3,0.0);
    glEnd();

    glBegin(GL_QUADS);//cola
        glVertex3f(-0.2,-0.2,0.0);
        glVertex3f(0.15,-0.2,0.0);
        glVertex3f(0.15,0.2,0.0);
        glVertex3f(-0.2,0.2,0.0);
    glEnd();

    glBegin(GL_TRIANGLES);//peinado
        glColor3f(0.0,0.5,0.0);
        glVertex3f(-0.75,0.5,0.0);
        glVertex3f(-0.9,0.65,0.0);
        glVertex3f(-0.75,0.65,0.0);
    glEnd();

    glBegin(GL_QUADS);//cabello1
        glVertex3f(-0.35,0.5,0.0);
        glVertex3f(-0.75,0.5,0.0);
        glVertex3f(-0.75,0.65,0.0);
        glVertex3f(-0.35,0.65,0.0);
    glEnd();  

    glBegin(GL_QUADS);//cabello2
        glVertex3f(-0.35,0.5,0.0);
        glVertex3f(-0.35,0.58,0.0);
        glVertex3f(-0.25,0.58,0.0);
        glVertex3f(-0.25,0.5,0.0);
    glEnd(); 

    glBegin(GL_QUADS);//coleta1
        glVertex3f(-0.2,0.2,0.0);
        glVertex3f(-0.2,0.35,0.0);
        glVertex3f(-0.1,0.35,0.0);
        glVertex3f(-0.1,0.2,0.0);
    glEnd();

    glBegin(GL_QUADS);//coleta2
        glVertex3f(-0.2,0.2,0.0);
        glVertex3f(-0.2,0.35,0.0);
        glVertex3f(-0.1,0.35,0.0);
        glVertex3f(-0.1,0.2,0.0);
    glEnd();

    glBegin(GL_QUADS);//cola
        glVertex3f(0.05,-0.1,0.0);
        glVertex3f(0.05,-0.2,0.0);
        glVertex3f(0.15,-0.2,0.0);
        glVertex3f(0.15,-0.1,0.0);
    glEnd();

    glBegin(GL_POLYGON);//coleta2
        glVertex3f(0.05,0.0,0.0);
        glVertex3f(0.05,0.07,0.0);
        glVertex3f(0.1,0.1,0.0);
        glVertex3f(0.15,0.1,0.0);
        glVertex3f(0.15,0.0,0.0);
    glEnd();

    glBegin(GL_QUADS);//cola
        glVertex3f(0.05,0.1,0.0);
        glVertex3f(0.05,0.2,0.0);
        glVertex3f(-0.1,0.2,0.0);
        glVertex3f(-0.1,0.1,0.0);
    glEnd();
glBegin(GL_QUADS);//cola
        glVertex3f(-0.1,0.05,0.0);
        glVertex3f(-0.1,-0.05,0.0);
        glVertex3f(-0.2,-0.05,0.0);
        glVertex3f(-0.2,0.05,0.0);
    glEnd();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS); //torso/panza
        glVertex3f(-0.33,-0.2,0.0);
        glVertex3f(-0.6,-0.2,0.0);
        glVertex3f(-0.6,0.08,0.0);
        glVertex3f(-0.33,0.08,0.0);
    glEnd();

    glBegin(GL_QUADS);//otra brillo
        glVertex3f(-0.53,-0.2,0.0);
        glVertex3f(-0.47,-0.2,0.0);
        glVertex3f(-0.47,-0.3,0.0);
        glVertex3f(-0.53,-0.3,0.0);
    glEnd();

    glBegin(GL_QUADS);//pata/brillo?
        glVertex3f(-0.27,-0.2,0.0);
        glVertex3f(-0.33,-0.2,0.0);
        glVertex3f(-0.33,-0.3,0.0);
        glVertex3f(-0.27,-0.3,0.0);
    glEnd();

glColor3f(1.0,1.0,0.0);
    glBegin(GL_QUADS);//mano
        glVertex3f(-0.33,-0.1,0.0);
        glVertex3f(-0.43,-0.1,0.0);
        glVertex3f(-0.43,0.0,0.0);
        glVertex3f(-0.33,0.0,0.0);
    glEnd();

    glLineWidth(10.0);
     glBegin(GL_LINES);//peinado
        glColor3f(0.0,0.2,0.0);
        glVertex3f(-0.75,0.5,0.0);
        glVertex3f(-0.9,0.65,0.0);
        glVertex3f(-0.35,0.65,0.0);
        glVertex3f(-0.35,0.58,0.0);
        glVertex3f(-0.25,0.58,0.0);
        glVertex3f(-0.25,0.5,0.0);
        glVertex3f(-0.2,0.5,0.0);
    glEnd();

    glBegin(GL_QUADS);//cabello2
        glVertex3f(-0.35,0.5,0.0);
        glVertex3f(-0.35,0.58,0.0);
        glVertex3f(-0.25,0.58,0.0);
        glVertex3f(-0.25,0.5,0.0);
    glEnd(); 

    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(300,200);
    glutCreateWindow("Ajaw");

    glClearColor(0.0,0.0,0.0,0.0);
    glViewport(0,0,500,500);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(1.0,1.0,-1.0,1.0,-1.0,1.0);
    glShadeModel(GL_FLAT);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}