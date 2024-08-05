#include "./levels-manager.h"
#include <stddef.h>
#include <assert.h>

bool loadLevel(GameConfig* gameConfig,LevelConfig* levelConfig){
    return false;
}

void unloadLevel(GameConfig* gameConfig,LevelConfig* levelConfig){

}

GenericList* loadLevelsConfig(char* levelsDirPath){
    /**
     * @brief Format attendu des éléments
     * dossier-de-niveau/
     *  - level.yaml fichier de configuration du niveau
     *  - map.yaml configuration de la map du niveau
     */

    // lecture des éléments du dossier


    /**
     * @brief récupération partielle des données globales utiles à la présentation du niveau
     * nom
     * ordre du niveau
     */

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