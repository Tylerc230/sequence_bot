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

#define MAP_RESOURCE(path, var_name) \
    this->addRoute(path, resource_for_path); \
    (*resources_)[path] = (void*)var_name;

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
    const prog_char* resource_data = (prog_char *)(*resources_)[url].get_value().oValue;
    if (resource_data != NULL) {
        WiServer.print_P(resource_data);
    }

}
