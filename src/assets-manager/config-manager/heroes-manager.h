#if !defined(ASSETS_MANAGER_CONFIG_MANAGER_HEROES_MANAGER_H)
#define ASSETS_MANAGER_CONFIG_MANAGER_HEROES_MANAGER_H
    #include "./image-config-manager.h"
    #include <yaml.h>

    /**
     * @brief Longueur max supposé du nom d'un héro
     */
    #define SUPPOSED_HERO_NAME_MAX_LEN 20

    /**
     * @brief Map des frames d'un héro
     */
    typedef ImageConfig* HeroFrames;

    /**
     * @brief Configuration d'un héro
     */
    typedef struct{
        HeroFrames framesMap;

        /**
         * @brief Nom du héro
         */
        char name[SUPPOSED_HERO_NAME_MAX_LEN];
    }HeroConfig;

    /**
     * @brief Map des héros
     */
    typedef HeroConfig* HeroesMap;

    /**
     * @brief Configuration des héros
     */
    typedef struct{
        HeroesMap map;

        /**
         * @brief Nombre de héros
         */
        int countOfHeroes;
    }HeroesConfig;

    /**
     * @brief Charge la configuration
     * @param parser
     * @param parentDirPath
     * @return
     */
    void* loadHeroesConfig(yaml_parser_t *parser,char* parentDirPath);
#endif