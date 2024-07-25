#include "./assets-manager/config-manager/config-manager.h"
#include "./assets-manager/assets.h"
#include "./assets-manager/config-manager/tills-manager.h"
#include <stdio.h>
#include <stdlib.h>
#include "./utils/generic-list/generic-list.h"

int main(int argc,char ** argv){
    /**
     * @todo Supprimer le test
     */
    {
        void* tillsConfig = loadConfig(RESSOURCES_PATH"/game-assets/tills/config.yaml",loadTillsConfig);

        if(tillsConfig != NULL){
            printf("Chargement de configuration réussi");
            free(tillsConfig);
        }
        else
            printf("Echec de chargement de configuration");
    }
    
    return 0;
}
