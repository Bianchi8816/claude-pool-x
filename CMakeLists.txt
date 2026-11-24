cmake_minimum_required(VERSION 3.16)
project(claude-pool-x CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(claudepoolx
    src/main.cpp
    src/sessions.cpp
    src/rotate.cpp
    src/proxy.cpp
    src/cli.cpp
)

target_include_directories(claudepoolx PRIVATE include)

if(WIN32)
    target_link_libraries(claudepoolx PRIVATE userenv)
endif()
