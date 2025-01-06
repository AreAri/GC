/*Programa para dibujar dos segmentos giratorios, unidos.
Areli Arisai Meza Rendon - AreAri */

#include <GL/freeglut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// Definición de variables globales 
double Vector1[4] = {90, 0, 0, 1}; //hombro y humero
double Vector2[4] = {0, 90, 0, 1}; //codo y radio
double center[2] = {250, 250}; // Centro de rotación

//Registro para almacenar un punto y la matriz de transformación
typedef struct
{
	double posicion[4];   // Para representar la posición del cuerpo en el espacio
	double matriz[4][4];  // Matriz que se utilizará para rotar y trasladar la figura
} body;

/*Multiplicacion de una matrix 4x4 por un vector de longitud 4, salida en vector c.
Esta función, así como la de rotar y trasladar, se encargan de las operaciones 
matemáticas necesarias para transformar los vectores al espacio 3D*/
void Matriz_X_Vector(double matrix[4][4], double vector[4], double *c)
{
	for (int i = 0; i < 4; i++)
		c[i] = matrix[i][0] * vector[0] +
				matrix[i][1] * vector[1] +
				matrix[i][2] * vector[2] + matrix[i][3] * vector[3];
}

/*Funcion para rotar el punto definido por el vectorGlobal (X,Y,Z,1) en un angulo angle.
Estamos rotando el  brazo alrededor de la articulación.*/
void rotar(double *vector, double angle)
{
	double seno = sin(angle);
	double coseno = cos(angle);
	double vectortemp[4];
	//Matriz utilizada para realizar la rotación.
	double matrizRot[4][4] = {{coseno, -seno, 0, 0}, 
			    {seno,  coseno, 0, 0},
			    {   0,       0, 1, 0},
			    {   0,       0, 0, 1}};

	Matriz_X_Vector(matrizRot, vector, vectortemp);
	for (int i = 0; i < 4; i++)
		vector[i] = vectortemp[i];
}

/*Funcion para trasladar el vector con salida en el vector vectorout,
es decir, para trasladar el extremo del brazo robótico al centro de 
rotación*/
void trasladar(double *vector, double *vectorout, double center[2])
{
	//Matriz utilizada pra realizar la traslación.
	double matrizTras[4][4] = {{1, 0, 0, center[0]},
			      {0, 1, 0, center[1]},
			      {0, 0, 1, 0},
			      {0, 0, 0, 1}};
	Matriz_X_Vector(matrizTras, vector, vectorout);
}

/* Función que inicializa OpenGL
    -Dentro de ella se establece el color de borrado y
    -el sombreado. */
static void init01(void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);  // clear to color RGB A
	glShadeModel(GL_FLAT); // The default value is GL_SMOOTH
}

/* Función para visualizar.
    -Limpia la pantalla,
    -dibuja los segmentos y
    -actualiza. */
static void display01(void)
{
	double vectortemp1[4]; // hombro y humero
	double vectortemp2[4]; // codo y radio
	trasladar(Vector1, vectortemp1, center);//Para calcular la posición del brazo, traslada el vector al centro de la ventana.
	glClear(GL_COLOR_BUFFER_BIT);  //limpiar ventana en el color del clear color definido en glClearColor()
  	glColor3f(128,0.0,128.0); // Color morado hombro y humero

	//PARA LAS TRANSFORMACIONES
	//HOMBRO Y HUMERO
	//glPushMatrix();//Es una pila de matrices para graficar.
    //Dibujando líneas para representar el brazo.
    //El primer segmento del brazo
	glBegin(GL_LINES); //se define que se dibujaran lineas
		glVertex3f(center[0], center[1], 0); //primer punto para dibujar 
		glVertex3f(vectortemp1[0], vectortemp1[1], vectortemp1[2]); // segundo punto de la linea
	glEnd();
	//glPopMatrix(); //Es una pila de matrices para gráficar
	
	//CODO Y RADIO
	glColor3f(0.0, 0.0, 128.0); //color lila 
	glPushMatrix();
	double center2[2] = {vectortemp1[0], vectortemp1[1]};
	trasladar(Vector2, vectortemp2, center2);
	glBegin(GL_LINES); 
		glVertex3f(vectortemp1[0], vectortemp1[1], vectortemp1[2]);
		glVertex3f(vectortemp2[0], vectortemp2[1], vectortemp2[2]); //esto hay que cambiarlo ^.^
	glEnd(); 
	//glPopMatrix();
	
	glFlush (); // el dibujo, no será visible de incio. Use glutSwapBuffers(); if GLUT_DOUBLE
  	glutSwapBuffers(); //el dibujo será visible desde inicio.
  	glutPostRedisplay();//refrescar la ventana
}

/* Función que ajusta la vista, se llama cuando la ventana cambia de 
  tamaño. */
static void reshape01(int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); // set view to ALL
   glMatrixMode (GL_PROJECTION); // use PROJECTION matrix
   glLoadIdentity (); // and load it...
   // set to whole screen
   gluOrtho2D (0.0, (GLdouble) w, 0.0, (GLdouble) h);
}

/* Función para manejar eventos del teclado */
static void keyboard01(unsigned char key, int x, int y)
{
	if((key == 0x1b)||(key == 'q')||(key == 'Q'))
      exit(0); // terminar programa
  	else
  	//rotar ambos en sentidos diferentes
	if ((key == 'R') || (key == 'r'))
	{
		rotar(Vector1, 0.1);
		rotar(Vector2, -0.1);
		//rotar(Vector2, -0.1);
	}
	else
	//holaaaaaaaaaaaaaa (codo y radio)
	if ((key == 'H') || (key == 'h'))
	{
		rotar(Vector2, 0.1);
	}
	else
	if ((key == 'I') || (key == 'i'))
	{
		rotar(Vector2, -0.1);
	}
	glutSwapBuffers();//Para intercambiar los buffers de color de la ventana, hace que el dibujo sea visible.
   	glutPostRedisplay();//refrescar
}
/*  Función principal, en ella:
    -Se establece la configuración del todo,
    -se inicializa GLUT, 
    -se crea la ventana y
    -se mandan llamar las funciones necesarias. */
int main(int argc, char *argv[]) 
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(300, 200);
  glutCreateWindow("MI PRIMER BRACITO UwU");
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