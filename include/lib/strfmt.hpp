#ifndef LIB_STRFMT_HPP
#define LIB_STRFMT_HPP

#include <cstdarg>
#include <cstdio>
#include <string>
#include <vector>

#if defined(__GNUC__) || defined(__clang__)
    /// @brief std::format fill-in utility since we're on C++11. (has attr)
    /// @param fmt the message
    /// @param ... provided by __VA_ARGS__
    std::string strfmt(const char* fmt, ...)
    __attribute__((format(printf, 1, 2)));
#else
    /// @brief std::format fill-in utility since we're on C++11. (no attr)
    /// @param fmt the message
    /// @param ... provided by __VA_ARGS__
    std::string strfmt(const char* fmt, ...);
#endif

#endif /* lib_strfmt_hpp */