cmake_minimum_required (VERSION 3.8)

project(SklaviaBot CXX)
set(CMAKE_CXX_STANDARD 20)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_library(Utils STATIC ${SOURCES})
target_include_directories(Utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
