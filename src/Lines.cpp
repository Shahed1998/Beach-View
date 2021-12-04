#include "Lines.h"

Lines::Lines()
{
    //ctor
}

void Lines::horizontal_long_line(float y_axis)
{
    glBegin(GL_LINES);
    glVertex3f(-100.5, y_axis, 0.0);
    glVertex3f(100.5, y_axis, 0.0);
    glEnd();
}

void Lines::lined_quad(float max_x_axis, float max_y_axis)
    {
        //Square with lines
        glBegin(GL_LINE_LOOP);
        glVertex2f(0.0, 0.0);
        glVertex2f(max_x_axis, 0.0);
        glVertex2f(max_x_axis, max_y_axis);
        glVertex2f(0.0, max_y_axis);
        glEnd();
    }

void Lines::filled_quad(float max_x_axis, float max_y_axis)
    {
        //Square with lines
        glBegin(GL_POLYGON);
        glVertex2f(0.0, 0.0);
        glVertex2f(max_x_axis, 0.0);
        glVertex2f(max_x_axis, max_y_axis);
        glVertex2f(0.0, max_y_axis);
        glEnd();
    }
