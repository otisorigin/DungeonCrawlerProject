// /*
//  * Copyright © 2025 Fiodar Rymarovich
//  * All rights reserved.
//  *

#pragma once
#include <unordered_map>


class MeshResource;

class ResourceManager {

public:
    std::unordered_map<std::string, MeshResource> meshes;

    void LoadAtlas(const std::string& path);

    MeshResource* GetMesh(const std::string& name);
};
