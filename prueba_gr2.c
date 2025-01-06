
#include <GL/glut.h>

static void display(void) { //static para que solo se llame en este proyecto

  glClear(GL_COLOR_BUFFER_BIT); //limpiar ventana en el color del clear color definido en glClearColor()
  //glColor3f(1, 0, 0);//Rojo
  glColor3f(0,0,0);//Negro

  // Dibujamos la línea en 2D y 3D.

  /*glBegin(GL_LINES);
    glVertex2f(160, 50.0);
    glVertex2f(100.0, 100.0);
    glVertex2f(300, 140);
    glVertex2f(250.0, 100.0);
  glEnd();

  glBegin(GL_LINE_LOOP);//glBegin(GL_LINE_LOOP); //se define que se dibujaran lineas
    glVertex3f(0.0, 0, 0) ; //primer punto de la 1er linea
    glVertex3f(100,150,0); // segundo punto de la 1er línea
    glVertex3f(200,150,0); // primer punto de la 2da linea
    glVertex3f(200,250,0); // segundo punto de la 2da linea
  glEnd();

  glBegin(GL_TRIANGLES);
    glVertex2f(150.0, 150.0); //1er vertice
    glVertex2f(200.0, 100.0); //2do vertice
    glVertex2f(150.0, 100.0); //3er vertice
  glEnd();*/

  glBegin(GL_TRIANGLE_STRIP);
    //Pentagono invertido dentro de otro
    glVertex2f(30, 0);
    glVertex2f(130.0, 0.0);
    glVertex2f(160.0, 95.0);
    glVertex2f(80.0, 153.0);
    glVertex2f(0,95);
    glVertex2f(30,0);
    glVertex2f(130.0, 0.0);

    //Pentagono relleno
    /*glVertex2f(130, 0);
    glVertex2f(30,0);
    glVertex2f(160.0, 95.0);
    glVertex2f(0,95);
    glVertex2f(80,153);*/
    //glVertex2f(30,0);
    //glVertex2f(130.0, 0.0);

    /*glVertex3f(0.0, 0, 0) ; 
    glVertex3f(100,150,0); 
    glVertex3f(200,150,0); 
    glVertex3f(200,250,0); 
    glVertex3f(300,350,0);
    glVertex3f(300,350,0);*/
  glEnd();



  // Actualizamos la ventana.
  glutSwapBuffers();
}

int main(int argc, char** argv) {
  // Inicializa la biblioteca GLUT
  glutInit(&argc, argv); //glutInit: Inicializa la biblioteca GLUT.
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  // Crea una ventana
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(300, 200);
  glutCreateWindow("Mi primera ventana"); //glutCreateWindow: Crea una ventana de visualización.

  glClearColor (1.0, 1.0, 1.0, 0.0);  // clear to color RGB A
  glViewport (0, 0, (GLsizei) 500, (GLsizei) 500); // establecemos las coordenadas ancho y alto de viewport
  glMatrixMode (GL_PROJECTION); // Usando la matriz de proyección
  glLoadIdentity (); // cargandola
   // Establecer en pantalla completa
  gluOrtho2D (0.0, (GLdouble) 500, 0.0, (GLdouble) 500);
  glShadeModel (GL_FLAT); // El valor default es GL_SMOOTH
  // Establecemos la función de dibujo.
  glutDisplayFunc(display); //glutDisplayFunc: Define la función que se llama cada vez que se actualiza la ventana.

  

  // Inicia el bucle de renderización
  glutMainLoop(); //glutMainLoop: Inicia el bucle de renderización.

  return 0;
}
