#include "./rendering.h"
#include "raylib.h"
#include "../game/window-manager.h"

/**
 * @brief Vérifie si l'image peut être passé à la suivante automatiquement
 * @attention actuellement vérifie que le type d'image n'est pas lié à une action
 * @param config configuration d'image
 * @return si l'image peut être passé à la suivante automatiquement
 */
bool checkCanBeSetToNext(ImageConfig* config){
    return config->type != IMAGES_ON_ACTION;
}

/**
 * @brief Affiche les tills
 * @param gameConfig configuration globale du jeux
 * @param mapConfig configuration de map
 * @return si l'affichage réussi
 */
bool renderTills(GameConfig* gameConfig,GameMapConfig* mapConfig){
    GameTillsMap* tillsConfig = &mapConfig->tillsMapConfig;

    // rendu de la map de tills
    for(int rowIndex = 0; rowIndex < tillsConfig->countOfRows; rowIndex++){
        for(int colIndex = 0; colIndex < tillsConfig->countOfCols; colIndex++){
            GameMapTillConfig config = tillsConfig->tillsMap[rowIndex][colIndex];
            GenericList* linkedImages = &gameConfig->tillsConfig->map[config.id - 1].linkedImages;

            DrawTextureEx(
                *((Texture2D*)linkedImages->items->data),
                (Vector2){.x = (float)config.x,.y= (float)config.y},
                gameConfig->tillsConfig->map[config.id - 1].rotation,
                mapConfig->scale,
                WHITE
            );

            // passage à l'image de till suivante si possible
            if(checkCanBeSetToNext(gameConfig->tillsConfig->map + config.id - 1))
                linkedImages->items = linkedImages->items->nextItem == NULL ? linkedImages->listStart : linkedImages->items->nextItem;
        }
    }

    return true;
}

/**
 * @brief Affiche les items
 * @param gameConfig configuration globale du jeux
 * @param mapConfig configuration de map
 * @return si l'affichage réussi
 */
bool renderItems(GameConfig* gameConfig,GameMapConfig* mapConfig){
    GenericList* itemsConfig = &mapConfig->itemsConfig;

    // rendu des items
    while(itemsConfig->items != NULL){
        GameMapItemConfig* itemConfig = (GameMapItemConfig*) itemsConfig->items->data;
        GenericList* linkedImages = &gameConfig->itemsConfig->map[itemConfig->id - 1].linkedImages;

        DrawTextureEx(
            *((Texture2D*)linkedImages->items->data),
            (Vector2){.x = (float)itemConfig->x,.y = (float)itemConfig->y},
            gameConfig->itemsConfig->map[itemConfig->id].rotation,
            mapConfig->scale,
            WHITE
        );

        // passage à l'image suivante de l'item si possible
        if(checkCanBeSetToNext(gameConfig->itemsConfig->map + (itemConfig->id - 1)))
            linkedImages->items = linkedImages->items->nextItem == NULL ? linkedImages->listStart : linkedImages->items->nextItem;

        itemsConfig->items = itemsConfig->items->nextItem;
    }

    itemsConfig->items = itemsConfig->listStart;

    return true;
}

/**
 * @brief Affiche les ennemies
 * @param gameConfig configuration globale du jeux
 * @param mapConfig configuration de map
 * @return si l'affichage réussi
 */
bool renderEnemies(GameConfig* gameConfig,GameMapConfig* mapConfig){
    GenericList* enemiesConfig = &mapConfig->enemiesConfig;

    while(enemiesConfig->items != NULL){
        GameMapEnemyConfig* mapEnemyConfig = (GameMapEnemyConfig*) enemiesConfig->items->data;
        EnemyConfig enemyConfig = gameConfig->enemiesConfig->map[mapEnemyConfig->id - 1];
        EnemyActionConfig currentAction = enemyConfig.actionsMap[mapEnemyConfig->currentAction];

        DrawTextureEx(
            *((Texture2D*)currentAction.framesConfig->linkedImages.items->data),
            (Vector2){.x = (float)mapEnemyConfig->x,.y = (float)mapEnemyConfig->y,},
            currentAction.framesConfig->rotation,
            mapConfig->scale,
            WHITE
        );

        if(checkCanBeSetToNext(currentAction.framesConfig))
            currentAction.framesConfig->linkedImages.items = currentAction.framesConfig->linkedImages.items->nextItem == NULL ? currentAction.framesConfig->linkedImages.listStart : currentAction.framesConfig->linkedImages.items->nextItem ;

        enemiesConfig->items = enemiesConfig->items->nextItem;
    }

    enemiesConfig->items = enemiesConfig->listStart;

    return true;
}

bool renderMap(GameConfig* gameConfig,GameMapConfig* mapConfig){
    if(
        renderTills(gameConfig,mapConfig) &&
        renderItems(gameConfig,mapConfig) &&
        renderEnemies(gameConfig,mapConfig)
    ){
        SetWindowSize(mapConfig->windowWidth,mapConfig->windowHeight);
        centerWindow();
        return true;
    }

    return false;
}