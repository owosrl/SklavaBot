cmake_minimum_required (VERSION 3.8)

project(SklavaBot CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/out)
set(Boost_USE_MULTITHREADED ON)


find_package(PkgConfig REQUIRED)

pkg_check_modules(TESSERACT REQUIRED tesseract)
pkg_check_modules(LEPTONICA REQUIRED lept)
pkg_check_modules(JSONCPP jsoncpp)

find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
find_package(CURL)
link_directories(${TESSERACT_LIBRARY_DIRS} ${LEPTONICA_LIBRARY_DIRS} ${JSONCPP_LIBRARY_DIRS})
include_directories(
    /usr/local/include 
    ${OPENSSL_INCLUDE_DIR} 
    ${Boost_INCLUDE_DIR} 
    ${TESSERACT_INCLUDE_DIRS} 
    ${LEPTONICA_INCLUDE_DIRS} 
    ${JSONCPP_INCLUDE_DIRS}
)
if (CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIRS})
    add_definitions(-DHAVE_CURL)
endif()
set(TGBOT_LIBRARIES /usr/local/lib/libTgBot.a)

add_subdirectory(lib)

add_executable(sklavabot main.cpp)
target_link_libraries(
    sklavabot 
    Utils 
    ${CMAKE_THREAD_LIBS_INIT} 
    ${OPENSSL_LIBRARIES} 
    ${Boost_LIBRARIES} 
    ${CURL_LIBRARIES} 
    ${TGBOT_LIBRARIES} 
    ${TESSERACT_LIBRARIES} 
    ${LEPTONICA_LIBRARIES}
    ${JSONCPP_LIBRARIES}
)
