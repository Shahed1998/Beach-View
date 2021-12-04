#include "KeyEvents.h"

KeyEvents::KeyEvents()
{
    //ctor
}

void KeyEvents::key(unsigned char key, int x, int y)
{
    switch(key)
    {
        // Escape key
        case 27:
            exit(0);
            break;


    }
    glutPostRedisplay();
}
