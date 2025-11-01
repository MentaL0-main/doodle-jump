#include "player.hpp"
#include <raylib.h>

void Player::Init(float x, float y, int w, int h)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

void Player::Proccess()
{
    if (IsKeyDown(KEY_LEFT))
        x--;
    if (IsKeyDown(KEY_RIGHT))
        x++;

    if (gravity < 0)
    {
        static int timer = 0;
        if (timer >= 100)
        {
            timer = 0;
            gravity = -gravity;
        }
        ++timer;
    }

    y += gravity;
}

void Player::Draw()
{
    DrawRectangle(x, y, w, h, YELLOW);
    DrawRectangleLines(x, y, w, h, BLACK);
}

void Player::SetPosition(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Player::Jump()
{
    gravity = -gravity;
}