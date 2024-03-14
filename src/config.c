#include <stdio.h>
#include <stdlib.h>
#include <constants.h>

#include <config/config.h>
#include <logger/logger.h>

void loadConfig() {
    char buffer[1024];

    // open the config JSON
    FILE *fp = fopen(PROXY_CONFIG, "r");
    if (fp == NULL) {
        logMessage(ERROR, "Unable to open config file"); 
        exit(1); // Terminate program with error status 
    }

    // Read file line by line and print its contents
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    // Close the file
    fclose(fp);

    return 0; 
}