/*Nuestro primer ejemplito
OpenGL, GLUT

GLUT es una biblioteca de gráficos, de proposito general, 
nos permite operaciones de renderización de OpenGL.

GLUT es multiplataforma, OSX, Windows, Linux

glutInit -> inicializar las bibliotecas de GLUT
glutCreateWindow -> Crear ventana de visualización

*/
#include <GL/glut.h>
//<OpenGL/glut.h>

void display(void); //prototipo de la función

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  //glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(200, 200);
  glutCreateWindow("Mi primer ventanita");

  glClearColor (1.0, 1.0, 1.0, 0.0); 
  //glClearColor(0.0, 0.0, 0.0, 0.0);
  

  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 0.0, 0.0);//rojo
  //glColor3f(0.0, 0.0, 0.0); //negro

  glBegin(GL_LINE_LOOP); //GL_LINES
    glVertex3f(0.0, 0, 0); //punto inicio
    glVertex3f(100,150,0);  //Punto final
    glVertex3f(200,150,0); 
    glVertex3f(150,250,0);
  glEnd();

  glBegin(GL_TRIANGLES);
    glVertex2f(0.0, 0.0); 
    glVertex2f(100.0,150.0); 
    glVertex2f(200.0,150.0); 
    //glVertex3f(150,250,0);
  glEnd();

  //glFlush();
  glutSwapBuffers(); //Para GLUT DOUBLE
}

































