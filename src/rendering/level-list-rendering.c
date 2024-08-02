#include "./level-list-rendering.h"
#include "../game/game.h"
#include "../assets-manager/config-manager/levels-manager.h"

bool renderLevelsList(RenderingConfig* renderingConfig){
    GameRenderingConfig* gameRenderingConfig = (GameRenderingConfig*) renderingConfig->data;

    // chargement des niveaux de jeux sur le premier appel
    if(gameRenderingConfig->supplementaryConfig == NULL){
        void* levelsConfig = loadLevelsConfig(LEVELS_DIR_PATH);

        if(levelsConfig == NULL){
            fputs("\nEchec de chargement de la liste des niveaux",stderr);
            return false;
        }

        gameRenderingConfig->supplementaryConfig = levelsConfig;
        gameRenderingConfig->supplementaryDataHaveToBeFree = true;
    }

    // récupération et affichage des niveaux de jeux
    GenericList* levelsConfig = (GenericList*) gameRenderingConfig->supplementaryConfig;

    /**
     * @todo au choix d'un niveau supprimer cette liste et remettre les configurations supplémentaires à 0
     */


    return true;
}