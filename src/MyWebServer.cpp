#include "MyWebServer.h"
#include "Arduino.h"
#include <avr/pgmspace.h>
extern "C"
{
#include "MyConfig.h"
}

MyWebServer::MyWebServer(Router * router, boolean (*responseFunc)(char*))
{
	WiServer.init(responseFunc);
	WiServer.enableVerboseMode(true);
	this->router_ = router;

}

void MyWebServer::run()
{
	WiServer.server_task();
}

void MyWebServer::request(char *url)
{
	Serial.println("in request");
	this->router_->route(url);
}


