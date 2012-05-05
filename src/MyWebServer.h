#include "Router.h"
class MyWebServer
{
	public:
		MyWebServer(Router *router);
		void run();
	private:
		Router *router_;
	
};


