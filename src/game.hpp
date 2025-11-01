#pragma once

#include "player.hpp"
#include "world.hpp"
#include <raylib.h>

class Game
{
public: void Start();
private:
    unsigned int windowWidth = 400;
    unsigned int windowHeight = 700;
    float delta = 0.0f;

    unsigned int levelHeight = 0; // Score

    World world;
    Camera2D camera;
    Player player;

    void Init();
    void InitCamera();
    void MainLoop();
    void CleanUp();
};