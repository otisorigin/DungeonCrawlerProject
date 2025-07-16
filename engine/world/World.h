// /*
//  * Copyright © 2025 Fiodar Rymarovich
//  * All rights reserved.
//  *

#pragma once

#include <raylib.h>
#include <vector>

#define MAX_COLUMNS 20

class World {

public:

    void GenerateWorld();

    const std::vector<float>& GetHeights() const { return heights; }
    const std::vector<Vector3>& GetPositions() const { return positions; }
    const std::vector<Color>& GetColors() const { return colors; }

private:
    //WORLD
    std::vector<float> heights;
    std::vector<Vector3> positions;
    std::vector<Color> colors;
    //WORLD
};
