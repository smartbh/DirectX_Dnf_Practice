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
	//창크기에 맞춰서 배경 충돌체 위치조정;
	bgCol->scale = Vector2(app.GetWidth() * 3.0f, 20.0f);
	//bgCol->SetWorldPos(Vector2(0.0f, -app.GetHalfHeight() + 50.0f));
	
	/*ImGui::Text("FPS : %d", TIMER->GetFramePerSecond());

	if (ImGui::Button("vSync"))
	{
		cout << app.vSync << endl;
		app.vSync = !app.vSync;
	}*/
	player->printPlState();
	player->getPlDir();
	
	//ImGui::Text("%s", player->printPlState());
	
	if (INPUT->KeyPress(VK_RIGHT))
	{
		//1초에 100픽셀 움직여라
		bg1->uv.x += DELTA / bg1->scale.x * 50.0f;
		bg1->uv.z += DELTA / bg1->scale.x * 50.0f;

		bg2->uv.x += DELTA / bg2->scale.x * 100.0f;
		bg2->uv.z += DELTA / bg2->scale.x * 100.0f;

		player->getCol()->MoveWorldPos(RIGHT * 200.0f * DELTA);
		bgCol->MoveWorldPos(RIGHT * 200.0f * DELTA);
		CAM->position += RIGHT * 200.0f * DELTA;
	}
	else if (INPUT->KeyPress(VK_LEFT))
	{
		bg1->uv.x -= DELTA / bg1->scale.x * 50.0f;
		bg1->uv.z -= DELTA / bg1->scale.x * 50.0f;

		bg2->uv.x -= DELTA / bg2->scale.x * 100.0f;
		bg2->uv.z -= DELTA / bg2->scale.x * 100.0f;

		player->getCol()->MoveWorldPos(LEFT * 200.0f * DELTA);
		bgCol->MoveWorldPos(LEFT * 200.0f * DELTA);
		CAM->position += LEFT * 200.0f * DELTA;
	}
	if (INPUT->KeyPress(VK_RIGHT) && INPUT->KeyPress(VK_LSHIFT))//달리기
	{
		bg1->uv.x += DELTA / bg1->scale.x * 200.0f;
		bg1->uv.z += DELTA / bg1->scale.x * 200.0f;

		bg2->uv.x += DELTA / bg2->scale.x * 300.0f;
		bg2->uv.z += DELTA / bg2->scale.x * 300.0f;

		player->getCol()->MoveWorldPos(RIGHT * 1000.0f * DELTA);
		bgCol->MoveWorldPos(RIGHT * 1000.0f * DELTA);
		CAM->position += RIGHT * 1000.0f * DELTA;
	}
	else if (INPUT->KeyPress(VK_LEFT) && INPUT->KeyPress(VK_LSHIFT)) {
		bg1->uv.x -= DELTA / bg1->scale.x * 200.0f;
		bg1->uv.z -= DELTA / bg1->scale.x * 200.0f;

		bg2->uv.x -= DELTA / bg2->scale.x * 300.0f;
		bg2->uv.z -= DELTA / bg2->scale.x * 300.0f;

		player->getCol()->MoveWorldPos(LEFT * 1000.0f * DELTA);
		bgCol->MoveWorldPos(LEFT * 1000.0f * DELTA);
		CAM->position += LEFT * 1000.0f * DELTA;
	}
	if (INPUT->KeyDown('Z'))//공격
	{
		if(player->getPlAttackCount() < 3 && player->getPlState() == PLSTATE::ATTACK)
			player->getCol()->SetWorldPosX(player->getCol()->GetWorldPos().x + 5.0f);
	}

	//맵 이동범위 제한
	//player->getCol()->SetWorldPosX(Utility::Saturate(player->getCol()->GetWorldPos().x, 0.0f, 1000.0f));
	//CAM->position.x = Utility::Saturate(CAM->position.x, 0.0f, 100.0f);
	

	bg1->Update();
	bg2->Update();
	bgCol->Update();
	player->Update();
	boss->Update();

}

void Main::LateUpdate()
{
	if (bgCol->Intersect(player->getCol()->GetWorldPos())) //땅이랑 충돌시
	{
		player->getCol()->SetWorldPosY(bgCol->GetWorldPos().y);
		player->setPlGravity(0.0f);

		if (player->getPlState() == PLSTATE::JUMP)
		{
			player->setPlState(PLSTATE::STAND);
		}

		player->Update();
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