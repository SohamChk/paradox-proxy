#include <stdio.h>
#include <time.h>
#include <include/logger/logger.h>
#include <../include/constants.h>

// Function to initialize the logger
void initLogger(Logger *logger) {
    logger->level = LOG_LEVEL;

    // Set default colors
    logger->colors.reset = "\033[0m";
    logger->colors.red = "\033[31m";
    logger->colors.green = "\033[32m";
    logger->colors.yellow = "\033[33m";
    logger->colors.blue = "\033[34m";
}

void log(Logger *logger, const char *format) {
     // Check if the message level is greater than or equal to the logger level
    if (LogLevel.ERROR <= logger->level) {
        FILE *stream = stderr;

        // Get current timestamp
        char timestamp[20];
        getCurrentTimestamp(timestamp, sizeof(timestamp));

        fprintf(stream, "[%s][ERROR][%s]\n", timestamp, format);    // Print the log message to the console
    }
}