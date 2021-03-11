/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       DietMilk420                                               */
/*    Created:      Wed Feb 24 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Xmotor               motor         1
// Ymotor               motor         2
// Zmotor               motor         3
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <cmath>
using namespace vex;

void goTo(int x, int y, int z) {
  Zmotor.spinToPosition(z, degrees);

  Xmotor.setVelocity(
      std::abs((x - Xmotor.position(degrees) / y - Ymotor.position(degrees))),
      percent);
  Ymotor.setVelocity(
      std::abs((y - Ymotor.position(degrees) / x - Xmotor.position(degrees))),
      percent);

  Ymotor.startSpinTo(y, degrees);
  Xmotor.spinToPosition(x, degrees);
}
// allows free movement in any of the 3 axes of the machine.

void goFor(int x, int y, int z) {
  Zmotor.spinToPosition(z, degrees);

  Xmotor.setVelocity(
      std::abs((x - Xmotor.position(degrees) / y - Ymotor.position(degrees))),
      percent);
  Ymotor.setVelocity(
      std::abs((y - Ymotor.position(degrees) / x - Xmotor.position(degrees))),
      percent);

  Ymotor.startSpinFor(y, degrees);
  Xmotor.spinFor(x, degrees);
}
// goFor went unused, it is easier to draw letters based upon absolute points
//curves would be useful for smoother letters. 
void reset() {
  Xmotor.setPosition(0, degrees);
  Ymotor.setPosition(60, degrees);
}
const int home = 15;
// home is where pen touches paper.

int main() {
  // Initializing Robot Configuration. DO NOT REMOV1E!
  vexcodeInit();
  goTo(0, 60, 0);
  reset();
 // goes to the "home" position of the letters.
  Brain.Screen.clearScreen();
  Brain.Screen.printAt(1, 1, "Start Draw letter A");
// start of first letter
  goTo(15, 0, home);
  goTo(30, 60, home);
  goTo(0, 30, 0);
  goTo(30, 30, home); // should draw letter A
                      // end of first letter
  Brain.Screen.printAt(5, 5, "resetting x and y to start positions");
  goTo(50, 60, 0);
  reset();
  Brain.Screen.clearScreen();
  Brain.Screen.printAt(1, 1, "Start Draw Letter B");
// start of second letter
  goTo(0, 0, home);
  goTo(30, 15, home);
  goTo(0, 30, home);
  goTo(30, 45, home);
  goTo(0, 60, home); // should draw letter B
                     // end of second letter
  Brain.Screen.printAt(5, 5, "resetting x and y to start positions");
  goTo(50, 60, 0);
  reset();
  Brain.Screen.clearScreen();
  Brain.Screen.printAt(1, 1, "Start Draw letter C");
// start of third letter
  goTo(0, 0, home);
  goTo(30, 0, home);
  goTo(30, 60, 0);
  goTo(0, 60, home); // should draw letter C
                     // end of third letter
  Brain.Screen.printAt(5, 5, "resetting x and y to start positions");
  goTo(50, 60, 0);
  reset();
}
