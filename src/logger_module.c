#include <stdio.h>
#include <time.h>
#include <include/logger/logger.h>
#include <../include/constants.h>

// Function to initialize the logger
void initLogger(Logger *logger) {
    logger->level = LOG_LEVEL;

    // Set default colors
    logger->colors.RESET = "\033[0m";
    logger->colors.ERROR = "\033[31m";
    logger->colors.INFO = "\033[32m";
    logger->colors.WARNING = "\033[33m";
    logger->colors.DEBUG = "\033[34m";
}

void log(Logger *logger, LogLevel messageLevel, const char *format) {
     // Check if the message level is greater than or equal to the logger level
    if (messageLevel <= logger->level) {
        FILE *stream = (messageLevel == ERROR) ? stderr : stdout;

        // Get current timestamp
        char timestamp[20];
        getCurrentTimestamp(timestamp, sizeof(timestamp));

        fprintf(stream, "[%s][", timestamp);

        switch (messageLevel) {
            case ERROR:
                fprintf(stream, "ERROR");
                break;
            case WARNING:
                fprintf(stream, "WARNING");
                break;
            case INFO:
                fprintf(stream, "INFO");
                break;
            case DEBUG:
                fprintf(stream, "DEBUG");
                break;
        }

        fprintf(stream, "][%s]\n", format);    // Print the log message to the console
    }
}