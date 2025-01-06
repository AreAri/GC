#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/freeglut.h>
void display(void);
int main (int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE| GLUT_DEPTH); //diferentes maneras 
    glutInitWindowSize (500,500); //tamaño de la ventana
    glutInitWindowPosition (100,100); //donde aparecera en coordenadas
    glutCreateWindow ("Mi primer Ventanita"); //nombre de la ventana
    glClearColor(1.0,1.0,1.0,0.0); //se limpia el color de fondo poniendo un nueco color
    glutDisplayFunc(display); //se manda a llama la funcion display
    glutMainLoop ();
    return 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    //glColor3f(1.0,0.0,0.0); //rojo    3f significa flotante
    glColor3f(0.0,0.0,0.0); //negro
    //crear linea
    /*glBegin(GL_LINES); //donde iniciara
    //se ingresan las coordenadas del punto de inicio y final
        glVertex2f(0.0,0.0);
        glVertex2f(100.0,100.0);
    glEnd(); //punto donde termina*/
    /*glBegin(GL_LINES);
        glVertex3f(0.0,0.0,0.0);
        glVertex3f(100.0,100.0,100.0);
    glEnd();*/
    /*glBegin(GL_LINE_LOOP); 
        glVertex2f(1.0,1.0);
        glVertex2f(100.0,150.0);
        glVertex2f(200.0,150.0);
        glVertex2f(200.0,250.0);
    glEnd();*/
    glBegin(GL_TRIANGLES); 
        glVertex3f(15.0,20.0,0.0);
        glVertex3f(100.0,150.0,0.0);
        glVertex3f(200.0,150.0,0.0);
       // glVertex3f(200,250,0);
    glEnd();
    glFlush();
}