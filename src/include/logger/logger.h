#include <levels.h>
#include <../include/constants.h>

Logger logger = {LOG_LEVEL}; // Set the default log level

#ifndef LOGGER_H
#define LOGGER_H

// Global configuration structure
typedef struct {
    LogLevel logLevel;
} Logger;

// Logger function to print log messages
void logMessage(LogLevel level, const char* message);

#endif // LOGGER_H
