#include "MyWebServer.h"
#include "Arduino.h"
#include <avr/pgmspace.h>
extern "C"
{
#include "MyConfig.h"
}

MyWebServer::MyWebServer(boolean (*responseFunc)(char*))
{
    this->numRouters_ = 0;
	WiServer.init(responseFunc);
	WiServer.enableVerboseMode(true);
}

void MyWebServer::addRouter(Router * router)
{
    this->routers_[this->numRouters_++] = router;
}

void MyWebServer::run()
{
	WiServer.server_task();
}

void MyWebServer::request(char *url)
{
    for (int i = 0; i < this->numRouters_; i++) {
        this->routers_[i]->route(url);
    }

}


