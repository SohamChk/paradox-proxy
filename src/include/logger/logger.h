#include <levels.h>


// Struct to represent colors
typedef struct {
    const char *reset;
    const char *red;
    const char *green;
    const char *yellow;
    const char *blue;
} LoggerColor;

// Logger Struct
struct Logger {
    LogLevel level;
    LoggerColor colors;
};

// Declare initial Logger method
void initLogger(Logger *logger);

void logError(Logger *logger, const char *format)
void logWarning(Logger *logger, const char *format)
void logInfo(Logger *logger, const char *format)
void logDebug(Logger *logger, const char *format)