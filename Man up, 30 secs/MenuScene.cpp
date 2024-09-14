#include "MenuScene.h"

void MenuScene::on_enter()
{	
	std::ifstream inFile;
	inFile.open("data.txt");

	inFile >> max_score;
	max_score /= 1000.0;

    mciSendString("play menu_scene_enter from 0", NULL, 0, NULL);
}

void MenuScene::on_input(ExMessage& msg)
{
    switch (msg.message)
    {
    case WM_KEYDOWN:
        switch (msg.vkcode)
        {
        case VK_RETURN:	// 按回车进入游戏场景
            scene_manager->switch_to(SceneManager::SceneType::Game);
            mciSendString("play menu_scene_enter from 0", NULL, 0, NULL);
            break;
        case VK_ESCAPE:	// 按ESC退出游戏
            is_running = false;
            break;

        default:
            break;
        }
        break;
    default:
        break;
    }
}

void MenuScene::on_update(int delta)
{

}

void MenuScene::on_draw()
{
	settextcolor(WHITE);

	settextstyle(30, 15, "宋体");
	char max_score_text[256] = { 0 };
	sprintf_s(max_score_text, sizeof(max_score_text), "最高存活时间：%.1lf s", max_score);
	outtextxy(10, 10, max_score_text);

    settextstyle(80, 40, "华文琥珀");
    outtextxy(getwidth() / 2 - textwidth("是男人就活过30秒") / 2, getheight() / 2 - textheight("是男人就活过30秒") / 2 - 50, "是男人就活过30秒");
    settextstyle(40, 20, "华文琥珀");
    outtextxy(getwidth() / 2 - textwidth("按回车进入游戏") / 2, getheight() / 2 - textheight("按回车进入游戏") / 2 + 250, "按回车进入游戏");
    outtextxy(getwidth() / 2 - textwidth("按ESC退出游戏") / 2, getheight() / 2 - textheight("按ESC退出游戏") / 2 + 300, "按ESC退出游戏");
}

void MenuScene::on_exit()
{

}
