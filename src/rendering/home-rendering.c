#include "./home-rendering.h"
#include "../game/game.h"
#include "./rendering.h"
#include "../components/text/text-component.h"
#include "./level-list-rendering.h"

bool renderGameHome(RenderingConfig* renderingConfig){
    // récupération des configurations

    GameRenderingConfig* gameRenderingConfig = (GameRenderingConfig*) renderingConfig->data;
    GameConfig* gameConfig = gameRenderingConfig->gameConfig;

    if(!IsSoundPlaying(gameConfig->homePageSound))
        PlaySound(gameConfig->homePageSound);

    if(!renderMap(gameConfig,gameConfig->homeMapConfig))
        return false;

    // texte d'affichage

    drawAndCenterTextIn(
        (Rectangle){.x = 0,.y = 0,.width = gameConfig->homeMapConfig->windowWidth,.height = gameConfig->homeMapConfig->windowHeight},
        "C labyrinth",
        WHITE,
        58,
        3,
        gameConfig->specialFont
    );

    drawAndCenterTextWithGapIn(
        (Rectangle){.x = 0,.y = 0,.width = gameConfig->homeMapConfig->windowWidth,.height = gameConfig->homeMapConfig->windowHeight},
        "Appuyez sur \"entrer\"",
        WHITE,
        23,
        3,
        gameConfig->specialFont,
        0,
        90
    );

    if(IsKeyDown(KEY_ENTER)){
        gameRenderingConfig->currentRenderingFunction = renderLevelsList;
        gameRenderingConfig->supplementaryConfig = NULL;
    }

    return true;
}