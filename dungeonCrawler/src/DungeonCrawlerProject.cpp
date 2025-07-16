/*
* Copyright © 2025 Fiodar Rymarovich
 * All rights reserved.
 */

#include "DungeonCrawlerProject.h"
#include "game/Game.h"

DungeonCrawlerProject::DungeonCrawlerProject() = default;

void DungeonCrawlerProject::Run() {
    Game game;
    game.RunGameLoop();
}
