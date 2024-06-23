#include "GameScene.h"

GameScene::GameScene()
{
	timer_enemy_generation.set_interval(200);
	timer_enemy_generation.set_loop(true);
	timer_enemy_generation.set_shot_callback(
		[&]() {
			can_enemy_generate = true;
		}
	);

}

void GameScene::on_enter()
{
	timer_enemy_generation.restart();
	timer_enemy_generation.resume();

	player->restart();

	begin_time = clock();

	mciSendString("play game_scene_music repeat from 0", NULL, 0, NULL);
}

void GameScene::on_input(ExMessage& msg)
{
	player->on_input(msg);
}

void GameScene::on_update(int delta)
{
	player->on_update(delta);

	if (can_enemy_generate)
	{
		Enemy* enemy = new Enemy();
		enemy_list.push_back(enemy);
		can_enemy_generate = false;
	}

	for (Enemy* enemy : enemy_list)
	{
		enemy->on_update(delta);
	}

	// 清除超过边界的敌人
	for (int i = 0; i < enemy_list.size(); i++)
	{
		if (enemy_list[i]->get_is_invalid())
		{
			delete enemy_list[i];
			std::swap(enemy_list[i], enemy_list.back());
			enemy_list.pop_back();

			std::cout << "enemy delete!" << std::endl;
		}
	}

	for (Enemy* enemy : enemy_list)
	{
		if (enemy->get_collision_box().check_if_collide(player->get_collision_box()))
		{
			game_lose();
			break;
		}
	}

	timer_enemy_generation.on_update(delta);
}

void GameScene::on_draw()
{
	// 绘制玩家

	player->on_draw();

	// 绘制敌人

	for (int i = 0; i < enemy_list.size(); i++)
	{
		enemy_list[i]->on_draw();
	}

	// 绘制当前得分
	alive_time = clock() - begin_time;
	char score_text[256] = { 0 };
	sprintf_s(score_text, sizeof(score_text), "存活时间：%ds", alive_time / 1000);
	settextstyle(18, 9, "宋体");
	settextcolor(WHITE);
	outtextxy(10, 10, score_text);
}

void GameScene::game_lose()
{
	mciSendString("play player_die from 0", NULL, 0, NULL);
	MessageBox(GetHWnd(), "你输了！", "提示", MB_OK);
	scene_manager->switch_to(SceneManager::SceneType::Menu);
}

void GameScene::on_exit()
{
	for (int i = 0; i < enemy_list.size(); i++)
		delete enemy_list[i];
	enemy_list.clear();

	mciSendString("stop game_scene_music", NULL, 0, NULL);

	std::ifstream inFile;
	inFile.open("data.txt");
	int max_score;	inFile >> max_score;

	if ((int)alive_time > max_score)
	{
		std::ofstream outFile;
		outFile.open("data.txt");
		outFile << alive_time << std::endl;
	}
}
