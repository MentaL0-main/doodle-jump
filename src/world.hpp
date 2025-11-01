#pragma once

#include <deque>
#include <raylib.h>
#include <random>

class World
{
public:
    void Init(unsigned int &windowWidth, unsigned int &windowHeight);
    void Proccess(unsigned int &levelHeight, unsigned int &windowWidth, unsigned int &windowHeight);
    void Draw();
    Vector2 GetFirstPlatform() const { return {platforms[platforms.size()-1]}; }
    bool GetCollision(Vector2 pos);

private:
    std::deque<Vector2> platforms;
    std::random_device rd;

    Vector2 GeneratePlatform(unsigned int &windowWidth, unsigned int y)
    {
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(0, windowWidth-50);
        unsigned short x = dis(gen);

        return {(float)x, (float)y};
    }
};