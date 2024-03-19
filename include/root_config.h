#ifndef ROOT_CONFIG_H
#define ROOT_CONFIG_H

#include <http_config.h>    // Load the `HTTP` config header

struct RootConfig {
    int maxConn;   // Define the max number of connections allowed
    HTTPConfig httpConf[1];    // The minimum required http config is for port 80
};

#endif
