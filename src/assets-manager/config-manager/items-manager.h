#if !defined(ASSETS_MANAGER_CONFIG_MANAGER_ITEMS_CONFIG_MANAGER_H)
#define ASSETS_MANAGER_CONFIG_MANAGER_ITEMS_CONFIG_MANAGER_H
    #include "yaml.h"

    #include "./image-config-manager.h"

    /**
     * @brief Configuration des items. Tableau indicé par l'id converti en entier - 1. Il est conseillé d'utiliser les fonctions d'accès
     */
    typedef ImageConfig* ItemsMap;

    /**
     * @brief Configuration d'item
     */
    typedef struct{ 
        /**
         * @brief Map des items
         */
        ItemsMap map;
        /**
         * @brief Nombre d'items
         */
        int countOfItems;
    }ItemsConfig;

    /**
     * @brief Charge la configuration des tuiles de jeux
     * @param parser l'adresse du parseur initialisé
     * @param parentConfigPath chemin du fichier de configuration parent
     * @return TillsConfig la structure des tuiles ou null en cas
     */
    void* loadItemsConfig(yaml_parser_t* parser, char* parentConfigPath);
#endif
