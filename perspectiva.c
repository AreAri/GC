#include <GL/glut.h>
#include <stdio.h>
static void display (void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,0.0);

	glTranslatef(0.0,0.0,-2.0);//se juga con la perspectiva en z

	glBegin(GL_QUADS);
		glVertex3f(-0.5,0.5,-0.5);
		glVertex3f(-0.5,0.5,0.5);
		glVertex3f(0.5,-0.5,0.5);
		glVertex3f(0.5,0.5,-0.5);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex2f(300.0,300.0);
		glVertex2f(200.0,100.0);
		glVertex2f(400.0,100.0);
	glEnd();

	glutSwapBuffers();
}

int main(int argc, char** argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(300,200);
	glutCreateWindow("Y... Como lo vez?");
	glClearColor(0.0,0.0,0.0,0.0);
	glViewport(0,0, (GLsizei)500, (GLsizei)500);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho2D(0.0, (GLdouble)500.0, 0.0, (Gldouble)500.0);
	glOrthot(1.0,1.0,1.0,1.0,1.0,-1.0);
	gluPerspective(40.0,1.0,1.0,100.0 ); //andulo de vozualizacion angulo/anchoylargo/distanciamin en z/distanciamax
	glShadeModel(GL_FLAT);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}