/*
* Copyright © 2025 Fiodar Rymarovich
 * All rights reserved.
 */

#include "DungeonCrawlerProject.h"
#include "game/Game.h"

DungeonCrawlerProject::DungeonCrawlerProject() = default;

void DungeonCrawlerProject::Run() {
    Game game;
    game.SetContentRoot("../dungeonCrawler/content/");
    game.InitGameWithProperties("../dungeonCrawler/config/config.json");

    //TODO not call game loop manually?
    game.RunGameLoop();
}
