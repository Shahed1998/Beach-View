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
float carPos = 0.0;
float cloudPos1 = -2.0;
float cloudPos2 = 2.0;
float cloudPos3 = 0.0;
float birdPos1 = -2.0;
float birdPos2 = 2.0;
float birdPos3 = 0.0;
float hotAirBalloonPos = 2.0;
float wheelAngle = 360;
bool bounceBack = false;
float ballAngle = 0.0;

//char sky_color = 'd';

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

    // Shape's instances
    Shapes car,
        boat1, boat2,
        cloud1, cloud2, cloud3,
        bird1, bird2, bird3,
        moon, sun;

    // Boat
    boat2.showBoat(KeyEvents::boatPos2, 4.5);
    boat1.showBoat(KeyEvents::boatPos, 6.0);


    if(KeyEvents::skyColor=='n')
    {
        // Moon
        moon.showSunMoon(1.0, 1.0, 1.0);

        // Sky
        glPushMatrix();
            Shapes sky;
            glColor3f(0.0, 0.0, 0.0);
            glTranslatef(-5.0, 1.5, 0.0);
            sky.filled_quad(100.0, 1.5);
        glPopMatrix();


    }else if(KeyEvents::skyColor=='m')
    {
        // Hot air balloon
        glPushMatrix();
            Shapes hotAirBalloon;
            glTranslatef(hotAirBalloonPos, 2.3, 0.0);
            glColor3f(1.00, 0.271, 0.0);
            hotAirBalloon.filled_halfCircle(0.29);
            glRotatef(90, 1.0, 0.0, 0.0);
            glutWireCone(0.25, 0.6, 20, 20);
            glRotatef(-90, 1.0, 0.0, 0.0);
            glTranslatef(0.0, -0.6, 0.0);
            glColor3f(0.0, 0.0, 0.0);
            glutWireCube(0.2);
            glColor3f(0.545, 0.0, 0.0);
            glutSolidCube(0.2);
        glPopMatrix();

        // Clouds
       cloud1.showCloud(cloudPos1, 2.3);
       cloud2.showCloud(cloudPos2, 2.0);
       cloud3.showCloud(cloudPos3, 2.3);

       // Birds
       bird1.showBirds(birdPos1);
       bird2.showBirds(birdPos2);
       bird3.showBirds(birdPos3);

        // Sun
        sun.showSunMoon(1.0, 1.0, 0.0);

        // Sky
        glPushMatrix();
        Shapes sky;
        glColor3f(0.529, 0.808, 0.980);
        glTranslatef(-5.0, 1.5, 0.0);
        sky.filled_quad(100.0, 1.5);
        glPopMatrix();

}

    // 3D look
	glPushMatrix();
	//glRotatef(1.5, 0.0, 0.0, 1.0);

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
    if(KeyEvents::skyColor=='n')
    {
        glPushMatrix();
        glColor3f(1.0, 1.0, 0.0);
        glTranslatef(-3.2, -0.6, 0.0);
        glRotatef(-92, 1.0, 0.0, 0.0);
        glRotatef(-10, 0.0, 1.0, 0.0);
        glRotatef(_angle, 0.0, 0.0, 1.0);
        glutWireCone(0.2, 0.5, 20, 20);
        glPopMatrix();
    }


    // Volley ball
    glPushMatrix();
    glTranslatef(-1.0, -0.6, 0.0);
    glRotatef(-ballAngle, 0.0, 0.0, 1.0);
    glTranslatef(-0.8, 0.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glRotatef(_angle, 0.0, 0.0, 1.0);
    glutWireSphere(0.2, 30, 30);
    glPopMatrix();

    // Sand
    glPushMatrix();
    Shapes sand;
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(-5.0, -1.5, 0.0);
    sand.horizontal_long_line(0.0);
    glColor3f(0.957, 0.643, 0.376);
    sand.filled_quad(100.0, 2.0);
    glPopMatrix();

	// Sea
    glPushMatrix();
    Shapes sea;
    glBegin(GL_QUADS);
    glVertex3f(-5.0, 0.0, 0.0);
    glVertex3f(5.0, 0.0, 0.0);
    glColor3f(0.0, 0.749, 1.0);
    glVertex3f(5.0, 0.8, 0.0);
    glVertex3f(-5.0, 0.8, 0.0);
    glEnd();
    glColor3f(0.0, 0.749, 1.0);
    glTranslatef(-5.0, 0.5, 0.0);
    sea.filled_quad(100.0, 1.5);
    glPopMatrix();

    // Car
	glPushMatrix();
	glTranslatef(carPos, -2.6, 0.0);
	glScalef(0.8,0.8,0.0);
	// Back wheel
	glPushMatrix();
	glRotatef(wheelAngle, 0.0, 0.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	car.filled_circle(0.05);
	car.straightLine(0.2, 0.0);
	car.straightLine(0.0, 0.2);
	car.straightLine(-0.2, 0.0);
	car.straightLine(0.0, -0.2);
	glColor3f(0.863, 0.863, 0.863);
	car.filled_circle(0.15);
	glColor3f(0.0, 0.0, 0.0);
	car.filled_circle(0.2);
	glPopMatrix();
	// Front wheel
	glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();
	glRotatef(wheelAngle, 0.0, 0.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	car.filled_circle(0.05);
	car.straightLine(0.2, 0.0);
	car.straightLine(0.0, 0.2);
	car.straightLine(-0.2, 0.0);
	car.straightLine(0.0, -0.2);
	glColor3f(0.863, 0.863, 0.863);
	car.filled_circle(0.15);
	glColor3f(0.0, 0.0, 0.0);
	car.filled_circle(0.2);
	glPopMatrix();
    // Front light
    if(KeyEvents::skyColor=='n')
    {
        glTranslatef(0.65, 0.4, 0.0);
        glColor3f(1.0, 1.0, 0.0);
        glRotatef(-90, 0.0, 1.0, 0.0);
        glPushMatrix();
        glRotatef(_angle, 0.0, 0.0, 1.0);
        glutWireCone(0.18, 0.3, 20, 20);
        glPopMatrix();
        glRotatef(90, 0.0, 1.0, 0.0);
        glTranslatef(-0.3, -0.15, 0.0);
        car.filled_quad(0.15, 0.3);
    }else
    {
        glTranslatef(0.65, 0.4, 0.0);
        glColor3f(1.0, 1.0, 0.0);
        glRotatef(-90, 0.0, 1.0, 0.0);
        glPushMatrix();
        glRotatef(_angle, 0.0, 0.0, 1.0);
        //glutWireCone(0.18, 0.3, 20, 20);
        glPopMatrix();
        glRotatef(90, 0.0, 1.0, 0.0);
        glTranslatef(-0.3, -0.15, 0.0);
        car.filled_quad(0.15, 0.3);
    }

	// Back light
	glTranslatef(-1.85, 0.15, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	car.filled_quad(0.1, 0.2);
	// Body
	glTranslatef(0.0, -0.4, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	car.filled_quad(2.0, 0.6);
	// Window
	glRotatef(180, 1.0, 0.0, 0.0);
	glTranslatef(0.65, -1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	car.straightLine(0.0,0.5);
    glBegin(GL_LINE_LOOP);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.5, 0.0, 0.0);
    glVertex3f(1.0, 0.5, 0.0);
    glVertex3f(-0.6, 0.5, 0.0);
    glVertex3f(-0.5, 0.0, 0.0);
    glEnd();
    glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.5, 0.0, 0.0);
    glVertex3f(1.0, 0.5, 0.0);
    glVertex3f(-0.6, 0.5, 0.0);
    glVertex3f(-0.5, 0.0, 0.0);
    glEnd();
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
    glTranslatef(-5.0, -3.2, 0.0);
    road.filled_quad(100.0, 1.5);
    glPopMatrix();

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
	if (_ang_tri > 360)
		_ang_tri -= 360;

    if(KeyEvents::moveCar)
    {
        carPos += 0.05f;
        if(carPos > 6.0)
            carPos = -6.0;

        wheelAngle -= 10.0f;
        if (wheelAngle < 0)
            wheelAngle = 360;
    }

    cloudPos1 += 0.01;
    if(cloudPos1 > 6.0)
        cloudPos1 = -6.0;

    cloudPos2 -= 0.01;
    if(cloudPos2 < -6.0)
        cloudPos2 = 6.0;

    cloudPos3 += 0.02;
    if(cloudPos3 > 6.0)
        cloudPos3 = -6.0;

    birdPos1 += 0.03;
    if(birdPos1 > 6.0)
        birdPos1 = -6.0;

    birdPos2 -= 0.03;
    if(birdPos2 < -6.0)
        birdPos2 = 6.0;

    birdPos3 += 0.04;
    if(birdPos3 > 6.0)
        birdPos3 = -6.0;

    hotAirBalloonPos -= 0.02;
    if(hotAirBalloonPos < -5.0)
        hotAirBalloonPos = 5.0;

    if(KeyEvents::moveVolleyBall)
    {
        if(bounceBack) {
        ballAngle -= 2.0f;
        }
        else {
            ballAngle += 2.0f;
        }

        if(ballAngle > 180) {
            bounceBack = true;
            KeyEvents::moveVolleyBall = false;
        }
        else if(ballAngle < 0) {
            bounceBack = false;
            KeyEvents::moveVolleyBall = false;
        }
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

	cout << "1. Press d to move boat right" << endl;
	cout << "2. Press a to move boat left" << endl;
	cout << "3. Press c to move/stop car" << endl;
	cout << "4. Press v to throw volley ball" << endl;
	cout << "5. Press m or n to toggle between day and night" << endl;

	glutMainLoop();
	return 0;
}




