#include "../../src/MyWebServer.h"
#include "webserver.h"
#include "MyConfig.h"
static MyWebServer *webServer = NULL;
extern "C"{
void webserver_init() 
{
	webServer = new MyWebServer(NULL);
}

void webserver_appcall()
{
	//struct webserver_state *s = &(uip_conn->appstate);
	//char * inputBuf = s->inputbuf;
	//if(uip_connected()) {
		//PSOCK_INIT(&s->p, (unsigned char *)inputBuf, sizeof(inputBuf));
	//}
	//String *request	= new String(inputBuf);

	//webServer->handleRequest(request);
}
}

void setup()
{
}

void loop()
{
}
