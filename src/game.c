#include "./assets-manager/config-manager/config-manager.h"
#include "raylib.h"

int main(int argc,char ** argv){
    GameConfig* gameConfig = loadGameConfig();

    loadItemsImages(gameConfig);

    freeGameConfig(gameConfig,true);

    return 0;
}
