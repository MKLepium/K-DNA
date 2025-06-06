cmake_minimum_required(VERSION 3.25.1)
project(K-DNA)

set(CMAKE_CXX_STANDARD 20)

find_library(LIBMATA mata REQUIRED)

add_executable(K-DNA main.cpp
        definitions.h)

set_target_properties(K-DNA PROPERTIES OUTPUT_NAME "K-DNA.out")

target_link_libraries(K-DNA PUBLIC ${LIBMATA})
