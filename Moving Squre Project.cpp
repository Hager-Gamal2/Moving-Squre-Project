#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>

float squareX = 0.0f;
float squareY = 0.0f;
float squareSize = 0.3f; 
float moveStep = 0.05f;

// زاوية الدوران
float angle = 0.0f;

float colorR = 1.0f;
float colorG = 0.0f;
float colorB = 0.0f;

int colorState = 0;

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(colorR, colorG, colorB);

    // التحرك للمكان المطلوب
    glTranslatef(squareX, squareY, 0.0f);
    // الدوران
    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    // رسم المربع
    glBegin(GL_QUADS);
    glVertex2f(-squareSize / 2, squareSize / 2);
    glVertex2f(squareSize / 2, squareSize / 2);
    glVertex2f(squareSize / 2, -squareSize / 2);
    glVertex2f(-squareSize / 2, -squareSize / 2);
    glEnd();

    glutSwapBuffers();
}

void processSpecialKeys(int key, int x, int y) {
    float halfSize = squareSize / 2;

    switch (key) {
    case GLUT_KEY_LEFT:
        if (squareX - moveStep - halfSize >= -1.0f) squareX -= moveStep;
        break;
    case GLUT_KEY_RIGHT:
        if (squareX + moveStep + halfSize <= 1.0f) squareX += moveStep;
        break;
    case GLUT_KEY_UP:
        if (squareY + moveStep + halfSize <= 1.0f) squareY += moveStep;
        break;
    case GLUT_KEY_DOWN:
        if (squareY - moveStep - halfSize >= -1.0f) squareY -= moveStep;
        break;
    }

    glutPostRedisplay();
}

void processNormalKeys(unsigned char key, int x, int y) {

    // Rotate بالمفتاح 1
    if (key == '1') {
        angle += 10.0f;
    }

    // تغيير اللون بالـ Space
    if (key == 32) {
        colorState++;
        if (colorState > 2) colorState = 0;

        if (colorState == 0) {
            colorR = 1.0f; colorG = 0.0f; colorB = 0.0f;
        }
        else if (colorState == 1) {
            colorR = 0.0f; colorG = 1.0f; colorB = 0.0f;
        }
        else {
            colorR = 0.0f; colorG = 0.0f; colorB = 1.0f;
        }
    }

    // خروج
    if (key == 27) {
        exit(0);
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(350, 120);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rotate with 1");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glutDisplayFunc(renderScene);
    glutSpecialFunc(processSpecialKeys);
    glutKeyboardFunc(processNormalKeys);

    glutMainLoop();
    return 0;
}


