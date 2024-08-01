#include "./game/game.h"
#include <stdio.h>

void testGameConfig(){
    GameConfig* config = loadGameConfig();

    if(config != NULL){
        printMapConfig(config->homeMapConfig);
        freeGameConfig(config,true);
    }
}

int main(int argc,char ** argv){
    testGameConfig();

//    if(initializeGame()){
//        startGame();
//        closeGame();
//
//        return 0;
//    }

    fputs("\nEchec de lancement du jeux",stderr);

    return 1;
}
