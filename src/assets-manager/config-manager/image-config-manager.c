#include "./image-config-manager.h"
#include <string.h>

/**
 * @brief Charge la configuration de chemins lors du parsing
 * @param inConfig la configuration dans laquelle placer le résultat
 * @param parser le parser
 * @return si l'élément à bien été chargé
 */
bool loadPath(ImageConfig* inConfig,yaml_parser_t* parser){
    return true;
}

/**
 * @brief Charge la configuration de description lors du parsing
 * @param inConfig la configuration dans laquelle placer le résultat
 * @param parser le parser
 * @return si l'élément à bien été chargé
 */
bool loadDescription(ImageConfig* inConfig,yaml_parser_t* parser){
    yaml_token_t token;
    bool stop = false;
    bool nextIsValue = false;

    while(!stop){
        if(!yaml_parser_scan(parser,&token))
            return false;

        switch(token.type){
            case YAML_DOCUMENT_END_TOKEN:
                stop = true;
            ; break;

            case YAML_VALUE_TOKEN:
                nextIsValue = true;
            ; break;

            case YAML_SCALAR_TOKEN:
                if(nextIsValue){
                    strncpy(inConfig->description,token.data.scalar.value,sizeof(char) * SUPPOSED_DESCRIPTION_MAX_LEN);
                    yaml_token_delete(&token);
                    return true;
                }
            ; break;
        }

        yaml_token_delete(&token);
    }

    return false;
}

/**
 * @brief Charge la configuration de type lors du parsing
 * @param inConfig la configuration dans laquelle placer le résultat
 * @param parser le parser
 * @return si l'élément à bien été chargé
 */
bool loadType(ImageConfig* inConfig,yaml_parser_t* parser){
    yaml_token_t token;
    bool stop = false;
    bool nextIsValue = false;

    while(!stop){
        if(!yaml_parser_scan(parser,&token))
            return false;

        switch(token.type){
            case YAML_DOCUMENT_END_TOKEN:
                stop = true;
            ; break;

            case YAML_VALUE_TOKEN:
                nextIsValue = true;
            ; break;

            case YAML_SCALAR_TOKEN:
                if(nextIsValue){
                    inConfig->type = atoi(token.data.scalar.value);
                    yaml_token_delete(&token);
                    return true;
                }
            ; break;
        }

        yaml_token_delete(&token);
    }

    return false;
}

/**
 * @brief Charge la configuration de rotation lors du parsing
 * @param inConfig la configuration dans laquelle placer le résultat
 * @param parser le parser
 * @return si l'élément à bien été chargé
 */
bool loadRotation(ImageConfig* inConfig,yaml_parser_t* parser){
    yaml_token_t token;
    bool stop = false;
    bool nextIsValue = false;

    while(!stop){
        if(!yaml_parser_scan(parser,&token))
            return false;

        switch(token.type){
            case YAML_DOCUMENT_END_TOKEN:
                stop = true;
            ; break;

            case YAML_VALUE_TOKEN:
                nextIsValue = true;
            ; break;

            case YAML_SCALAR_TOKEN:
                if(nextIsValue){
                    inConfig->rotation = atoi(token.data.scalar.value);
                    yaml_token_delete(&token);
                    return true;
                }
            ; break;
        }

        yaml_token_delete(&token);
    }

    return false;  
}

ImageConfig createImageFromConfig(yaml_parser_t* parser){
    ImageConfig config = {.errorState = true};
    int countOfElementsToLoad = 4;
    bool nextIsKey = false;
    bool stop = false;

    yaml_token_t token;

    while(countOfElementsToLoad != 0 && !stop){
        if(!yaml_parser_scan(parser,&token))
            break;

        switch(token.type){
            case YAML_DOCUMENT_END_TOKEN:
                stop = true;
            ; break;

            case YAML_KEY_TOKEN:
                nextIsKey = true;
            ; break;

            case YAML_SCALAR_TOKEN:
                if(nextIsKey){
                    nextIsKey = false;

                    // vérification de l'élément de comparaison à charger
                    bool (*loadFunction)(ImageConfig*,yaml_parser_t*) = NULL;

                    if(strcmp(token.data.scalar.value,"path") == 0)
                        loadFunction = loadPath;
                    else if(strcmp(token.data.scalar.value,"description") == 0)
                        loadFunction = loadDescription;
                    else if(strcmp(token.data.scalar.value,"type") == 0)
                        loadFunction = loadType;
                    else if(strcmp(token.data.scalar.value,"rotation") == 0)
                        loadFunction = loadRotation;

                    if(loadFunction == NULL)
                        break;

                    // chargement de l'élément
                    if(!loadFunction(&config,parser)){
                        stop = true;
                        break;
                    }

                    countOfElementsToLoad--;
                }
            ; break;
        } 

        yaml_token_delete(&token);          
    }

    if(countOfElementsToLoad == 0)
        config.errorState = false;

    return config;
}
