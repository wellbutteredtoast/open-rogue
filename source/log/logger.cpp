#include "log/logger.hpp"

#include <cstdio>
#include <cstdarg>

void log_internal(enum LogLevel level, const char* file, int line, const char* fmt, ...) {
    /* I don't think this is the most efficient way to do this. Oh well, we 
     * can always come back to this later if this is somehow causing slowdowns.
     */

    char buf[512];
    char final_buf[768];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);

    switch (level) {
        case LogLevel::LOG_TRACE:
            snprintf(final_buf, sizeof(final_buf), "[%s] %s: %d > %s\n", "Trace", file, line, buf);
            fputs(final_buf, stdout);
            break;

        case LogLevel::LOG_DEBUG:
            snprintf(final_buf, sizeof(final_buf), "[%s] %s: %d > %s\n", "Debug", file, line, buf);
            fputs(final_buf, stdout);
            break;

        case LogLevel::LOG_INFO:
            snprintf(final_buf, sizeof(final_buf), "[%s] %s: %d > %s\n", "Info ", file, line, buf);
            fputs(final_buf, stdout);
            break;

        case LogLevel::LOG_WARNING:
            snprintf(final_buf, sizeof(final_buf), "[%s] %s: %d > %s\n", "Warn ", file, line, buf);
            fputs(final_buf, stdout);
            break;

        case LogLevel::LOG_ERROR:
            snprintf(final_buf, sizeof(final_buf), "[%s] %s: %d > %s\n", "Error", file, line, buf);
            fputs(final_buf, stdout);
            break;

        case LogLevel::LOG_FATAL:
            snprintf(final_buf, sizeof(final_buf), "[%s] %s: %d > %s\n", "Fatal", file, line, buf);
            fputs(final_buf, stdout);
            break;
    }

    return;
}
