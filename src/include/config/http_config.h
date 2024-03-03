#ifndef HTTP_CONFIG_H
#define HTTP_CONFIG_H

struct HTTPConfig {
    int listenPort;   // The port on which we need to listen
    int ipv;   // The ipv socket on which we need to listen
};

#endif