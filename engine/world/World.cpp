// /*
//  * Copyright © 2025 Fiodar Rymarovich
//  * All rights reserved.
//  *

#include "World.h"

#include <fstream>
#include <iostream>
#include <string>
#include <spdlog/spdlog.h>

#include "TileLevel.h"

void World::PrepareWorldData(const std::string& LevelPath) {
    std::ifstream file("../" + LevelPath);

    if (!file.is_open()) {
        throw std::runtime_error("Can't open level: " + LevelPath);
    }

    json j;
    file >> j;

    const TileLevel level = TileLevel::fromJson(j);

    spdlog::info("Entity layers: " + level.entityLayers.size());
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
