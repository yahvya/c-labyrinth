#include "./image-config-manager.h"
#include <string.h>
#include <assert.h>
#include "custom-color.h"

/**
 * @brief Assertions sur les fonctions de chargement
 */
#define LOAD_FUNCTIONS_GUARD assert(inConfig != NULL && "La configuration d'image à remplir fournie est NULL");\
    assert(parser != NULL && "Le parser fourni est NULL");\
    assert(parentDirPath != NULL && "Le chemin de dossier fourni est NULL");

/**
 * @brief Ternaire de choix de l'affichage
 */
#define TO_PRINT toPrintBefore == NULL ? "" : toPrintBefore

/**
 * @brief Charge la configuration de chemins sous forme statique
 * @param inConfig la configuration dans laquelle placer le résultat
 * @param parser le parser
 *  * @param parentDirPath chemin du dossier parent de la configuration
 * @return si l'élément à bien été chargé
 */
bool loadStaticPath(ImageConfig* inConfig,yaml_parser_t* parser,char* parentDirPath){
    LOAD_FUNCTIONS_GUARD

    yaml_token_t token;
    bool stop = false;
    bool nextIsValue = false;

    while(!stop){
        if(!yaml_parser_scan(parser,&token))
            return false;

        if(
            token.type == YAML_DOCUMENT_END_TOKEN ||
            token.type == YAML_STREAM_END_TOKEN
        ){
            yaml_token_delete(&token);
            break;
        }

        switch(token.type){
            case YAML_VALUE_TOKEN:
                nextIsValue = true;
            break;

            case YAML_SCALAR_TOKEN:
                if(nextIsValue){
                    stop = true;

                    // ajout du chemin par copie du chemin parent + chemin image
                    unsigned long long len = strlen(parentDirPath);
                    char* path = calloc(
                        (token.data.scalar.length / sizeof(char)) + (sizeof(char) * len) + 1,
                        sizeof(char)
                    );

                    if(path == NULL)
                        break;

                    strncpy(path,parentDirPath,sizeof(char) * len);
                    strncat(path,(char*) token.data.scalar.value,token.data.scalar.length);

                    if(listAppend(&inConfig->paths,path) ){
                        yaml_token_delete(&token);
                        return true;
                    }
                    else
                        stop = true;
                }
            break;

            default:;
        }

        yaml_token_delete(&token);
    }

    return false;
}

/**
 * @brief Charge la configuration de chemins sous forme de liste
 * @param inConfig la configuration dans laquelle placer le résultat
 * @param parser le parser
 *  * @param parentDirPath chemin du dossier parent de la configuration
 * @return si l'élément à bien été chargé
 */
bool loadListPath(ImageConfig* inConfig,yaml_parser_t* parser,char* parentDirPath){
    LOAD_FUNCTIONS_GUARD

    yaml_token_t token;
    bool startReadSequence = false;
    bool stop = false;

    while(!stop){
        if(!yaml_parser_scan(parser,&token))
            break;

        if(
            token.type == YAML_DOCUMENT_END_TOKEN ||
            token.type == YAML_STREAM_END_TOKEN
        ){
            yaml_token_delete(&token);
            break;
        }

        switch(token.type){
            case YAML_FLOW_SEQUENCE_START_TOKEN:
                startReadSequence = true;
            break;

            case YAML_FLOW_SEQUENCE_END_TOKEN:
                return true;

            case YAML_SCALAR_TOKEN:
                if(!startReadSequence)
                    break;

                // ajout du chemin par copie du chemin parent + chemin image
                unsigned long long len = strlen(parentDirPath);
                char* path = calloc(
                    (token.data.scalar.length / sizeof(char)) + (sizeof(char) * len) + 1,
                    sizeof(char)
                );

                if(path == NULL)
                    break;

                strncpy(path,parentDirPath,sizeof(char) * len);
                strncat(path,(char*) token.data.scalar.value,token.data.scalar.length);

                if(listAppend(&inConfig->paths,path) )
                    break;

                stop = true;
                freeGenericList(&inConfig->paths,true);
            break;

            default:;
        }

        yaml_token_delete(&token);
    }

    return false;
}

/**
 * @brief Charge la configuration de chemins lors du parsing
 * @param inConfig la configuration dans laquelle placer le résultat
 * @param parser le parser
 *  * @param parentDirPath chemin du dossier parent de la configuration
 * @return si l'élément à bien été chargé
 */
bool loadPath(ImageConfig* inConfig,yaml_parser_t* parser,char* parentDirPath){
    LOAD_FUNCTIONS_GUARD

    newGenericListFrom(&inConfig->paths);

    return inConfig->type == STATIC ? loadStaticPath(inConfig,parser,parentDirPath) : loadListPath(inConfig,parser,parentDirPath);
}

/**
 * @brief Charge la configuration de description lors du parsing
 * @param inConfig la configuration dans laquelle placer le résultat
 * @param parser le parser
 *  * @param parentDirPath chemin du dossier parent de la configuration
 * @return si l'élément à bien été chargé
 */
bool loadDescription(ImageConfig* inConfig,yaml_parser_t* parser,char* parentDirPath){
    LOAD_FUNCTIONS_GUARD

    yaml_token_t token;
    bool nextIsValue = false;

    while(true){
        if(!yaml_parser_scan(parser,&token))
            return false;

        if(
            token.type == YAML_DOCUMENT_END_TOKEN ||
            token.type == YAML_STREAM_END_TOKEN
        ){
            yaml_token_delete(&token);
            break;
        }

        switch(token.type){
            case YAML_VALUE_TOKEN:
                nextIsValue = true;
            break;

            case YAML_SCALAR_TOKEN:
                if(!nextIsValue)
                    break;

                strncpy(inConfig->description,(char*)token.data.scalar.value,sizeof(char) * (SUPPOSED_DESCRIPTION_MAX_LEN - 1));
                yaml_token_delete(&token);
                return true;

            default:;
        }

        yaml_token_delete(&token);
    }

    return false;
}

/**
 * @brief Charge la configuration de type lors du parsing
 * @param inConfig la configuration dans laquelle placer le résultat
 * @param parser le parser
 *  * @param parentDirPath chemin du dossier parent de la configuration
 * @return si l'élément à bien été chargé
 */
bool loadType(ImageConfig* inConfig,yaml_parser_t* parser,char* parentDirPath){
    LOAD_FUNCTIONS_GUARD

    yaml_token_t token;
    bool nextIsValue = false;

    while(true){
        if(!yaml_parser_scan(parser,&token))
            return false;

        if(
            token.type == YAML_DOCUMENT_END_TOKEN ||
            token.type == YAML_STREAM_END_TOKEN
        ){
            yaml_token_delete(&token);
            break;
        }

        switch(token.type){
            case YAML_VALUE_TOKEN:
                nextIsValue = true;
            break;

            case YAML_SCALAR_TOKEN:
                if(!nextIsValue)
                    break;

                inConfig->type = atoi((char*) token.data.scalar.value);
                yaml_token_delete(&token);
                return true;

            default:;
        }

        yaml_token_delete(&token);
    }

    return false;
}

/**
 * @brief Charge la configuration de rotation lors du parsing
 * @param inConfig la configuration dans laquelle placer le résultat
 * @param parser le parser
 * @param parentDirPath chemin du dossier parent de la configuration
 * @return si l'élément à bien été chargé
 */
bool loadRotation(ImageConfig* inConfig,yaml_parser_t* parser,char* parentDirPath){
    LOAD_FUNCTIONS_GUARD

    yaml_token_t token;
    bool nextIsValue = false;

    while(true){
        if(!yaml_parser_scan(parser,&token))
            return false;

        if(
            token.type == YAML_DOCUMENT_END_TOKEN ||
            token.type == YAML_STREAM_END_TOKEN
        ){
            yaml_token_delete(&token);
            break;
        }

        switch(token.type){
            case YAML_VALUE_TOKEN:
                nextIsValue = true;
            break;

            case YAML_SCALAR_TOKEN:
                if(!nextIsValue)
                    break;

                inConfig->rotation = atoi((char*)token.data.scalar.value);
                yaml_token_delete(&token);
                return true;

            default:;
        }

        yaml_token_delete(&token);
    }

    return false;  
}

ImageConfig createImageFromConfig(yaml_parser_t* parser,char* parentDirPath){
    assert(parser != NULL && "Le parser fourni est NULL");
    assert(parentDirPath != NULL && "Le chemin parent fourni est NULL");

    ImageConfig config = {.errorState = true};

    memset(config.description,0,sizeof(char) * SUPPOSED_DESCRIPTION_MAX_LEN);
    memset(config.id,0,sizeof(char) * SUPPOSED_ID_MAX_LEN);

    int countOfElementsToLoad = 4;
    bool nextIsKey = false;
    bool stop = false;
    yaml_token_t token;

    while(countOfElementsToLoad != 0 && !stop){
        if(!yaml_parser_scan(parser,&token))
            break;

        if(
            token.type == YAML_DOCUMENT_END_TOKEN ||
            token.type == YAML_STREAM_END_TOKEN
        ){
            yaml_token_delete(&token);
            break;
        }

        switch(token.type){
            case YAML_KEY_TOKEN:
                nextIsKey = true;
            break;

            case YAML_SCALAR_TOKEN:
                if(nextIsKey){
                    nextIsKey = false;

                    // vérification de l'élément de comparaison à charger
                    bool (*loadFunction)(ImageConfig*,yaml_parser_t*,char*) = NULL;

                    if(strcmp((char*)token.data.scalar.value,"path") == 0)
                        loadFunction = loadPath;
                    else if(strcmp((char*)token.data.scalar.value,"description") == 0)
                        loadFunction = loadDescription;
                    else if(strcmp((char*)token.data.scalar.value,"type") == 0)
                        loadFunction = loadType;
                    else if(strcmp((char*)token.data.scalar.value,"rotation") == 0)
                        loadFunction = loadRotation;

                    if(loadFunction == NULL)
                        break;

                    // chargement de l'élément
                    if(!loadFunction(&config,parser,parentDirPath)){
                        stop = true;
                        break;
                    }

                    countOfElementsToLoad--;
                }
            break;

            default:;
        } 

        yaml_token_delete(&token);          
    }

    if(countOfElementsToLoad == 0)
        config.errorState = false;

    return config;
}

void freeImageConfig(ImageConfig* config,bool freeContainer){
    assert(config != NULL && "Configuration d'image NULL pour la libération");

    freeGenericList(&config->paths,true);
    
    if(freeContainer)
        free(config);
}

void printImageConfig(ImageConfig* config,char* toPrintBefore){
    assert(config != NULL && "Configuration d'image NULL pour l'affichage");

    printf(CC_BBLUE"\n%sConfiguration d'image :"CC_RESET,TO_PRINT);
    printf(CC_BWHITE"\n%s\tId: "CC_RESET"%s",TO_PRINT,config->id);
    printf(CC_BWHITE"\n%s\tType: "CC_RESET"%d",TO_PRINT,config->type);
    printf(CC_BWHITE"\n%s\tDescription: "CC_RESET"%s",TO_PRINT,config->description);
    printf(CC_BWHITE"\n%s\tRotation: "CC_RESET"%d",TO_PRINT,config->rotation);
    printf(CC_BWHITE"\n%s\tContient une erreur: "CC_RESET"%s",TO_PRINT,config->errorState ? "Oui" : "Non");
    printf(CC_BWHITE"\n%s\tListe des chemins: "CC_RESET,TO_PRINT);

    while(config->paths.items != NULL){
        printf("\n%s\t\t=> %s",TO_PRINT,(char*) config->paths.items->data);

        config->paths.items = config->paths.items->nextItem;
    }

    config->paths.items = config->paths.listStart;
}
