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
        case VK_RETURN:	// ���س�������Ϸ����
            scene_manager->switch_to(SceneManager::SceneType::Game);
            mciSendString("play menu_scene_enter from 0", NULL, 0, NULL);
            break;
        case VK_ESCAPE:	// ��ESC�˳���Ϸ
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

	settextstyle(30, 15, "����");
	char max_score_text[256] = { 0 };
	sprintf_s(max_score_text, sizeof(max_score_text), "��ߴ��ʱ�䣺%.1lf s", max_score);
	outtextxy(10, 10, max_score_text);

    settextstyle(80, 40, "��������");
    outtextxy(getwidth() / 2 - textwidth("�����˾ͻ��30��") / 2, getheight() / 2 - textheight("�����˾ͻ��30��") / 2 - 50, "�����˾ͻ��30��");
    settextstyle(40, 20, "��������");
    outtextxy(getwidth() / 2 - textwidth("���س�������Ϸ") / 2, getheight() / 2 - textheight("���س�������Ϸ") / 2 + 250, "���س�������Ϸ");
    outtextxy(getwidth() / 2 - textwidth("��ESC�˳���Ϸ") / 2, getheight() / 2 - textheight("��ESC�˳���Ϸ") / 2 + 300, "��ESC�˳���Ϸ");
}

void MenuScene::on_exit()
{

}
