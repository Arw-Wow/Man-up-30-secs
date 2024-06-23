#pragma once

#include <corecrt_math.h>
#include <easyx.h>
#include <iostream>

#include "CollisionBox.h"
#include "Vector2.h"

class Player
{
public:

	Player();

	~Player() = default;

	void on_input(const ExMessage& msg);

	void on_update(int delta);

	void on_draw();

	bool check_if_out_of_window();

	const CollisionBox& get_collision_box();

	void set_position(int x, int y);

	void restart();

private:

	void draw_player();

private:

	Vector2 m_position;
	int m_width = 10;
	int m_height = 10;

	CollisionBox m_collision_box;

	double m_speed = 3.5;

	bool is_move_up = false;
	bool is_move_down = false;
	bool is_move_left = false;
	bool is_move_right = false;

};

