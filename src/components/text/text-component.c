#include "./text-component.h"

void drawAndCenterTextIn(Rectangle container,char* text,Color color,float size,float spacing,Font font){
    Vector2 textSize = MeasureTextEx(font,text,size,spacing);

    // variables de clarté
    const float width = textSize.x;
    const float height = textSize.y;

    Vector2 textPos = {
        .x = container.x + ((container.width - width) / 2),
        .y = container.y + ((container.height - height) / 2)
    };

    DrawTextEx(font,text,textPos,size,spacing,color);
}

void drawAndCenterTextWithGapIn(Rectangle container,char* text,Color color,float size,float spacing,Font font,int xGap,int yGap){
    Vector2 textSize = MeasureTextEx(font,text,size,spacing);

    // variables de clarté
    const float width = textSize.x;
    const float height = textSize.y;

    Vector2 textPos = {
        .x = container.x + ((container.width - width) / 2) + (float)xGap,
        .y = container.y + ((container.height - height) / 2) + (float)yGap
    };

    DrawTextEx(font,text,textPos,size,spacing,color);
}