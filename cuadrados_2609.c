#include <GL/glut.h>

static void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,0.0);

	//glTranslatef(0.1,0.1,-1.0);

	/*glBegin(GL_QUADS);
		glVertex3f(-0.5,0.5,-0.5);
		glVertex3f(-0.5,-0.5,0.5);
		glVertex3f(0.5,-0.5,0.5);
		glVertex3f(0.5,0.5,-0.5);
	glEnd();

	/*

	glBegin(GL_TRIANGLES);
		glColor3f(0.0,1.0,0.0);
		glVertex3f(0.0,0.8,0.0);

		glColor3f(0.0,0.0,1.0);
		glVertex3f(-0.6,-0.2,0.0);

		glColor3f(1.0,0.0,0.0);
		glVertex3f(0.6,-0.2,0.0);
	glEnd();*/

	/*glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0,1.0,0.0);
		glVertex3f(0.0,0.8,0.0);

		glColor3f(0.0,0.0,1.0);
		glVertex3f(-0.6,-0.2,0.0);

		glColor3f(1.0,0.0,0.0);
		glVertex3f(0.6,-0.2,0.0);
	glEnd();*/

	glBegin(GL_TRIANGLE_STRIN);
		glColor3f(0.0,1.0,0.0);
		glVertex3f(0.0,0.8,0.0);

		glColor3f(0.0,0.0,1.0);
		glVertex3f(-0.6,-0.2,0.0);

		glColor3f(1.0,0.0,0.0);
		glVertex3f(0.6,-0.2,0.0);

		glColor3f(1.0,1.0,0.0);
		glVertex3f(-0.6, -0.6, 0.0);

		glColor3f(1.0,0.0,1.0);
		glVertex3f(0.6, -0.6, 0.0);

		glColor3f(1.0,1.0,1.0);
		glVertex3f(-0.6, -1.0, 0.0);
	glEnd();

	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(300,200);
	glutCreateWindow("Cuadrados en marcha");

	glClearColor(0.0,0.0,0.0,0.0);
	glViewport(0,0,500,500);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(1.0,1.0,-1.0,1.0,-1.0,1.0);
	//gluPerspective(80.0,1.0,1.0,100.0);
	//gluOrtho2D(0.0,500.0,0.0,500.0);
	//glShadeModel(GL_FLAT);
	glShadeModel (GL_SMOOTH);

	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}