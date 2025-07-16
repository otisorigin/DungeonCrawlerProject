cmake_minimum_required(VERSION 3.15)
project(engine)
add_library(engine
        core/core.cpp
        core/Core.h
        game/game.cpp
        game/Game.h
        camera/camera.cpp
        camera/Camera.h
        render/Render.cpp render/Render.h
        input/Input.cpp input/Input.h
#        world/world.cpp world/World.h
)
find_package(raylib REQUIRED)
target_link_libraries(engine PUBLIC raylib)
target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}) 