#if !defined(ASSETS_MANAGER_IMAGE_LOADER_IMAGE_H)
#define ASSETS_MANAGER_IMAGE_LOADER_IMAGE_H
    /**
     * @brief Configuration d'image
     */
    typedef struct{
        /**
         * @var Chemin à partir du parent
         */
        char** path;
        /**
         * @var Description de l'élément
         */
        char* description;
        /**
         * @var Type de l'élément
         */
        int type;
        /**
         * @var Rotation par défaut de l'image
         */
        int rotation;
    }Image;
#endif
