#include "./game.h"
#include "../rendering/home-rendering.h"
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
    SetConfigFlags(FLAG_WINDOW_HIDDEN | FLAG_WINDOW_UNDECORATED);
    InitWindow(0,0,"Initialize raylib");
    InitAudioDevice();

    SetTargetFPS(60);
    SetTraceLogLevel(LOG_ERROR);

    bool isWindowReady = IsWindowReady();
    bool isAudioDeviceReady = IsAudioDeviceReady();

    if(!isWindowReady || !isAudioDeviceReady){
        if(isWindowReady)
            CloseWindow();

        if(isAudioDeviceReady)
            CloseAudioDevice();

        return false;
    }

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
    ClearWindowState(FLAG_WINDOW_HIDDEN);

    GameRenderingConfig gameRenderingConfig = {
        .gameConfig = gameConfig,
        .currentRenderingFunction = renderGameHome,
        .supplementaryConfig = NULL,
        .supplementaryDataHaveToBeFree = false
    };

    RenderingConfig renderingConfig = {
        .data = &gameRenderingConfig
    };

    // rendu du jeu
    while(!WindowShouldClose()){
        if(!renderWindow(&renderingConfig,gameRenderingConfig.currentRenderingFunction)){
            fputs("\nEchec de rendu de fenêtre",stderr);
            break;
        }
    }

    if(gameRenderingConfig.supplementaryDataHaveToBeFree && gameRenderingConfig.supplementaryConfig != NULL)
        free(gameRenderingConfig.supplementaryConfig);
}

void closeGame(){
    CloseWindow();
    CloseAudioDevice();
    freeGameConfig(gameConfig,true);
}