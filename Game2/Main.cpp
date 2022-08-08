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

	//ui
	bossPortrait = new ObImage(L"boss_portrait.png");
	bossPortrait->scale = Vector2(264.0f, 256.0f);
	bossPortrait->SetWorldPos(Vector2(-app.GetHalfWidth() - 220.0f, 450.0f));
	bossPortrait->space = SPACE::SCREEN;

	bossHPbar = new ObRect();
	bossHPbar->scale = Vector2(1000.0f, 50.0f);
	bossHPbar->SetParentT(*bossPortrait);
	bossHPbar->SetLocalPosX(85.0f);
	bossHPbar->SetLocalPosY(50.0f);
	bossHPbar->color = Color(0.5f, 0.0f, 0.0f, 1.0f);
	bossHPbar->visible - false;
	bossHPbar->isFilled = true;
	bossHPbar->pivot = OFFSET_L;
	bossHPbar->space = SPACE::SCREEN;

	playerPortrait = new ObImage(L"player_portrait.png");
	playerPortrait->scale = Vector2(259.0f, 253.0f);
	playerPortrait->SetWorldPos(Vector2(-app.GetHalfWidth()-220.0f, -450.0f));
	playerPortrait->space = SPACE::SCREEN;

	playerHPbar = new ObRect();
	playerHPbar->scale = Vector2(1000.0f, 50.0f);
	playerHPbar->SetParentT(*playerPortrait);
	playerHPbar->SetLocalPosX(100.0f);
	playerHPbar->SetLocalPosY(-40.0f);
	playerHPbar->color = Color(0.5f, 0.0f, 0.0f, 1.0f);
	playerHPbar->visible = false;
	playerHPbar->isFilled = true;
	playerHPbar->pivot = OFFSET_L;
	playerHPbar->space = SPACE::SCREEN;

	blackBar = new ObImage(L"black_bar.png");
	blackBar->scale = Vector2(2000.0f, 500.0f);
	blackBar->SetWorldPos(Vector2(0.0f, 300.0f));
	blackBar->space = SPACE::SCREEN;
	blackBar->Update();

	blackBar2 = new ObImage(L"black_bar.png");
	blackBar2->scale = Vector2(2000.0f, 500.0f);
	blackBar2->SetWorldPos(Vector2(0.0f, -300.0f));
	blackBar2->space = SPACE::SCREEN;
	blackBar2->Update();
	//

	bgCol = new ObRect();
	bgCol->scale = Vector2(app.GetWidth(), 20.0f);
	bgCol->isFilled = false;
	bgCol->pivot = OFFSET_T;
	bgCol->SetWorldPos(Vector2(0.0f, -app.GetHalfHeight() + 50.0f)); // -226.0f
	bgCol->visible = false;
	bgCol->collider = COLLIDER::RECT;

	//발판 세개 만들기
	floors[0].col = new ObRect();
	floors[0].col->scale = Vector2(79.0f, 10.0f);
	floors[0].col->pivot = OFFSET_T;
	floors[0].col->isFilled = false;
	floors[0].col->SetWorldPos(Vector2(100.0f, -200.0f));
	floors[0].col->visible = false;
	floors[0].col->collider = COLLIDER::RECT;

	floors[0].img = new ObImage(L"floor.png");
	floors[0].img->scale = Vector2(79.0f, 48.0f);
	floors[0].img->pivot = OFFSET_T;
	floors[0].img->SetParentRT(*floors[0].col);
	//

	floors[1].col = new ObRect();
	floors[1].col->scale = Vector2(79.0f, 10.0f) * 2.0f;
	floors[1].col->pivot = OFFSET_T;
	floors[1].col->isFilled = false;
	floors[1].col->SetWorldPos(Vector2(300.0f, 50.0f));
	floors[1].col->visible = false;
	floors[1].col->collider = COLLIDER::RECT;

	floors[1].img = new ObImage(L"floor.png");
	floors[1].img->scale = Vector2(79.0f, 48.0f) * 2.0f;
	floors[1].img->pivot = OFFSET_T;
	floors[1].img->SetParentRT(*floors[1].col);
	//

	floors[2].col = new ObRect();
	floors[2].col->scale = Vector2(79.0f * 1.5f, 10.0f);
	floors[2].col->pivot = OFFSET_T;
	floors[2].col->isFilled = false;
	floors[2].col->SetWorldPos(Vector2(-200.0f, -100.0f));
	floors[2].col->visible = false;
	floors[2].col->collider = COLLIDER::RECT;

	floors[2].img = new ObImage(L"floor.png");
	floors[2].img->scale = Vector2(79.0f * 1.5f, 48.0f);
	floors[2].img->pivot = OFFSET_T;
	floors[2].img->SetParentRT(*floors[2].col);
	//

	//양쪽 벽
	walls[0].col = new ObRect();
	walls[0].col->scale = Vector2(174.0f * 3.0f, 1169.0f);
	walls[0].col->pivot = OFFSET_B;
	walls[0].col->isFilled = false;
	walls[0].col->SetWorldPos(Vector2(app.GetHalfWidth(), -600.0f));
	walls[0].col->visible = false;
	walls[0].col->collider = COLLIDER::RECT;

	walls[0].img = new ObImage(L"wall.png");
	walls[0].img->scale = Vector2(174.0f * 3.0f, 1169.0f);
	walls[0].img->pivot = OFFSET_B;
	walls[0].img->SetParentRT(*walls[0].col);
	//

	walls[1].col = new ObRect();
	walls[1].col->scale = Vector2(174.0f * 3.0f, 1169.0f);
	walls[1].col->pivot = OFFSET_B;
	walls[1].col->isFilled = false;
	walls[1].col->SetWorldPos(Vector2(-app.GetHalfWidth(), -600.0f));
	walls[1].col->visible = false;
	walls[1].col->collider = COLLIDER::RECT;

	walls[1].img = new ObImage(L"wall.png");
	walls[1].img->scale = Vector2(174.0f * 3.0f, 1169.0f);
	walls[1].img->pivot = OFFSET_B;
	walls[1].img->SetParentRT(*walls[1].col);
	//

	player = new DnFPlayer();
	boss = new bossFem();

	bgColor = 0.5f;

	SOUND->AddSound("bgm.wav", "BGM",true);

	startSceneTime = 5.0f;
}

void Main::Release()
{

}

void Main::Update()
{	
	//창크기에 맞춰서 배경 충돌체 위치조정;
	bgCol->scale = Vector2(app.GetWidth() * 3.0f, 20.0f);
	walls[0].col->SetWorldPosX(app.GetHalfWidth() + 200.0f);
	walls[1].col->SetWorldPosX(-app.GetHalfWidth() - 200.0f);

	startSceneTime -= DELTA;
	if (startSceneTime > 0.0f)
	{
		bossHPbar->visible - false;
		playerHPbar->visible = false;
		SOUND->Play("BGM");
		SOUND->SetVolume("BGM", 0.2f);
		blackBar->MoveWorldPos(UP * DELTA * 100.0f);
		blackBar2->MoveWorldPos(DOWN * DELTA * 100.0f);
		blackBar->Update();
		blackBar2->Update();
		player->Update();
	}
	else
	{
		SOUND->SetVolume("BGM", 0.2f);
		bossPortrait->SetWorldPos(Vector2(-app.GetHalfWidth() + 50.0f, 430.0f));
		playerPortrait->SetWorldPos(Vector2(-app.GetHalfWidth() + 50.0f, -450.0f));
		bossPortrait->Update();
		bossHPbar->visible = true;
		playerPortrait->Update();
		playerHPbar->visible = true;
		bossHPbar->Update();
		playerHPbar->Update();

		boss->setBossDir(player->getCol()->GetWorldPos());

		if (INPUT->KeyPress(VK_RIGHT))
		{
			if (player->getPlState() == PLSTATE::WALK_R ||
				player->getPlState() == PLSTATE::JUMP)
			{
				////1초에 50픽셀 움직여라
				//bg1->uv.x += DELTA / bg1->scale.x * 50.0f;
				//bg1->uv.z += DELTA / bg1->scale.x * 50.0f;
				bg1->uv.x += DELTA / bg1->scale.x * 50.0f;
				bg1->uv.z += DELTA / bg1->scale.x * 50.0f;

				////1초에 100픽셀 움직여라
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
		if (player->getPlState() == PLSTATE::RUN_R)//달리기 INPUT->KeyPress(VK_RIGHT) && INPUT->KeyPress(VK_LSHIFT)
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
		if (INPUT->KeyDown('Z'))//공격
		{
			if (player->getPlState() == PLSTATE::ATTACK)
				if (player->getPlDir() == RIGHT)
					player->getCol()->SetWorldPosX(player->getCol()->GetWorldPos().x + 5.0f);
				else if (player->getPlDir() == LEFT)
					player->getCol()->SetWorldPosX(player->getCol()->GetWorldPos().x - 5.0f);
		}
		if (INPUT->KeyDown('A')) //스킬 돌진
		{
			if (player->getPlDir() == RIGHT)
			{
				if (player->getPlState() == PLSTATE::SKILL1)
					for (int i = 0; i < 1000; i++)
					{
						player->getCol()->MoveWorldPos(RIGHT * 10.0f * DELTA);
						bgCol->MoveWorldPos(RIGHT * 10.0f * DELTA);
						CAM->position += RIGHT * 10.0f * DELTA;
					}

			}
			else if (player->getPlDir() == LEFT)
			{
				if (player->getPlState() == PLSTATE::SKILL1)
					for (int i = 0; i < 1000; i++)
					{
						player->getCol()->MoveWorldPos(LEFT * 10.0f * DELTA);
						bgCol->MoveWorldPos(LEFT * 10.0f * DELTA);
						CAM->position += LEFT * 10.0f * DELTA;
					}
			}
		}

		//맵 이동범위 제한

		player->Update();

		float minX = Utility::Saturate(player->getCol()->GetWorldPos().x, -app.GetHalfWidth(), app.GetHalfWidth());

		player->getCol()->SetWorldPosX(minX);

		minX = Utility::Saturate(boss->getCol()->GetWorldPos().x, -700.0f + 25.0f, 700.0f - 25.0f);

		boss->getCol()->SetWorldPosX(minX);

		minX = Utility::Saturate(CAM->position.x, -400.0f + 25.0f, 400.0f - 25.0f);

		CAM->position.x = minX;

		minX = Utility::Saturate(bgCol->GetWorldPos().x, -700.0f + 25.0f, 700.0f - 25.0f);

		bgCol->SetWorldPosX(minX);

		minX = Utility::Saturate(bg1->uv.x, 0.0f, 0.05f);

		bg1->uv.x = minX;

		minX = Utility::Saturate(bg1->uv.z, 0.95f, 1.0f);

		bg1->uv.z = minX;

		minX = Utility::Saturate(bg2->uv.x, 0.0f, 0.125f);

		bg2->uv.x = minX;

		minX = Utility::Saturate(bg2->uv.z, 0.88f, 1.0f);

		bg2->uv.z = minX;

		//cout << "bg2.uv.x = " << bg2->uv.x << endl;
		//cout << "bg1.uv.z = " << bg1->uv.z << endl;

	}

	bg1->Update();
	bg2->Update();
	bgCol->Update();
	player->Update();
	boss->Update();


	for (int i = 0; i < 2; i++)
	{
		walls[i].img->Update();
		walls[i].col->Update();
	}

	for (int i = 0; i < 3; i++)
	{
		floors[i].img->Update();
		floors[i].col->Update();
	}
}



void Main::LateUpdate()
{
	getTickTime = boss->getBsGetTickTime();

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

	/// <summary>
	/// 발판
	/// </summary>
	for (int i = 0; i < 3; i++)
	{
		if (floors[i].col->Intersect(player->getCol()->GetWorldPos()))
		{
			player->getCol()->SetWorldPosY(floors[i].col->GetWorldPos().y);
			player->setPlGravity(0.0f);

			if (player->getPlState() == PLSTATE::JUMP)
			{
				player->setPlState(PLSTATE::STAND);
			}

			player->Update();
		}
	}


	//플레이어 공격 -> 보스 검사
	if (boss->getCol()->Intersect(player->getWeaponCol()))
	{
		boss->TakeDamage(1000.0f);
		bossHPbar->scale.x -= 50.0f;
		bossHPbar->Update();
		boss->printBossHp();
		player->playerWeaponColoff();
	}

	//보스 공격 -> 플레이어 검사
	if (player->getCol()->Intersect(boss->getAttackCol()))
	{
		
		if (boss->getBossState() == BOSSSTATE::SKILL1)
		{
			player->TakeDamage(5.0f);
			playerHPbar->scale.x -= 25.0f * DELTA;
		}
		else if (boss->getBossState() == BOSSSTATE::SKILL2)
		{
			player->TakeDamage(5.0f);
			playerHPbar->scale.x -= 25.0f * DELTA;
			boss->bossAttackColoff();
		}
		else if (boss->getBossState() == BOSSSTATE::ATTACK)
		{
			player->TakeDamage(100.0f);
			playerHPbar->scale.x -= 50.0f * DELTA;
			boss->bossAttackColoff();
		}
		
		playerHPbar->Update();
		player->printPlayerHp();
		
	}


	/// <summary>
	/// 배경 밝기 조절 실험
	/// </summary>
	if (boss->getBossState() == BOSSSTATE::SKILL1 || 
		boss->getBossState() == BOSSSTATE::SKILL2)
	{

			getTickTime -= DELTA;
			if (getTickTime > 0.0f)
			{
				if (bgColor > 0.0f && bgColor <= 0.5f)
				{
					bgColor -= 0.001f;
					bg1->color = Color(bgColor, bgColor, bgColor, 0.5f);
				}
				getTickTime = 1.3f;
			}
			else
			{

			}
	}
	else if (boss->getBossState() == BOSSSTATE::STAND)
	{
		if (bgColor < 0.5)
		{
			if (getTickTime > 0.0f)
			{
				bgColor += 0.001f;
				bg1->color = Color(bgColor, bgColor, bgColor, 0.5f);
			}
			else
			{
				bgColor = 0.5f;
			}
		}
	}
}

void Main::Render()
{
	bg1->Render();
	bg2->Render();
	bgCol->Render();

	for (int i = 0; i < 2; i++)
	{
		walls[i].img->Render();
		walls[i].col->Render();
	}

	for (int i = 0; i < 3; i++)
	{
		floors[i].img->Render();
		floors[i].col->Render();
	}

	
	boss->Render();
	player->Render();
	bossHPbar->Render();
	playerHPbar->Render();
	bossPortrait->Render();
	playerPortrait->Render();
	blackBar->Render();
	blackBar2->Render();

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