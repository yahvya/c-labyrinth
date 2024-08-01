#if !defined(COMPONENTS_TEXT_TEXT_COMPONENT_H)
#define COMPONENTS_TEXT_TEXT_COMPONENT_H
    #include "raylib.h"

    /**
     * @brief Dessine un texte en le centrant dans le conteneur fourni
     * @param container conteneur
     * @param text le texte
     * @param color couleur du text
     * @param size taille du texte
     * @param spacing espacement du texte
     * @param font police du text
     */
    void drawAndCenterTextIn(Rectangle container,char* text,Color color,float size,float spacing,Font font);

    /**
     * @brief Dessine un texte en le centrant dans le conteneur fourni
     * @param container conteneur
     * @param text le texte
     * @param color couleur du text
     * @param size taille du texte
     * @param spacing espacement du texte
     * @param font police du text
     * @param xGap gap x
     * @param yGap gap y
     */
    void drawAndCenterTextWithGapIn(Rectangle container,char* text,Color color,float size,float spacing,Font font,int xGap,int yGap);
#endif