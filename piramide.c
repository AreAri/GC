/*Areli Arisai Meza Rendon - AreAri
   Intento de piramide */

#include <GL/freeglut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

//variables a rotar
double eje_x = 0.0;
double eje_y = 0.0;
double eje_z =0.0;

static void init01(void) 
{
   glClearColor (1.0, 1.0, 1.0, 0.0);  
   glShadeModel (GL_SMOOTH); 
}

static void display01(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  
  glRotatef(eje_x, 1.0, 0.0, 0.0);
  glRotatef(eje_y, 0.0, 1.0, 0.0);
  glRotatef(eje_z, 0.0, 0.0, 1.0);

//enfrente
  glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.0,0.28);//azul
    glVertex3f(0.0,0.5,0.0);
    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(0.5,-0.5,0.5); 
  glEnd();

//derecha
  glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.28,0.28);//verde aceituna
    glVertex3f(0.0,0.5,0.0);
    glVertex3f(0.5,-0.5,0.5);   
    glVertex3f(0.5,-0.5,-0.5); 
  glEnd();

//atras
  glBegin(GL_TRIANGLES);
    glColor3f(0.28,0.0,0.28);//uva
    glVertex3f(0.0,0.5,0.0);   
    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(-0.5,-0.5,-0.5); 
  glEnd();

 //izquierda
  glBegin(GL_TRIANGLES);
    glColor3f(0.28,0.28,0.28);//gris
    glVertex3f(0.0,0.5,0.0);   
    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(-0.5,-0.5,0.5); 
  glEnd();
   
  glFlush (); // el dibujo, no será visible de incio. Use glutSwapBuffers(); if GLUT_DOUBLE
  glutSwapBuffers(); //el dibujo será visible desde inicio.
  glutPostRedisplay();//refrescar la ventana
}

static void reshape01(int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); // set view to ALL
   glMatrixMode (GL_PROJECTION); // use PROJECTION matrix
   glLoadIdentity (); // and load it...
   // set to whole screen
   gluOrtho2D (0.0, (GLdouble) w, 0.0, (GLdouble) h);
}

/*
  Función que maneja los eventos de teclado.
*/
static void keyboard01(unsigned char key, int x, int y)
{
   if((key == 0x1b)||(key == 'q')||(key == 'Q'))
      exit(0); // terminar programa
   else
     if ((key=='X') || (key == 'x'))//Rotar, se llama función rotar()
       {
          eje_x +=5;
       }
       else
     if ((key=='Y') || (key == 'y'))//Rotar, se llama función rotar()
       {
         eje_y +=5;
       }
       else
     if ((key=='Z') || (key == 'z'))//Rotar, se llama función rotar()
       {
         eje_z +=5;
       }
        else
     if ((key=='s') || (key == 'S'))//Rotar, se llama función rotar()
       {
         eje_z -=5;
       }
   glutSwapBuffers();//Para intercambiar los buffers de color de la ventana, hace que el dibujo sea visible.
   glutPostRedisplay();//refrescar
}

int main(int argc, char *argv[]) {


  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(300, 200);
  glutCreateWindow("Piramide ^o^");

  //HABILITAR PRUEBA DE PROFUNDIDAD DEL Z_BUFFER
  glEnable(GL_DEPTH_TEST);

  init01();

  //Para imprimir la cadena de que se utiliza para los render y la versión de OPENGL
  const GLubyte* renderer = glGetString(GL_RENDERER); //Obtener cadena Render
  const GLubyte* version = glGetString(GL_VERSION); // Obtener cadena versión

  printf("Renderer: %s\n", renderer);
  printf("Versión de OpenGL que soporta: %s\n", version);
  glutDisplayFunc(display01);
  glutReshapeFunc(reshape01);
  glutKeyboardFunc(keyboard01);
  glutMainLoop();
  return 0;
} 
