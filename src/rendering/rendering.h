#if !defined(RENDERING_RENDERING_H)
#define RENDERING_RENDERING_H
    #include "../assets-manager/config-manager/config-manager.h"
    #include "../assets-manager/config-manager/game-map-manager.h"

    /**
     * @brief Affiche sur la fenêtre une map à partir de la configuration
     * @param gameConfig configuration globale du jeux
     * @param mapConfig configuration de map
     * @return si le rendu est un succès
     */
    bool renderMap(GameConfig* gameConfig,GameMapConfig* mapConfig);
#endif