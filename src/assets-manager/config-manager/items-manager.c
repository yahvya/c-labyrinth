#include "./items-manager.h"

/**
 * @brief Macro de libération des ressources de parsing
 */
#define FREE_RESOURCES_AND_QUIT free(config->map);\
    free(config);\
    yaml_token_delete(&token);\
    return NULL;

void* loadItemsConfig(yaml_parser_t* parser, char* parentConfigPath){
    // allocation de base des données items et de map
    ItemsConfig* config = malloc(sizeof(ItemsConfig));

    if(config == NULL){
        fputs("Echec d'allocation de la configuration d'items",stderr);
        return NULL;
    }

    config->countOfItems = 0;
    config->map = malloc(sizeof(ImageConfig));

    if(config->map == NULL){
        free(config);
        fputs("Echec d'allocation le map de la configuration d'items",stderr);
        return NULL;
    }

    // parsing des items
    yaml_token_t token;

    while(true){
        if(!yaml_parser_scan(parser,&token)){
            fputs("Echec de lecture de token lors du parsing de configuration des items\n",stderr);
            FREE_RESOURCES_AND_QUIT
        }
    }

    return config;
}
