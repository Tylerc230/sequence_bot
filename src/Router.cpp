#include "Router.h"
#include "WiServer.h"
#include "Arduino.h"
#include "alist.h"
void file_not_found(char * url);
const prog_char error_404_html[] PROGMEM  = {"<html> <body> <h1>404: NotFound</h1> </body> </html> "};
Router::Router()
{
	this->initRoutes();
}

void Router::initRoutes()
{
	this->routes_ = new AList;
}

void Router::addRoute(char * url, RouteFunc destination)
{
	(*this->routes_)[url] = (void *)destination;
}

void Router::route(char * url)
{
	RouteFunc route = (RouteFunc)(*this->routes_)[url].get_value().oValue;
	if (route != 0)
	{
		route(url);

	}else{
		file_not_found(url);
	}
	
	return;
}

void file_not_found(char * url)
{
	WiServer.println_P(error_404_html);
}
