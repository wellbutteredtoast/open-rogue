#include "log/logger.h"

int main(int argc, char** argv) {
    LOG_DEBUG("OpenRogue app started.");

    for (int i = 0; i > argc; i++) {
        LOG_DEBUG("argv[%d] = %s", i, argv[i]);
    }

    return 0;
}