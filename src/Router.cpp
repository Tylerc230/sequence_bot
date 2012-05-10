#include "Router.h"
#include "WiServer.h"
void file_not_found(char * url);
const prog_char error_404_html[] PROGMEM  = {"<html> <body> <h1>404: NotFound</h1> </body> </html> "};
Router::Router()
{

	this->initRoutes();
}

void Router::initRoutes()
{
	this->numRoutes = 0;

}

void Router::addRoute(char * url, RouteFunc destination)
{
	this->urls[this->numRoutes] = url;
	this->destinations[this->numRoutes] = destination;
	this->numRoutes++;

}

void Router::route(char * url)
{
	for (int i = 0; i < this->numRoutes; i++ )
	{
		if (strcmp(url, this->urls[i]) == 0)
		{
			RouteFunc destination = this->destinations[i];
			destination(url);
			return;
		}
	}
	file_not_found(url);
	return;
}

void file_not_found(char * url)
{
	WiServer.println_P(error_404_html);
}
