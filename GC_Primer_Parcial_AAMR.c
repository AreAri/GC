/* Codigo de examen - Areli Arisai Meza Rendon
	El codigo dibuja un fantasma el cual tiene diferentes expresiones,
	se mueve en la direccion de las 4 flechas y desaparece */

#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

//Funciones
int Ojos_Abiertos = 1;
float ojos_X = 0.07; // indica la posición inicial de los ojos en el eje X
float ojos_Y = 0.15; // indica la posición inicial de los ojos en el eje Y
float Rad_OjoX = 0.04; // Radio del ovalo de los ojos en x
float Rad_OjoY = 0.08; //Radio del ovalo de los ojos en y
int Mover_Boca = 0;
int bocaAbierta = 0; //se utiliza para poder mover la boca en caso de que sea 1
float Ojo_Boca = 0.0; //nos permite mover tanto los ojos y la boca en el eje de las cuando esta cantando
//variables que nos ayudan en la desaparicion del fantasma
float ghost_bye = 1.0;
float Ghost_bye2 = 1.0;
float clear_ojos = 1.0; //nos permitira desaparecer lo ojos junto con el cuerpo
int hi = 0;//aparecer al fantasma
float a = 0.3;//en x
float b = 0.8;//en y
float dis = -0.4; // ajusta este valor para cambiar la posición vertical 
float radio = 0.1; //radio para la figuras de la parte inferior
float speed = 0.005;
//emociones, se ponen en 0 para poder "activarlas" al seleccionar la tecla adecuada
int sad = 0;
int enojo = 0;
int canto =0;
float cuerpoPosX = 0.0;
float cuerpoPosy = 0.0;

//Funcion para poder crear un fondo simulando que es tipo madera como si el fantasma estuviera en una casa
void fondo ()
{
    glLineWidth(3); //se define e grosor de cada linea que simula las tablas

    //simular tablones de madera
    glColor3f(0.44, 0.22, 0.0); //colo lijeramente mas oscuro al del fondo
    glBegin(GL_LINES);
    //se utilizo un bucle para poder realizar las lineas horizontales sin tener la necesidad de poner uno por uno
        for (float y = -0.9; y <= 0.9; y += 0.15) 
        {
        	//debido a que todas empiezan desde la misma distancia de x unicamente varia el valor de y para asi ubicarlas a una cierta distancia
            glVertex2f(1, y);
            glVertex2f(-1, y);
        }
    glEnd();

    /*Se hace la divicion de algunos tablones simulando la union entre las tablas de madera
    	debido a que no se aplica de forma homogenia en todo el fondo se hizo una por una*/
    glBegin(GL_LINES);
        glVertex2f(-0.7, -.9);
        glVertex2f(-0.7, -0.75);
        glVertex2f(0.1, -.6);
        glVertex2f(0.1, -0.45);
        glVertex2f(0.7, -0.3);
        glVertex2f(0.7, -0.15);
        glVertex2f(-0.7, 0.75);
        glVertex2f(-0.7, 0.6);
        glVertex2f(-0.3, 0.6);
        glVertex2f(-0.3, 0.45);
    glEnd();
}

//funcion que me permite crear los ojos y modificarlos segun la emocion que se selecciona
void ojos (float x, float y)
{
	glColor4f(0.0, 0.0, 0.0, clear_ojos); //al poner clear_ojos nos permite disminuir la opacidad del dibujo simulando que esta desapareciendo
	if (Ojos_Abiertos && !sad && !enojo && !canto) 
    {
    	/*Apariencia normaL, solos se muestran 2 ojos
        	Dibujar el ojo izquierdo abierto*/
        glBegin(GL_TRIANGLE_FAN);//mallado para poder hacer los ovalos
        glVertex2f(x - ojos_X, y + ojos_Y); // Centro del ojo
        /*Este ciclo permite crear un conjunto de puntos tomando en cuenta el centro hasta formar un ovalo completo*/
        for (int i = 0; i <= 360; i++)
        {
            float theta = i * M_PI / 180.0;//calcula el angulo en radianes
            float ojoX = x - ojos_X + Rad_OjoX * cos(theta);
            float ojoY = y + ojos_Y + Rad_OjoY * sin(theta);
            glVertex2f(ojoX, ojoY);
        }
        glEnd();
        // Dibujar el ojo derecho abierto
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x + ojos_X, y + ojos_Y); // Centro del ojo
        /*Este ciclo permite crear un conjunto de puntos tomando en cuenta el centro hasta formar un ovalo completo como el anterior*/
        for (int i = 0; i <= 360; i++)
        {
            float theta = i * M_PI / 180.0;
            float ojoX = x + ojos_X + Rad_OjoX * cos(theta);
            float ojoY = y + ojos_Y + Rad_OjoY * sin(theta);
            glVertex2f(ojoX, ojoY);
        }
        glEnd();
    } 
    else if (!Ojos_Abiertos && !sad && !enojo && !canto) //Emocion de felicidad
    {
        // Se usa las mismas funciones como en las lineas anteriores
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x - ojos_X, y + ojos_Y); // Centro del ojo
        //A diferencia del anterior este ciclo unicamente forma un medio ovalo
        for (int i = 0; i <= 180; i++)
        {
            float theta = i * M_PI / 180.0;
            float ojoX = x - ojos_X + Rad_OjoX * cos(theta);
            float ojoY = y + ojos_Y + Rad_OjoY * sin(theta);
            glVertex2f(ojoX, ojoY);
        }
        glEnd();
        // Dibujar el ojo derecho cerrado
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x + ojos_X, y + ojos_Y); // Centro del ojo
        for (int i = 0; i <= 180; i++)
        {
            float theta = i * M_PI / 180.0;
            float ojoX = x + ojos_X + Rad_OjoX * cos(theta);
            float ojoY = y + ojos_Y + Rad_OjoY * sin(theta);
            glVertex2f(ojoX, ojoY);
        }
        glEnd();
        //para la boca se le dio un grosor a la linea para que se viera mejor
        glLineWidth(5);
        glBegin(GL_LINE_STRIP);
        //Este ciclo es como el anterior que hace un medio ovalo pero unicamente la linea y no se unen las puntas
	    for (int i = 0; i <= 180; i++)
	    {
	        float theta = i * M_PI / 180.0;
	        float sonrisaX = x + 0.05  *cos(theta);
	        float sonrisaY = -0.02 - 0.05* sin(theta);
	        glVertex2f(sonrisaX, sonrisaY);
		}
	    glEnd();
	}
    else if (enojo) //fantasma enojado
    {
    	// Dibujar el ojo izquierdo cerrado
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x - ojos_X, y + ojos_Y); // Centro del ojo
        //A diferencia de feliz este ciclo unicamente forma un medio ovalo y la curva es abajo no arriba
        for (int i = 0; i <= 180; i++)
        {
            float theta = i * M_PI / 180.0;
            float ojoX = x - ojos_X + Rad_OjoX * cos(theta);
            float ojoY = y + ojos_Y - Rad_OjoY * sin(theta);
            glVertex2f(ojoX, ojoY);
        }
        glEnd();
        // Dibujar el ojo derecho cerrado
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x + ojos_X, y + ojos_Y); // Centro del ojo
        for (int i = 0; i <= 180; i++)
        {
            float theta = i * M_PI / 180.0;
            float ojoX = x + ojos_X + Rad_OjoX * cos(theta);
            float ojoY = y + ojos_Y - Rad_OjoY * sin(theta);
            glVertex2f(ojoX, ojoY);
        }
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINE_STRIP);
        //Este ciclo es como el anterior que hace un medio ovalo pero unicamente la linea y no se unen las puntas
	    for (int i = 0; i <= 180; i++)
	    {
	        float theta = i * M_PI / 180.0;
	        float tristeX = x + ojos_X * 0.5 + Rad_OjoX * cos(theta);
	        float tristeY = -0.02 - 0.05* 1.5 + Rad_OjoY * 0.5 * sin(theta);
	        glVertex2f(tristeX, tristeY);
	    }
	    glEnd();
    }
    else if (sad) //fantasma triste
    {
        // Dibujar el ojo izquierdo cerrado
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x - ojos_X, y + ojos_Y); // Centro del ojo
        //se utiliza el mismo ciclo de los ojos de felicidad
        for (int i = 0; i <= 180; i++)
        {
            float theta = i * M_PI / 180.0;
            float ojoX = x - ojos_X + Rad_OjoX * cos(theta);
            float ojoY = y + ojos_Y + Rad_OjoY * sin(theta);
            glVertex2f(ojoX, ojoY);
        }
        glEnd();

        // Dibujar el ojo derecho cerrado
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x + ojos_X, y + ojos_Y); // Centro del ojo
        for (int i = 0; i <= 180; i++)
        {
            float theta = i * M_PI / 180.0;
            float ojoX = x + ojos_X + Rad_OjoX * cos(theta);
            float ojoY = y + ojos_Y + Rad_OjoY * sin(theta);
            glVertex2f(ojoX, ojoY);
        }
        glEnd();
        //en vez de que la curva este abajo ahora es arriba
        glLineWidth(5);
        glBegin(GL_LINE_STRIP);
	    for (int i = 0; i <= 180; i++)
	    {
	        float theta = i * M_PI / 180.0;
	        float meeX = x + ojos_X * 0.5 + Rad_OjoX * cos(theta);
	        float meeY = -0.02 - 0.05* 1.5 + Rad_OjoY * 0.5 * sin(theta);
	        glVertex2f(meeX, meeY);
	    }
	    glEnd();
    }
    else if (canto && Mover_Boca) //Fantasma inspirado, tanto como la boca y los ojos cambian cuando se pone esta opción
    { 
        glBegin(GL_TRIANGLE_FAN); // Ojo izquierdo
        glVertex2f(x - ojos_X, y + ojos_Y + Ojo_Boca); // Centro del ojo
        for (int i = 0; i <= 360; i++)
        {
            float theta = i * M_PI / 180.0;
            float ojoX = x - ojos_X + 0.05 * cos(theta); 
            float ojoY = y + ojos_Y + 0.02 * sin(theta); 
            glVertex2f(ojoX, ojoY + Ojo_Boca);
        }
        glEnd();
        glBegin(GL_TRIANGLE_FAN); // Ojo derecho
        glVertex2f(x + ojos_X, y + ojos_Y + Ojo_Boca); // Centro del ojo
        for (int i = 0; i <= 360; i++)
        {
            float theta = i * M_PI / 180.0;
            float ojoX = x + ojos_X + 0.05 * cos(theta); // Radio en x es 0.05
            float ojoY = y + ojos_Y + 0.02 * sin(theta); // Radio en y es 0.02
            glVertex2f(ojoX, ojoY + Ojo_Boca);
        }
        glEnd();

        //para la boca se utilizo un circulo
        glBegin(GL_POLYGON); 
        for (int i = 0; i <= 360; i++)
        {
            float theta = i * M_PI / 180.0;
            float singX = x + 0.05 * cos(theta);
            float singY = -0.1 - 0.05 * sin(theta);
            glVertex2f(singX, singY + Ojo_Boca);
        }
        glEnd();
    }    
    else if (canto ) //a pesar de tener activado el modo de canto este puede detenerse y mostrar una risa nerviosa
    { 
        // Dibujar el ojo izquierdo abierto
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x - ojos_X, y + ojos_Y); // Centro del ojo
        for (int i = 0; i <= 360; i++)
        {
            float theta = i * M_PI / 180.0;
            float ojoX = x - ojos_X + Rad_OjoX * cos(theta);
            float ojoY = y + ojos_Y + Rad_OjoY * sin(theta);
            glVertex2f(ojoX, ojoY);
        }
        glEnd();
        // Dibujar el ojo derecho abierto
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x + ojos_X, y + ojos_Y); // Centro del ojo
        for (int i = 0; i <= 360; i++)
        {
            float theta = i * M_PI / 180.0;
            float ojoX = x + ojos_X + Rad_OjoX * cos(theta);
            float ojoY = y + ojos_Y + Rad_OjoY * sin(theta);
            glVertex2f(ojoX, ojoY);
        }
        glEnd();
        //se dibuja una pequeña sonrisa de nervios cuando no esta cantando
      glBegin(GL_LINE_STRIP);
	    for (int i = 0; i <= 180; i++)
	    {
	        float theta = i * M_PI / 180.0;
	        float sonrisaX = x + 0.05  *cos(theta);
	        float sonrisaY = -0.04 - 0.05* sin(theta);
	        glVertex2f(sonrisaX, sonrisaY);
	 	}
	    glEnd();
    }      
}

//funcion que crea el cuerpo del fantasma
void cuerpecito()
{
	glPushMatrix(); // Guardar la matriz de transformación actual permitiendonos permitir mover todo lo que se encuentra despues
	glTranslatef(cuerpoPosX, 0.0, 0.0);
	glTranslatef(0.0, cuerpoPosy, 0.0);
	glEnable(GL_BLEND); //nos permite mezclar los colores, en este caso se uso para poder disimular la desaparicion del fantasma
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//se complementa con el anterior donde el dibujo se combiara con el fondo
	glColor4f(1.0, 1.0, 1.0, ghost_bye);
   	glBegin(GL_POLYGON);
    //ovalo para poder redonderar la cabeza, se limita para que pueda terminar de forma recta 
    for (int i = 0; i < 180; i++) 
    {
        float theta = i * M_PI / 180.0;
        float x = a * cos(theta);
        float y = b * sin(theta) + dis;
        glVertex2f(x, y);
    }
    glEnd();
    glBegin(GL_POLYGON);
     // Parte inferior simulando ondas
    for (int i = 0; i <= 180; i++) 
    {
        float theta = i * M_PI / 180.0;
        float x = 0.2 + radio * cos(theta);
        float y = -0.38 - radio * sin(theta);
        glVertex2f(x, y);
    }
    for (int i = 0; i <= 180; i++) 
    {
        float theta = i * M_PI / 180.0;
        float x = 0.0 + radio * cos(theta);
        float y = -0.38 - radio* sin(theta);
        glVertex2f(x, y);
    }
    for (int i = 0; i <= 180; i++) 
    {
        float theta = i * M_PI / 180.0;
        float x = -0.2 + radio * cos(theta);
        float y = -0.38 - radio * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
    ojos(0.0, -0.1);//incluimos los ojos tanto a la figura como al movimiento
    glDisable(GL_BLEND);
    glPopMatrix();
}

//inclui una funcion timer con el fin de que los ojos y la boca al momento de cantar se muevan de arriba a abajo (idea sacada de un video de fantasmas)
void timer(int value)
{
    if (Mover_Boca )
    {
        if (Ojo_Boca > 0.15)  // Ajusta la posición máxima vertical donde llegaran los ojos y la boca 
            speed = -0.002;  // Cambia la dirección al llegar al límite superior
        else if (Ojo_Boca < 0.1)  // Ajusta la posición mínima vertical donde llegaran boca y ojos
            speed = 0.002;  // Cambia la dirección al llegar al límite inferior
        Ojo_Boca += speed;
        glutPostRedisplay();//nos permite que se este actualizando el dibujo cada vez que lo hacemos funcionar
    }
    glutTimerFunc(16, timer, 0);  // temporizador que permite que la funcion este corriendo
}

/* Funcion para poder usar el teclado y cambiar las emociones del fantasma
	Donde 1 sera nomal, 2 sera feliz, 3 sera triste, 4 sera enojado, 5 es cantar y 6 nos permitira cambiar y utilizar el timer
	si no se ingresa a la opcion 5 no se puede aplicar el 6
	Para desaparecer el fantasma se ocupa q y para volverlo aparecer es w*/
void keyboard(unsigned char key, int x, int y) 
{
	if (key == '1') // Neutral
    {
        Ojos_Abiertos = 1;
        sad = 0;
        enojo = 0;
         canto = 0;
    }
    else if (key == '2') //feliz
    {
        Ojos_Abiertos =0;
        sad = 0;
        enojo = 0;
         canto = 0;
    }
    else if (key == '3') //triste
    {
        Ojos_Abiertos = 0;
        sad = 1;
        enojo = 0;
        canto = 0;
    }
    else if (key == '4') //enojado
    {
        Ojos_Abiertos = 0;
        sad = 0;
        enojo = 1;
        canto = 0;
    }
     else if (key == '5') // canto
    {
        canto = 1;
        Ojos_Abiertos = 0;
        sad = 0;
        enojo = 0;
        bocaAbierta = !bocaAbierta;  // Alterna entre abierto y cerrado
        Mover_Boca = 0;  // Activa el movimiento de la boca
    }
       else if (key == '6')
    {
        if (canto)
        {
            bocaAbierta = !bocaAbierta;  // Alterna entre abierto y cerrado
            Mover_Boca = !Mover_Boca;  // Activa/desactiva el movimiento de la boca
        }
    }
    else if (key == 'q' || key == 'Q')//desaparecer
    {
        if (cuerpecito)
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

//esta funcion nos sirve mas que nada para el mover el fantasma de arriba a abajo utilizando las felchas
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

//funcion mas importante, nos permite mostrar todo lo que hemos hecho agregando una ventana
void display()
{
    glClearColor (0.58,0.29,0.0, 0.0); //cafe
    glClear(GL_COLOR_BUFFER_BIT);
    fondo();
    gluOrtho2D(-1.5, 1.0, -1.0, 1.5);  // me permite hacer el fantasma mas pequeño sin afectar lo que he hizo en el fondo
    //esto nos permite poder aplicar la opacidad al fantasma permitiendo que se dezaparezca o vuelva aparecer
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
        cuerpecito();
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutSwapBuffers();
}

//para ejecutar
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Boooo");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
	glutTimerFunc(0, timer, 0);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}