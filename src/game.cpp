#include "game.hpp"
#include <raylib.h>
#include <string>

void Game::Start()
{
    Init();
    InitCamera();
    MainLoop();
    CleanUp();
}

void Game::Init()
{
    InitWindow(windowWidth, windowHeight, "Doodle Jump");
    world.Init(windowWidth, windowHeight);
    Vector2 pos = world.GetFirstPlatform();
    player.Init(pos.x + (float)25 / 2, pos.y-60, 25, 50);
    SetTargetFPS(120);
}

void Game::InitCamera()
{
    camera.offset = {0.0f, 0.0f};
    camera.rotation = 0.0f;
    camera.target = {0.0f, 0.0f};
    camera.zoom = 1.0f;
}

void Game::MainLoop()
{
    while (!WindowShouldClose())
    {
        delta = GetFrameTime();
        world.Proccess(levelHeight, windowWidth, windowHeight);
        player.Proccess();
        camera.target.y = player.GetPosition().y - windowHeight + 70;

        if (world.GetCollision(player.GetPosition())) player.Jump();

        BeginDrawing();
        BeginMode2D(camera);
            ClearBackground(RAYWHITE);
            world.Draw();
            player.Draw();
        EndMode2D();
            DrawText(std::to_string(levelHeight).c_str(), 25, 25, 50, YELLOW);
        EndDrawing();
    }
}

void Game::CleanUp()
{
    CloseWindow();
}