#include <iostream>
#include <easyx.h>
#include <time.h>

#include <vector>

#include "Player.h"
#include "Enemy.h"
#include "Scene.h"
#include "GameScene.h"
#include "MenuScene.h"
#include "SceneManager.h"

constexpr int FPS = 144;

Player* player = nullptr;
Scene* game_scene = nullptr;
Scene* menu_scene = nullptr;
SceneManager* scene_manager = nullptr;
std::vector <Enemy*> enemy_list;

bool is_running;

/*--------------------------------------资源---------------------------------------------------*/
#pragma comment(lib, "Winmm.lib")

void load_resource()
{
	mciSendString("open res/game_scene_music.mp3 alias game_scene_music", NULL, 0, NULL);
	mciSendString("open res/menu_scene_enter.mp3 alias menu_scene_enter", NULL, 0, NULL);
	mciSendString("open res/player_die.mp3 alias player_die", NULL, 0, NULL);
}
/*---------------------------------------------------------------------------------------------*/

int main()
{

	srand(time(NULL));

	initgraph(1280, 720);
	setbkcolor(BLACK);

	load_resource();

	player = new Player();
	game_scene = new GameScene();
	menu_scene = new MenuScene();
	scene_manager = new SceneManager();
	scene_manager->set_current_scene(menu_scene);
	
	ExMessage msg;

	BeginBatchDraw();

	is_running = true;
	while (is_running)
	{
		clock_t frame_start_time = clock();
		
		// input

		while (peekmessage(&msg))
		{
			scene_manager->on_input(msg);
		}

		// update

		static clock_t last_tick_time = clock();
		clock_t current_tick_time = clock();
		scene_manager->on_update(int(current_tick_time - last_tick_time));
		last_tick_time = current_tick_time;

		// draw

		cleardevice();
		scene_manager->on_draw();
		FlushBatchDraw();

		// fps

		clock_t frame_end_time = clock();
		if (frame_end_time - frame_start_time < 1000.0 / FPS)
		{
			Sleep(1000.0 / FPS - (frame_end_time - frame_start_time));
		}

	}

	EndBatchDraw();

	// 释放资源

	delete player;
	delete game_scene;
	delete scene_manager;
	for (Enemy* enemy : enemy_list)
		delete enemy;

	return 0;
}

// 1116行