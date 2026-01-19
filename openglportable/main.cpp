#include <GL/glut.h>
#include <math.h>
float cloudPositionX=-2.0f;

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy) {

    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i=0;i<=360;i++) {
        float angle=3.1416f*i/180;
        float x=rx*cosf(angle);
        float y=ry*sinf(angle);
        glVertex2f((x+cx),(y+cy));
    }
    glEnd();
}
void cloud(float x, float y) {
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
   glTranslatef(cloudPositionX, 0.0f, 0.0f);

    circle(0.25,0.25,x,y);
    circle(0.24,0.18,x+2.5,y);
   circle(0.24,0.21,x-2.5,y);
    circle(0.26,0.23,x,y+1.2);
    circle(0.24,0.20,x+1.5,y+1.0);
    circle(0.28,0.23,x-1.1,y+0.8);
   circle(0.27,0.22,x-1.3,y+0.6);
    glPopMatrix();
}
void updatePositionCloud(int value) {
    cloudPositionX +=0.009f;
    if(cloudPositionX>4.0f) {
        cloudPositionX=-10.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(30,updatePositionCloud,0);
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(0.5, 0.8, 0.9);
    glBegin(GL_QUADS);
        glVertex2f(4.0, -4.0);
        glVertex2f(4.0, 7.0);
        glVertex2f(-4.0, 7.0);
        glVertex2f(-4.0, -4.0);
    glEnd();

    cloud(2.0,5.2);
    cloud(2.1,5.3);
    cloud(2.0,5.0);
    cloud(2.1,5.2);
    cloud(2.2,5.5);
    cloud(2.3,5.2);

 glutSwapBuffers();
glFlush();
}

void myInit() {
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-4.0,4.0,-4.0,7.0);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1400, 750);
    glutCreateWindow("Graphics Project");
    myInit();
    glutDisplayFunc(display);
    glutTimerFunc(30, updatePositionCloud, 0);
    glutMainLoop();
    return 0;
}
