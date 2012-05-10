#define kMaxRoutes 20
typedef void (*RouteFunc)(char *);

class Router
{
public:
	Router();
	void route(char * url);
	virtual void initRoutes();
protected:
	void addRoute(char * url, RouteFunc destination);
private:
	int numRoutes;
	char * urls[kMaxRoutes];
	RouteFunc destinations[kMaxRoutes];
};
