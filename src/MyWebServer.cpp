#include "MyWebServer.h"
#include "Arduino.h"
#define APP_WISERVER
#include "WiServer.h"
extern "C"
{
#include "MyConfig.h"
}
boolean response(char * url);

MyWebServer::MyWebServer(Router * router)
{
	WiServer.init(response);
	WiServer.enableVerboseMode(true);
	this->router_ = router;

}

void MyWebServer::run()
{
	WiServer.server_task();
}

boolean response(char * url)
{
	Serial.println("here");
	WiServer.println_P("<html> <body> <h1>My First Heading</h1> <p>My first paragraph.</p> </body> </html> ");
}


