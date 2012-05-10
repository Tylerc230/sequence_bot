#define APP_WISERVER
#include "WiServer.h"
#include "Router.h"
class MyWebServer
{
	public:
		MyWebServer(Router * router, boolean (*responseFunc)(char*));
		void run();
		void request(char *url);
	private:
		Router *router_;
	
};


