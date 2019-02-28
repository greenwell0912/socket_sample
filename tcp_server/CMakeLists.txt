cmake_minimum_required (VERSION 2.6)
project (tcp_server)
include_directories("${PROJECT_SOURCE_DIR}")
add_executable(tcp_server server.c)
#target_link_libraries(tcp_server socket)

# gcc -Wall オプションを指定する
set(CMAKE_C_FLAGS "-Wall -O3")
