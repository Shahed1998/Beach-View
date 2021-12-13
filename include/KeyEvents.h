#ifndef KEYEVENTS_H
#define KEYEVENTS_H
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include<GL/gl.h>
#include <GL/glut.h>


class KeyEvents
{
    public:
        static float boatPos;
        static bool moveCar, moveVolleyBall;
        KeyEvents();
        void key(unsigned char key, int x, int y);

};

#endif // KEYEVENTS_H
