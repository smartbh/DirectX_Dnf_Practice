#include "stdafx.h"

DnFPlayer::DnFPlayer()
{
	col = new ObRect();
	col->scale = Vector2(120.0f, 231.0f) / 2.0f;
	col->SetWorldPos(Vector2(0.0f, 0.0f));
	col->pivot = OFFSET_B;
	col->isFilled = false;
	col->visible = true;
	col->collider = COLLIDER::RECT;


	/* 애니메이션 모음 */
	/// stand 1~2
	stand1 = new ObImage(L"PLstand1.png");
	stand1->SetParentRT(*col);
	stand1->maxFrame.x = 4;
	stand1->scale.x = 372.0f* 1.5f; //* 3.0f
	stand1->scale.y = 231.0f* 1.5f;
	stand1->SetLocalPosY(60.0f);
	stand1->pivot = OFFSET_N;
	stand1->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	stand1->visible = false;
	// 4 * 0.1 = 0.4f

	stand2 = new ObImage(L"PLstand2.png");
	stand2->SetParentRT(*col);
	stand2->maxFrame.x = 17;
	stand2->scale.x = 372.0f* 1.5f;
	stand2->scale.y = 231.0f* 1.5f;
	stand2->SetLocalPosY(60.0f);
	stand2->pivot = OFFSET_N;
	stand2->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	stand2->visible = false;
	// 17 * 0.1 = 1.7f

	/* walk */
	walk = new ObImage(L"PLwalk.png");
	walk->SetParentRT(*col);
	walk->maxFrame.x = 10;
	walk->scale.x = 372.0f* 1.5f;
	walk->scale.y = 231.0f* 1.5f;
	walk->SetLocalPosY(60.0f);
	walk->pivot = OFFSET_N;
	walk->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	walk->visible = false;

	/* run */
	//달리기 시작모습 한번만 재생
	run1 = new ObImage(L"PLrun1.png");
	run1->SetParentRT(*col);
	run1->maxFrame.x = 5;
	run1->scale.x = 372.0f* 1.5f;
	run1->scale.y = 231.0f* 1.5f;
	run1->SetLocalPosY(60.0f);
	run1->pivot = OFFSET_N;
	run1->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	run1->visible = false;
	
	//keyPress 시 모습, 계속달림
	run2 = new ObImage(L"PLrun2.png");
	run2->SetParentRT(*col);
	run2->maxFrame.x = 8;
	run2->scale.x = 372.0f * 1.5f;
	run2->scale.y = 231.0f * 1.5f;
	run2->SetLocalPosY(60.0f);
	run2->pivot = OFFSET_N;
	run2->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	run2->visible = false;

	//attack 1~6?


	///기본 변수
	state = PLSTATE::STAND;
	getTickTime = 0.0f;
	standTime = 0.0f;
	Timer = 0.0f;

	attackCount = 0;
	walkCount = 0;
}

DnFPlayer::~DnFPlayer()
{
}

void DnFPlayer::Update()
{
	/////플레이어 중력
	col->MoveWorldPos(DOWN * gravity * DELTA);
	gravity += 700.0f * DELTA;

	/// <summary>
	/// 플레이어 조작
	/// </summary>
	if (state == PLSTATE::STAND)
	{
		//motionRand = RANDOM->Int(0, 4);

		stand1->visible = true;

		standTime += DELTA;

		cout << standTime << endl;

		if (standTime > 10.0f) //가만히 있는지 10초정도 지나면
		{
			state = PLSTATE::STAND2;
			stand1->visible = false;
			stand2->visible = true;
			getTickTime = 1.7f; //stand2의 애니메이션 출력 시간
		}

		if (INPUT->KeyDown(VK_RIGHT))
		{
			cout << "걷기시작" << endl;
			stand1->visible = false;
			walk->visible = true;
			walkCount = 1;
			standTime = 0.0f;
			getTickTime = 0.5f;
			state = PLSTATE::WALK_R;
		}

		else if (INPUT->KeyDown('C'))
		{
			cout << "점프" << endl;
			state = PLSTATE::JUMP;
			gravity = -700.0f;
		}
	}
	else if (state == PLSTATE::STAND2)
	{
		getTickTime -= DELTA;
		if (getTickTime > 0.0f)
		{
			cout << getTickTime << endl;
		}
		else
		{
			stand1->visible = true;
			stand2->visible = false;
			getTickTime = 0.0f;
			standTime = 0.0f;
			state = PLSTATE::STAND;
		}
	}
	else if (state == PLSTATE::WALK_R) //오른쪽으로 걷기
	{
		if (INPUT->KeyUp(VK_RIGHT))
		{
			stand1->visible = true;
			walk->visible = false;
			state = PLSTATE::STAND;
		}
		else if (INPUT->KeyPress(VK_RIGHT) && INPUT->KeyPress(VK_LSHIFT))
		{
			walk->visible = false;
			//run1->visible = true;

			//getTickTime -= DELTA;
			//if (getTickTime > 0.0f)
			//{
			//	cout << getTickTime << endl;
			//}
			//else
			//{
				//run1->visible = false;
				run2->visible = true;
				getTickTime = 0.0f;
				state = PLSTATE::RUN_R;
			//}
		}
	}
	else if (state == PLSTATE::RUN_R)
	{	
		if (INPUT->KeyUp(VK_LSHIFT))
		{
			walkCount = 0;
			run2->visible = false;
			walk->visible = true;
			state = PLSTATE::WALK_R;
		}

	}
	else if (state == PLSTATE::JUMP) {

	}



	col->Update();
	stand1->Update();
	stand2->Update();
	walk->Update();
	run1->Update();
	run2->Update();
	//stand2->Update();
	//stand2->Update();
	//stand2->Update();
}

void DnFPlayer::Render()
{
	col->Render();
	stand1->Render();
	stand2->Render();
	walk->Render();
	run1->Render();
	run2->Render();
	//stand2->Render();
	//stand2->Render();
	//stand2->Render();
}

ObRect* DnFPlayer::getCol()
{
	return col;
}

float DnFPlayer::getPlGravity()
{
	return gravity;
}

void DnFPlayer::setPlGravity(float number)
{
	gravity = number;
}

PLSTATE DnFPlayer::getPlState()
{
	return state;
}

void DnFPlayer::setPlState(PLSTATE new_state)
{
	state = new_state;
}

void DnFPlayer::TakeDamage(int damage)
{
	hp -= damage;
	damagingTime = 0.5f;

	if (hp < 0)
	{
		col->visible = false;
		col->colOnOff = false;
	}
}
