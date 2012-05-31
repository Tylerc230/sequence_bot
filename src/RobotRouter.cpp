#include "RobotRouter.h"
#include "WiServer.h"
#include "Arduino.h"
void turn_robot_right(char * url);
void turn_robot_left(char * url);
void robot_forward(char * url);
void robot_backward(char * url);

void RobotRouter::initRoutes()
{
	Router::initRoutes();
	this->addRoute("/robot/turnright", turn_robot_right);
	this->addRoute("/robot/turnleft", turn_robot_left);
	this->addRoute("/robot/forward", robot_forward);
	this->addRoute("/robot/backward", robot_backward);
}

void turn_robot_right(char * url)
{
	Serial.println("turn right");
}

void turn_robot_left(char * url)
{
	Serial.println("turn left");
}

void robot_forward(char * url)
{

}

void robot_backward(char * url)
{

}

