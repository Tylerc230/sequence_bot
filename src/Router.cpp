#include "Router.h"
#include "WiServer.h"
#include "Arduino.h"
void file_not_found(char * url);
const prog_char error_404_html[] PROGMEM  = {"<html> <body> <h1>404: NotFound</h1> </body> </html> "};
Router::Router()
{
	this->initRoutes();
}

void Router::initRoutes()
{
	Serial.println("in initRoutes");
	this->numRoutes = 0;

}

void Router::addRoute(char * url, RouteFunc destination)
{
	Serial.println("in addRoute");
	this->urls[this->numRoutes] = url;
	this->destinations[this->numRoutes] = destination;
	this->numRoutes++;

}

void Router::route(char * url)
{
	Serial.println("in route");
	for (int i = 0; i < this->numRoutes; i++ )
	{
		char * nextURL = this->urls[i];
		Serial.println(nextURL);
		if (strcmp(url, nextURL) == 0)
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
