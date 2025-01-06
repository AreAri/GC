/*Meza Rendon Areli Arisai - AreAri
  Formar un cubo?*/

#include <GL/glut.h>
static void display(void) 
{
  glClear(GL_COLOR_BUFFER_BIT); 
  glColor3f(0, 0, 255); //azul

  //1ra cara de la figura... 
  glBegin(GL_LINE_LOOP);
    glVertex3f(0,0,0); //inicio
    glVertex3f(0,150,0); //vertical
    glVertex3f(100,150,0); //horizontal arriba
    glVertex3f (100,0,0); //horizontal abajo
  glEnd();

  //2a cara de la figura
  glBegin(GL_LINE_LOOP);
    glVertex3f(100,100,100); //inicio
    glVertex3f(100,250,100); //vertical
    glVertex3f(200,250,100); //horizontal arriba
    glVertex3f (200,100,100); //horizontal abajo
  glEnd();

  //union para cada cara, es decir, aparecen caras laterares, superior e inferior
  glBegin(GL_LINES);

   //lado derecho
    glVertex3f(100,0,0); //horizontal abajo cara 1
    glVertex3f(200,100,100); //horizontal abajo cara 2
    glVertex3f(100,150,0); //horizontal arriba cara 1
    glVertex3f(200,250,100); //horizontal arriba cara 2

    //lado izquierdo
    glVertex3f(0,0,0); //inicio cara 1
    glVertex3f(100,100,100); //inicio cara 2
    glVertex3f(0,150,0); //vertical cara 1
    glVertex3f(100,250,100); //vertical cara 2
  glEnd();
  
  glutSwapBuffers();
}

int main(int argc, char** argv) 
{
  glutInit(&argc, argv); 
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(300, 200);
  glutCreateWindow("La caja"); 
  glClearColor (1.0, 1.0, 1.0, 0.0);  
  glViewport (0, 0, (GLsizei) 500, (GLsizei) 500); 
  glMatrixMode (GL_PROJECTION); 
  glLoadIdentity (); 
  glOrtho(-255, 255, -255, 255, -255, 255);
  glShadeModel (GL_FLAT); 
  glutDisplayFunc(display); 
  glutMainLoop(); 
  return 0;
}