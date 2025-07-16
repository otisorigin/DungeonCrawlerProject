// /*
//  * Copyright © 2025 Fiodar Rymarovich
//  * All rights reserved.
//  *

#pragma once

#include <raylib.h>

#define MAX_COLUMNS 20

class World {

    World();
    ~World();

public:

    static World* GetInstance();

    //WORLD
    float heights[MAX_COLUMNS] = { 0 };
    Vector3 positions[MAX_COLUMNS] = { 0 };
    Color colors[MAX_COLUMNS] = { 0 };
    //WORLD
};