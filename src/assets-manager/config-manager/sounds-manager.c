#include "./sounds-manager.h"
#include <assert.h>
#include "custom-color.h"

/**
 * @brief Ternaire de choix de l'affichage
 */
#define TO_PRINT toPrintBefore == NULL ? "" : toPrintBefore

/**
 * @brief Libère les ressources de parsing et quitte
 */
#define FREE_RESOURCES_AND_QUIT freeSoundsConfig(soundsConfig,true); \
    yaml_token_delete(&token);\
    return NULL;

void* loadSoundsConfig(yaml_parser_t* parser,char* parentDirPath){
    assert(parser != NULL && "Le parser fourni est NULL à la récupération de la configurationd es sons");
    assert(parentDirPath != NULL && "Le dossier parent fourni est NULL à la récupération de la configurationd es sons");

    // allocation de base de la configuration et de la map
    SoundsConfig* soundsConfig = malloc(sizeof(SoundsConfig));

    if(soundsConfig == NULL){
        fputs("\nEchec d'allocation de la configuration des sons",stderr);
        return NULL;
    }

    soundsConfig->countOfSounds = 0;
    soundsConfig->map = malloc(sizeof(SoundConfig));

    if(soundsConfig->map == NULL){
        fputs("\nEchec d'allocation de la map des sons",stderr);
        free(soundsConfig);
        return NULL;
    }

    // récupération des configurations
    yaml_token_t token;
    int valueCount = 0;

    while(true){
        if(!yaml_parser_scan(parser,&token)){
            fputs("\nEchec de récupération du token lors du parsing des sons",stderr);
            freeSoundsConfig(soundsConfig,true);
            return NULL;
        }

        if(
            token.type == YAML_DOCUMENT_END_TOKEN ||
            token.type == YAML_STREAM_END_TOKEN
        )
            break;

        switch(token.type){
            case YAML_VALUE_TOKEN:
                valueCount++;
            break;

            case YAML_SCALAR_TOKEN:
                if(valueCount == 0){
                    // récupération de l'id et agrandissement de l'espace alloué
                    void* tmpAddress = realloc(soundsConfig->map,sizeof(SoundConfig) * (soundsConfig->countOfSounds + 1));

                    if(tmpAddress == NULL){
                        fputs("\nEchec d'agrandissement de l'espace map des sons",stderr);
                        FREE_RESOURCES_AND_QUIT
                    }

                    soundsConfig->map = tmpAddress;

                    // initialisation de la structure allouée
                    soundsConfig->map[soundsConfig->countOfSounds].haveToBeLoaded = false;
                    soundsConfig->map[soundsConfig->countOfSounds].isCurrentlyLoaded = false;
                    memset(&soundsConfig->map[soundsConfig->countOfSounds].path,0,sizeof(char) * SUPPOSED_PATH_MAX_LEN);

                    soundsConfig->countOfSounds++;
                }
                else if(valueCount == 2){
                    // récupération du chemin
                    valueCount = 0;

                    strncpy(
                        soundsConfig->map[soundsConfig->countOfSounds - 1].path,
                        parentDirPath,
                        sizeof(char) * SUPPOSED_PATH_MAX_LEN
                    );
                    strncat(
                        soundsConfig->map[soundsConfig->countOfSounds - 1].path,
                        (char*)token.data.scalar.value,
                        sizeof(char) * (SUPPOSED_PATH_MAX_LEN - strlen(parentDirPath))
                    );
                }
            break;

            default:;
        }

        yaml_token_delete(&token);
    }

    return soundsConfig;
}

void freeSoundsConfig(SoundsConfig* config,bool freeContainer){
    assert(config != NULL && "La configuration de son fournie à la libération est NULL");

    unloadMarkedSounds(config);

    if(config->map != NULL)
        free(config->map);

    if(freeContainer)
        free(config);
}

void printSoundsConfig(SoundsConfig* config,char* toPrintBefore){
    assert(config != NULL && "Configuration de sons NULL pour l'affichage");

    printf("\n"CC_BLUE"%s------------------------------------------------------------------------"CC_RESET,TO_PRINT);
    printf("\n"CC_BBLUE"%sConfiguration des sons"CC_RESET"\n",TO_PRINT);
    printf("\n"CC_BG_BLUE"%sNombre de sons : %d"CC_RESET"\n",TO_PRINT,config->countOfSounds);
    printf("\n"CC_BG_BLUE"%sListe des sons"CC_RESET"\n",TO_PRINT);

    for(int i = 0; i < config->countOfSounds; i++){
        printf("\n%s"CC_BWHITE">> Chemin : %s - Actuellement chargé : %s",
           TO_PRINT,
           config->map[i].path,
           config->map[i].isCurrentlyLoaded ? "Oui" : "Non"
       );
    }

    printf("\n"CC_BLUE"------------------------------------------------------------------------"CC_RESET"\n");
}

bool loadMarkedSounds(SoundsConfig* config){
    for(int i = 0; i < config->countOfSounds; i++){
        if(!config->map[i].haveToBeLoaded || config->map[i].isCurrentlyLoaded)
            continue;

        Sound loadedSound = LoadSound(config->map[i].path);

        if(!IsSoundReady(loadedSound))
            return false;

        memcpy(&config->map[i].sound,&loadedSound,sizeof(Sound));
        config->map[i].haveToBeLoaded = false;
        config->map[i].isCurrentlyLoaded = true;
    }

    return true;
}

void unloadMarkedSounds(SoundsConfig* config){
    // libération des sounds raylib
    for(int i = 0; i < config->countOfSounds; i++){
        if(config->map[i].isCurrentlyLoaded)
            UnloadSound(config->map[i].sound);
    }
}