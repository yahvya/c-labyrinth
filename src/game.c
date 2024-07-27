#include "./assets-manager/config-manager/config-manager.h"
#include "./assets-manager/assets/assets.h"
#include "./assets-manager/config-manager/tills-manager.h"
#include <stdio.h>
#include "./assets-manager/config-manager/items-manager.h"

void testTillsConfig(){
    TillsConfig* tillsConfig = (TillsConfig*) loadConfig(RESOURCES_PATH"/game-assets/tills/config.yaml",loadTillsConfig);

    printTillsConfig(tillsConfig,NULL);
    freeTillsConfig(tillsConfig,true);

    printf("\nok");
}

void testLoadItems(){
    ItemsConfig* itemsConfig = loadConfig(RESOURCES_PATH"/game-assets/items/config.yaml",loadItemsConfig);
}

void testLoadHeroes(){

}

void testLoadEnnemies(){

}

int main(int argc,char ** argv){
//     testTillsConfig();
    testLoadItems();
    // testLoadHeroes();
    // testLoadEnnemies();

    return 0;
}
