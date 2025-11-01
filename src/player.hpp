#pragma once

#include <raylib.h>
class Player
{
public:
    void Init(float x, float y, int w, int h);
    void Proccess();
    void Draw();
    void SetPosition(float x, float y);
    Vector2 GetPosition() { return {(float)x, (float)y}; }
    void Jump();

private:
    float x, y;
    int w, h;
    float gravity = 1.0f;
};