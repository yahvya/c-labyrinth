#include "./assets-manager/config-manager/config-manager.h"
#include "./assets-manager/assets/assets.h"
#include "./assets-manager/config-manager/tills-manager.h"
#include <stdio.h>
#include <stdlib.h>
#include "./utils/generic-list/generic-list.h"

void testTillsConfig(){
    TillsConfig* tillsConfig = (TillsConfig*) loadConfig(RESOURCES_PATH"/game-assets/tills/config.yaml",loadTillsConfig);

    printTillsConfig(tillsConfig,NULL);
    freeTillsConfig(tillsConfig,true);

    printf("\nok");
}

int main(int argc,char ** argv){
    testTillsConfig();

    return 0;
}
