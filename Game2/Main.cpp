#include "stdafx.h"
#include "Main.h"

void Main::Init()
{
	bg1 = new ObImage(L"bg_1.png");
	bg1->scale = Vector2 (1600.0f, 900.0f ) * 1.5;
	bg1->space = SPACE::SCREEN;
	

	bg2 = new ObImage(L"bg_2_fix.png");
	bg2->scale = Vector2(1344.0f, 274.0f) * 1.5f;
	bg2->SetWorldPosY(-500.0f + 100.0f);
	bg2->space = SPACE::SCREEN;

	bgCol = new ObRect();
	bgCol->scale = Vector2(app.GetWidth(), 20.0f);
	bgCol->isFilled = false;
	bgCol->pivot = OFFSET_T;
	bgCol->SetWorldPos(Vector2(0.0f, -app.GetHalfHeight() + 50.0f)); // -226.0f
	bgCol->collider = COLLIDER::RECT;

	player = new DnFPlayer();
	boss = new bossFem();

}

void Main::Release()
{

}

void Main::Update()
{	
	//âũ�⿡ ���缭 ��� �浹ü ��ġ����;
	bgCol->scale = Vector2(app.GetWidth() * 3.0f, 20.0f);
	//bgCol->SetWorldPos(Vector2(0.0f, -app.GetHalfHeight() + 50.0f));
	
	/*ImGui::Text("FPS : %d", TIMER->GetFramePerSecond());

	if (ImGui::Button("vSync"))
	{
		cout << app.vSync << endl;
		app.vSync = !app.vSync;
	}*/
	cout << "boss x : " <<boss->getCol()->GetWorldPos().x << endl;
	cout << "boss y : " << boss->getCol()->GetWorldPos().y << endl;
	boss->setBossDir(player->getCol()->GetWorldPos());
	//player->printPlState();
	//player->getPlDir();
	
	//ImGui::Text("%s", player->printPlState());
	
	if (INPUT->KeyPress(VK_RIGHT))//player->getPlState() == PLSTATE::WALK_R
	{
		if (player->getPlState() == PLSTATE::WALK_R ||
			player->getPlState() == PLSTATE::JUMP)
		{
			//1�ʿ� 100�ȼ� ��������
			bg1->uv.x += DELTA / bg1->scale.x * 50.0f;
			bg1->uv.z += DELTA / bg1->scale.x * 50.0f;

			bg2->uv.x += DELTA / bg2->scale.x * 100.0f;
			bg2->uv.z += DELTA / bg2->scale.x * 100.0f;

			player->getCol()->MoveWorldPos(RIGHT * 200.0f * DELTA);
			bgCol->MoveWorldPos(RIGHT * 200.0f * DELTA);
			CAM->position += RIGHT * 200.0f * DELTA;
		}

	}
	else if (INPUT->KeyPress(VK_LEFT))
	{
		if (player->getPlState() == PLSTATE::WALK_L ||
			player->getPlState() == PLSTATE::JUMP)
		{
			bg1->uv.x -= DELTA / bg1->scale.x * 50.0f;
			bg1->uv.z -= DELTA / bg1->scale.x * 50.0f;

			bg2->uv.x -= DELTA / bg2->scale.x * 100.0f;
			bg2->uv.z -= DELTA / bg2->scale.x * 100.0f;

			player->getCol()->MoveWorldPos(LEFT * 200.0f * DELTA);
			bgCol->MoveWorldPos(LEFT * 200.0f * DELTA);
			CAM->position += LEFT * 200.0f * DELTA;
		}

	}
	if (player->getPlState() == PLSTATE::RUN_R)//�޸��� INPUT->KeyPress(VK_RIGHT) && INPUT->KeyPress(VK_LSHIFT)
	{
		bg1->uv.x += DELTA / bg1->scale.x * 200.0f;
		bg1->uv.z += DELTA / bg1->scale.x * 200.0f;

		bg2->uv.x += DELTA / bg2->scale.x * 300.0f;
		bg2->uv.z += DELTA / bg2->scale.x * 300.0f;

		player->getCol()->MoveWorldPos(RIGHT * 1000.0f * DELTA);
		bgCol->MoveWorldPos(RIGHT * 1000.0f * DELTA);
		CAM->position += RIGHT * 1000.0f * DELTA;
	}
	else if (player->getPlState() == PLSTATE::RUN_L) {
		bg1->uv.x -= DELTA / bg1->scale.x * 200.0f;
		bg1->uv.z -= DELTA / bg1->scale.x * 200.0f;

		bg2->uv.x -= DELTA / bg2->scale.x * 300.0f;
		bg2->uv.z -= DELTA / bg2->scale.x * 300.0f;

		player->getCol()->MoveWorldPos(LEFT * 1000.0f * DELTA);
		bgCol->MoveWorldPos(LEFT * 1000.0f * DELTA);
		CAM->position += LEFT * 1000.0f * DELTA;
	}
	if (INPUT->KeyDown('Z'))//����
	{
		if(player->getPlAttackCount() < 3 && player->getPlState() == PLSTATE::ATTACK)
			if(player->getPlDir() == RIGHT)
				player->getCol()->SetWorldPosX(player->getCol()->GetWorldPos().x + 5.0f);
			else if(player->getPlDir() == LEFT)
				player->getCol()->SetWorldPosX(player->getCol()->GetWorldPos().x - 5.0f);
	}
	if (INPUT->KeyDown('A')) //��ų ����
	{
		//float getTickTime = 10.0f;
		//if (getTickTime > 0.0f)
		//{
			if (player->getPlDir() == RIGHT)
			{
				for (int i = 0; i < 1000; i++)
				{
					//player->getCol()->SetWorldPosX(player->getCol()->GetWorldPos().x + 100.0f);
					player->getCol()->MoveWorldPos(RIGHT * 10.0f * DELTA);
					bgCol->MoveWorldPos(RIGHT * 10.0f * DELTA);
					CAM->position += RIGHT * 10.0f * DELTA;
				}

			}
			else if (player->getPlDir() == LEFT)
			{
				for (int i = 0; i < 1000; i++)
				{
					player->getCol()->MoveWorldPos(LEFT * 10.0f * DELTA);
					bgCol->MoveWorldPos(LEFT * 10.0f * DELTA);
					CAM->position += LEFT * 10.0f * DELTA;
				}
			}
		//}

	}

	//�� �̵����� ����
	//player->getCol()->SetWorldPosX(Utility::Saturate(player->getCol()->GetWorldPos().x, 0.0f, 1000.0f));
	//CAM->position.x = Utility::Saturate(CAM->position.x, 0.0f, 100.0f);
	
	//cout << "player x : " << player->getCol()->GetWorldPos().x << endl;
	//cout << "player y : " << player->getCol()->GetWorldPos().y << endl;

	bg1->Update();
	bg2->Update();
	bgCol->Update();
	player->Update();
	boss->Update();

}

void Main::LateUpdate()
{
	if (bgCol->Intersect(player->getCol()->GetWorldPos())) //���̶� �浹��
	{
		player->getCol()->SetWorldPosY(bgCol->GetWorldPos().y);
		player->setPlGravity(0.0f);

		if (player->getPlState() == PLSTATE::JUMP)
		{
			player->setPlState(PLSTATE::STAND);
		}

		player->Update();
	}

	//if (bgCol->Intersect(boss->getCol()->GetWorldPos()))
	//{
	//	boss->getCol()->SetWorldPosY(bgCol->GetWorldPos().y);
	//	boss->setBSGravity(0.0f);
	//}

	if (boss->getCol()->Intersect(player->getWeaponCol()))
	{
		boss->TakeDamage(1000.0f);
		boss->printBossHp();
		player->playerWeaponColoff();
	}
}

void Main::Render()
{
	bg1->Render();
	bg2->Render();
	bgCol->Render();
	player->Render();
	boss->Render();
}

void Main::ResizeScreen()
{
}

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prevInstance, LPWSTR param, int command)
{
	app.SetAppName(L"Game2");
	app.SetInstance(instance);
	app.InitWidthHeight(1400.0f, 1000.0f);
	Main* main = new Main();
	int wParam = (int)WIN->Run(main);
	WIN->DeleteSingleton();
	SafeDelete(main);
	return wParam;
}