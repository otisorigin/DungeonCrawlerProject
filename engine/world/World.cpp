// /*
//  * Copyright © 2025 Fiodar Rymarovich
//  * All rights reserved.
//  *

#include "World.h"

void World::GenerateWorld() {
    // WORLD generation
    for (int i = 0; i < MAX_COLUMNS; i++)
    {
        //TODO fix
        heights[i] = (float)GetRandomValue(1, 12);
        positions[i] = (Vector3){ (float)GetRandomValue(-15, 15), heights[i]/2.0f, (float)GetRandomValue(-15, 15) };
        colors[i] = (Color){ static_cast<unsigned char>(GetRandomValue(20, 255)), static_cast<unsigned char>(GetRandomValue(10, 55)), 30, 255 };
    }
    // WORLD generation
}
