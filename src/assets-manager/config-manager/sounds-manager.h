#if !defined(ASSETS_MANAGER_CONFIG_MANAGER_SONGS_MANAGER_H)
#define ASSETS_MANAGER_CONFIG_MANAGER_SONGS_MANAGER_H
    #include "raylib.h"
    #include "../assets/assets.h"
    #include "yaml.h"
    #include <stdbool.h>

    /**
     * @brief Configuration de son
     */
    typedef struct{
        /**
         * @brief Son raylib
         */
        Sound sound;

        /**
         * @brief Si le son doit être chargé
         */
        bool haveToBeLoaded;

        /**
         * @brief Si le son est actuellement chargé
         */
        bool isCurrentlyLoaded;

        /**
         * @brief Chemin complet du son
         */
        char path[SUPPOSED_PATH_MAX_LEN];
    }SoundConfig;

    /**
     * @brief Map de son
     */
    typedef SoundConfig* SoundsMap;

    /**
     * @brief Configuration des sons
     */
    typedef struct {
        /**
         * @brief Map des sons
         */
        SoundsMap map;

        /**
         * @brief Nombre de sons
         */
        int countOfSounds;
    }SoundsConfig;

    /**
     * @brief Charge la configuration des sons
     * @param parser parser yaml
     * @param parentDirPath chemin du dossier parent
     * @return la configuration de son ou NULL
     */
    void* loadSoundsConfig(yaml_parser_t* parser,char* parentDirPath);

    /**
     * @brief Affiche la configuration de son
     * @param config configuration de sons
     * @param toPrintBefore chaine à afficher avant chaque ligne de configuration
     */
    void printSoundsConfig(SoundsConfig* config,char* toPrintBefore);

    /**
     * @brief Libère les ressources de la configuration de sons
     * @param config configuration de sons
     * @param freeContainer si true libère le conteneur fourni
     */
    void freeSoundsConfig(SoundsConfig* config,bool freeContainer);
#endif