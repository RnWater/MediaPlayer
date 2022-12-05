cmake_minimum_required(VERSION 3.18.1)
project("player")
include_directories(include)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/../../../libs/${ANDROID_ABI}")
add_library(
        player
        SHARED
        player.cpp
        PLogger.cpp
)
find_library(
        log-lib
        log)
target_link_libraries(
        player
        android
        yuv
        ffmpeg
        ${log-lib})