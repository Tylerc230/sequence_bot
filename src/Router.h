#ifndef ROUTER_H
#define ROUTER_H
#include "Arduino.h"
typedef void (*RouteFunc)(char *);
class AList;
class Router
{
public:
	Router();
	boolean route(char * url);
	virtual void initRoutes();
protected:
	void addRoute(char * url, RouteFunc destination);
private:
	AList *routes_;
};
#endif
