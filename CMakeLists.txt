
cmake_minimum_required(VERSION 3.10)
project(velaris VERSION 0.1.0 LANGUAGES CXX)

# Use C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Header files
include_directories(include)

# Create executable
add_executable(velaris src/main.cpp)