#!/usr/bin/env bash

set -e pipefail

if [ ! -d "$PWD/external/glfw" ]; then
    mkdir -pv $PWD/external
    pushd $PWD/external
    git clone http://github.com/glfw/glfw.git --branch 3.5.1
    pushd glfw
    cmake -S . -B build -G "Unix Makefiles" \
        -DBUILD_SHARED_LIBS=OFF \
        -DGLFW_BUILD_EXAMPLES=OFF \
        -DGLFW_BUILD_TESTS=OFF \
        -DGLFW_BUILD_DOCS=OFF \
        -DGLFW_BUILD_WAYLAND=OFF \
        -DGLFW_BUILD_X11=ON
    cmake --build build --config Release
    popd
    popd
fi

exit 0