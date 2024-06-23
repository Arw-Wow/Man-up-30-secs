#pragma once

#include <iostream>
#include <time.h>
#include <fstream>

#include <vector>

#include "Scene.h"
#include "SceneManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Timer.h"

extern SceneManager* scene_manager;
extern Player* player;
extern std::vector <Enemy*> enemy_list;

class GameScene :
    public Scene
{
public:

	GameScene();

	~GameScene() = default;

	void on_enter() override;

	void on_input(ExMessage& msg) override;

	void on_update(int delta) override;

	void on_draw() override;

	void game_lose();

	void on_exit() override;

private:

	Timer timer_enemy_generation;
	bool can_enemy_generate = false;

	clock_t begin_time;
	clock_t alive_time;

};

