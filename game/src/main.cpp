#include "rlImGui.h"
//#define SCREEN_WIDTH 450
//#define SCREEN_HEIGHT 450






int main(void)
{


    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "raylib [textures] example - background scrolling");
    SetTargetFPS(60);

    ////////////////////

    // Creating background

    Texture2D backestGround = LoadTexture("../game/assets/textures/1.png");
    Texture2D background = LoadTexture("../game/assets/textures/2.png");
    Texture2D midground = LoadTexture("../game/assets/textures/3.png");
    Texture2D middestGround = LoadTexture("../game/assets/textures/4.png");
    Texture2D foreGround = LoadTexture("../game/assets/textures/5.png");
    backestGround.width = 800;
    backestGround.height = 500;
    background.width = 800;
    background.height = 500;
    midground.width = 800;
    midground.height = 500;
    middestGround.width = 800;
    middestGround.height = 500;
    foreGround.width = 800;
    foreGround.height = 500;
    float scrollingBackest = 0.0f;
    float scrollingBack = 0.0f;
    float scrollingMid = 0.0f;
    float scrollingMiddest = 0.0f;
    float scrollingForeGround = 0.0f;
        ////////////////////

    // Choosing target fps for this game

    SetTargetFPS(60);

    // Music    

        InitAudioDevice();
        Music music = LoadMusicStream("../game/assets/audio/Chill.mp3");
        music.looping = true;
        PlayMusicStream(music);
        float volume = 1.0f;
        bool pause = false;

        
        /////////////
       

        //Balls

        Vector2 ballposition1 = { 500.0f, 500.0f };

        Vector2 ballPosition2 = { 100.0f, 100.0f };

        bool collison = false;

        Color ballColor1 = DARKBROWN;

        Color ballColor2 = DARKGREEN;

        //////////////
       // if (scrollingBack <= -backGround.width * 2) scrollingBack = 0;
       
      // DrawTextureEx(backGround, (Vector2 { scrollingBack, 20 }), 0.0f, 2.0f, WHITE);
       // DrawTextureEx(backGround, (Vector2 { backGround.width * 2 + scrollingBack, 20 }), 0.0f, 2.0f, WHITE);
       // ImageDraw("../game/assets/textures/Zen.jpg");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("I LOVE MAC DEMARCO", 16, 9, 20, RED);

        ClearBackground(RED);

        void DrawTexture(Texture2D texture, int posX, int posY, Color tint);

        DrawTexture(backestGround, 0, 100, WHITE);

        // Background updating and etc...

        scrollingBackest -= 0.1f;
        scrollingBack -= 0.2f;
        scrollingMid -= 0.3f;
        scrollingMiddest -= 0.6f;
        scrollingForeGround -= 1.0f;

        if (scrollingBackest <= -backestGround.width * 1.5) scrollingBackest = 0;
        if (scrollingBack <= -background.width * 1.5) scrollingBack = 0;
        if (scrollingMid <= -midground.width * 1.5) scrollingMid = 0;
        if (scrollingMiddest <= -middestGround.width * 1.5) scrollingMiddest = 0;
        if (scrollingForeGround <= -foreGround.width * 1.5) scrollingForeGround = 0;

        
        ///////////////
        
        DrawTextureEx(backestGround, (Vector2 { scrollingBackest, 20 }), 0.0f, 2.0f, WHITE);
        DrawTextureEx(backestGround, (Vector2 { backestGround.width * 2 + scrollingBackest, 20 }), 0.0f, 2.0f, WHITE);

        // Draw midground image twice
        DrawTextureEx(background, (Vector2 { scrollingBack, 20 }), 0.0f, 2.0f, WHITE);
        DrawTextureEx(background, (Vector2 { background.width * 2 + scrollingBack, 20 }), 0.0f, 2.0f, WHITE);

        DrawTextureEx(midground, (Vector2 { scrollingMid, 20 }), 0.0f, 2.0f, WHITE);
        DrawTextureEx(midground, (Vector2 { midground.width * 2 + scrollingMid, 20 }), 0.0f, 2.0f, WHITE);

        // Draw midground image twice
        DrawTextureEx(middestGround, (Vector2 { scrollingMiddest, 60 }), 0.0f, 2.0f, WHITE);
        DrawTextureEx(middestGround, (Vector2 { middestGround.width * 2 + scrollingMiddest, 60 }), 0.0f, 2.0f, WHITE);
       
        // Draw foreground image twice
        DrawTextureEx(foreGround, (Vector2 { scrollingForeGround, 60 }), 0.0f, 2.0f, WHITE);
        DrawTextureEx(foreGround, (Vector2 { foreGround.width * 2 + scrollingForeGround, 60 }), 0.0f, 2.0f, WHITE);






        //Update music

        UpdateMusicStream(music);

        /////////////////////////////////////////////////////////////

        DrawCircleV(ballPosition2, 50, ballColor2);

        DrawCircleV(ballposition1, 50, ballColor1);

        ballPosition2 = GetMousePosition();
       
        /////////////////////////////////////////////////////////////

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
    UnloadTexture(backestGround);
    UnloadTexture(background);   
    UnloadTexture(midground);  
    UnloadTexture(middestGround);
    UnloadTexture(foreGround);   
   
    UnloadMusicStream(music);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}