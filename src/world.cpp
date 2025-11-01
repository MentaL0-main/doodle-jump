#include "world.hpp"
#include <raylib.h>

void World::Init(unsigned int &windowWidth, unsigned int &windowHeight)
{
    for (int i = 0; i < 10; ++i)
        platforms.push_back(GeneratePlatform(windowWidth, i*(windowHeight / 10)));
}

void World::Proccess(unsigned int &levelHeight, unsigned int &windowWidth, unsigned int &windowHeight)
{

}

void World::Draw()
{
    for (auto &platform : platforms)
        DrawRectangle(platform.x, platform.y, 50, 5, BLACK);
}

bool World::GetCollision(Vector2 pos)
{
    for (auto &platform : platforms)
        if (pos.x >= platform.x && pos.x <= platform.x+50 && pos.y+51 == platform.y)
            return true;

    return false;
}