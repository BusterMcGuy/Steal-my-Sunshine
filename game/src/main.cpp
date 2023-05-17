#include "rlImGui.h"







int main(void)
{

    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Emory's Game Yay");

    // For consistencies sake I added a set target FPS function
    // This will help in future development to keep things consistent
    SetTargetFPS(60);

    ////////////////////

    // Creating background

    //Below are my load texture functions that turn the background images into textures that are later drawn
    //Textures have been easy to work with
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

    // Music //

    // There are a few music focused functions here

    //The first initializes and audio device to be used
        InitAudioDevice();
        // This loads the music to a stream for calling lter
        Music music = LoadMusicStream("../game/assets/audio/Chill.mp3");
        music.looping = true;
        // This starts the music
        PlayMusicStream(music);
        float volume = 1.0f;
        bool pause = false;

        
        /////////////
       
        //Drawing textures for background function
        // This includes the texture, the position, and the color if I would like one
        void DrawTexture(Texture2D texture, int posX, int posY, Color tint);

        //Balls

        Vector2 ballposition1 = { 500.0f, 500.0f };

        Vector2 ballPosition2 = { 100.0f, 100.0f };

        bool collison = false;

        Color ballColor1 = DARKBROWN;

        Color ballColor2 = DARKGREEN;

        //////////////
     

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        int getFps(void);

        // Background updating and etc...

        scrollingBackest -= 0.3f;
        scrollingBack -= 0.4f;
        scrollingMid -= 0.5f;
        scrollingMiddest -= 0.7f;
        scrollingForeGround -= 1.0f;

        if (scrollingBackest <= -backestGround.width * 2) scrollingBackest = 0;
        if (scrollingBack <= -background.width * 2) scrollingBack = 0;
        if (scrollingMid <= -midground.width * 2) scrollingMid = 0;
        if (scrollingMiddest <= -middestGround.width * 2) scrollingMiddest = 0;
        if (scrollingForeGround <= -foreGround.width * 2) scrollingForeGround = 0;

        
        ///////////////
        // All these images are drawn twice to provide the effect of scrolling
        DrawTextureEx(backestGround, (Vector2 { scrollingBackest, 20 }), 0.0f, 2.0f, WHITE);
        DrawTextureEx(backestGround, (Vector2 { backestGround.width * 2 + scrollingBackest, 20 }), 0.0f, 2.0f, WHITE);

        // Draw midground image twice
        DrawTextureEx(background, (Vector2 { scrollingBack, 20 }), 0.0f, 2.0f, WHITE);
        DrawTextureEx(background, (Vector2 { background.width * 2 + scrollingBack, 20 }), 0.0f, 2.0f, WHITE);

        DrawTextureEx(midground, (Vector2 { scrollingMid, 30 }), 0.0f, 2.0f, WHITE);
        DrawTextureEx(midground, (Vector2 { midground.width * 2 + scrollingMid, 30 }), 0.0f, 2.0f, WHITE);

        // Draw midground image twice
        DrawTextureEx(middestGround, (Vector2 { scrollingMiddest, 80 }), 0.0f, 2.0f, WHITE);
        DrawTextureEx(middestGround, (Vector2 { middestGround.width * 2 + scrollingMiddest, 80 }), 0.0f, 2.0f, WHITE);
       
        // Draw foreground image twice
        DrawTextureEx(foreGround, (Vector2 { scrollingForeGround, 80 }), 0.0f, 2.0f, WHITE);
        DrawTextureEx(foreGround, (Vector2 { foreGround.width * 2 + scrollingForeGround, 80 }), 0.0f, 2.0f, WHITE);



        // Drawing some fun text
        DrawText("I LOVE MAC DEMARCO", 100, 30, 20, RED);
        

        //Update music

        UpdateMusicStream(music);

        /////////////////////////////////////////////////////////////

        DrawCircleV(ballPosition2, 50, ballColor2);

        DrawCircleV(ballposition1, 50, ballColor1);
        // This is how I attached the ball to my mouse
        ballPosition2 = GetMousePosition();
       
        /////////////////////////////////////////////////////////////
        // Checking collison between balls followed by an if statement to to show they collide
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
    // Unkoading all my textures
    UnloadTexture(backestGround);
    UnloadTexture(background);   
    UnloadTexture(midground);  
    UnloadTexture(middestGround);
    UnloadTexture(foreGround);   
   // Unloading music
    UnloadMusicStream(music);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}