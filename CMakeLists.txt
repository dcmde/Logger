cmake_minimum_required(VERSION 3.5)
project(logger)

include_directories(include)

set(SOURCES
        src/main.cpp)

add_executable(logger ${SOURCES})