cmake_minimum_required(VERSION 3.10)
project(GestionEstudiantes LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(gestion
    main.cpp
    Estudiante.cpp
)

target_include_directories(gestion PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if (MSVC)
    target_compile_options(gestion PRIVATE /W4 /permissive-)
else()
    target_compile_options(gestion PRIVATE -Wall -Wextra -Wpedantic -Wconversion)
endif()
