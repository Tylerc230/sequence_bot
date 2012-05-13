#include "RobotRouter.h"
#include "WiServer.h"
#include "Arduino.h"
#include "resources.h"

void controls_ui(char * url);

void RobotRouter::initRoutes()
{
	Router::initRoutes();
	Serial.println("derived initRoutes");
	this->addRoute("/index.html", controls_ui);
}

void controls_ui(char * url)
{
	WiServer.println_P(resources_controls_html);
}
