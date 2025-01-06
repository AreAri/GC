/* Areli Arisai Meza Rendon - AreAri
    INSTRUCCIONES
        En c, utilizando opengl realizar un menu que tenga:
            -Dibujar una figura:
                -1 Triangulo
                -2 Cuadrado
                -3 Cubo
                -4 Prisma triangular
            -Colores
                -1 Amarillo
                -2 Rojo
                -3 Verde
                -4 Azul
                -5 Morado
            -Movimiento
                -Movimiento en los ejes x, y, z
            -keyboard
                -Utilizar para el cambio de color
            -SpecialKeys, Flechas
                -GLUT_KEY_RIGTH
                    eje_x+=5
                -GLUT_KEY_LEFT
                    eje_y+=5
                -GLUT_KEY_UP
                    eje_z+=5
                -GLUT_KEY_DOWN
                    -Terminar
*/
#include <stdio.h>
#include <GL/glut.h>

// Colores
float R = 0;
float G = 0;
float B = 0;
float R2 = 0;
float G2 = 0;
float B2 = 0;

//movimiento
double eje_x = 0.0;
double eje_y = 0.0;
double eje_z =0.0;

void triangulo()
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glRotatef(eje_x, 1.0, 0.0, 0.0);
  	glRotatef(eje_y, 0.0, 1.0, 0.0);
  	glRotatef(eje_z, 0.0, 0.0, 1.0);
    
    glBegin(GL_TRIANGLES);
        glColor3f(R, G, B);
	    glVertex3f(0.0, 0.5, 0.0);
        glColor3f(R2, G2, B2);
	    glVertex3f(-0.5, -0.5, 0.0);
	    glVertex3f(0.5, -0.5, 0.0);
    glEnd();
    glFlush();
}

void cuadrado()
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glRotatef(eje_x, 1.0, 0.0, 0.0);
  	glRotatef(eje_y, 0.0, 1.0, 0.0);
  	glRotatef(eje_z, 0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
        glColor3f(R2, G2, B2);
	    glVertex3f(-0.25, -0.25, 0.0); //inferior i
	    glVertex3f(0.25, -0.25, 0.0); //inferior d
        glColor3f(R, G, B);
	    glVertex3f(0.25, 0.25, 0.0); //superior d
	    glVertex3f(-0.25, 0.25, 0.0); //superior i
    glEnd();
    glFlush();
}

void cubo()
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glRotatef(eje_x, 1.0, 0.0, 0.0);
  	glRotatef(eje_y, 0.0, 1.0, 0.0);
  	glRotatef(eje_z, 0.0, 0.0, 1.0);

    //frente
    glBegin(GL_POLYGON);
        glColor3f(R2, G2, B2);
	    glVertex3f(-0.25, -0.25, 0.25); //inferior i
	    glVertex3f(0.25, -0.25, 0.25); //inferior d
        glColor3f(R, G, B);
	    glVertex3f(0.25, 0.25, 0.25); //superior d
	    glVertex3f(-0.25, 0.25, 0.25); //superior i
    glEnd();

    //atras
    glBegin(GL_POLYGON);
        glColor3f(R2, G2, B2);
	    glVertex3f(-0.25, -0.25, -0.25); //inferior i
	    glVertex3f(0.25, -0.25, -0.25); //inferior d
        glColor3f(R, G, B);
	    glVertex3f(0.25, 0.25, -0.25); //superior d
	    glVertex3f(-0.25, 0.25, -0.25); //superior i
    glEnd();

  	//izquierda
    glBegin(GL_POLYGON);
        glColor3f(R2, G2, B2);
	    glVertex3f(-0.25, -0.25, 0.25);  // Inferior f
        glColor3f(R, G, B);
	    glVertex3f(-0.25, 0.25, 0.25);   // Superior f
	    glVertex3f(-0.25, 0.25, -0.25);  // Superior a
        glColor3f(R2, G2, B2);
	    glVertex3f(-0.25, -0.25, -0.25); // Inferior a
    glEnd();

    //derecha
    glBegin(GL_POLYGON);
        glColor3f(R2, G2, B2);
	    glVertex3f(0.25, -0.25, 0.25);  // Inferior  f
        glColor3f(R, G, B);
	    glVertex3f(0.25, 0.25, 0.25);   // Superior f
	    glVertex3f(0.25, 0.25, -0.25);  // Superior a
        glColor3f(R2, G2, B2);
	    glVertex3f(0.25, -0.25, -0.25); // Inferior a
    glEnd();

    //arriba
    glBegin(GL_POLYGON);
        glColor3f(R, G, B);
	    glVertex3f(-0.25, 0.25, 0.25);  // Frontal i
	    glVertex3f(0.25, 0.25, 0.25);   // Frontal d
	    glVertex3f(0.25, 0.25, -0.25);  // Trasera d
	    glVertex3f(-0.25, 0.25, -0.25); // Trasera i
    glEnd();

    // Cara inferior
    glBegin(GL_POLYGON);
        glColor3f(R2, G2, B2);
	    glVertex3f(-0.25, -0.25, 0.25);  // Frontal i
	    glVertex3f(0.25, -0.25, 0.25);   // Frontal d
	    glVertex3f(0.25, -0.25, -0.25);  // Trasera d
	    glVertex3f(-0.25, -0.25, -0.25); // Trasera i
    glEnd();

    glFlush();
}

void prismaT()
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glRotatef(eje_x, 1.0, 0.0, 0.0);
  	glRotatef(eje_y, 0.0, 1.0, 0.0);
  	glRotatef(eje_z, 0.0, 0.0, 1.0);
    
    //frente
    glBegin(GL_TRIANGLES);
        glColor3f(R, G, B);
	    glVertex3f(0.0, 0.5, 0.0); //c
        glColor3f(R2, G2, B2);
	    glVertex3f(-0.5, -0.5, 0.0);//i
	    glVertex3f(0.5, -0.5, 0.0);//d
    glEnd();

    //atras
    glBegin(GL_TRIANGLES);
        glColor3f(R, G, B);
	    glVertex3f(0.0, 0.5, -0.9);//c
        glColor3f(R2, G2, B2);
	    glVertex3f(-0.5, -0.5, -0.9);//i
	    glVertex3f(0.5, -0.5, -0.9);//d
    glEnd();

    //izquierda
    glBegin(GL_POLYGON);
        glColor3f(R, G, B);
	    glVertex3f(0.0, 0.5, 0.0); //C F
        glColor3f(R2, G2, B2);
	    glVertex3f(-0.5, -0.5, 0.0);// I F
	    glVertex3f(-0.5, -0.5, -0.9);//I A
        glColor3f(R, G, B);
	    glVertex3f(0.0, 0.5, -0.9);//C A
    glEnd();
    
    //derecha
    glBegin(GL_POLYGON);
        glColor3f(R, G, B);
	    glVertex3f(0.0, 0.5, 0.0); //C F
        glColor3f(R2, G2, B2);
	    glVertex3f(0.5, -0.5, 0.0);// d F
	    glVertex3f(0.5, -0.5, -0.9);//d A
        glColor3f(R, G, B);
	    glVertex3f(0.0, 0.5, -0.9);//C A
    glEnd();

    //derecha
    glBegin(GL_POLYGON);
        glColor3f(R2, G2, B2);
        glVertex3f(-0.5, -0.5, 0.0); //f i
        glVertex3f(0.5, -0.5, 0.0);// f d
        glVertex3f(0.5, -0.5, -0.9);//a d
        glVertex3f(-0.5, -0.5, -0.9);//a i
    glEnd();
    glFlush();
}

void specialKeys (int key, int x, int y)
{
    if (key == GLUT_KEY_RIGHT)
    	{
	    	eje_x +=5;
    	}
       else
       	if (key == GLUT_KEY_LEFT)
       	{
	       eje_y +=5;
       	}
       else
       	if (key == GLUT_KEY_UP)
       	{
	       eje_z +=5;
       	}
       else
       	if (key == GLUT_KEY_DOWN)
       {
	       exit(0); 
       }
     
   glutSwapBuffers();//Para intercambiar los buffers de color de la ventana, hace que el dibujo sea visible.
   glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB| GLUT_DEPTH);
    glutInitWindowSize(400, 400);  // Tamaño de la ventana
    glutInitWindowPosition(300, 200);
    glutCreateWindow("Menu de locura");
    int opF;
    int opC;
    printf("Ingrese un valor para seleccionar una figura:\n");
    printf("1 Triangulo\n");
    printf("2 Cuadrado\n");
    printf("3 Cubo\n");
    printf("4 Prisma Triangular\n");
    printf("Opcion: ");
    scanf("%d", &opF);
    printf("Ingrese un valor para seleccionar el color:\n");
    printf("1 Amarillo\n");
    printf("2 Rojo\n");
    printf("3 Verde\n");
    printf("4 Azul\n");
    printf("5 Morado\n");
    printf ("opcion: ");
    scanf("%d", &opC);

    switch (opF)
    {
    case 1:
        glutDisplayFunc(triangulo);
        break;
    case 2:
        glutDisplayFunc(cuadrado);
        break;
    case 3:
        glutDisplayFunc(cubo);
        break;
    case 4:
        glutDisplayFunc(prismaT);
        break;
    }

    //Menu colores
    switch (opC)
    {
    	case 1:
	        R = 1.0;
	        G = 1.0;
	        B = 0.0;
            R2 = 0.5;
            G2 = 0.5;
            B2 = 0.0;
	        break;
    	case 2:
	        R = 1.0;
	        G = 0.0;
	        B = 0.0;
            R2 = 0.5;
            G2 = 0.0;
            B2 = 0.0;
	        break;
	    case 3:
	        R = 0.0;
	        G = 1.0;
	        B = 0.0;
            R2 = 0.0;
            G2 = 0.5;
            B2 = 0.0;
	        break;
	    case 4:
	        R = 0.0;
	        G = 0.0;
	        B = 1.0;
            R2 = 0.0;
            G2 = 0.0;
            B2 = 0.5;
	        break;
	    case 5:
	        R = 0.56;
	        G = 0.0;
	        B = 0.56;
            R2 = 0.28;
            G2 = 0.0;
            B2 = 0.28;
	        break;
    }
    glClearColor(1.0, 1.0, 1.0, 1.0);  // Color de fondo negro
    glutSpecialFunc(specialKeys);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
