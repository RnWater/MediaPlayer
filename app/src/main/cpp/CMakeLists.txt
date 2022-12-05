cmake_minimum_required(VERSION 3.18.1)
project("mediaplayer")
add_library(
        mediaplayer
        SHARED
        native-lib.cpp)
find_library(
        log-lib
        log)
target_link_libraries(
        mediaplayer
        ${log-lib})