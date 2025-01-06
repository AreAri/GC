/* Codigo de proyecto final - Areli Arisai Meza Rendon
	El codigo consiste en crear a Gasparin en un formato 3d tratando de incluir los mismo movimientos como en su formato 2d (formato navideño)
	Puntos importantes a tomar en cuenta:
	Sus emociones:
		- Feliz ----- Listo
		- Enojado ---- Listo
		- Triste ----- Se convirtio en preocupacion ----- Listo
		- Neutro ------ Listo
	Sus movimientos:
		- Usando las teclas de flechas de la computadora ----- Listo
	Su Habilidad:
		- Cambiar emociones ------- Listo   
		- Desaparecer y reaparecer -------- Listo
*/
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

// Empieza le hipermega lista de variables....
float cuerpoPosX = 0.0;
float cuerpoPosy = 0.0;
// para poder validar y elegir las emociones
int neutral = 1; 
int sad = 0;
int enojo = 0;
int canto =0;
float clear_ojos = 1.0; //nos permitira desaparecer lo ojos junto con el cuerpo
int hi = 0;//aparecer al fantasma
float ghost_bye = 1.0; //nos permitira desaparecer el cuerpo
float Ghost_bye2 = 1.0;

/* Nueva funcion descubierta en clase
    Funciona cuando se cambia el tamaño de la ventana permitiendonos que asi se pueda ajustar la figura al tamaño de la ventana 
    sin que la figura se deforme.
*/
static void resize(int width, int height)
{
     const float ar = (float)width / (float)height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, ar, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
}

void ojos ()
{
	
	glColor4f(0.0, 0.0, 0.0, clear_ojos);
	if (neutral && !sad && !enojo && !canto) 
	{

		// ~~~~~~~~~ Neutral ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		//derecho
	    glPushMatrix();
		    glTranslatef(cuerpoPosX+0.3, cuerpoPosy + 0.06, -6); // Mueve el óvalo hacia atrás en el eje Z
		    // Escala para hacer el óvalo
		    glScalef(0.35, 0.65, 1.0);
		    // Dibuja un esferoide (que parece un óvalo cuando se escala)
		    glutSolidSphere(1.0, 50, 50);
	    glPopMatrix();

	    // izquierdo
	    glPushMatrix();
		    glTranslatef(cuerpoPosX-0.3, cuerpoPosy + 0.06, -6); 
		    glScalef(0.35, 0.65, 1.0);
		    glutSolidSphere(1.0, 50, 50);
	    glPopMatrix();
	}
	else if (!neutral && !sad && !enojo && !canto)
	{
		// ~~~~~~~~ feliz ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		//izquierdo
	    glPushMatrix();
		    glTranslatef(cuerpoPosX - 0.3, cuerpoPosy + 0.06, -6); 
		    glScalef(0.35, 0.65, 1.0); 
		    // Definir un plano para poder cortar la mitad del óvalo
		    GLdouble clipPlane[] = {0.0, 1.0, 0.0, 0.0};
		    glClipPlane(GL_CLIP_PLANE0, clipPlane);
		    glEnable(GL_CLIP_PLANE0);
		    // Dibuja el óvalo
		    glutSolidSphere(1.0, 50, 50);
		    glDisable(GL_CLIP_PLANE0);// Desactiva el plano de recorte después de dibujar
	    glPopMatrix();

	    //derecho
	    glPushMatrix();
		    glTranslatef(cuerpoPosX + 0.3, cuerpoPosy + 0.06, -6); 
		    glScalef(0.35, 0.65, 1.0); 
		    GLdouble clipPlane1[] = {0.0, 1.0, 0.0, 0.0};
		    glClipPlane(GL_CLIP_PLANE0, clipPlane1);
		    glEnable(GL_CLIP_PLANE0);
		    glutSolidSphere(1.0, 50, 50);
		    glDisable(GL_CLIP_PLANE0);
	    glPopMatrix();

	    //Sonrisa
	    glPushMatrix();
	    // 1er numero es la distancia de arriba abajo, 2do numero es de atras pa delante
		    glTranslatef(cuerpoPosX , cuerpoPosy -0.2, -5.9); 
		    glScalef(0.35, 0.65, 1.0); // Escala para hacer el óvalo
		    // primer numero angulo de rotacion
		    glRotated(180, 1, 0, 0); 
		    GLdouble clipPlane2[] = {0.0, 1.0, 0.0, 0.0};
		    glClipPlane(GL_CLIP_PLANE0, clipPlane2);
		    glEnable(GL_CLIP_PLANE0);
		    glutSolidSphere(1.0, 50, 50);
		    glDisable(GL_CLIP_PLANE0);
	    glPopMatrix();
	}
	else if (enojo)
	{
	    //~~~~~~~~~~~~~~ molesto ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	    //izquierdo
	    glPushMatrix();
		    glTranslatef(cuerpoPosX - 0.3, cuerpoPosy + 0.19, -6); 
		    glScalef(0.35, 0.65, 1.0); 
		    glRotated(180, 1, 0, 0);
		    GLdouble clipPlane[] = {0.0, 1.0, 0.0, 0.0};
		    glClipPlane(GL_CLIP_PLANE0, clipPlane);
		    glEnable(GL_CLIP_PLANE0);
		    glutSolidSphere(1.0, 50, 50);
		    glDisable(GL_CLIP_PLANE0);
	    glPopMatrix();

	    //derecho
	    glPushMatrix();
		    glTranslatef(cuerpoPosX + 0.3, cuerpoPosy + 0.19, -6); 
		    glScalef(0.35, 0.65, 1.0); 
		    glRotated(180, 1, 0, 0);
		    GLdouble clipPlane1[] = {0.0, 1.0, 0.0, 0.0};
		    glClipPlane(GL_CLIP_PLANE0, clipPlane1);
		    glEnable(GL_CLIP_PLANE0);
		    glutSolidSphere(1.0, 50, 50);
		    glDisable(GL_CLIP_PLANE0);
	    glPopMatrix();

	    //boca
	    glPushMatrix();
		    // 1er numero es la distancia de arriba abajo, 2do numero es de atras pa delante
		    glTranslatef(cuerpoPosX , cuerpoPosy -0.2, -5.9); 
		    glScalef(0.35, 0.65, 1.0); 
		    GLdouble clipPlane2[] = {0.0, 1.0, 0.0, 0.0};
		    glClipPlane(GL_CLIP_PLANE0, clipPlane2);
		    glEnable(GL_CLIP_PLANE0);
		    glutSolidSphere(1.0, 50, 50);
		    glDisable(GL_CLIP_PLANE0);
	    glPopMatrix();
	}
	else if (sad)
	{
		// ~~~~~~~~~~ Preocupado ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	    glPushMatrix();
		    glTranslatef(cuerpoPosX - 0.3, cuerpoPosy + 0.06, -6); 
		    glScalef(0.35, 0.65, 1.0); 
		    GLdouble clipPlane[] = {0.0, 1.0, 0.0, 0.0};
		    glClipPlane(GL_CLIP_PLANE0, clipPlane);
		    glEnable(GL_CLIP_PLANE0);
		    glutSolidSphere(1.0, 50, 50);
		    glDisable(GL_CLIP_PLANE0);
	    glPopMatrix();

	    //derecho
	    glPushMatrix();
		    glTranslatef(cuerpoPosX + 0.3, cuerpoPosy + 0.06, -6); 
		    glScalef(0.35, 0.65, 1.0); 
		    GLdouble clipPlane1[] = {0.0, 1.0, 0.0, 0.0};
		    glClipPlane(GL_CLIP_PLANE0, clipPlane1);
		    glEnable(GL_CLIP_PLANE0);
		    glutSolidSphere(1.0, 50, 50);
		    glDisable(GL_CLIP_PLANE0);
	    glPopMatrix();

		//boca
	    glPushMatrix();
	    // 1er numero es la distancia de arriba abajo, 2do numero es de atras pa delante
	    glTranslatef(cuerpoPosX , cuerpoPosy -0.2, -5.9); 
		    glScalef(0.35, 0.65, 1.0);
		    GLdouble clipPlane2[] = {0.0, 1.0, 0.0, 0.0};
		    glClipPlane(GL_CLIP_PLANE0, clipPlane2);
		    glEnable(GL_CLIP_PLANE0);
		    glutSolidSphere(1.0, 50, 50);
		    glDisable(GL_CLIP_PLANE0);
	    glPopMatrix();
	}

}

void gorrito ()
{
	// parte de abajo del gorrito
    glPushMatrix();
    	glColor3f(0.0, 0.5, 0.0);
	    glTranslated(cuerpoPosX, cuerpoPosy + 0.9, -6); 
	    glRotated(90, 1, 0, 0);
	    glutSolidTorus(0.2, 0.6, 50, 50);
    glPopMatrix();

    //medio
    glPushMatrix();
	    // Traslada la esfera hacia atrás en el eje Z
	    glColor3f(0.5, 0, 0);
	    glTranslated(cuerpoPosX, cuerpoPosy + 1, -6); 
	    // Escala para hacer la esfera más aplastada en el eje Y
	    glScalef(.9, 0.9, 1.0);
	    glutSolidSphere(0.75, 50, 50);    
    glPopMatrix();

    //parte de arriba
    glPushMatrix();
	    glTranslated(cuerpoPosX-0.04, cuerpoPosy + 1.5, -6); 
	    glRotated(-90, 1, 0, 0);
	    glutSolidCone(0.4, 0.6, 50, 50); 
    glPopMatrix();

    //pom-pom
    glPushMatrix();
    glColor3f(0.0, 0.5, 0.0);
	    glTranslated(cuerpoPosX-0.04, cuerpoPosy + 2, -6); 
	    // Dibuja una esfera
	    glutSolidSphere(.2, 50, 50); 
    glPopMatrix();  
}

//Cuerpo de gasparin
void cuerpo ()
{
	// cabezota
	glEnable(GL_BLEND); //nos permite mezclar los colores, en este caso se uso para poder disimular la desaparicion del fantasma
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//se complementa con el anterior donde el dibujo se combiara con el fondo
	glColor4f(1.0, 1.0, 1.0, ghost_bye);
	glPushMatrix();
        glTranslated(cuerpoPosX,cuerpoPosy,-6);
        glutSolidSphere(1,50,50);
    glPopMatrix();

    // si no se aplica aqui tambien y solo se deja desde el principio el cuerpo no desaparece, solo la cabeza
    glEnable(GL_BLEND); 
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1.0, 1.0, 1.0, ghost_bye);
    glPushMatrix();
	    glTranslated(cuerpoPosX, cuerpoPosy + 0.09, -6); // Ajusta la posición del cilindro procurando que quede en medio de la esfera
	    glRotated(90, 1, 0, 0); // Rota el cilindro 90 grados para que asi se pueda ver vertical y forme parte del cuerpo
	    gluCylinder(gluNewQuadric(), 1.01, 1.01, 2, 50, 50);
    glPopMatrix();

     ojos();
    // -----esferas opacas para poder cortar el cilindro y hacer la simulacion de las ondas de gasparin
  	glColor3d(0, 0, 0);  
    const float radio_esfera = 1.2;  // radio para poder definir el tamaño de la esfera
    const int num_esferas = 10;  // Número de esferas que estaran alrededor del cilindro... mientras menos haya el espacio en blanco se vera mas
    // ciclo para poder dibujar las esferas sin la necesidad de estar repitiendolo una y otra vez
    for (int i = 0; i < num_esferas; ++i) 
    {
        float angle = (2.0 * M_PI * i) / num_esferas;
        float x = radio_esfera * cos(angle);
        float z = radio_esfera * sin(angle);
        glPushMatrix();
	        glTranslated(cuerpoPosX + x, cuerpoPosy + -1.8, -6 + z);
	         /* Configuración del material, a pesar de que esta en forma general aqui se pone dentro del ciclo debido a que queremos evitar que brilles las
	         	esferas negras, de ser asi no se entenderia y se veria raro */
		    GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
			   GLfloat mat_diffuse[] = { 0.0, 0.0, 0.0, 1.0 };
		    GLfloat mat_specular[] = { 0.0, 0.0, 0.0, 1.0 };
		    GLfloat mat_shininess[] = { 0.0 };
		    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	        glutSolidSphere(0.5, 50, 50);  // el primer valos nos permite poder hacer las esferas mas pequeñas
        glPopMatrix();
    }
    gorrito(); // no es un error, el gorro no desaparece porque es ropa 
}

//iluminacion
const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 8.0f, 5.0f, 0.0f };

//material
const GLfloat m_ambient[]={ 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]={ 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]={ 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[]={ 100.0f };

void specialKeys(int key, int x, int y) 
{
    switch (key) 
    {
        case GLUT_KEY_UP:
            cuerpoPosy += 0.5;
            break;
        case GLUT_KEY_DOWN:
             cuerpoPosy -= 0.5;
            break;
        case GLUT_KEY_LEFT:
            cuerpoPosX -= 0.5;
            break;
        case GLUT_KEY_RIGHT:
             cuerpoPosX += 0.5;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) 
{
	if (key == '1') // Neutral
    {
        neutral = 1;
        sad = 0;
        enojo = 0;
         canto = 0;
    }
    else if (key == '2') //feliz
    {
        neutral =0;
        sad = 0;
        enojo = 0;
         canto = 0;
    }
    else if (key == '3') //triste
    {
        neutral = 0;
        sad = 1;
        enojo = 0;
        canto = 0;
    }
    else if (key == '4') //enojado
    {
        neutral = 0;
        sad = 0;
        enojo = 1;
        canto = 0;
    }
    else if (key == 'q' || key == 'Q')//desaparecer
    {
        if (cuerpo)
        {
            // Restablecer la opacidad cuando se muestra el fantasma
            Ghost_bye2 = 0.0;
        }
        
    }
     else if (key == 'w' || key == 'W') // volver aparecer el fantasma
    {
        hi = 1;  // Indicar que se debe restablecer el fantasma
    }
        glutPostRedisplay();
}

void display3D ()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	 if (hi)
    {
        // Restablecer el estado del fantasma
        ghost_bye = 1.0;
        Ghost_bye2 = 1.0;
        clear_ojos = 1.0;
        hi = 0;
    }
	if (clear_ojos && ghost_bye  > 0.0)
    {
       
        float bye = Ghost_bye2 - ghost_bye;
        ghost_bye += bye * 0.6; // velocidad de desaparicion
		bye = Ghost_bye2 - clear_ojos;
        clear_ojos += bye * 0.6;
        cuerpo();
    }
    glMatrixMode(GL_MODELVIEW);
	glutSwapBuffers();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    
    glutCreateWindow("Booo 3D");
    glutReshapeFunc(resize);
    glutDisplayFunc(display3D);
    glutSpecialFunc(specialKeys);
 	glutKeyboardFunc(keyboard);

    glShadeModel (GL_SMOOTH); //Sombreado ligero
    glEnable(GL_CULL_FACE); //Habilita la eliminación de la cara trasera 
    glCullFace(GL_BACK); //Esta indica que se deben eliminar las caras traseras
    
    glEnable(GL_DEPTH_TEST);//Prueba de profundidad
    glDepthFunc(GL_LESS); //Cantidad de profundidad (acuérdense del pulgar)
    
   
    glEnable(GL_LIGHT0);//Habilita la fuente de luz 0
    glEnable(GL_NORMALIZE);//Habilita la normalización de los vectores.
    glEnable(GL_COLOR_MATERIAL);//Habilita el color dependiendo de la luz
    glEnable(GL_LIGHTING); //Habilitar la iluminación en general
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient); //Componente ambiental de la luz
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse); //Componente difuso de la luz
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular); //Componente especular de la luz, hablando de superficies
    glLightfv(GL_LIGHT0, GL_POSITION, light_position); //Componente posición de la fuente de luz
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, m_ambient); //Componente ambiental del material
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse); //Componente difuso del material
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); //Componente especular del material
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess); //Componente de brillo de material

    glutMainLoop();
	return 0;
}