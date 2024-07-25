#if !defined(ASSETS_MANAGER_CONFIG_MANAGER_TILLS_MANAGER_H)
#define ASSETS_MANAGER_CONFIG_MANAGER_TILLS_MANAGER_H
    #include <yaml.h>
    #include "./image-config-manager.h"

    /**
     * @brief Configuration des tills. Tableau indicé par l'id converti en entier
     */
    typedef ImageConfig* TillsConfig;

    /**
     * @brief Charge la configuration des tuiles de jeux
     * @param parser l'adresse du parseur initialisé
     * @param parentConfigPath chemin du fichier de configuration parent
     * @return TillsConfig la structure des tuiles ou null en cas
     */
    void* loadTillsConfig(yaml_parser_t* parser,char* parentConfigPath);
#endif
