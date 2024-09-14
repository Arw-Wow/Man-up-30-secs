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
	bool can_enemy_generate = false;	// timer的callback只会改变这个布尔值，具体要干什么可以之后再说，从而实现解耦合。
	const int original_interval_enemy_generate = 500;
	int interval_enemy_generate = 500;

	Timer timer_speed_up_enemy_generation;
	bool can_speed_up_enemy_generation = false;

	clock_t begin_time;
	clock_t alive_time;

};

