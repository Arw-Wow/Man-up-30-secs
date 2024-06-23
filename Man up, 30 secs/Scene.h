#pragma once

#include <easyx.h>

class Scene
{
public:

	Scene() = default;
	~Scene() = default;

	virtual void on_enter();

	virtual void on_input(ExMessage& msg);

	virtual void on_update(int delta);

	virtual void on_draw();

	virtual void on_exit();

private:


};

