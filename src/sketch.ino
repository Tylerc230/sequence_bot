#include "../../src/MyWebServer.h"
#include "webserver.h"
static MyWebServer *webServer = NULL;

void setup()
{
	webServer = new MyWebServer(NULL);
}

void loop()
{
	webServer->run();
}

extern "C"{
	void webserver_init() 
	{
		webServer->listen();
	}

	void webserver_appcall()
	{
	}
}
