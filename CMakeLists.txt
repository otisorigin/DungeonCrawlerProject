cmake_minimum_required(VERSION 3.15)
project(dungeon_crawler)
set(CMAKE_CXX_STANDARD 20)

find_package(raylib REQUIRED)

add_executable(dungeon_crawler main.cpp src/DungeonCrawlerProject.cpp src/DungeonCrawlerProject.h)
target_link_libraries(dungeon_crawler PRIVATE raylib)
target_include_directories(dungeon_crawler PRIVATE src)