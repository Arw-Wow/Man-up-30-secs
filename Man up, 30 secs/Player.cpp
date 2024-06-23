#include "Player.h"

Player::Player()
{
	is_move_up = false;
	is_move_down = false;
	is_move_left = false;
	is_move_right = false;

	m_position.x = (int)(1280 / 2 - 10 / 2);
	m_position.y = (int)(720 / 2 - 10 / 2);

	m_collision_box.set_position(m_position);
	m_collision_box.set_size(m_width, m_height);
}

void Player::on_input(const ExMessage& msg)
{
	switch (msg.message)
	{
	case WM_KEYDOWN:
		switch (msg.vkcode)
		{
		case 0x57:	// w
			is_move_up = true;
			break;
		case 0x53:	// s
			is_move_down = true;
			break;
		case 0x41:	// a
			is_move_left = true;
			break;
		case 0x44:	// d
			is_move_right = true;
			break;
		default:
			break;
		}
		break;

	case WM_KEYUP:
		switch (msg.vkcode)
		{
		case 0x57:	// w
			is_move_up = false;
			break;
		case 0x53:	// s
			is_move_down = false;
			break;
		case 0x41:	// a
			is_move_left = false;
			break;
		case 0x44:	// d
			is_move_right = false;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}
}

void Player::on_update(int delta)
{
	double x_direction_change = is_move_right - is_move_left;
	double y_direction_change = is_move_down - is_move_up;
	// 左下为正方向

	double change_length = sqrt(x_direction_change * x_direction_change + y_direction_change * y_direction_change);

	if (change_length <= 0)	// 防止被除数为0
		return;

	double x_move_change = (x_direction_change / change_length) * m_speed;
	double y_move_change = (y_direction_change / change_length) * m_speed;


	m_position.x += (int)x_move_change;
	m_position.y += (int)y_move_change;

	if (check_if_out_of_window())	// 超出边界就复位
	{
		m_position.x -= (int)x_move_change;
		m_position.y -= (int)y_move_change;
	}

	m_collision_box.set_position(m_position);

}

void Player::on_draw()
{
	draw_player();
}

bool Player::check_if_out_of_window()
{
	return (m_position.x + m_width > getwidth() || m_position.x < 0 ||
		m_position.y + m_height > getheight() || m_position.y < 0);
}

const CollisionBox& Player::get_collision_box()
{
	return m_collision_box;
}

void Player::set_position(int x, int y)
{
	m_position.x = x;
	m_position.y = y;
}

void Player::restart()
{
	is_move_up = false;
	is_move_down = false;
	is_move_left = false;
	is_move_right = false;

	set_position((int)(1280 / 2 - 10 / 2), (int)(720 / 2 - 10 / 2));

	m_collision_box.set_position(m_position);
	m_collision_box.set_size(m_width, m_height);
}

void Player::draw_player()
{
	setfillcolor(YELLOW);
	setlinecolor(YELLOW);
	solidrectangle(m_position.x, m_position.y, m_position.x + m_width, m_position.y + m_height);
}
