#include "./tills-manager.h"
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "custom-color.h"

/**
 * @brief Taille du buffer d'écart
 */
#define SPACE_BUFFER_SIZE 20

/**
 * @brief Ternaire de choix de l'affichage
 */
#define TO_PRINT toPrintBefore == NULL ? "" : toPrintBefore

/**
 * @brief Libère les ressources de la boucle de traitement avant de quitter
 */
#define FREE_RESOURCES_AND_QUIT free(config->map);\
    free(config);\
    yaml_token_delete(&readToken);\
    return NULL;

void* loadTillsConfig(yaml_parser_t* parser,char* parentConfigPath){
    assert(parser != NULL && "Le parser fourni pour la lecture de configuration des tills est NULL");
    assert(parentConfigPath != NULL && "Le chemin parent fourni pour la lecture de configuration des tills est NULL");

    // allocation de base de la configuration
    TillsConfig* config = malloc(sizeof(TillsConfig)); 

    if(config == NULL){
        fputs("Echec d'allocation de la configuration des tills\n",stderr);
        return NULL;
    }

    config->countOfTills = 0;

    // allocation de base de la map
    config->map = malloc(sizeof(ImageConfig));

    if(config->map == NULL){
        fputs("Echec d'allocation de la map des tills\n",stderr);
        free(config);
        return NULL;
    }

    // parsing du fichier
    yaml_token_t readToken;
    bool stop = false;
    bool nextIsKey = false;

    while(!stop){
        if(!yaml_parser_scan(parser,&readToken)){
            fputs("Echec de lecture de token lors du parsing de configuration de tills\n",stderr);
            FREE_RESOURCES_AND_QUIT
        }

        switch(readToken.type){
            case YAML_STREAM_END_TOKEN: 
                stop = true;
            ; break;

            case YAML_KEY_TOKEN:
                nextIsKey = true;
            break;

            case YAML_SCALAR_TOKEN:
                if(nextIsKey){
                    // aggrandissement de l'espace alloué
                    config->countOfTills++;

                    void* tmpAddress = realloc(config->map,sizeof(ImageConfig) * config->countOfTills);

                    if(tmpAddress == NULL){
                        fputs("Echec de reallocation d'adresse lors du parsing de configuration de tills\n",stderr);
                        FREE_RESOURCES_AND_QUIT;
                    }

                    // création de la configuration
                    config->map = tmpAddress;
                    ImageConfig createdImage = createImageFromConfig(parser,parentConfigPath);
                    
                    if(createdImage.errorState){
                        fputs("Echec de parsing de la configuration d'image lors du parsing de configuration de tills\n",stderr);
                        FREE_RESOURCES_AND_QUIT;
                    }

                    strncpy(createdImage.id,readToken.data.scalar.value,sizeof(char) * (SUPPOSED_ID_MAX_LEN - 1));
                    memcpy(config->map + (atoi(createdImage.id) - 1),&createdImage,sizeof(ImageConfig));

                    // attente de la clé suivante
                    nextIsKey = false;
                }
            ;
        }
    
        yaml_token_delete(&readToken);
    }

    return config;
}

void freeTillsConfig(TillsConfig* config,bool freeContainer){
    for(int i = 0; i < config->countOfTills; i++)
        freeImageConfig(&config->map[i],false);

    free(config->map);

    if(freeContainer)
        free(config);
}

void printTillsConfig(TillsConfig* config,char* toPrintBefore){
    printf(CC_BLUE"\n%s------------------------------------------------------------------------\n",TO_PRINT);
    printf(CC_BBLUE"\n%sConfiguration de tills\n"CC_RESET,TO_PRINT);
    printf(CC_BG_BLUE"\n%sNombre d'elements : %d\n",TO_PRINT,config->countOfTills);
    printf("\n%sListe des elements\n"CC_RESET,TO_PRINT);
    printf(CC_BLUE"%s------------------------------------------------------------------------\n"CC_RESET,TO_PRINT);

    char spaceBuffer[SPACE_BUFFER_SIZE];
    memset(spaceBuffer,0,sizeof(char) * SPACE_BUFFER_SIZE);

    if(toPrintBefore != NULL)
        strcpy(spaceBuffer,toPrintBefore);
    
    strncat(
        spaceBuffer,
        "\t",
        sizeof(char) * (SPACE_BUFFER_SIZE - (toPrintBefore != NULL ? strlen(toPrintBefore) : 0))
    );

    for(int i = 0; i < config->countOfTills; i++){
        printImageConfig(&config->map[i],toPrintBefore);
        printf("\n");
    }
}
