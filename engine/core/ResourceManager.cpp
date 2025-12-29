// /*
//  * Copyright © 2025 Fiodar Rymarovich
//  * All rights reserved.
//  *

#include "ResourceManager.h"

void ResourceManager::LoadAtlas(const std::string &path) {
    // TODO: через Assimp загрузить GLB/FBX → конвертнуть в raylib Mesh + Material
    // meshes["crate"] = {mesh, material};
    // meshes["door"]  = {mesh, material};
}

MeshResource * ResourceManager::GetMesh(const std::string &name) {
    auto it = meshes.find(name);
    if (it != meshes.end()) return &it->second;
    return nullptr;
}
