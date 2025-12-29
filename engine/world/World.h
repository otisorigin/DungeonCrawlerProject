// /*
//  * Copyright © 2025 Fiodar Rymarovich
//  * All rights reserved.
//  *

#pragma once

#include <raylib.h>
#include <vector>

#define MAX_COLUMNS 20

/* Generates and store data about game levels */
class World {

public:

    void LoadLevel(const std::string& LevelPath);
    void GenerateWorld();

    /* Legacy sample */
    const std::vector<float>& GetHeights() const { return heights; }
    const std::vector<Vector3>& GetPositions() const { return positions; }
    const std::vector<Color>& GetColors() const { return colors; }
    /* Legacy sample */

private:
    /* Legacy sample */
    //WORLD
    std::vector<float> heights;
    std::vector<Vector3> positions;
    std::vector<Color> colors;
    //WORLD
    /* Legacy sample */
};
