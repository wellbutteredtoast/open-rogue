#include <stdexcept>
#define GLFW_INCLUDE_NONE

#include "log/logger.hpp"

#include <GLFW/glfw3.h>

#include <string>

static int windowHeight = 480;
static int windowWidth = 640;

int main(int argc, char** argv) {
    RTRACE("OpenRogue app started.");

    for (int i = 0; i < argc; i++) {
        RTRACE("Checking ARGV: %s", argv[i]);
        if (std::string(argv[i]) == "--width") {
            if (i + 1 >= argc) {
                RERROR("Missing argument value!");
                break;
            }

            try {
                windowWidth = std::stoi(argv[i + 1]);
            } catch(std::invalid_argument) { 
                RERROR("Argument passed is invalid (requires int) !");
                windowWidth = 640;
                continue;
            }
        }
        else if (std::string(argv[i]) == "--height") {
            if (i + 1 >= argc) {
                RERROR("Missing argument value!");
                break;
            }

            try {
                windowHeight = std::stoi(argv[i + 1]);
            } catch(std::invalid_argument) { 
                RERROR("Argument passed is invalid (requires int) !");
                windowHeight = 480;
                continue;
            }
        }
    }

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
        glfwTerminate();
        return 1;
    }
    RDEBUG("GLFW created window ok");

    glfwMakeContextCurrent(window);
    RDEBUG("GLFW context is now current");

    while (!glfwWindowShouldClose(window)) {
        // Render (eventually)

        // Swap buffers
        glfwSwapBuffers(window);

        // Polling for events
        glfwPollEvents();
    }

    glfwTerminate();
    RDEBUG("Closing app.");

    return 0;
}