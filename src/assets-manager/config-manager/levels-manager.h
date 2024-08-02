#if !defined(ASSETS_MANAGER_CONFIG_MANAGER_LEVELS_MANAGER_H)
#define ASSETS_MANAGER_CONFIG_MANAGER_LEVELS_MANAGER_H
    #include "../../utils/generic-list/generic-list.h"

    /**
     * @brief Configuration d'un niveau
     */
    typedef struct{

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
     */
    void freeLevelsConfig(GenericList* levels);

    /**
     * @brief Afficha la configuration des niveaux
     * @param levels liste des niveaux
     * LevelConfig
     */
    void printLevelsConfig(GenericList* levels);
#endif