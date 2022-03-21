#include "libmenu.h"
#include <GL/glut.h>
//Constant define
#define RED 1
#define GREEN 2
#define BLUE 3
#define ORANGE 4
//Variable
extern float RGB[3];
int menuFlag = 0;

int fillMenu, shrinkMenu, mainMenu, colorMenu;
//Check if the menu is used
void processMenuStatus(int status, int x, int y) {

  if (status == GLUT_MENU_IN_USE)
    menuFlag = 1;
  else
    menuFlag = 0;
}
int menuIsUsed() {
  return menuFlag;
}
void processMainMenu(int option) {}

//Handle the change of color
void processColorMenu(int option) {

  switch (option) {
  case RED:
    RGB[0] = 255;
    RGB[1] = 0;
    RGB[2] = 0;
    break;
  case GREEN:
    RGB[0] = 0;
    RGB[1] = 255;
    RGB[2] = 0;
    break;
  case BLUE:
    RGB[0] = 0;
    RGB[1] = 0;
    RGB[2] = 255;
    break;
  case ORANGE:
    RGB[0] = 255;
    RGB[1] = 102;
    RGB[2] = 0;
    break;
  }
}

//Creates the menu popus on the right click
void createPopupMenus() {

  colorMenu = glutCreateMenu(processColorMenu);
  glutAddMenuEntry("Red", RED);
  glutAddMenuEntry("Blue", BLUE);
  glutAddMenuEntry("Green", GREEN);
  glutAddMenuEntry("Orange", ORANGE);

  mainMenu = glutCreateMenu(processMainMenu);

  glutAddSubMenu("Color", colorMenu);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  glutMenuStatusFunc(processMenuStatus);
}