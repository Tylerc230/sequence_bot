#include "../../src/MyWebServer.h"
static MyWebServer *webServer = NULL;

void setup()
{
	Serial.begin(9600);
	webServer = new MyWebServer(NULL);
}

void loop()
{
	webServer->run();
}

