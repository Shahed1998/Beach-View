#ifndef LINES_H
#define LINES_H
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include<GL/gl.h>
#include <GL/glut.h>


class Lines
{
    public:
        Lines();
        void horizontal_long_line(float y_axis);
        void lined_quad(float max_x_axis, float max_y_axis);
        void filled_quad(float max_x_axis, float max_y_axis);
};

#endif // LINES_H
