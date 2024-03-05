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

void log(Logger *logger, LogLevel messageLevel, const char *format)