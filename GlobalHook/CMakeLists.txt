cmake_minimum_required(VERSION 3.14)

project(GlobalHook LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)

message("QT_CONFIG = ${QT_CONFIG}")
message("Qt6_CONFIG = ${Qt6_CONFIG}")
message("Qt5_CONFIG = ${Qt5_CONFIG}")

find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

add_library(GlobalHook SHARED
  GlobalHook_global.h
  globalhook.cpp
  globalhook.h
)

target_link_libraries(GlobalHook PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(GlobalHook PRIVATE GLOBALHOOK_LIBRARY)
