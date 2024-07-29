#include "./window-manager.h"
#include "raylib.h"

void centerWindow(){
    int currentMonitorId = GetCurrentMonitor();

    SetWindowPosition(
        (GetMonitorWidth(currentMonitorId) - GetScreenWidth()) / 2,
        (GetMonitorHeight(currentMonitorId) - GetScreenHeight()) / 2
    );
}