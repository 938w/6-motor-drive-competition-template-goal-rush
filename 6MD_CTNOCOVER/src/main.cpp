/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here
bool state = false;
bool last = false;
bool boxstate = false;
bool boxlast = false;
bool ringstate = false;
bool ringlast = false;
bool pistonOn = false;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // .......................................................................... a password
  FourBar.stop(hold);
  Clamp.set(true);
  RightMotor1.setVelocity(100, pct);
  RightMotor2.setVelocity(100, pct);
  RightMotorREV.setVelocity(100, pct);
  LeftMotor1.setVelocity(100, pct);
  LeftMotor2.setVelocity(100, pct);
  LeftMotorREV.setVelocity(100, pct);
  RightMotor1.spin(forward);
  RightMotor2.spin(forward);
  RightMotorREV.spin(forward);
  LeftMotor1.spin(reverse);
  LeftMotor2.spin(reverse);
  LeftMotorREV.spin(reverse);
  wait(0.9, sec);
  RightMotor1.stop();
   RightMotor2.stop();
    RightMotorREV.stop();
      LeftMotor1.stop();
      LeftMotor2.stop();
      LeftMotorREV.stop();
      Clamp.set(false);
      RightMotor1.spin(reverse);
  RightMotor2.spin(reverse);
  RightMotorREV.spin(reverse);
  LeftMotor1.spin(forward);
  LeftMotor2.spin(forward);
  LeftMotorREV.spin(forward);
  
  wait(1, sec);
  RightMotor1.stop();
   RightMotor2.stop();
    RightMotorREV.stop();
      LeftMotor1.stop();
      LeftMotor2.stop();
      LeftMotorREV.stop();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  RingMech.spin(forward,600,rpm);
  RightPiston.set(true);
  Clamp.set(true);
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................
  
    RightMotor1.spin(forward, Controller1.Axis2.position(), percent);
    RightMotorREV.spin(forward,Controller1.Axis2.position(), percent);
    RightMotor2.spin(forward,Controller1.Axis2.position(), percent);
    LeftMotor1.spin(reverse, Controller1.Axis3.position(), percent);
    LeftMotorREV.spin(reverse, Controller1.Axis3.position(), percent);
    LeftMotor2.spin(reverse, Controller1.Axis3.position(), percent);

    if (Controller1.ButtonA.pressing() && !last) {
      last = true;
      state = !state;
    }
    if (!Controller1.ButtonA.pressing()) {
      last = false;
    }
        
    if (state) {
      if (Controller1.Axis3.position()  < 7 &&
          Controller1.Axis3.position() > -7) {
        
        LeftMotor1.stop(hold);
        LeftMotor2.stop(hold);
        LeftMotorREV.stop(hold);
      }
      if(Controller1.Axis2.position() < 7 && Controller1.Axis2.position() > -7) {
        RightMotor1.stop(hold);
        RightMotorREV.stop(hold);
        RightMotor2.stop(hold);
      }
    }
    if (!state) {
      if (Controller1.Axis3.position()  < 7 &&
          Controller1.Axis3.position() > -7) {
        
        LeftMotor1.stop(coast);
        LeftMotor2.stop(coast);
        LeftMotorREV.stop(coast);
      }
      if(Controller1.Axis2.position() < 7 && Controller1.Axis2.position() > -7) {
        RightMotor1.stop(coast);
        RightMotorREV.stop(coast);
        RightMotor2.stop(coast);
      }
    }
    //bbhbhbhbhbhbhvgvgvvgvghvgvgvgvghvvgvvghvghvghvgvgvhgvgvgvgvghvcgvgvgvgbhbhbbhbhbhbjbbhbhbbnbnmbnmbmnbmnbnbhjvggccgchcghcghcgcgcghcgcgcghcghcgcghcghcgcghcgcghchgcgcghchccggcghccgcfccfchcfcgfcchccffffgfjhfgjfgjfjfjffhgjfgjfghfhgffgfgfgfhgftftftfthfgffyftftfthfjfgfjghfghfghjfghjfghfgjfghjfhgjfgfghfjfgfgfgffjfhgjfgjfgjfgjfgfgfjfgffgjfffffghjfgfgfffjgfhgfgjfgjfgfjtyfgvhgftfvgvtftvbgvtgugtftgygygygyyygggvcfcvfcfcfcfcfcfgvfvgcvvfvfcfcgvfxdcbhvfcghhgvtfvbbjfwghehahclegrhfgrjvhrhvvggbhgghghghghghghhhhhghghgvrhbrhgnvnbbjtthrbfhghrbvbfbcbfhr ghrhgfbbffhbfhfbjnjn
    Controller2.Screen.newLine();
    Controller2.Screen.print(Controller1.ButtonR1.pressing());
    if ((Controller1.ButtonRight.pressing()) && !ringlast) {
      ringlast = true;
      ringstate = !ringstate;
    
    }
    
    if (!Controller1.ButtonRight.pressing()) {
      ringlast = false;
    }
    if (ringstate) {
      if (Controller1.ButtonDown.pressing()) {
      RingMech.spin(reverse, 600, rpm);
      
      } else {
      RingMech.spin(forward, 600, rpm);
      }
    }
    if(!ringstate) {
      RingMech.stop();
    }
    if (Controller1.ButtonR2.pressing()) {
      
      RightPiston.set(true);
    }
    if (Controller1.ButtonR1.pressing()) {
      
      RightPiston.set(false);
    }
    if(Controller1.ButtonY.pressing()) {
      Clamp.set(true);

    }
    if(Controller1.ButtonB.pressing()) {
      Clamp.set(false);
    }
    if (Controller1.ButtonL1.pressing()) {
      FourBar.spin(forward, 100, rpm);
    }
    if (Controller1.ButtonL2.pressing()) {
      FourBar.spin(reverse, 100, rpm);
    }
    if(!Controller1.ButtonL2.pressing()&&!Controller1.ButtonL1.pressing()) {
      FourBar.stop(hold);
    }
    if (Controller1.ButtonX.pressing() && !boxlast) {
      boxlast = true;
      boxstate = !boxstate;
    }
    if (!Controller1.ButtonX.pressing()) {
      boxlast = false;
    }
    if (boxstate) {
      GoalCover.set(true);
    }
    if (!boxstate) {
      GoalCover.set(false);
    }
    wait(5, msec);
    // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
