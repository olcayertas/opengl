#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

/*
 * File:   main.cpp
 * Author: Mukaddes
 *
 * Created on March 9, 2014, 12:16 AM
 */

#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include <math.h>
#include <GL/glew.h>
#include <GL/glut.h>

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {
	return 0;
}

void SimpleLineDrawing(int x1, int y1, int const x2, int const y2) {
	int dx = x2 - x1;
	int dy = y2 - y1;
	int x, y;
	
	for (x = x1; x < x2; ++x) {
		y = y1 + dy * (x - x1) / dx;
		plot(x, y);
	}
}

void Bresenham(int x1, int y1, int const x2, int const y2) {
	int delta_x(x2 - x1);
	// if x1 == x2, then it does not matter what we set here
	signed char const ix((delta_x > 0) - (delta_x < 0));
	delta_x = std::abs(delta_x) << 1;

	int delta_y(y2 - y1);
	// if y1 == y2, then it does not matter what we set here
	signed char const iy((delta_y > 0) - (delta_y < 0));
	delta_y = std::abs(delta_y) << 1;

	plot(x1, y1);

	if (delta_x >= delta_y) {
		// error may go below zero
		int error(delta_y - (delta_x >> 1));

		while (x1 != x2) {
			if ((error >= 0) && (error || (ix > 0))) {
				error -= delta_x;
				y1 += iy;
			}
			// else do nothing

			error += delta_y;
			x1 += ix;

			plot(x1, y1);
		}
	} else {
		// error may go below zero
		int error(delta_x - (delta_y >> 1));

		while (y1 != y2) {
			if ((error >= 0) && (error || (iy > 0))){
				error -= delta_y;
				x1 += ix;
			}
			// else do nothing

			error += delta_x;
			y1 += iy;

			plot(x1, y1);
		}
	}
}

