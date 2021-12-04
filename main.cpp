#include <iostream>
#include <stdlib.h>
#include <math.h>
#include<GL/gl.h>
#include <GL/glut.h>
// User defined headers
#include "KeyEvents.h"
#include "Lines.h"

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


    glPushMatrix();
    // Horizon
    Lines L1;
    //glColor3f(0.0,1.0,1.0);
    //L1.horizontal_long_line(1.5);
    //L1.horizontal_long_line(-1.5);
    // Regular quads
    //glColor3f(1.0,1.0,0.0);
    //L1.lined_quad(-2.0, 1.0);
    /*L1.filled_quad(-2.0,1.0);
    L1.lined_quad(-2.0, -1.0);
    L1.filled_quad(2.0, -1.0); */
    //L1.filled_quad(2.0, 1.0);
    L1.straightLine(1.0, 0.0);
    glTranslatef(1.0, 0.0, 0.0);
    L1.straightLine(0.0, 1.0);

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
	//glutTimerFunc(25, update, 0);

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
	//glutFullScreen();
	glutKeyboardFunc(keyPressed);
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);

	//glutTimerFunc(25, update, 0); //Add a timer

	glutMainLoop();
	return 0;
}




