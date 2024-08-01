#include "./home-rendering.h"
#include "../game/game.h"
#include "./rendering.h"

bool renderGameHome(RenderingConfig* renderingConfig){
    GameRenderingConfig* gameRenderingConfig = (GameRenderingConfig*) renderingConfig->data;
    GameConfig* gameConfig = gameRenderingConfig->gameConfig;

    if(!renderMap(gameConfig,gameConfig->homeMapConfig))
        return false;

    if(IsKeyDown(KEY_SPACE))
        PlaySound(gameConfig->soundsConfig->map[0].sound);

    return true;
}