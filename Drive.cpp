#include "Drive.h"
Servo control_servo;
int dir,vel=0;
void driveSetup(){
  pinMode(VELOCITY, OUTPUT);
  pinMode(REVERSE, OUTPUT);
  pinMode(FORWARD, OUTPUT);
  control_servo.attach(CONTROL_SERVO);
}


//GEAR 
void runG(String c){
    if (c.equalsIgnoreCase("stop"))
      calm();
    else if (c.equalsIgnoreCase("forward"))
      forward();
    else if (c.equalsIgnoreCase("back"))
      reverse();
}

//STEERING
void runST(int s){ 
   if (s > 6)
      s=6;
    else if (s < -6)
      s=-6;
    dir = map(s,-6,6,0,179);
    control_servo.write(dir);
    Serial.print("Servo: " + String(dir) + "\r\n");
 }

//THOTTLE
void runTH(int t){
     vel = map (t,0,10, 155, 255);
    if (vel <= 155)
      vel=0;
    analogWrite(VELOCITY, vel);
    Serial.print("Speed: " + String(vel) + "\r\n");
}


void calm(){
	Serial.println("Stop");
	digitalWrite(REVERSE, LOW);
	digitalWrite(FORWARD, LOW);
}

void reverse(){
	Serial.println("REVERSE");
	digitalWrite(REVERSE, HIGH);
	digitalWrite(FORWARD, LOW);
}

void forward(){
	Serial.println("Forward");
	digitalWrite(REVERSE, LOW);
	digitalWrite(FORWARD, HIGH);
}

