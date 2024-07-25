#if !defined(ASSETS_MANAGER_CONFIG_MANAGER_CONFIG_MANAGER_H)
#define ASSETS_MANAGER_CONFIG_MANAGER_CONFIG_MANAGER_H
    #include <yaml.h>

    /**
     * @brief Charge un fichier de configuration avec comme racine le dossier ressource
     * @param path chemin complet du fichier à partir du dossier ressource comme racine
     * @param treatmentFunction fonction de traitement renvoyant la structure générée ou null en cas d'échec. Prend en argument le parser initialisé (ne doit pas libérer la ressource), le chemin du fichier de configuration parent
     * @return void* La structure chargée ou null en cas d'échec
     */
    void* loadConfig(char* path,void* (*treatmentFunction)(yaml_parser_t*,char*) );
#endif
