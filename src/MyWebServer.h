#define APP_WISERVER
#include "WiServer.h"
#include "Router.h"
class MyWebServer
{
	public:
		MyWebServer(boolean (*responseFunc)(char*));
        void addRouter(Router * router);
		void run();
		void request(char *url);
	private:
        int numRouters_;
		Router* routers_[20];
	
};


