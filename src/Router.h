#include "HashMap.h"
//typdef void (*RouteFunc)(char *);

class Router
{
public:
	Router();
	void route(char * url);
	virtual void initRoutes();
private:
	//Hashmap<char *, RouteFunc> *routes;
};
