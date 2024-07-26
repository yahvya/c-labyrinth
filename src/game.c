#include "./assets-manager/config-manager/config-manager.h"
#include "./assets-manager/assets/assets.h"
#include "./assets-manager/config-manager/tills-manager.h"
#include <stdio.h>
#include <stdlib.h>
#include "./utils/generic-list/generic-list.h"

int main(int argc,char ** argv){
    /**
     * @todo Supprimer le test
     */
    {
        TillsConfig* tillsConfig = (TillsConfig*) loadConfig(RESSOURCES_PATH"/game-assets/tills/config.yaml",loadTillsConfig);

        if(tillsConfig != NULL){
            for(int i = 0; i < tillsConfig->countOfTills; i++){
                printf("\nId: %s - Description : %s - Type : %d - Rotation : %d\n",
                    tillsConfig->map[i].id,
                    tillsConfig->map[i].description,
                    tillsConfig->map[i].type,
                    tillsConfig->map[i].rotation
                );

                while(tillsConfig->map[i].paths.items != NULL){
                    printf("\n\tChemin: %s",(char*) tillsConfig->map[i].paths.items->data);

                    tillsConfig->map[i].paths.items = tillsConfig->map[i].paths.items->nextItem;
                }
            }

            // printf("Chargement de configuration réussi");
            free(tillsConfig);
        }
        else
            printf("Echec de chargement de configuration");
    }
    
    return 0;
}
