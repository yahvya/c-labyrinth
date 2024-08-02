#if !defined(RENDERINGN_LEVEL_LIST_RENDERING_H)
#define RENDERINGN_LEVEL_LIST_RENDERING_H
    #include "../game/window-manager.h"

    /**
     * @brief Affiche la liste des niveaux
     * @param renderingConfig configuration de rendu
     * @attention La configuration de données supplémentaires doit être mis à NULL sur le premier appel
     * @attention Modifie la configuration de données supplémentaires
     * @return l'état de réussite de l'affichage
     */
    bool renderLevelsList(RenderingConfig* renderingConfig);
#endif