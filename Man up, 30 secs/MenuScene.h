#pragma once

#include <fstream>

#include "Scene.h"
#include "SceneManager.h"

extern SceneManager* scene_manager;
extern bool is_running;

class MenuScene :
    public Scene
{
public:

	MenuScene() = default;
	~MenuScene() = default;

	void on_enter() override;

	void on_input(ExMessage& msg) override;

	void on_update(int delta) override;

	void on_draw() override;

	void on_exit() override;

private:

	int max_score = 0;

};

