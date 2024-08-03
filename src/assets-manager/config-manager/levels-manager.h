#if !defined(ASSETS_MANAGER_CONFIG_MANAGER_LEVELS_MANAGER_H)
#define ASSETS_MANAGER_CONFIG_MANAGER_LEVELS_MANAGER_H
    #include "../../utils/generic-list/generic-list.h"
    #include "config-manager.h"

    /**
     * @brief Longueur max supposé du nom d'un niveau
     */
    #define SUPPOSED_LEVEL_NAME_MAX_LEN 20

    /**
     * @brief Configuration d'un niveau
     */
    typedef struct{
        /**
         * @brief Ordre du niveau parmi le reste
         */
        int levelOrder;

        /**
         * @brief Nom du niveau
         */
        char levelName[SUPPOSED_LEVEL_NAME_MAX_LEN];

        /**
         * @brief Map du niveau
         */
        char linkedMapFilePath[SUPPOSED_PATH_MAX_LEN];

        /**
         * @brief Si le niveau et ses ressources sont chargés
         */
        bool isLoaded;
    }LevelConfig;

    /**
     * @brief Charge la configuration de la liste des niveaux
     * @param levelsDirPath Chemin du dossier des niveaux
     * @return la configuration des niveaux ou null en cas d'erreur
     * @attention les niveaux eux même ne seront pas chargés
     * LevelConfig
     */
    GenericList* loadLevelsConfig(char* levelsDirPath);

    /**
     * @brief Libère une liste de configuration de niveau
     * @param levels liste des niveaux
     * @param freeContainer si true libère le conteneur fourni
     */
    void freeLevelsConfig(GenericList* levels,bool freeContainer);

    /**
     * @brief Afficha la configuration des niveaux
     * @param levels liste des niveaux
     * LevelConfig
     */
    void printLevelsConfig(GenericList* levels);

    /**
     * @brief Charge les ressources d'un niveau
     * @param gameConfig Configuration globale du jeux
     * @param levelConfig configuration du niveau chargé
     * @return si le chargement réussi
     */
    bool loadLevel(GameConfig* gameConfig,LevelConfig* levelConfig);

    /**
     * @brief Libère les ressources d'un niveau
     * @param gameConfig Configuration globale du jeux
     * @param levelConfig configuration du niveau chargé
     */
    void unloadLevel(GameConfig* gameConfig,LevelConfig* levelConfig);
#endif