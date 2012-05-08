#include "MyWebServer.h"
#include "Arduino.h"
#include <avr/pgmspace.h>
#define APP_WISERVER
#include "WiServer.h"
extern "C"
{
#include "MyConfig.h"
}
const prog_char html[] PROGMEM  = {"<html> <body> <h1>My First Heading</h1> <p>My first paragraph.</p> </body> </html> "};
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
	WiServer.println_P(html);
}


