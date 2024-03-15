#include <stdio.h>
#include <stdlib.h>
#include <constants.h>

#include <config/config.h>
#include <logger/logger.h>

void loadConfig() {
    char buffer[1024];  // buffer to read config file

    // open the config JSON
    FILE *fp = fopen(PROXY_CONFIG, "r");    // `PROXY_CONFIG` is set in the `constants.h` file
    if (fp == NULL) {
        logMessage(ERROR, "Unable to open config file"); 
        return 1; // Return a non-zero value 
    }

    // Read file line by line and print its contents
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        
    }

    // Close the file
    fclose(fp);

    return 0; 
}