#include <GL/glut.h>
#include <math.h>
float cloudPosX =-2.0f;
float rocketPosX =3.0f; 
float rocketPosY =2.0f;
float rocketSpeedX =0.009f;
float rocketSpeedY =0.005f;

//cloud part by Pulock
void circle(float rx, float ry, float cx, float cy) {
    //circle fnc
    glBegin(GL_POLYGON);
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
   glTranslatef(cloudPosX, 0.0f, 0.0f);

    circle(0.25,0.25,x,y);
    circle(0.24,0.18,x+2.5,y);
   circle(0.24,0.21,x-2.5,y);
circle(0.26,0.23,x,y+1.2);
    circle(0.24,0.20,x+1.5,y+1.0);
    circle(0.28,0.23,x-1.1,y+0.8);
   circle(0.27,0.22,x-1.3,y+0.6);
    glPopMatrix();
}
void moveCloud(int value) {
    cloudPosX +=0.009f;
    if(cloudPosX>4.0f) {
        cloudPosX=-10.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(30,moveCloud,0);
}


//Rocket part by Pulock
void drawRocket(float x, float y){
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glRotatef(70, 0, 0, 1);

    glColor3ub(173,214,116);
    glBegin(GL_POLYGON);
        glVertex2f(-0.4, -0.2);
        glVertex2f(-0.4 ,0.8);
        glVertex2f(0.4, 0.8);
        glVertex2f(0.4, -0.2);
    glEnd();

    glColor3ub(237,71,90);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.6, 0.8);
        glVertex2f(0.0, 1.4);
        glVertex2f(0.6, 0.8);
    glEnd();

    glColor3f(0.0,0.0,0.5);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.4, -0.2);
        glVertex2f(0.0, -0.2);
        glVertex2f(-0.8, -0.6);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(0.0, -0.2);
        glVertex2f(0.4, -0.2);
        glVertex2f(0.8, -0.6);
    glEnd();

    glPopMatrix();
}
void moveRocket(int value){
    rocketPosX -=rocketSpeedX;
    rocketPosY +=rocketSpeedY;
    if(rocketPosX <-5.0f){
        rocketPosX =6.0f;
        rocketPosY =1.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(30, moveRocket,0);
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
     drawRocket(rocketPosX, rocketPosY);

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
    glutTimerFunc(30, moveCloud, 0);
    glutTimerFunc(30, moveRocket, 0); 
    glutMainLoop();
    return 0;
}
