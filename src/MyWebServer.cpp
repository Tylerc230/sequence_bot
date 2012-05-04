#include "MyWebServer.h"
#include "WiShield.h"
#define LISTEN_PORT 8080
extern "C"
{
#include "uip.h"
}

MyWebServer::MyWebServer(Router * router)
{
	WiFi.init();
	uip_listen(HTONS(80));
	this->router_ = router;

}

void MyWebServer::run()
{
	WiFi.run();
}

void MyWebServer::handleRequest(String *request)
{

}
