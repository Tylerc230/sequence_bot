#include "Router.h"
#include "arduino.h"
#define LISTEN_PORT 8080
extern "C"{
#include "uip.h"
	void webserver_init();
	void webserver_appcall();
}
class MyWebServer
{
	public:
		MyWebServer(Router *router);
		void listen(uint16_t port = LISTEN_PORT);
		void run();
		void handleRequest();
	private:
		int parseRequest(webserver_state *s);
		String *readLine(webserver_state *s);
		void initSocket(webserver_state * s);
		Router *router_;
	
};


