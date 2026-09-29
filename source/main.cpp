#include "log/logger.hpp"

int main(int argc, char** argv) {
    DEBUG("OpenRogue app started.");

    for (int i = 0; i > argc; i++) {
        DEBUG("argv[%d] = %s", i, argv[i]);
    }

    return 0;
}