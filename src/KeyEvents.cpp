#include "KeyEvents.h"

float KeyEvents::boatPos = 0.0;
bool KeyEvents::moveCar = true;
bool KeyEvents::moveVolleyBall = true;

KeyEvents::KeyEvents()
{
    //ctor
}

void KeyEvents::key(unsigned char key, int x, int y)
{
    switch(key)
    {
        // Escape key to close full screen
        case 27:
            exit(0);
            break;

        // To move boat right
        case 'd':
            if(KeyEvents::boatPos > 14)
                KeyEvents::boatPos = -14.0;
            else
                KeyEvents::boatPos += 0.1;
            break;

        // To move boat left
        case 'a':
            if(KeyEvents::boatPos < -14)
                KeyEvents::boatPos = 14.0;
            else
                KeyEvents::boatPos -= 0.1;
            break;

        // To move/stop car
        case 'c':
            if(KeyEvents::moveCar)
                KeyEvents::moveCar = false;
            else
                KeyEvents::moveCar = true;
            break;

        // To throw volley ball
        case 'v':
            if(!KeyEvents::moveVolleyBall)
                KeyEvents::moveVolleyBall = true;
            break;
    }
    glutPostRedisplay();
}
