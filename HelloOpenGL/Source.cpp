#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

GLfloat lb = -30, ub = 30;
GLfloat cpoints = 2048;

void graphfunct2D(void) {
	GLfloat dx, xi, yi;
	GLfloat i;
	dx = (ub - lb) / cpoints;

	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-30, 30, -30, 30, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINE_STRIP);

	for (i = 0; i <= cpoints; i++) {
		xi = (i * dx) + lb;
		yi = xi * sin(xi);
		glVertex2f(xi, yi);
	}

	glEnd();
	glutSwapBuffers();
}

void SimpleLineDrawing(void){
	int x1 = 100;
	int y1 = 100;
	int const x2 = 300;
	int const y2 = 300;

	int dx = x2 - x1;
	int dy = y2 - y1;
	int x, y;

	printf("X2 = %d - Y2 = %d\n", x2, y2);
	printf("X1 = %d - Y1 = %d\n", x1, y1);
	printf("DX = %d - DY = %d\n", dx, dy);

	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glViewport(0, 0, 500, 500);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 500, 0, 500, 1, -1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINE_STRIP);

	for (x = x1; x < x2; ++x) {
		y = y1 + dy * (x - x1) / dx;
		printf("X = %f - y = %f\n", x, y);
		glVertex2f(x, y);
	}

	//for (x = x1, y = y1; x < x2; ++x, ++y) {
	//	//y = y1 + dy * (x - x1) / dx;
	//	printf("X = %d - y = %d\n", x, y);
	//	glVertex2i(x, y);
	//}

	glEnd();
	glutSwapBuffers();
}

void Bresenham(void)
{
	int x1 = 100;
	int y1 = 100;
	int const x2 = 300;
	int const y2 = 300;

	int delta_x(x2 - x1);
	// if x1 == x2, then it does not matter what we set here
	signed char const ix((delta_x > 0) - (delta_x < 0));
	delta_x = abs(delta_x) << 1;

	int delta_y(y2 - y1);
	// if y1 == y2, then it does not matter what we set here
	signed char const iy((delta_y > 0) - (delta_y < 0));
	delta_y = abs(delta_y) << 1;

	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-30, 30, -30, 30, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINE_STRIP);

	glVertex2i(x1, y1);

	if (delta_x >= delta_y)
	{
		// error may go below zero
		int error(delta_y - (delta_x >> 1));

		while (x1 != x2)
		{
			if ((error >= 0) && (error || (ix > 0)))
			{
				error -= delta_x;
				y1 += iy;
			}
			// else do nothing

			error += delta_y;
			x1 += ix;

			glVertex2i(x1, y1);
		}
	}
	else
	{
		// error may go below zero
		int error(delta_x - (delta_y >> 1));

		while (y1 != y2)
		{
			if ((error >= 0) && (error || (iy > 0)))
			{
				error -= delta_y;
				x1 += ix;
			}
			// else do nothing

			error += delta_x;
			y1 += iy;

			glVertex2i(x1, y1);
		}
	}

	glEnd();
	glutSwapBuffers();
}

int main(int argc, char** argv) {
	/*printf("lower bound: ");
	scanf_s(" %d", &lb);
	printf("upper bound:");
	scanf_s(" %d", &ub);
	printf("Give me the number of points to plot (int)");
	scanf_s(" %d", &cpoints);*/

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	//glutCreateWindow("Graph function in 2D");
	//glutDisplayFunc(graphfunct2D);
	glutCreateWindow("Line function in 2D");
	glutDisplayFunc(SimpleLineDrawing);
	glutMainLoop();
}