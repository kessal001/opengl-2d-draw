//Include Library
#include "LibMath/libmath.h"
#include "LibDraw/libdraw.h"
#include "LibMenu/libmenu.h"

#include <GL/freeglut_std.h>
#include <GL/glut.h>

#include <stdio.h>

// Declare object property
float objX;
float objY;
const float objSize = 50;
float RGB[3] = {255, 255, 255};

//Structure to get mouse Position
typedef struct {
  float mx;
  float my;
  float mRGB[3];
} mousePoint;
mousePoint mp[100]; // TODO: Implement a dynamic structure (Problem: max 100 object)

//Click counter for drawing element
int click = 0;

//Function that update mouse position
void motion(int x, int y) {
  objX = x;
  objY = y;
}

void display() {
  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  const double w = glutGet(GLUT_WINDOW_WIDTH);
  const double h = glutGet(GLUT_WINDOW_HEIGHT);
  glOrtho(0, w, h, 0, -1, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  //Draw object
  for (int i = 0; i < click; i++) {
    draw2DQuad(mp[i].mx, mp[i].my, objSize, mp[i].mRGB);
  }

  //Draw object under the mouse
  draw2DQuad(RoundVertex(objX, 2*objSize), RoundVertex(objY, 2*objSize), objSize, RGB);

  //Grid draw
  for (int i = 0; i < 30; i++) {
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(i * 2*objSize + objSize, 0);
    glVertex2f(i * 2*objSize + objSize, h);
    glVertex2f(0, i * 2*objSize + objSize);
    glVertex2f(w, i * 2*objSize + objSize);
    glEnd();
  }
  glutSwapBuffers();
}

//Add object on click
void mouseClicks(int button, int state, int x, int y) {
  if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
    mp[click].mx = RoundVertex(x, 100);
    mp[click].my = RoundVertex(y, 100);
    mp[click].mRGB[0] = RGB[0];
    mp[click].mRGB[1] = RGB[1];
    mp[click].mRGB[2] = RGB[2];
    click++;
  }
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
  glutInitWindowSize(600, 600);
  glutCreateWindow("GLUT");
  glutDisplayFunc(display);
  glutMouseFunc(mouseClicks);
  glutPassiveMotionFunc(motion);
  glutIdleFunc(display);
  glutSetCursor(GLUT_CURSOR_NONE);
  createPopupMenus();
  glutMainLoop();
  return 0;
}
