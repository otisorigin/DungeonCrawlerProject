cmake_minimum_required(VERSION 3.15)
project(dungeonCrawler)

find_package(raylib REQUIRED)
add_executable(dungeonCrawler src/main.cpp src/DungeonCrawlerProject.cpp src/DungeonCrawlerProject.h)
target_link_libraries(dungeonCrawler PRIVATE engine raylib)
target_include_directories(dungeonCrawler PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)