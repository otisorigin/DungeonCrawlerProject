// /*
//  * Copyright © 2025 Fiodar Rymarovich
//  * All rights reserved.
//  *

#pragma once

#include <memory>
#include <raylib.h>
#include <string>

#include "world/World.h"

class Game {
public:
    Game();
    ~Game();

    void RunGameLoop();
    void SetContentRoot(const std::string& root) { contentRoot = root; }
    void InitGameWithProperties(const std::string& PropertiesPath);

protected:

    void InitGame();
    void Shutdown();
    void InitCamera();
    void LoadLevel(const std::string& relativePath);

private:

    Camera camera {};
    CameraMode cameraMode;
    std::unique_ptr<World> currentWorld;

    std::string contentRoot;

    int screenWidth;
    int screenHeight;
};