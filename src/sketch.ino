#include "../../src/MyWebServer.h"
static MyWebServer *webServer = NULL;

boolean response(char * url);
void setup()
{
	Serial.begin(9600);
	webServer = new MyWebServer(NULL, request);
}

void loop()
{
	webServer->run();
}

boolean request(char * url)
{
	webServer->request(url);
}

