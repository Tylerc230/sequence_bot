#include "../../src/MyWebServer.h"
#include "RobotRouter.h"
static MyWebServer *webServer = NULL;

boolean response(char * url);
void setup()
{
	Serial.begin(9600);
	Router * router = new RobotRouter();
	router->initRoutes();
	webServer = new MyWebServer(router, request);
}

void loop()
{
	webServer->run();
}

boolean request(char * url)
{
	webServer->request(url);
}

