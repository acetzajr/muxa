
cmake_minimum_required(VERSION 3.28)
project(muxa)
file(GLOB_RECURSE MUxA_SRC "Source/*.cpp")
add_executable(muxa ${MUxA_SRC})
target_compile_options(muxa PRIVATE -Wall -Wextra -Wpedantic)
target_include_directories(muxa PRIVATE "Include")
set_property(TARGET muxa PROPERTY CXX_STANDARD 26)
