#if !defined(ASSETS_MANAGER_ASSETS_H)
#define ASSETS_MANAGER_ASSETS_H
    /**
     * @brief Chemin racine du dossier ressource
     */
    #define RESOURCES_PATH "./resources"

    /**
     * @brief Longueur maximale supposée d'un chemin
     */
    #define SUPPOSED_PATH_MAX_LEN 300

    #include <stddef.h>

    /**
     * @brief Extrait le chemin de dossier en supprimant le dernier caractère de séparation rencontré (/ ou \)
     * @param fullPath chemin
     * @param buffer à remplir de taille SUPPOSED_PATH_MAX_LEN au minimum
     * @param bufferSize taille du buffer
     */
    void extractDirPathFrom(char* fullPath,char* buffer,size_t bufferSize);
#endif
