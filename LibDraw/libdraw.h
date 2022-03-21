#ifndef LIBDRAW_C
#define LIBDRAW_C
#include <GL/glut.h>
#endif

/**
 * @brief draw a 3D Triangle
 *
 * @param vertices 3X3 Matrix
 * @param RGB Row vector with RGB value between 0 and 1
 */
void draw3DTriangle(GLfloat vertices[3][3], float RGB[3]);

/**
 * @brief Draw a 2D Quad
 *
 * @param x x
 * @param y y
 * @param size size of the square
 * @param RGB Row vector with RGB value between 0 and 255
 */
void draw2DQuad(float x, float y, float size, float RGB[3]);

