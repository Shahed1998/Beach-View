#include <iostream>
#include <stdlib.h>
#include <math.h>
#include<GL/gl.h>
#include <GL/glut.h>
// User defined headers
#include "KeyEvents.h"
#include "Shapes.h"

using namespace std;

float _angle = 0.0, xAxis = -5.0f;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;

//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

//Draws the 3D scene
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units

	//Lamp Stand
    glPushMatrix();

    glPushMatrix();
    Shapes lampStand;
    glColor3f(0.412, 0.412, 0.412);
    glTranslatef(-4.0, -1.6, 0.0);
    lampStand.filled_quad(0.1,1.5);
    glPopMatrix();

    glPushMatrix();
    glRotatef(10, 0.0, 0.0, 1.0);
    glTranslatef(-4.2, 0.4, 0.0);
    lampStand.filled_quad(1.0,0.05);
    glPopMatrix();

    glPopMatrix();

    // Lamp light
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-3.2, -0.6, 0.0);
    glRotatef(-92, 1.0, 0.0, 0.0);
    glRotatef(-10, 0.0, 1.0, 0.0);
    glRotatef(_angle, 0.0, 0.0, 1.0);
    glutWireCone(0.2, 0.5, 20, 20);
    glPopMatrix();

	// Sun
    glPushMatrix();
    Shapes sun;
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-4.0, 2.5, 0.0);
    sun.filled_circle(0.3);
    glPopMatrix();

	// Sky
    glPushMatrix();
    Shapes sky;
    glColor3f(0.529, 0.808, 0.980);
    glTranslatef(-5.0, 1.5, 0.0);
    sky.filled_quad(100.0, 1.5);
    glPopMatrix();

    //Boat
    glPushMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 0.0, 0.0);
    glVertex3f(2.0, 1.0, 0.0);
    glVertex3f(-2.0, 1.0, 0.0);
    glVertex3f(-1.0, 0.0, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(0.6, 1.2, 0.0);
    glVertex3f(0.4, 1.2, 0.0);
    glVertex3f(0.4, 1.4, 0.0);
    glVertex3f(0.6, 1.4, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-0.6, 1.2, 0.0);
    glVertex3f(-0.4, 1.2, 0.0);
    glVertex3f(-0.4, 1.4, 0.0);
    glVertex3f(-0.6, 1.4, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-1.0, 1.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, 2.0, 0.0);
    glVertex3f(-1.0, 2.0, 0.0);
    glEnd();
    glPopMatrix();
    glPopMatrix();

	// Sea
    glPushMatrix();
    Shapes sea;
    glColor3f(0.0, 0.749, 1.0);
    glTranslatef(-5.0, 0.5, 0.0);
    sea.filled_quad(100.0, 1.0);
    glPopMatrix();

    // Sand
    glPushMatrix();
    Shapes sand;
    glColor3f(0.957, 0.643, 0.376);
    glTranslatef(-5.0, -1.5, 0.0);
    sand.filled_quad(100.0, 2.0);
    glPopMatrix();

    // Road Border
    glPushMatrix();
    Shapes roadBorder;
    glColor3f(0.502, 0.502, 0.502);
    glTranslatef(-5.0, -1.7, 0.0);
    roadBorder.filled_quad(100.0, 0.2);
    glPopMatrix();

    // Road Lines
    glPushMatrix();
    Shapes roadLines;
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.2, -2.4, 0.0);
    roadLines.filled_quad(1.0, 0.1);
    glTranslatef(1.5, 0.0, 0.0);
    roadLines.filled_quad(1.0, 0.1);
    glTranslatef(1.5, 0.0, 0.0);
    roadLines.filled_quad(1.0, 0.1);
    glTranslatef(-4.5, 0.0, 0.0);
    roadLines.filled_quad(1.0, 0.1);
    glTranslatef(-1.5, 0.0, 0.0);
    roadLines.filled_quad(1.0, 0.1);
    glTranslatef(-1.5, 0.0, 0.0);
    roadLines.filled_quad(1.0, 0.1);
    glPopMatrix();

    // Road
    glPushMatrix();
    Shapes road;
    glColor3f(0.663, 0.663, 0.663);
    glTranslatef(-5.0, -3.0, 0.0);
    road.filled_quad(100.0, 1.3);
    glPopMatrix();



	glutSwapBuffers();
}

void update(int value) {
	_angle += 2.0f;
	xAxis += 0.05f;


	if (_angle > 360) {
		_angle -= 360;
	}

    if(xAxis > 5.0)
    {
        xAxis = -5.0f;

    }

	_ang_tri += 2.0f;
	if (_ang_tri > 360) {
		_ang_tri -= 360;
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 10 milliseconds
	glutTimerFunc(25, update, 0);

}

void keyPressed(unsigned char key, int x, int y)
{

    KeyEvents k;
    k.key(key, x, y);

}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	//Create the window
	glutCreateWindow("Beach View");
	glutFullScreen();
	glutKeyboardFunc(keyPressed);
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);

	glutTimerFunc(25, update, 0); //Add a timer

	glutMainLoop();
	return 0;
}




