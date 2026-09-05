# Makefile for C++ + CMake + vcpkg projects on Apple Silicon (M1/M2/M3)
# Usage:
#   make configure   -> run once per project (or after editing vcpkg.json)
#   make build       -> compile
#   make run         -> just run the already-built executable (no build check)
#   make crun        -> build (as a dependency) + run the executable
#   make clean       -> wipe build folder
#   make rebuild     -> clean + configure + build

# CHANGE THIS to match your executable name in CMakeLists.txt (add_executable(name ...))
APP_NAME := newapp

VCPKG_TOOLCHAIN := $(HOME)/vcpkg/scripts/buildsystems/vcpkg.cmake

.PHONY: configure build run crun clean rebuild

configure:
	cmake -B build -S . \
		-DCMAKE_TOOLCHAIN_FILE=$(VCPKG_TOOLCHAIN) \
		-DVCPKG_TARGET_TRIPLET=arm64-osx \
		-DCMAKE_OSX_ARCHITECTURES=arm64 \
		-DCMAKE_EXPORT_COMPILE_COMMANDS=ON

build:
	cmake --build build

run:
	./build/$(APP_NAME)

crun: build
	./build/$(APP_NAME)

clean:
	rm -rf build

rebuild: clean configure build