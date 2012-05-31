#include "RobotRouter.h"
#include "WiServer.h"
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "COI.h"

#define CREATE_TX            2
#define CREATE_RX           3

void turn_robot_right(char * url);
void turn_robot_left(char * url);
void robot_forward(char * url);
void robot_backward(char * url);
void robot_stop(char * url);

void RobotRouter::initRoutes()
{
	Router::initRoutes();
    COIInitialize (CREATE_TX, CREATE_RX);
	this->addRoute("/robot/turnright", turn_robot_right);
	this->addRoute("/robot/turnleft", turn_robot_left);
	this->addRoute("/robot/forward", robot_forward);
	this->addRoute("/robot/backward", robot_backward);
	this->addRoute("/robot/stop", robot_stop);
}

void turn_robot_right(char * url)
{
	COIDrive (300, DRIVE_TURN_IN_PLACE_C);
	Serial.println("turn right");
}

void turn_robot_left(char * url)
{
	COIDrive (300, DRIVE_TURN_IN_PLACE_CW);
	Serial.println("turn left");
}

void robot_forward(char * url)
{
	COIDrive (500, DRIVE_STRAIGHT_RADIUS);
	Serial.println("forward");

}

void robot_backward(char * url)
{
	COIDrive (-500, DRIVE_STRAIGHT_RADIUS);
	Serial.println("backward");
}

void robot_stop(char * url)
{
	Serial.println("stop");
	COIDriveStop ();
}
