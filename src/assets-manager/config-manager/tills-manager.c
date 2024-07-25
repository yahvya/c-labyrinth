#include "./tills-manager.h"
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

void* loadTillsConfig(yaml_parser_t* parser,char* parentConfigPath){
    assert(parser != NULL && "Le parser fourni pour la lecture de configuration des tills est NULL");
    assert(parentConfigPath != NULL && "Le chemin parent fourni pour la lecture de configuration des tills est NULL");

    // allocation de base de la configuration
    TillsConfig config = malloc(sizeof(ImageConfig));

    if(config == NULL){
        fputs("Echec d'allocation de la configuration des tills",stderr);
        return NULL;
    }

    // parsing du fichier
    yaml_token_t readToken;
    bool stop = false;

    while(!stop){
        if(!yaml_parser_scan(parser,&readToken)){
            // libération des ressources d'erreur
            yaml_token_delete(&readToken);
            return NULL;
        }

        switch(readToken.type){
            case YAML_STREAM_END_TOKEN: 
                stop = true;
            ; break;

            case YAML_SCALAR_TOKEN:
                printf("Cle: %s\n",readToken.data.scalar.value);
            ;
        }
    }

    // libération des ressources
    yaml_token_delete(&readToken);

    return config;
}
