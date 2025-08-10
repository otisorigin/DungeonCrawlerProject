// /*
//  * Copyright © 8.08.25. Fiodar Rymarovich
//  * All rights reserved.
//  *

#include "TileLevel.h"

void from_json(const json& j, Layer& l) {
    j.at("name").get_to(l.name);
    j.at("offsetX").get_to(l.offsetX);
    j.at("offsetY").get_to(l.offsetY);
    j.at("gridCellWidth").get_to(l.gridCellWidth);
    j.at("gridCellHeight").get_to(l.gridCellHeight);
    j.at("gridCellsX").get_to(l.gridCellsX);
    j.at("gridCellsY").get_to(l.gridCellsY);
}

void from_json(const json& j, TileLayer& t) {
    from_json(j, static_cast<Layer&>(t));
    j.at("tileset").get_to(t.tileSet);
    j.at("data").get_to(t.data);
}

void from_json(const json& j, Entity& e) {
    j.at("name").get_to(e.name);
    j.at("id").get_to(e.id);
    j.at("_eid").get_to(e._eid);
    j.at("x").get_to(e.x);
    j.at("y").get_to(e.y);
    j.at("originX").get_to(e.originX);
    j.at("originY").get_to(e.originY);
    if (j.contains("rotation")) j.at("rotation").get_to(e.rotation);
}

void from_json(const json& j, EntityLayer& el) {
    from_json(j, static_cast<Layer&>(el));
    j.at("entities").get_to(el.entities);
}

void from_json(const json& j, TileLevel& level) {
    for (auto& layer : j.at("layers")) {
        if (layer.contains("data")) {
            level.tileLayers.push_back(layer.get<TileLayer>());
        } else if (layer.contains("entities")) {
            level.entityLayers.push_back(layer.get<EntityLayer>());
        }
    }
}

TileLevel TileLevel::fromJson(const json& j) {
    return j.get<TileLevel>();
}