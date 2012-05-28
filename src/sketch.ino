#include "../../src/MyWebServer.h"
#include "RobotRouter.h"
#include "ResourceRouter.h"
static MyWebServer *webServer = NULL;

boolean response(char * url);
void setup()
{
	Serial.begin(9600);
	webServer = new MyWebServer(request);
    
    Router * router = new RobotRouter();
	router->initRoutes();
    webServer->addRouter(router);
    
    Router * resourceRouter = new ResourceRouter();
    resourceRouter->initRoutes();
    webServer->addRouter(resourceRouter);
    
}

void loop()
{
	webServer->run();
}

boolean request(char * url)
{
	webServer->request(url);
}

