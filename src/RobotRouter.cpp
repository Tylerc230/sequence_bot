#include "RobotRouter.h"
#include "WiServer.h"
#include "Arduino.h"
void turn_robot_right(char * url);

void RobotRouter::initRoutes()
{
	Router::initRoutes();
	this->addRoute("/robot/turnright", turn_robot_right);
}

void turn_robot_right(char * url)
{
	Serial.println("turn right");
}

