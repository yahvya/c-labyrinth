#if !defined(ASSETS_MANAGER_CONFIG_MANAGER_GAME_MAP_MANAGER_H)
#define ASSETS_MANAGER_CONFIG_MANAGER_GAME_MAP_MANAGER_H
    #include "yaml.h"
    #include <stdbool.h>

    /**
     * @brief Configuration d'une till
     */
    typedef struct{
        /**
         * @brief Position x de la till
         */
        int x;
        /**
         * @brief Position y de la
         */
        int y;
        /**
         * @brief Id de la till
         */
        int id;
    }GameMapTillConfig;

    /**
     * @brief Configuration d'une map de tills
     */
    typedef struct{
        /**
         * @brief Map des tills
         */
        GameMapTillConfig** tillsMap;

        /**
         * @brief Nombre de colonnes
         */
        int countOfCols;

        /**
         * @brief Nombre de lignes
         */
        int countOfRows;
    }GameTillsMap;

    /**
     * @brief Configuration de map
     */
    typedef struct{
        /**
         * @brief Echelle d'affichage des éléments
         */
        int scale;

        /**
         * @brief Configuration de la map des tills
         */
        GameTillsMap tillsMapConfig;
    }GameMapConfig;

    /**
     * @brief Charge une map de configuration
     * @param parser parser
     * @param parentDirPath chemin du dossier parent
     * @return la configuration de map ou NULL en cas d'echec
     */
    void* loadGameMapConfig(yaml_parser_t* parser,char* parentDirPath);

    /**
     * @brief Affiche la configuration de map
     * @param config configuration de map
     */
    void printMapConfig(GameMapConfig* config);

    /**
     * @brief Libère la map de jeux
     * @param mapConfig configuration de map
     * @param freeContainer si le conteneur doit être libéré
     */
    void freeGameMapConfig(GameMapConfig* mapConfig,bool freeContainer);
#endif