#include <stdio.h> 
#include <cjson/cJSON.h> 

#include <include/config/config.h>
#include <../include/constants.h>
#include <include/logger/logger.h>

void loadConfig() {
    // open the config JSON
    FILE *fp = fopen(PROXY_CONFIG, "r");
    if (fp == NULL) {
        logMessage(ERROR, "Unable to open config file"); 
        return 1; 
    }

    // read the file contents into a string 
    char buffer[1024];
    int len = fread(buffer, 1, sizeof(buffer), fp);
    fclose(fp);

    // parse the JSON data
    cJSON *json = cJSON_Parse(buffer); 
    if (json == NULL) { 
        const char *error_ptr = cJSON_GetErrorPtr(); 
        if (error_ptr != NULL) { 
            logMessage(ERROR, error_ptr); 
        } 
        cJSON_Delete(json); 
        return 1; 
    } 
}