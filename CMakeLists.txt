cmake_minimum_required(VERSION 3.28)
project(utpjnicpart)

set(CMAKE_CXX_STANDARD 20)

set(JAVA_HOME "C:\\Program Files\\Java\\jdk-21")

include_directories(${JAVA_HOME}/include)
include_directories(${JAVA_HOME}/include/win32)

add_library(utpjnicpart SHARED library.cpp)
