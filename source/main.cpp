#define GLFW_INCLUDE_NONE

#include "log/logger.hpp"

#include <GLFW/glfw3.h>

int main(int argc, char** argv) {
    RTRACE("OpenRogue app started.");

    const char* errDesc;
    if (!glfwInit()) {
        RFATAL("GLFW Init failed: (%d)", glfwGetError(&errDesc));
        return 1;
    }
    RDEBUG("GLFW init ok");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(
        640, 480, "OpenRogue",
        nullptr, nullptr
    );

    if (!window) {
        RFATAL("glfwCreateWindow() failed: (%d)", glfwGetError(&errDesc));
        return 1;
    }
    RDEBUG("GLFW created window ok");

    glfwMakeContextCurrent(window);
    RDEBUG("GLFW context is now current");

    return 0;
}