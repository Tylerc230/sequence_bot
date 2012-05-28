#include "Router.h"
#include "WiServer.h"
#include "Arduino.h"
#include "alist.h"
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

boolean Router::route(char * url)
{
	RouteFunc route = (RouteFunc)(*this->routes_)[url].get_value().oValue;
	if (route != 0)
	{
		route(url);
		return true;
	}else{
		return false;
	}
}

