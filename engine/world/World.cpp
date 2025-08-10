// /*
//  * Copyright © 2025 Fiodar Rymarovich
//  * All rights reserved.
//  *

#include "World.h"

#include <fstream>
#include <iostream>
#include <string>

#include "TileLevel.h"

void World::PrepareWorldData(const std::string& LevelPath) {
    std::ifstream file(LevelPath);
    json j;
    file >> j;

    const TileLevel level = TileLevel::fromJson(j);

    std::cout << "Tile layers: " << level.tileLayers.size() << "\n";
    std::cout << "Entity layers: " << level.entityLayers.size() << "\n";
}

void World::GenerateWorld() {
    // WORLD generation
    heights.resize(MAX_COLUMNS);
    positions.resize(MAX_COLUMNS);
    colors.resize(MAX_COLUMNS);

    for (int i = 0; i < MAX_COLUMNS; ++i) {
        const auto height = static_cast<float>(GetRandomValue(1, 12));
        heights[i] = height;

        const auto x = static_cast<float>(GetRandomValue(-15, 15));
        const auto y = height / 2.0f;
        const auto z = static_cast<float>(GetRandomValue(-15, 15));
        positions[i] = Vector3{ x, y, z };

        const auto r = static_cast<unsigned char>(GetRandomValue(20, 255));
        const auto g = static_cast<unsigned char>(GetRandomValue(20, 255));
        const auto b = static_cast<unsigned char>(GetRandomValue(20, 255));
        colors[i] = Color{ r, g, b, 255 };
    }
    // WORLD generation
}
