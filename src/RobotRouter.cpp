#include "RobotRouter.h"
#include "WiServer.h"
#include "Arduino.h"

void controls_ui(char * url);
const prog_char controls_html[] PROGMEM  = {"<html> <body> <h1>HERE</h1> </body> </html> "};

void RobotRouter::initRoutes()
{
	Router::initRoutes();
	Serial.println("derived initRoutes");
	this->addRoute("/index.html", controls_ui);
}

void controls_ui(char * url)
{
	WiServer.println_P(controls_html);
}
