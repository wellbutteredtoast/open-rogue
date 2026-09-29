#include "lib/strfmt.hpp"

std::string strfmt(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    va_list copy;
    va_copy(copy, args);
    const int len = std::vsnprintf(nullptr, 0, fmt, copy);
    va_end(copy);

    std::string out;
    if (len > 0) {
        std::vector<char> buf(static_cast<std::size_t>(len) + 1);
        std::vsnprintf(buf.data(), buf.size(), fmt, args);
        out.assign(buf.data(), static_cast<std::size_t>(len));
    }

    va_end(args);
    return out;
}