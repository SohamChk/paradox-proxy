#include <stdio.h>
#include <time.h>
#include <include/logger/logger.h>
#include <../include/constants.h>

Logger logger = {LOG_LEVEL}; // Set the default log level

// Logger function to print log messages
void logMessage(LogLevel level, const char* message) {
    if (level >= logger.logLevel) {   // Check if the log level is less than or equal to the configured log level
        FILE* logStream = (level == ERROR || level == WARNING) ? stderr : stdout;

         // Get the current time
        time_t rawtime;
        struct tm* timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);

        // Convert time to ISO 8601 format
        char timestamp[20];
        strftime(timestamp, sizeof(timestamp), "%Y-%m-%dT%H:%M:%S", timeinfo);

        fprintf(logStream, "[%s] [", timestamp);

        switch (level) {
            case ERROR:
                fprintf(logStream, "ERROR");
                break;
            case WARNING:
                fprintf(logStream, "WARNING");
                break;
            case INFO:
                fprintf(logStream, "INFO");
                break;
            case DEBUG:
                fprintf(logStream, "DEBUG");
                break;
        }

        fprintf(logStream, "] %s\n", message);    // Print the log message to the console
    }
}
