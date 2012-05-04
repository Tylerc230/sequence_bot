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

void MyWebServer::handleRequest()
{
	Serial.println("HERE");
	webserver_state *s = &(uip_conn->appstate);
	this->initSocket(s);
	this->parseRequest(s);
}

String *MyWebServer::readLine(webserver_state *s)
{
	//PSOCK_READTO(&s->p, '\n');
	//return new String(s->inputbuf);
	return NULL;
}

int MyWebServer::parseRequest(webserver_state *s)
{
	PSOCK_BEGIN(&s->p);
	//String * newline = readLine(s);
	PSOCK_READTO(&s->p, '\n');
	String * newline = new String(s->inputbuf);
	unsigned char buffer [200];
	unsigned int length = min(199, newline->length());
	newline->getBytes(buffer, length);
	buffer[length] = '\0';
	Serial.println((char*)buffer);
	PSOCK_CLOSE(&s->p);
	PSOCK_END(&s->p);
}

void MyWebServer::initSocket(webserver_state * s)
{
	char * inputBuf = s->inputbuf;
	if(uip_connected()) {
		PSOCK_INIT(&s->p, (unsigned char *)inputBuf, sizeof(inputBuf));
	}
}

