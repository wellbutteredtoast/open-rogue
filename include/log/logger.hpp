#ifndef LOG_LOGGER_HPP
#define LOG_LOGGER_HPP

#include <cstdint>

enum class LogLevel : std::uint8_t {
    LOG_TRACE = 0,
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
    LOG_FATAL,
};

#if defined(__GNUC__) || defined(__clang__)
    /// @brief Internal log implementation (with attr), use the macros over this!
    /// @param level log_level enum
    /// @param file provided by __FILE_NAME__
    /// @param line provided by __LINE__
    /// @param fmt the actual message
    /// @param ... provided by __VA_ARGS__
    void log_internal(LogLevel level, const char* file, int line, const char* fmt, ...)
    __attribute__((format(printf, 4, 5)));
#else
    /// @brief Internal log implementation (without attr), use the macros over this!
    /// @param level log_level enum
    /// @param file provided by __FILE__
    /// @param line provided by __LINE__
    /// @param fmt the actual message
    /// @param ... provided by __VA_ARGS__
    void log_internal(LogLevel level, const char* file, int line, const char* fmt, ...);
#endif

#define TRACE(fmt, ...) log_internal(LogLevel::LOG_TRACE, __FILE_NAME__, __LINE__, fmt, ##__VA_ARGS__)

#define DEBUG(fmt, ...) log_internal(LogLevel::LOG_DEBUG, __FILE_NAME__, __LINE__, fmt, ##__VA_ARGS__)

#define INFO(fmt, ...) log_internal(LogLevel::LOG_INFO, __FILE_NAME__, __LINE__, fmt, ##__VA_ARGS__)

#define WARN(fmt, ...) log_internal(LogLevel::LOG_WARNING, __FILE_NAME__, __LINE__, fmt, ##__VA_ARGS__)

#define ERROR(fmt, ...) log_internal(LogLevel::LOG_ERROR, __FILE_NAME__, __LINE__, fmt, ##__VA_ARGS__)

#define FATAL(fmt, ...) log_internal(LogLevel::LOG_FATAL, __FILE_NAME__, __LINE__, fmt, ##__VA_ARGS__)

#endif /* log_logger_hpp */
