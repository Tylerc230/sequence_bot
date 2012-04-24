#include "Router.h"
#include <string.h>
#include <arduino.h>
class MyWebServer
{
	public:
	MyWebServer(Router *router);
	void handleRequest(String *request);
	private:
	Router *router_;
	
};
