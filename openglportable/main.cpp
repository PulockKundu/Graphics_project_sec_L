#include <GL/glut.h>
#include <math.h>



void display() {
    glClear(GL_COLOR_BUFFER_BIT);  
     glColor3f(0.5, 0.8, 0.9); 
    glBegin(GL_QUADS);
        glVertex2f(4.0, -4.0);
        glVertex2f(4.0, 7.0);
        glVertex2f(-4.0, 7.0);
        glVertex2f(-4.0, -4.0);
    glEnd();


 glutSwapBuffers();
}

void myInit() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
    gluOrtho2D(-4.0, 4.0, -4.0, 7.0);  
    glMatrixMode(GL_MODELVIEW);  
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);  
    glutInitWindowSize(1400, 750); 
    glutCreateWindow("Graphics Project");  
    myInit();  
    glutDisplayFunc(display);  
    //glutTimerFunc(30, updatePositionCloud, 0);  
    // glutTimerFunc(30, updatePositionRocket, 0);  
    glutMainLoop();  
    return 0;
}
