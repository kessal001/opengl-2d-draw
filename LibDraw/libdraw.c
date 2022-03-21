#include <GL/glut.h>
//Draw triangle in a 3d space
void draw3DTriangle(GLfloat vertices[3][3], float RGB[3]) {
  glBegin(GL_TRIANGLES);
  glColor3f(RGB[0], RGB[1], RGB[2]);
  for (int i = 0; i < 3; i++) {
    glVertex3f(vertices[i][0], vertices[i][1], vertices[i][2]);
  }
  glEnd();
}
//Draw quad in a 2d space
void draw2DQuad(float x, float y, float size,float RGB[3]) {
  glPushMatrix();
  glTranslatef(x, y, 0.0f);
  glScalef(size, size, 1.0f);
  glBegin(GL_QUADS);
  glColor3ub(RGB[0], RGB[1], RGB[2]);
  glVertex2f(-1, -1);
  glVertex2f(1, -1);
  glVertex2f(1, 1);
  glVertex2f(-1, 1);
  glEnd();
  glPopMatrix();
}