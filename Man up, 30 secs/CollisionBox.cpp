#include "CollisionBox.h"

CollisionBox::CollisionBox(int x, int y, int w, int h)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

CollisionBox::CollisionBox(const CollisionBox& other)
{
    x = other.x;
    y = other.y;
    w = other.w;
    h = other.h;
}

bool CollisionBox::check_if_collide(const CollisionBox& other) const
{
    return (x + w > other.x && x < other.x + other.w &&
        y + h > other.y && y < other.y + other.h);
}

void CollisionBox::set_position(int x, int y)
{
    this->x = x;
    this->y = y;
}

void CollisionBox::set_position(Vector2 pos)
{
    x = pos.x;
    y = pos.y;
}

void CollisionBox::set_size(int w, int h)
{
    this->w = w;
    this->h = h;
}

void CollisionBox::set_x(int val)
{
    x = val;
}

void CollisionBox::set_y(int val)
{
    y = val;
}

void CollisionBox::set_w(int val)
{
    w = val;
}

void CollisionBox::set_h(int val)
{
    h = val;
}
