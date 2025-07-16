// /*
//  * Copyright © 2025 Fiodar Rymarovich
//  * All rights reserved.
//  *

#pragma once

#include <memory>
#include <raylib.h>
#include "world/World.h"

class Game {
public:
    Game();
    ~Game();

    void RunGameLoop();

protected:

    void InitGame();
    void Shutdown();


    void InitCamera();

private:

    Camera camera {};
    CameraMode cameraMode;

    std::unique_ptr<World> currentWorld;
};