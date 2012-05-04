#include "../../src/MyWebServer.h"
#include "webserver.h"
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

extern "C"{
	void webserver_init() 
	{
		webServer->listen(1000);
	}

	void webserver_appcall()
	{
		webServer->handleRequest();
	}
}
