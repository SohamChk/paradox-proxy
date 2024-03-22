#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <constants.h>
#include <config.h>
#include <logger.h>

int parseConfig(char* configData) {

    printf("COnfig %s", configData);

    free( configData );
    return 0;
}

int loadConfig() {
    char buffer[1024];  // buffer to read config file
    char* configData;
    long fileLength;

    // open the config JSON
    FILE *fp = fopen(PROXY_CONFIG, "r");    // `PROXY_CONFIG` is set in the `constants.h` file
    if (fp == NULL) {
        logMessage(ERROR, "Unable to open config file"); 
        return 1; // Return a non-zero value 
    }

    // Get file length
    fseek(fp, 0, SEEK_END);
    fileLength = ftell(fp);
    rewind(fp);

    // Dynamically allocate memory for config file content
    configData = (char *)malloc(fileLength * sizeof(char));

    // Read file line by line and print its contents
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        strcat(configData, buffer);
    }

    // Close the file
    fclose(fp);

    return parseConfig(configData);
}