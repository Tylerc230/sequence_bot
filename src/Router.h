#ifndef ROUTER_H
#define ROUTER_H
typedef void (*RouteFunc)(char *);
class AList;
class Router
{
public:
	Router();
	void route(char * url);
	virtual void initRoutes();
protected:
	void addRoute(char * url, RouteFunc destination);
private:
	AList *routes_;
};
#endif
