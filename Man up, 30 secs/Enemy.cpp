#include "Enemy.h"

Enemy::Enemy()
{
    // initialize the enemy's brithplace and velocity

    int birth_direction = rand() % 4;

    double x_component = 0;
    double y_component = 0;

    switch (birth_direction)
    {
    case 0:	// up
        m_position.x = rand() % (getwidth() - m_width);
        m_position.y = 0 - m_height;
        x_component = (rand() % 200 - 100) / 100.0;	// -1.00 ~ 1.00
        y_component = (rand() % 80 + 20) / 100.0;	//  0.20 ~ 1.00
        break;
    case 1:	// down
        m_position.x = rand() % (getwidth() - m_width);
        m_position.y = getheight();
        x_component = (rand() % 200 - 100) / 100.0;	//  -1.00 ~ 1.00
        y_component = -(rand() % 80 + 20) / 100.0;	// -1.00 ~ -0.20
        break;
    case 2:	// left
        m_position.x = 0 - m_width;
        m_position.y = rand() % (getheight() - m_height);
        x_component = (rand() % 80 + 20) / 100.0;	//  0.20 ~ 1.00
        y_component = (rand() % 200 - 100) / 100.0;	// -1.00 ~ 1.00
        break;
    case 3:	// right
        m_position.x = getwidth();
        m_position.y = rand() % (getheight() - m_height);
        x_component = -(rand() % 80 + 20) / 100.0;	// -1.00 ~ -0.20
        y_component = (rand() % 200 - 100) / 100.0;	//  -1.00 ~ 1.00
        break;

    default:
        m_position.x = 0;
        m_position.y = 0;
        break;
    }

    m_velocity.x = x_component * m_speed;
    m_velocity.y = y_component * m_speed;

    m_collision_box.set_position(m_position);
    m_collision_box.set_size(m_width, m_height);
}

void Enemy::on_update(int delta)
{
    m_position.x += m_velocity.x;
    m_position.y += m_velocity.y;

    m_collision_box.set_position(m_position);	// update the collision_box's position

    if (is_out_of_window())
        set_invalid();
}

void Enemy::on_draw()
{
    setfillcolor(RED);
    setlinecolor(RED);
    fillrectangle(m_position.x, m_position.y, m_position.x + m_width, m_position.y + m_height);
}

bool Enemy::is_out_of_window() const
{
    return (m_position.x > getwidth() || m_position.x + m_width < 0 ||
        m_position.y > getheight() || m_position.y + m_height < 0);
}

void Enemy::set_invalid()
{
    is_invalid = true;
}

bool Enemy::get_is_invalid() const
{
    return is_invalid;
}

const CollisionBox& Enemy::get_collision_box()
{
    return m_collision_box;
}
