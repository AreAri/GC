/*Areli Arisai Meza Rendon - AreAri
  Rotar el punto de 2 lineas*/

#include <GL/glut.h> 
double vx =100.0;
double vy =400.0;

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
  glutCreateWindow("Rotacion de linea");
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
  glColor3f(0,255,255);//cian
  glPushMatrix();

  //El primer segmento del brazo
  glBegin(GL_LINES); 
    glVertex3f(vx, vy, 0) ;
    glVertex3f(250,250,0); 
  glEnd();

   //2do brazo (la sombra)
  glColor3f(0,0,255);//azul
  glBegin(GL_LINE_LOOP); 
    glVertex3f(vx, vy, 0) ; 
    glVertex3f(300,300,0); 
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
      if ((key=='D') || (key == 'd'))//rotar a derecha
      {
       vx += 10; 
      }
      else
        if ((key=='A') || (key == 'a'))//rotar a izquierda
        {
          vx -= 10;
        }
        else
      if ((key=='w') || (key == 'W'))//rotar arriba
      {
       vy += 10; 
      }
      else
        if ((key=='S') || (key == 's'))//rotar abajo
        {
          vy -= 10;
        }
   //glLoadIdentity();
   //glutSwapBuffers();
   glutPostRedisplay();//refrescar
}