# set base project settings
cmake_minimum_required(VERSION 3.22)
project(cpp-template LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include testing dependencies
include(CTest)
find_package(GTest REQUIRED)
find_package(spdlog REQUIRED)
include(GoogleTest)

# create subdirectories
add_subdirectory(src)
add_subdirectory(inc)
add_subdirectory(tests)