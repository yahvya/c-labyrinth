#include "./game.h"
#include "../assets-manager/config-manager/config-manager.h"
#include <stddef.h>
#include "raylib.h"

/**
 * @brief Chargement d'image ou libération des ressources du jeux
 */
#define LOAD_OR_QUIT(loadFunction,gameConfig)if(!loadFunction(gameConfig)){\
    freeGameConfig(gameConfig,true);\
    return false;\
}

// ressources du jeu
static GameConfig* gameConfig = NULL;

bool initializeGame(){
    InitWindow(0,0,"Initialize raylib");

    if(!IsWindowReady())
        return false;

    gameConfig = loadGameConfig();

    if(gameConfig == NULL)
        return false;

    LOAD_OR_QUIT(loadItemsImages,gameConfig)
    LOAD_OR_QUIT(loadTillsImages,gameConfig)
    LOAD_OR_QUIT(loadEnemiesImages,gameConfig)
    LOAD_OR_QUIT(loadHeroesImages,gameConfig)

    SetWindowTitle("Labyrinth");
    SetWindowSize(WINDOW_DEFAULT_WIDTH,WINDOW_DEFAULT_HEIGHT);
    SetWindowFocused();
    centerWindow();

    return true;
}

void startGame(){
    while(!WindowShouldClose()){
        BeginDrawing();

            ClearBackground(RAYWHITE);

        EndDrawing();
    }
}

void closeGame(){
    CloseWindow();
    freeGameConfig(gameConfig,true);
}