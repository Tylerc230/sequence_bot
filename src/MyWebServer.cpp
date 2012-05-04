#include "MyWebServer.h"
#include "WiShield.h"
extern "C"
{
#include "uip.h"
#include "MyConfig.h"
}

MyWebServer::MyWebServer(Router * router)
{
	WiFi.init();
	this->router_ = router;

}

void MyWebServer::listen(uint16_t port)
{
	uip_listen(HTONS(port));
}

void MyWebServer::run()
{
	WiFi.run();
}

void MyWebServer::handleRequest(struct uip_conn *uip_conn)
{
	struct webserver_state *s = &(uip_conn->appstate);
	char * inputBuf = s->inputbuf;
	if(uip_connected()) {
		PSOCK_INIT(&s->p, (unsigned char *)inputBuf, sizeof(inputBuf));
	}
	String *request	= new String(inputBuf);


}

