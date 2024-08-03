#include "./levels-manager.h"
#include <stddef.h>
#include <assert.h>

bool loadLevel(GameConfig* gameConfig,LevelConfig* levelConfig){
    return false;
}

void unloadLevel(GameConfig* gameConfig,LevelConfig* levelConfig){

}

GenericList* loadLevelsConfig(char* levelsDirPath){
    return NULL;
}

void freeLevelsConfig(GenericList* levels,bool freeContainer){
    assert(levels != NULL && "La liste de niveau fourni à la libération est NULL");

    freeGenericList(levels,true);

    if(freeContainer)
        free(levels);
}

void printLevelsConfig(GenericList* levels){

}