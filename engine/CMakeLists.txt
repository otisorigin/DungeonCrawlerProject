cmake_minimum_required(VERSION 3.15)
project(engine)
add_library(engine
        game/game.cpp
        game/Game.h
        camera/camera.cpp
        camera/Camera.h
        render/Render.cpp render/Render.h
        input/Input.cpp input/Input.h
        world/World.cpp
        world/World.h
        world/LevelData.cpp
        world/LevelData.h
        world/Level.cpp
        world/Level.h
        core/MeshResource.h
        core/ResourceManager.cpp
        core/ResourceManager.h
)
find_package(raylib REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(spdlog REQUIRED)
find_package(assimp REQUIRED)

target_link_libraries(engine PUBLIC raylib nlohmann_json::nlohmann_json spdlog::spdlog assimp::assimp)
target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})