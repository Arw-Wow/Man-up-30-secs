#pragma once

#include "Scene.h"

extern Scene* game_scene;
extern Scene* menu_scene;

class SceneManager
{
public:

	enum SceneType {
		Menu, Game, 
	};

public:

	SceneManager() = default;
	~SceneManager() = default;

	void set_current_scene(Scene* scene);

	void switch_to(SceneType type);

	void on_input(ExMessage& msg);

	void on_update(int delta);

	void on_draw();

private:

	Scene* current_scene = nullptr;

};

