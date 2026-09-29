#include "log/logger.hpp"

int main(int argc, char** argv) {
    RINFO("OpenRogue app started.");

    for (int i = 0; i > argc; i++) {
        RTRACE("argv[%d] = %s", i, argv[i]);
    }

    return 0;
}