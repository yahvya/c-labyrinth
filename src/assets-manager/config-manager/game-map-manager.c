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

    printf("\n"CC_BLUE"------------------------------------------------------------------------"CC_RESET"\n");
    printf("\n"CC_BBLUE"Configuration de map"CC_RESET"\n");
    printf("\n"CC_BG_BLUE"Echelle d'affichage : %d"CC_RESET"\n",config->scale);
    printf(CC_BLUE"------------------------------------------------------------------------"CC_RESET"\n");

//    map des items
    printf(CC_BBLUE"Configuration des tills"CC_RESET"\n");
    printf("\n"CC_BG_BLUE"Lignes x Colonnes : %d x %d"CC_RESET"\n",
       config->tillsMapConfig.countOfRows,
       config->tillsMapConfig.countOfCols
   );
}