#include "stdafx.h"
#include "Main.h"

void Main::Init()
{
	bg1 = new ObImage(L"bg_1.png");
	bg1->scale = Vector2 (1600.0f, 900.0f ) * 1.5;
	bg1->space = SPACE::SCREEN;
	

	bg2 = new ObImage(L"bg_2_fix.png");
	bg2->scale = Vector2(1344.0f, 274.0f) * 1.5f;
	bg2->SetWorldPosY(-500.0f + 274.0f);
	bg2->space = SPACE::SCREEN;

	bgCol = new ObRect();
	bgCol->scale = Vector2(app.GetWidth(), 20.0f);
	bgCol->isFilled = false;
	bgCol->SetWorldPos(Vector2(0.0f, -226.0f));
	bgCol->collider = COLLIDER::RECT;

	player = new DnFPlayer();

}

void Main::Release()
{

}

void Main::Update()
{	
	//창크기에 맞춰서 배경 충돌체 위치조정;
	bgCol->scale = Vector2(app.GetWidth(), 20.0f);
	bgCol->SetWorldPos(Vector2(0.0f, -app.GetHalfHeight() + 50.0f));
	
	/*ImGui::Text("FPS : %d", TIMER->GetFramePerSecond());

	if (ImGui::Button("vSync"))
	{
		cout << app.vSync << endl;
		app.vSync = !app.vSync;
	}*/
	bg1->Update();
	bg2->Update();
	bgCol->Update();
	player->Update();

}

void Main::LateUpdate()
{
	if (bgCol->Intersect(player->getCol()->GetWorldPos())) //땅이랑 충돌시
	{
		player->getCol()->SetWorldPosY(bgCol->GetWorldPos().y + 30.0f);
	}
}

void Main::Render()
{
	bg1->Render();
	bg2->Render();
	bgCol->Render();
	player->Render();
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