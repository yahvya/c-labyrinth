#include "./ennemies-manager.h"
#include <string.h>

EnemyAction getEnemyActionIndexFromName(char* name){
    static char enemyActionsMap[ENEMIES_MAX_FOR_ARRAY_KEYS][SUPPOSED_ENEMY_ACTION_MAX_LEN] = {
        "front-walk",
        "right-walk",
        "left-walk",
        "back-walk"
    };

    for(int i = 0; i < ENEMIES_MAX_FOR_ARRAY_KEYS; i++){
        if(strcmp(enemyActionsMap[i],name) == 0)
            return i;
    }

    return -1;
}

void* loadEnemies(yaml_parser_t* parser,char* parentDirPath){
    return NULL;
}