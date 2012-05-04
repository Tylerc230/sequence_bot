#include "Router.h"
#include "arduino.h"
#define LISTEN_PORT 8080
extern "C"{
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
		Router *router_;
	
};


