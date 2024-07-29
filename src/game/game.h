#if !defined(GAME_GAME_H)
#define GAME_GAME_H
    #include <stdbool.h>
    #include "./window-manager.h"

    /**
     * @brief Largeur par défaut de la fenêtre
     */
    #define WINDOW_DEFAULT_WIDTH 500
    /**
     * @brief Hauteur par défaut de la fenêtre
     */
    #define WINDOW_DEFAULT_HEIGHT 300

    /**
     * @brief Initialise les ressources du jeux
     * @return si l'initialisation réussi
     */
    bool initializeGame();

    /**
     * @brief Lance le jeux
     * @return si la lancement du jeux réussi
     */
    void startGame();

    /**
     * @brief Ferme et libère les ressources du jeux
     */
    void closeGame();
#endif