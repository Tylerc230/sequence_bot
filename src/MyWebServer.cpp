#include "MyWebServer.h"
#include "Arduino.h"
#include <avr/pgmspace.h>
extern "C"
{
#include "MyConfig.h"
}

const prog_char error_404_html[] PROGMEM  = {"<html> <body> <h1>404: NotFound</h1> </body> </html> "};
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
    boolean found = false;
    for (int i = 0; i < this->numRouters_; i++) {
        found |= this->routers_[i]->route(url);
    }
    if(!found)
    {
	WiServer.println_P(error_404_html);
    }

}


