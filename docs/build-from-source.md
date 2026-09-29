# Building OpenRogue
<!-- When writing your own target article, be sure to include a "last updated" note. -->

Use the list below to jump to your target system. If it's not listed, document your process in here and open a PR! We're always looking for new ways to get this game onto all kinds of systems.

### Linux Targets
 - [Linux (x86_64)](#building-for-linux-x86_64)

### Windows Targets

### macOS Targets

### Other targets

---

# Building for Linux (x86_64)

> [!NOTE]
> Last updated: 29 September, 2026

0. Ensure you have the following packages installed and ready:
    - make
    - git
    - gcc/g++ OR clang/clang++
    - cmake
    - gdb/lldb
    - an ide like neovim or vscode
1. Ensure the `setup/setup.sh` file is executable with the `chmod` command:
    - `chmod +x setup/setup.sh`
2. Run the setup script _before_ you run the Makefile. Setup will check for any missing dependencies and setup the build environment.
3. Run `make` and the process begins! It should only take a few seconds for compiling and linking to occur.