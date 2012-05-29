//
//  ResourceRouter.cpp
//  sequence_bot
//
//  Created by Tyler Casselman on 5/27/12.
//  Copyright (c) 2012 Casselman Consulting. All rights reserved.
//
#include "ResourceRouter.h"
#include "alist.h"
#include "Arduino.h"
#include "WiServer.h"

#include "resource_declarations.h"
class Resource{
    public:
        Resource(const prog_char* data, size_t length) : data_(data), length_(length){}
        const prog_char * data_;
        size_t length_;
};
#define MAP_RESOURCE(path, var_name) \
    this->addRoute(path, resource_for_path); \
    (*resources_)[path] = (void*)new Resource(var_name, sizeof(var_name));

void resource_for_path(char * url);

static AList *resources_ = NULL;
void ResourceRouter::initRoutes()
{
    Router::initRoutes();
    resources_ = new AList;
#include "resource_mappings.h"
}

void resource_for_path(char * url)
{
    Resource* resource_data = (Resource *)(*resources_)[url].get_value().oValue;
    if (resource_data != NULL) {
        int length = resource_data->length_;
        const prog_char *data = resource_data->data_;
        WiServer.write_P(data, length);
    }

}
