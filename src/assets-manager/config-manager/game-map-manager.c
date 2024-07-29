#include "./game-map-manager.h"
#include "custom-color.h"
#include <assert.h>

void* loadGameMapConfig(yaml_parser_t* parser,char* parentDirPath){
    // allocation de la map
    GameMapConfig* config = malloc(sizeof(GameMapConfig));

    if(config == NULL){
        fputs("\nEchec d'allocation de la map de jeux",stderr);
        return NULL;
    }


    // pre allocation de la map de jeux
    config->scale = 10;
    config->tillsMapConfig.countOfRows= 100;
    config->tillsMapConfig.countOfCols= 80;

    return config;
}

void freeGameMapConfig(GameMapConfig* mapConfig,bool freeContainer){
    assert(mapConfig != NULL && "La map de jeux à libérer est NULL");

    if(mapConfig->tillsMapConfig.tillsMap != NULL)
        free(mapConfig->tillsMapConfig.tillsMap);

    if(freeContainer)
        free(mapConfig);
}

void printMapConfig(GameMapConfig* config){
    assert(config != NULL && "La map de jeux à libérer est NULL");

    printf(CC_BLUE"\n------------------------------------------------------------------------\n");
    printf(CC_BBLUE"\nConfiguration de map\n"CC_RESET);
    printf(CC_BG_BLUE"\nEchelle d'affichage : %d\n",config->scale);
    printf(CC_BLUE"------------------------------------------------------------------------\n"CC_RESET);

//    map des items
    printf(CC_BBLUE"Configuration des tills\n"CC_RESET);
    printf(CC_BG_BLUE"\nLignes x Colonnes : %d x %d\n",
       config->tillsMapConfig.countOfRows,
       config->tillsMapConfig.countOfCols
   );
}