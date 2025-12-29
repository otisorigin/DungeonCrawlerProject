// /*
//  * Copyright © 2025 Fiodar Rymarovich
//  * All rights reserved.
//  *

#include "World.h"

#include <fstream>
#include <iostream>
#include <string>
#include <spdlog/spdlog.h>
#include "raylib.h"
#include "TileLevel.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

void World::LoadLevel(const std::string& LevelPath)
{
    std::ifstream file("../" + LevelPath);

    if (!file.is_open()) {
        throw std::runtime_error("Can't open level: " + LevelPath);
    }

    json j;
    file >> j;

    //TODO make abstract by Level?
    const TileLevel level = TileLevel::fromJson(j);

    SPDLOG_INFO("Entity layers: {}", level.entityLayers.size());

    std::unordered_set<std::string> meshesToLoad;

    for (const auto& layer : level.entityLayers) {
        for (const auto& entity : layer.second.entities) {
            meshesToLoad.insert(entity.meshName);
        }
    }

    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(
        "../../dungeonCrawler/content/objects/modular_dungeon_kit.glb",
        aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenNormals
    );

    std::vector<std::pair<std::string, Mesh>> result;

    if (!scene || !scene->mRootNode)
    {
        std::cerr << "Error loading model: " << importer.GetErrorString() << std::endl;
        return;
    }

    for (unsigned int i = 0; i < scene->mNumMeshes; i++)
    {
        aiMesh* mesh = scene->mMeshes[i];
        SPDLOG_INFO("Mesh name: {}", mesh->mName.C_Str());

        if (meshesToLoad.contains(mesh->mName.C_Str())) {

        }
    }

    //TODO choose concrete meshes and convert them to RayLib format

    //Model model = LoadModel("../../dungeonCrawler/content/objects/modular_dungeon_kit.glb");

    // for (auto& [name, entityLayer] : level.entityLayers) {
    //     for (const auto& entity : entityLayer.entities) {
    //         auto pos = entity.mesh.find(':');              // ищем позицию ':'
    //         if (pos != std::string::npos) {
    //             std::string meshPath = entity.mesh.substr(pos + 1);  // берём всё после ':'
    //             std::string absolutePath = "../../" + meshPath;
    //
    //             //TODO check if movel loaded previously then not load -> add models pool
    //             if (std::filesystem::exists(absolutePath)) {
    //                 Model model = LoadModel(absolutePath.c_str());
    //                 // if (model.materialCount == 0 || model.materials == nullptr) {
    //                 //     model.materialCount = 1;
    //                 //     model.materials = new Material[1];
    //                 //     model.materials[0] = LoadMaterialDefault();
    //                 //     model.materials[0].maps[MATERIAL_MAP_ALBEDO].color = RED;  // красная заглушка
    //                 // }
    //                 SPDLOG_INFO("Load model: {}", absolutePath);
    //
    //                 for (int i = 0; i < model.meshCount; i++) {
    //                     const Mesh& mesh = model.meshes[i];
    //
    //                     mesh.
    //                     SPDLOG_INFO("Load model: {}", absolutePath);
    //                 }
    //             }
    //             else {
    //                 SPDLOG_WARN("Can't load model: {}", absolutePath);
    //             }
    //         }
    //     }
    // }
}
//
// // Функция: конвертировать aiMesh → raylib::Mesh
// Mesh ConvertAssimpMesh(const aiMesh* mesh) {
//     Mesh rlMesh = {0};
//
//     rlMesh.vertexCount = mesh->mNumVertices;
//     rlMesh.triangleCount = mesh->mNumFaces;
//
//     rlMesh.vertices = (float*)MemAlloc(rlMesh.vertexCount * 3 * sizeof(float));
//     rlMesh.texcoords = (float*)MemAlloc(rlMesh.vertexCount * 2 * sizeof(float));
//     rlMesh.normals   = (float*)MemAlloc(rlMesh.vertexCount * 3 * sizeof(float));
//
//     // Копируем вершины
//     for (unsigned int v = 0; v < mesh->mNumVertices; v++) {
//         rlMesh.vertices[v*3+0] = mesh->mVertices[v].x;
//         rlMesh.vertices[v*3+1] = mesh->mVertices[v].y;
//         rlMesh.vertices[v*3+2] = mesh->mVertices[v].z;
//
//         if (mesh->HasNormals()) {
//             rlMesh.normals[v*3+0] = mesh->mNormals[v].x;
//             rlMesh.normals[v*3+1] = mesh->mNormals[v].y;
//             rlMesh.normals[v*3+2] = mesh->mNormals[v].z;
//         }
//
//         if (mesh->HasTextureCoords(0)) {
//             rlMesh.texcoords[v*2+0] = mesh->mTextureCoords[0][v].x;
//             rlMesh.texcoords[v*2+1] = mesh->mTextureCoords[0][v].y;
//         }
//     }
//
//     // Индексы
//     int indexCount = mesh->mNumFaces * 3;
//     rlMesh.indices = (unsigned short*)MemAlloc(indexCount * sizeof(unsigned short));
//
//     int iIndex = 0;
//     for (unsigned int f = 0; f < mesh->mNumFaces; f++) {
//         aiFace face = mesh->mFaces[f];
//         for (unsigned int j = 0; j < face.mNumIndices; j++) {
//             rlMesh.indices[iIndex++] = face.mIndices[j];
//         }
//     }
//
//     UploadMesh(&rlMesh, false);
//     return rlMesh;
// }
//
// // Загружаем все меши из файла и выводим их имена
// std::vector<std::pair<std::string, Mesh>> LoadMeshesWithNames(const std::string& path) {
//     Assimp::Importer importer;
//     const aiScene* scene = importer.ReadFile(
//         path,
//         aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenNormals
//     );
//
//     std::vector<std::pair<std::string, Mesh>> result;
//
//     if (!scene || !scene->mRootNode) {
//         std::cerr << "Error loading model: " << importer.GetErrorString() << std::endl;
//         return result;
//     }
//
//     for (unsigned int i = 0; i < scene->mNumMeshes; i++) {
//         aiMesh* mesh = scene->mMeshes[i];
//         std::string name = mesh->mName.C_Str();  // имя меша из файла
//         Mesh rlMesh = ConvertAssimpMesh(mesh);
//         result.push_back({name, rlMesh});
//     }
//
//     return result;
// }

void World::GenerateWorld()
{
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
