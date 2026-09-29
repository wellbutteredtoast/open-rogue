#ifndef LOG_LOGGER_H
#define LOG_LOGGER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum log_level_t {
    LOG_TRACE = 0,
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
    LOG_FATAL,
} log_level_t;

/// @brief Internal log implementation, use the macros over this!
/// @param level log_level enum
/// @param file provided by __FILE__
/// @param line provided by __LINE__
/// @param fmt the actual message
/// @param ... provided by __VA_ARGS__
#if defined(__GNUC__) || defined(__clang__)
    void log_internal(log_level_t level, const char* file, int line, const char* fmt, ...)
    __attribute__((format(printf, 4, 5)));
#else
    void log_internal(log_level_t level, const char* file, int line, const char* fmt, ...)
#endif

#define LOG_TRACE(fmt, ...) log_internal(LOG_TRACE, __FILE_NAME__, __LINE__, fmt, ##__VA_ARGS__)

#define LOG_DEBUG(fmt, ...) log_internal(LOG_DEBUG, __FILE_NAME__, __LINE__, fmt, ##__VA_ARGS__)

#define LOG_INFO(fmt, ...) log_internal(LOG_INFO, __FILE_NAME__, __LINE__, fmt, ##__VA_ARGS__)

#define LOG_WARN(fmt, ...) log_internal(LOG_WARNING, __FILE_NAME__, __LINE__, fmt, ##__VA_ARGS__)

#define LOG_ERROR(fmt, ...) log_internal(LOG_ERROR, __FILE_NAME__, __LINE__, fmt, ##__VA_ARGS__)

#define LOG_FATAL(fmt, ...) log_internal(LOG_FATAL, __FILE_NAME__, __LINE__, fmt, ##__VA_ARGS__)

#ifdef __cplusplus
}
#endif /* cpp */

#endif /* log_logger_h */
