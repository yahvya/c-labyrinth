#include "./assets-manager/config-manager/config-manager.h"
#include "./assets-manager/assets/assets.h"
#include "./assets-manager/config-manager/tills-manager.h"
#include "./assets-manager/config-manager/items-manager.h"
#include "./assets-manager/config-manager/heroes-manager.h"
#include "./assets-manager/config-manager/enemies-manager.h"
#include <stdio.h>
#include "raylib.h"

void testTillsConfig(){
    TillsConfig* tillsConfig = (TillsConfig*) loadConfig(RESOURCES_PATH"/game-assets/tills/config.yaml",loadTillsConfig);

    printTillsConfig(tillsConfig,NULL);
    freeTillsConfig(tillsConfig,true);

    printf("\nok");
}

void testLoadItems(){
    ItemsConfig* itemsConfig = loadConfig(RESOURCES_PATH"/game-assets/items/config.yaml",loadItemsConfig);

    printItemsConfig(itemsConfig,NULL);
    freeItemsConfig(itemsConfig,true);

    printf("\nok");
}

void testLoadHeroes(){
    HeroesConfig* heroesConfig = loadConfig(RESOURCES_PATH"/game-assets/heroes/config.yaml",loadHeroesConfig);

    printHeroesConfig(heroesConfig,NULL);
    freeHeroesConfig(heroesConfig,true);
}

void testLoadEnnemies(){
    EnemiesConfig* enemiesConfig = loadConfig(RESOURCES_PATH"/game-assets/ennemies/config.yaml",loadEnemies);

    printEnemiesConfig(enemiesConfig,NULL);

    freeEnemiesConfig(enemiesConfig,true);
}

int main(int argc,char ** argv){
    InitWindow(300,400,"Ajout raylib");

    while(!WindowShouldClose()){
        BeginDrawing();



        EndDrawing();
    }

    return 0;
}
