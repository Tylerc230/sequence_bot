#include "Router.h"
#include "arduino.h"
extern "C"{
	void webserver_init();
	void webserver_appcall();
}
class MyWebServer
{
	public:
	MyWebServer(Router *router);
	void run();
	void handleRequest(String *request);
	private:
	Router *router_;
	
};


