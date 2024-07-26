#include "./config-manager.h"
#include "../assets/assets.h"
#include <assert.h>
#include <stdio.h>

void* loadConfig(char* path,void* (*treatmentFunction)(yaml_parser_t*,char*)){
    assert(path != NULL && "Le chemin fourni pour le document à charger est NULL");

    // chargement du fichier
    FILE* configFile = fopen(path,"r");

    if(configFile == NULL){
        fputs("Echec de lecture d'ouverture du fichier de configuration\n",stderr);
        return NULL;
    }

    // chargement du document
    yaml_parser_t parser;

    if(!yaml_parser_initialize(&parser)){
        fputs("Echec d'initialisation du parser yaml\n",stderr);
        fclose(configFile);
        return NULL;
    }

    yaml_parser_set_input_file(&parser,configFile);

    // parsing
    char dirPath[SUPPOSED_PATH_MAX_LEN];
    extractDirPathFrom(path,dirPath,sizeof(char) * SUPPOSED_PATH_MAX_LEN);

    void* treatmentResult = treatmentFunction(&parser,dirPath);

    // libération des ressources
    yaml_parser_delete(&parser);
    fclose(configFile);

    return treatmentResult;
}
