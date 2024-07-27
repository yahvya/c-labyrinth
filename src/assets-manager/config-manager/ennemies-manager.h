#if !defined(ASSETS_MANAGER_CONFIG_MANAGER_ENNEMIES_MANAGER_H)
#define ASSETS_MANAGER_CONFIG_MANAGER_ENNEMIES_MANAGER_H
    #include <yaml.h>
    #include "./image-config-manager.h"

    /**
     * @brief Longueur maximale supposée du nom d'un ennemie
     */
    #define SUPPOSED_ENEMY_NAME_MAX_LEN 20

    /**
     * @brief Longueur max supposée du nom d'une action ennemie
     */
    #define SUPPOSED_ENEMY_ACTION_MAX_LEN 40

    /**
     * @brief Liste des actions ennemie
     */
    typedef enum{
        ENEMY_FRONT_WALK,
        ENEMY_RIGHT_WALK,
        ENEMY_LEFT_WALK,
        ENEMY_BACK_WALK,
        /**
         * @brief Clé max des actions ennemies
         */
        ENNEMIES_MAX_FOR_ARRAY_KEYS
    }EnemyAction;

    /**
     * @brief Configuration d'action ennemie
     */
    typedef struct{
        /**
         * @brief Nom de l'action
         */
        char actionName[SUPPOSED_ENEMY_ACTION_MAX_LEN];

        /**
         * @brief Configuration des images de l'action
         */
        ImageConfig* framesConfig;
    }EnemyActionConfig;

    /**
     * @brief Configuration d'un ennemie
     */
    typedef struct{
        /**
         * @brief Map des actions ennemies
         */
        EnemyActionConfig actionsMap[ENNEMIES_MAX_FOR_ARRAY_KEYS];

        /**
         * @brief Nom de l'ennemie
         */
        char name[SUPPOSED_ENEMY_NAME_MAX_LEN];

        /**
         * @brief Longueur max supposée d'un id
         */
        char id[SUPPOSED_ID_MAX_LEN];
    }EnemyConfig;

    /**
     * @brief map des ennemies
     */
    typedef EnemyConfig* EnemiesMap;

    /**
     * @brief Configuration des ennemies
     */
    typedef struct{
        /**
         * @brief Map des ennemies
         */
        EnemiesMap map;

        /**
         * @brief Nombre d'ennemies
         */
        int countOfEnemies;
    }EnemiesConfig;

    /**
     * @brief Charge la configuration des ennemies
     * @param parser le parser
     * @param parentDirPath chemin du dossier parent
     * @return la configuration ou null en cas d'échec
     */
    void* loadEnemies(yaml_parser_t* parser,char* parentDirPath);
#endif