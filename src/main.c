#include <include/logger/logger.h>
#include <include/config/config.h>

void main() {
    logMessage(DEBUG, 'Running main ....');
    loadConfig();
}