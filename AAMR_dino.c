//peluche de chiwi jiji
#include <GL/glut.h>
#include <GL/glut.h>
#include <stdio.h>

void display() 
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,1.0,0.0);

    glBegin(GL_POLYGON); //cabeza
        glVertex2f(0.0,0.0);
        glVertex2f(0.0,0.6);
        glVertex2f(0.5,0.6);
        glVertex2f(0.8,0.4);
        glVertex2f(0.8,0.1);
        glVertex2f(0.7,0.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1.0,1.0,1.0);
        glVertex2f(0.1,0.3);
        glVertex2f(0.1,0.5);
        glVertex2f(0.3,0.5);
        glVertex2f(0.3,0.3);

        glColor3f(0.0,0.0,0.0);
        glVertex2f(0.1,0.4);
        glVertex2f(0.1,0.5);
        glVertex2f(0.2,0.5);
        glVertex2f(0.2,0.4);

        glColor3f(0.5,0.7,0.5);
        glVertex2f(0.6,0.1);
        glVertex2f(0.7,0.1);
        glVertex2f(0.7,0.2);
        glVertex2f(0.6,0.2);

    glEnd();

    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON); //torso
        glVertex2f(0.0,0.0);
        glVertex2f(0.0,-0.65);
        glVertex2f(0.1,-0.8);
        glVertex2f(0.5,-0.8);
        glVertex2f(0.5,0.0);
    glEnd();

    glBegin(GL_POLYGON); //cola
        glVertex2f(0.0,-0.6);
        glVertex2f(0.1,-0.8);
        glVertex2f(-0.2,-0.8);
        glVertex2f(-0.2,-0.6);
    glEnd();
    glBegin(GL_POLYGON); 
        glVertex2f(-0.2,-0.6);
        glVertex2f(-0.2,-0.8);
        glVertex2f(-0.4,-0.8);
        glVertex2f(-0.5,-0.6);
        glVertex2f(-0.4,-0.5);
    glEnd();

    glBegin(GL_TRIANGLES); //cola
        glColor3f(0.5,0.7,0.5);
        glVertex2f(-0.5,-0.6);
        glColor3f(0.0,1.0,0.0);
        glVertex2f(-0.4,-0.5);
        glVertex2f(-0.6,-0.4);
    glEnd();

    glBegin(GL_POLYGON); 
        glVertex2f(0.4,-0.1);
        glVertex2f(0.3,-0.2);
        glVertex2f(0.4,-0.35);
        glVertex2f(0.55,-0.35);
        glVertex2f(0.55,-0.2);
    glEnd();

    glBegin(GL_POLYGON); 
        glVertex2f(0.55,-0.2);
        glVertex2f(0.55,-0.35);
        glVertex2f(0.7,-0.35);
        glVertex2f(0.75,-0.25);
        glVertex2f(0.7,-0.15);
        glVertex2f(0.65, -0.1);
    glEnd();

    glBegin(GL_POLYGON); 
        glVertex2f(0.4,-0.4);
        glVertex2f(0.2,-0.5);
        glVertex2f(0.2,-0.7);
        glVertex2f(0.4,-0.8);
        glVertex2f(0.6,-0.7);
        glVertex2f(0.6, -0.5);
    glEnd();

    glBegin(GL_POLYGON); 
        glVertex2f(0.4,-0.8);
        glVertex2f(0.5,-0.85);
        glVertex2f(0.8,-0.85);
        glVertex2f(0.6,-0.7);
        
    glEnd();
glColor3f(1.0,0.4,0.7);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.2,0.6);
        glVertex2f(0.1,0.7);
        glVertex2f(0.0,0.6);

        glVertex2f(0.0,0.6);
        glVertex2f(-0.1,0.5);
        glVertex2f(0.0,0.4);

        glVertex2f(0.0,0.4);
        glVertex2f(-0.1,0.3);
        glVertex2f(0.0,0.2);

        glVertex2f(0.0,0.2);
        glVertex2f(-0.1,0.1);
        glVertex2f(0.0,0.0);

        glVertex2f(0.0,0.0);
        glVertex2f(-0.1,-0.1);
        glVertex2f(0.0,-0.2);

        glVertex2f(0.0,-0.2);
        glVertex2f(-0.1,-0.3);
        glVertex2f(0.0,-0.4);

        glVertex2f(0.0,-0.4);
        glVertex2f(-0.1,-0.5);
        glVertex2f(0.0,-0.6);

    glEnd();

    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(300,200);
    glutCreateWindow("Yo no jui");

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