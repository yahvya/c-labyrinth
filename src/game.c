#include "./assets-manager/config-manager/config-manager.h"
#include "raylib.h"

int main(int argc,char ** argv){
    GameConfig* gameConfig = loadGameConfig();

    loadItemsImages(gameConfig);
    loadTillsImages(gameConfig);
    loadEnemiesImages(gameConfig);
    loadHeroesImages(gameConfig);

    freeGameConfig(gameConfig,true);

    return 0;
}
