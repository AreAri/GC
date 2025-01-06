/*Areli Arisai Meza Rendon - AreAri
  Regresar la linea de derecha a izquierda y viseversa*/

#include <GL/glut.h> 
double variable =100.0;

//Prototipo funci�n
static void desplegar(void);
static void reshape01(int w, int h);
static void init01(void);
static void keyboard01(unsigned char key, int x, int y);

int main(int argc, char *argv[]) 
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(300, 200);
  glutCreateWindow("Dezplazamiento linea");
  init01();
  glutDisplayFunc(desplegar);
  glutReshapeFunc(reshape01);
  glutKeyboardFunc(keyboard01); 
  glutMainLoop();
  return 0;
}

static void desplegar(void)
{
  glClear(GL_COLOR_BUFFER_BIT); 
  glColor3f(0,0,255);//azul
  glPushMatrix();

  //El primer segmento del brazo
  glBegin(GL_LINES); //se define que se dibujaran lineas
    glVertex3f(variable, 400, 0) ; //primer punto para dibujar (punto en movimiento)
    glVertex3f(250,250,0); // segundo punto de la linea (centro)
  glEnd();
  glPopMatrix();
  glutSwapBuffers();
}

// se llama cuando la ventana cambia de tama�o
static void reshape01(int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); // Establecer vista
   glMatrixMode (GL_PROJECTION); // Usando la matriz de proyecci�n
   glLoadIdentity (); //y cargandola
   // pantalla completa
   gluOrtho2D (0.0, (GLdouble) w, 0.0, (GLdouble) h);
}

//Valores de inicio
static void init01(void) 
{
   glClearColor (1.0, 1.0, 1.0, 0.0);  // claro a color RGB A
   glShadeModel (GL_FLAT); // El valor default es GL_SMOOTH
}


// Llamado en cada caracter del TECLADO
static void keyboard01(unsigned char key, int x, int y)
{
   if((key == 0x1b)||(key == 'q')||(key == 'Q'))
      exit(0); // terminar programa
   else
      if ((key=='R') || (key == 'r'))//rotar a derecha
      {
       variable += 10; 
      }
      else
        if ((key=='L') || (key == 'l'))//rotar a izquierda
        {
          variable -= 10;
        }
   //glLoadIdentity();
   //glutSwapBuffers();
   glutPostRedisplay();//refrescar
}
