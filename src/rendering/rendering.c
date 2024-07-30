#include "./rendering.h"
#include "raylib.h"

/**
 * @brief Affiche les tills
 * @param gameConfig configuration globale du jeux
 * @param tillsConfig configuration des tills
 * @return si l'affichage réussi
 */
bool renderTills(GameConfig* gameConfig,GameTillsMap* tillsConfig){
    for(int rowIndex = 0; rowIndex < tillsConfig->countOfRows; rowIndex++){
        for(int colIndex = 0; colIndex < tillsConfig->countOfCols; colIndex++){
            GameMapTillConfig config = tillsConfig->tillsMap[rowIndex][colIndex];

            DrawTexture(
                *((Texture2D*)gameConfig->tillsConfig->map[config.id - 1].linkedImages.items->data),
                config.x,
                config.y,
                WHITE
            );
        }
    }

    return true;
}

/**
 * @brief Affiche les items
 * @param gameConfig configuration globale du jeux
 * @param tillsConfig configuration des items
 * @return si l'affichage réussi
 */
bool renderItems(GameConfig* gameConfig,GenericList* itemsConfig){
    while(itemsConfig->items != NULL){
        GameMapItemConfig* itemConfig = (GameMapItemConfig*) itemsConfig->items->data;

        DrawTexture(
            *((Texture2D*)gameConfig->itemsConfig->map[itemConfig->id].linkedImages.items->data),
            itemConfig->x,
            itemConfig->y,
            WHITE
        );

        itemsConfig->items = itemsConfig->items->nextItem;
    }

    itemsConfig->items = itemsConfig->listStart;

    return true;
}

/**
 * @brief Affiche les ennemies
 * @param gameConfig configuration globale du jeux
 * @param tillsConfig configuration des ennemies
 * @return si l'affichage réussi
 */
bool renderEnemies(GameConfig* gameConfig,GenericList* enemiesConfig){
    return true;
}

bool renderMap(GameConfig* gameConfig,GameMapConfig* mapConfig){

    return renderTills(gameConfig,&mapConfig->tillsMapConfig) &&
        renderItems(gameConfig,&mapConfig->itemsConfig) &&
        renderEnemies(gameConfig,&mapConfig->enemiesConfig);
}