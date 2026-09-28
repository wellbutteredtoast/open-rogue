# OpenRogue Makefile
# (C) 2026 OpenRogue Project
# SPDX-License-Identifier: zlib

# -----------------------------------------------------------------------------
# Flags
# -----------------------------------------------------------------------------

BUILD		?= debug	# Debug   | Release
PEDANTIC 	?= 0		# 0 = Off | 1 = On
SANITIZE	?= 0		# 0 = Off | 1 = On

# -----------------------------------------------------------------------------
# Constants across the entire project
# -----------------------------------------------------------------------------

CXX_STANDARD 	?= -std=c++03
C_STANDARD		?= -std=c99

# -----------------------------------------------------------------------------
# Toolchain work
# -----------------------------------------------------------------------------

ifeq ($(origin CC),default)
	CC 		:= $(firstword $(shell command -v clang gcc cc 2>/dev/null))
endif
ifeq ($(origin CXX),default)
	CXX 	:= $(firstword $(shell command -v clang++ g++ c++ 2>/dev/null))
endif

CC_VERSION	:= $(shell $(CC) --version 2>/dev/null | head -n1)
CC_TARGET	:= $(shell $(CC) -dumpmachine)

ifneq (,$(findstring clang,$(CC_VERSION_FULL)))
  CC_FAMILY := clang
else ifneq (,$(findstring gcc,$(CC_VERSION_FULL)))
  CC_FAMILY := gcc
else
  CC_FAMILY := unknown
endif

# -----------------------------------------------------------------------------
# Host + Git info
# -----------------------------------------------------------------------------

HOST_OS   		:= $(shell uname -s)
HOST_ARCH 		:= $(shell uname -m)
BUILD_DATE     	:= $(shell date -u +%Y-%m-%dT%H:%M:%SZ)
LAST_COMMIT    	:= $(shell git rev-parse --short HEAD 2>/dev/null || echo unknown)
CURRENT_BRANCH 	:= $(shell git branch --show-current 2>/dev/null || echo unknown)

# Adding all our results to the shared flags
BUILDINFO_DEFS := \
	'-DBUILD_COMPILER="$(CC_FAMILY)"'         \
	'-DBUILD_COMPILER_VER="$(CC_VERSION)"'    \
	'-DBUILD_TARGET="$(CC_TARGET)"'           \
	'-DHOST_ARCH="$(HOST_ARCH)"'              \
	'-DHOST_OS="$(HOST_OS)"'                  \
	'-DGIT_COMMIT="$(LAST_COMMIT)"'           \
	'-DGIT_BRANCH="$(CURRENT_BRANCH)"'        \
	'-DBUILD_DATE="$(BUILD_DATE)"'

# -----------------------------------------------------------------------------
# Specialized warning flags, because cool and helpful
# -----------------------------------------------------------------------------

WARN_COMMON := \
	-Wall -Wextra -Wshadow -Wconversion -Wpointer-arith -Wunused-variable	   \
	-Wcast-qual -Wcast-align -Wformat=2 -Wundef -Wwrite-strings -Wfatal-errors \
	-Wimplicit-fallthrough -Wmissing-braces 

WARN_C 		:= \
	-Wstrict-prototypes -Wmissing-prototypes -Wold-style-definition

WARN_CXX 	:= \
	-Wold-style-cast -Woverloaded-virtual -Wnon-virtual-dtor

WERRORS		:= \
	-Werror=implicit-function-declaration -Werror=return-type \
	-Werror=null-dereference -Werror=return-mismatch

# -----------------------------------------------------------------------------
# Source collection + lib collection (this assumes libraries are pre-compiled)
# -----------------------------------------------------------------------------

# todo: this
