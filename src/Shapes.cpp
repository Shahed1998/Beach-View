#include "Shapes.h"

Shapes::Shapes()
{
    //ctor
}

void Shapes::horizontal_long_line(float y_axis)
{
    glBegin(GL_LINES);
    glVertex3f(-100.5, y_axis, 0.0);
    glVertex3f(100.5, y_axis, 0.0);
    glEnd();
}

void Shapes::lined_quad(float max_x_axis, float max_y_axis)
    {
        //Square with lines
        glBegin(GL_LINE_LOOP);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(max_x_axis, 0.0, 0.0);
        glVertex3f(max_x_axis, max_y_axis, 0.0);
        glVertex3f(0.0, max_y_axis, 0.0);
        glEnd();
    }

void Shapes::filled_quad(float max_x_axis, float max_y_axis)
    {
        //Square with lines
        glBegin(GL_POLYGON);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(max_x_axis, 0.0, 0.0);
        glVertex3f(max_x_axis, max_y_axis, 0.0);
        glVertex3f(0.0, max_y_axis, 0.0);
        glEnd();
    }

void Shapes::straightLine(float x, float y)
{
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(x, y, 0.0);
    glEnd();
}

void Shapes::dashed_circle(float r)
{
	glBegin(GL_LINES);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x, y, 0.0);
	}
	glEnd();
}

void Shapes::filled_circle(float r)
{
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x, y, 0.0);
	}
	glEnd();
}

void Shapes::dashed_halfCircle(float r)
{
	glBegin(GL_LINES);
	for(int i=0;i<=50;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x, y, 0.0);
	}
	glEnd();
}

void Shapes::filled_halfCircle(float r)
{
	glBegin(GL_POLYGON);
	for(int i=0;i<=50;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex3f(x, y, 0.0);
	}
	glEnd();
}
