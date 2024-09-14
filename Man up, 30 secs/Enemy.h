#pragma once

#include <easyx.h>
#include <time.h>

#include "CollisionBox.h"
#include "Vector2.h"

class Enemy
{
public:

	Enemy();

	~Enemy() = default;

	void on_update(int delta);

	void on_draw();

	bool is_out_of_window() const;

	void set_invalid();

	bool get_is_invalid() const;

	const CollisionBox& get_collision_box();

private:

	Vector2 m_position;
	int m_width;
	int m_height;

	CollisionBox m_collision_box;

	double m_speed = 2.0;

	Vector2 m_velocity;

	bool is_invalid = false;

};

