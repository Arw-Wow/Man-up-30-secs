#pragma once

#include <easyx.h>

#include "Vector2.h"

class CollisionBox
{
public:
	
	CollisionBox(int x = 0, int y = 0, int w = 0, int h = 0);
	CollisionBox(const CollisionBox& other);

	~CollisionBox() = default;

	bool check_if_collide(const CollisionBox& other) const;

	void set_position(int x, int y);

	void set_position(Vector2 pos);

	void set_size(int w, int h);

	void set_x(int val);

	void set_y(int val);

	void set_w(int val);

	void set_h(int val);

private:

	int x;
	int y;
	int w;
	int h;

};

