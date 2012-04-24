#include <WiShield.h>
#include <string.h>
#include "webserver.h"
#include "config.h"
#include "../../src/MyWebServer.h"


static MyWebServer *webServer = NULL;

void webserver_init(void) 
{
	webServer = new MyWebServer(NULL);
}

void webserver_appcall(void)
{
	struct webserver_state *s = &(uip_conn->appstate);
	if(uip_connected()) {
		PSOCK_INIT(&s->p, s->inputbuf, sizeof(s->inputbuf));
	}
	String *request	= new String((char *)s->inputbuf);

	webServer->handleRequest(request);
}

void setup()
{
	WiFi.init();
}

void loop()
{
	WiFi.run();
}
