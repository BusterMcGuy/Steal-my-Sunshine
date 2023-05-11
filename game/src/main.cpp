#include "rlImGui.h"
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

int main(void)
{


    const int screenWidth = 1000;
    const int screenHeight = 1000;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sunshine");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello World!", 16, 9, 20, RED);
        //int centreX = 100;
        //int centreY = 100;
        //float radius = 30;

        Vector2 GetMousePosition(void);


        Vector2 ballPosition2 = { -100.0f, -100.0f };

        Vector2 ballposition1 = { 100.0f, 100.0f };

        Color ballColor1 = DARKBROWN;

        Color ballColor2 = DARKGREEN;

        ballPosition2 = GetMousePosition();

        DrawCircleV(ballPosition2, 50, ballColor2);

        DrawCircleV(ballposition1, 50, ballColor1);

        DrawCircle(screenWidth / 5, 120, 35, DARKBLUE);

        bool IsKeyPressed(int s);

        bool CheckCollisionCircles(Vector2 center1, float radius1, Vector2 center2, float radius2);
      
        CheckCollisionCircles(ballposition1, 50, ballPosition2, 50);
        if(CheckCollisionCircles = true)
       

        EndDrawing();
    }

    CloseWindow();
    return 0;
}