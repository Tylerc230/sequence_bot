#include "MyWebServer.h"
#include "uip.h"
#define LISTEN_PORT 8080

MyWebServer::MyWebServer(Router * router)
{
	//uip_listen(HTONS(80));
	//this->router_ = router;

}

void MyWebServer::handleRequest(String *request)
{

}
