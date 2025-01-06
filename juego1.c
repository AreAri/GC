#include <GL/glut.h>

// Variables para la posición del personaje
float x = 100.0;
float y = 100.0;
float step = 5.0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Dibuja el personaje de perfil
    glColor3f(1.0, 0.0, 0.0);  // Color rojo
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + 50, y);
    glVertex2f(x + 50, y + 100);
    glVertex2f(x, y + 100);
    glEnd();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
}

void specialKeys(int key, int special, int mousePos) {
    // El parámetro 'key' se utiliza, pero 'special' y 'mousePos' no se usan en el cuerpo de la función
    switch (key) {
    case GLUT_KEY_UP:
        y += step;
        break;
    case GLUT_KEY_DOWN:
        y -= step;
        break;
    case GLUT_KEY_LEFT:
        x -= step;
        break;
    case GLUT_KEY_RIGHT:
        x += step;
        break;
    }

    glutPostRedisplay();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Personaje de Pixel Art");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);

    glClearColor(1.0, 1.0, 1.0, 1.0);  // Color de fondo blanco

    glutMainLoop();
    return 0;
}
