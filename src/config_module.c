#include <stdio.h> 
#include <cjson/cJSON.h> 

#include <include/config/load_config.h>
#include <../include/constants.h>

void loadConfig() {
    // open the config JSON
    FILE *fp = fopen(PROXY_CONFIG, "r"); 
    if (fp == NULL) { 
        printf("Error: Unable to open the file.\n"); 
        return 1; 
    }  
}