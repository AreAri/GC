/*Programa para dibujar dos segmentos giratorios, unidos.*/

//LIBRERÍAS NECESARIAS
#include <GL/freeglut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

//~~~~~Vamos a trabajar con rotate
//VARIABLES GLOBALES
double eje_x = 0.0;
double eje_y = 0.0;
double eje_z =0.0;

static void init01(void) 
{
   glClearColor (1.0, 1.0, 1.0, 0.0);  // clear to color RGB A
   glShadeModel (GL_SMOOTH); // gl_flat
}

/*
  Función para visualizar.
    -Limpia la pantalla,
    -dibuja los segmentos y
    -actualiza.
*/
static void display01(void)
{
  //limpiar ventana y el buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //resetea todo, matriz identidad 
  glLoadIdentity();
  
  //glPushMatrix();
  glRotatef(eje_x, 1.0, 0.0, 0.0);
  glRotatef(eje_y, 0.0, 1.0, 0.0);
  glRotatef(eje_z, 0.0, 0.0, 1.0);

  
  glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.0,0.28);
    glVertex3f(0.0,0.8,0.0);

    glColor3f(1.0,0.28,0.28);
    glVertex3f(-0.6,-0.5,0.0);

    glColor3f(0.28,0.0,0.28);
    glVertex3f(0.6,-0.5,0.0); 
  glEnd();

  //glPopMatrix();
  
  /*glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.0,0.28);
    glVertex3f(0.0,0.5,0.0);
    glVertex3f(-0.5,-0.4,0.0);
    glVertex3f(0.5,-0.4,0.0); 
  glEnd();*/
  
   
  glFlush (); // el dibujo, no será visible de incio. Use glutSwapBuffers(); if GLUT_DOUBLE
  glutSwapBuffers(); //el dibujo será visible desde inicio.
  glutPostRedisplay();//refrescar la ventana
}



/*
  Función que ajusta la vista, se llama cuando la ventana cambia de 
  tamaño.
*/
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

/* 
  Función principal, en ella:
    -Se establece la configuración del todo,
    -se inicializa GLUT, 
    -se crea la ventana y
    -se mandan llamar las funciones necesarias.
*/
int main(int argc, char *argv[]) {


  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(300, 200);
  glutCreateWindow("Triangulito ^.^");

  //HABILITAR PRUEBA DE PROFUNDIDAD DEL Z_BUFFER
  //glEnable(GL_DEPTH_TEST)

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
