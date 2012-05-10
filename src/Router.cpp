#include "Router.h"
#include "WiServer.h"
const prog_char error_404_html[] PROGMEM  = {"<html> <body> <h1>404: NotFound</h1> </body> </html> "};
Router::Router()
{
	this->initRoutes();
}

void Router::initRoutes()
{
}

void Router::route(char * url)
{
}

void file_not_found(char * url)
{
	WiServer.println_P(error_404_html);
}
