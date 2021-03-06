// Drive.h

#ifndef _DRIVE_h
#define _DRIVE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#include <Servo.h>

#define CONTROL_SERVO 2
#define FORWARD 3
#define REVERSE 4
#define VELOCITY 5

void driveSetup();
void runG(String c);
void runST(int s);
void runTH(int t);
void calm();
void reverse();
void forward();
#endif

