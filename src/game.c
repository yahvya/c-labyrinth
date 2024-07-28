#include "./assets-manager/config-manager/config-manager.h"
#include "raylib.h"

int main(int argc,char ** argv){
    GameConfig* gameConfig = loadGameConfig();

    InitWindow(400,500,"Test");

    loadItemsImages(gameConfig);
    loadTillsImages(gameConfig);
    loadEnemiesImages(gameConfig);
    loadHeroesImages(gameConfig);

    SetTargetFPS(40);

    ImageConfig heroFront = *(gameConfig->enemiesConfig->map[1].actionsMap[ENEMY_FRONT_WALK].framesConfig);

    int yPos = 0;

    while(!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(WHITE);

            if(heroFront.linkedImages.items == NULL)
                heroFront.linkedImages.items = heroFront.linkedImages.listStart;

            DrawTexture(*((Texture2D*)heroFront.linkedImages.items->data),30,yPos,RAYWHITE);

            if(IsKeyDown(KEY_DOWN)){
                heroFront.linkedImages.items = heroFront.linkedImages.items->nextItem;
                yPos += 1;
            }
        EndDrawing();
    }

    freeGameConfig(gameConfig,true);

    return 0;
}
