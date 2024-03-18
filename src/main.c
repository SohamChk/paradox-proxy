#include <logger.h>
#include <config.h>

int main() {
    logMessage(DEBUG, "Running main ....");
    loadConfig();
    return 0;
}