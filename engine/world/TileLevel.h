// /*
//  * Copyright © 8.08.25 Fiodar Rymarovich
//  * All rights reserved.
//  *

#pragma once
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

struct Layer {
    std::string name;
    int offsetX;
    int offsetY;
    int gridCellWidth;
    int gridCellHeight;
    int gridCellsX;
    int gridCellsY;
};

struct TileLayer : Layer {
    std::string tileSet;
    std::vector<int> data;
};

struct Entity {
    std::string name;
    int id;
    std::string _eid;
    int x;
    int y;
    int originX;
    int originY;
    float rotation;
};

struct EntityLayer : Layer {
    std::vector<Entity> entities;
};

class TileLevel {

public:
    std::vector<TileLayer> tileLayers;
    std::vector<EntityLayer> entityLayers;

    //TODO map between Entity and 3d model

    static TileLevel fromJson(const json& j);

private:
    friend void from_json(const json& j, Layer& l);
    friend void from_json(const json& j, TileLayer& t);
    friend void from_json(const json& j, Entity& e);
    friend void from_json(const json& j, EntityLayer& el);
    friend void from_json(const json& j, TileLevel& level);
};
