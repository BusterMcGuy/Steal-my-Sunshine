#include "rlImGui.h"
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720


class circle
{

public:



};








int main(void)
{


    const int screenWidth = 1000;
    const int screenHeight = 1000;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sunshine");
    SetTargetFPS(60);

    // This is how ive added music

        InitAudioDevice();
        Music music = LoadMusicStream("../game/assets/audio/Garbo.mp3");
        music.looping = true;
        PlayMusicStream(music);
        float volume = 1.0f;
        bool pause = false;


        Vector2 ballposition1 = { 500.0f, 500.0f };

        Vector2 ballPosition2 = { 100.0f, 100.0f };

        bool collison = false;

        Color ballColor1 = DARKBROWN;

        Color ballColor2 = DARKGREEN;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("I LOVE MAC DEMARCO", 16, 9, 20, RED);

        UpdateMusicStream(music);

        /////////////////////////////////////////////////////////////

        DrawCircleV(ballPosition2, 50, ballColor2);

        DrawCircleV(ballposition1, 50, ballColor1);

        ballPosition2 = GetMousePosition();
       
        //bool IsKeyPressed(int s);

        collison = CheckCollisionCircles(ballposition1, 50, ballPosition2, 50);
      
       if (collison)
       {
           ballColor2 = ORANGE;

           ballColor1 = ORANGE;
       }
       else
       {
           ballColor1 = DARKBROWN;

           ballColor2 = DARKGREEN;
       }
        
        EndDrawing();
    }
    UnloadMusicStream(music);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}