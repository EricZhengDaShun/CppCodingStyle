cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_CXX_EXTENSIONS OFF)

project(CppCodingStyle LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME} )

target_sources(
    ${PROJECT_NAME}
        PRIVATE
            main.cpp
)
