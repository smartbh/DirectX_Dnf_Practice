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

	//jump
	jump = new ObImage(L"PLjump.png");
	jump->SetParentRT(*col);
	jump->maxFrame.x = 6;
	jump->scale.x = 372.0f * 1.5f;
	jump->scale.y = 231.0f * 1.5f;
	jump->SetLocalPosY(60.0f);
	jump->pivot = OFFSET_N;
	jump->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	jump->visible = false;

	//attack 1~6?
	attack1 = new ObImage(L"PLattack1.png");
	attack1->SetParentRT(*col);
	attack1->maxFrame.x = 5;
	attack1->scale.x = 372.0f * 1.5f;
	attack1->scale.y = 231.0f * 1.5f;
	attack1->SetLocalPosY(60.0f);
	attack1->pivot = OFFSET_N;
	attack1->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	attack1->visible = false;

	attack2 = new ObImage(L"PLattack2.png");
	attack2->SetParentRT(*col);
	attack2->maxFrame.x = 4;
	attack2->scale.x = 372.0f * 1.5f;
	attack2->scale.y = 231.0f * 1.5f;
	attack2->SetLocalPosY(90.0f);
	attack2->pivot = OFFSET_N;
	attack2->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	attack2->visible = false;

	attack3 = new ObImage(L"PLattack3.png");
	attack3->SetParentRT(*col);
	attack3->maxFrame.x = 9;
	attack3->scale.x = 372.0f * 1.5f;
	attack3->scale.y = 231.0f * 1.5f;
	attack3->SetLocalPosY(60.0f);
	attack3->pivot = OFFSET_N;
	attack3->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	attack3->visible = false;

	attack4 = new ObImage(L"PLattack4.png");
	attack4->SetParentRT(*col);
	attack4->maxFrame.x = 4;
	attack4->scale.x = 372.0f * 1.5f;
	attack4->scale.y = 231.0f * 1.5f;
	attack4->SetLocalPosY(60.0f);
	attack4->pivot = OFFSET_N;
	attack4->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	attack4->visible = false;

	///기본 변수
	state = PLSTATE::STAND;
	getTickTime = 0.0f;
	standTime = 0.0f;
	Timer = 0.0f;

	attackCount = 0;
	walkCount = 0;
	playerDir = RIGHT;
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
	if (state == PLSTATE::STAND) //오른쪽 스탠딩
	{
		jump->visible = false; //점프 끝났으니
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
			jump->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
			stand1->visible = false;
			jump->visible = true;
			gravity = -700.0f;
		}

		else if (INPUT->KeyDown('Z'))
		{
			stand1->visible = false;

			attack1->visible = true;
			attack1->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
			state = PLSTATE::ATTACK;
			cout << "공격1" << endl;
			attackCount = 1;
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
		else if (INPUT->KeyPress(VK_RIGHT) && INPUT->KeyPress(VK_LSHIFT))//달리기
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

		else if (INPUT->KeyDown('C'))
		{
			cout << "점프" << endl;
			state = PLSTATE::JUMP;
			jump->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
			walk->visible = false;
			jump->visible = true;
			gravity = -500.0f;
		}
	}
	else if (state == PLSTATE::RUN_R)
	{
		/*col->MoveWorldPos(RIGHT * 400.0f * DELTA);
		CAM->position += RIGHT * 400.0f * DELTA;*/

		if (INPUT->KeyUp(VK_LSHIFT))
		{
			walkCount = 0;
			run2->visible = false;
			walk->visible = true;
			state = PLSTATE::WALK_R;
		}
		else if (INPUT->KeyDown('C'))
		{
			cout << "점프" << endl;
			state = PLSTATE::JUMP;
			jump->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
			run2->visible = false;
			jump->visible = true;
			gravity = -700.0f;
		}

	}
	else if (state == PLSTATE::JUMP) {
		//점프공격 염두
	}
	else if (state == PLSTATE::ATTACK) {
		cout << attackCount << endl;

		if (INPUT->KeyDown('Z') && attackCount == 1) //2연타
		{
			cout << "공격2" << endl;
			attack1->visible = false;
			attack2->visible = true;
			attack2->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
			attackCount = 2;
			cout << attackCount << endl;
		}

		else if (INPUT->KeyDown('Z') && attackCount == 2) //3연타
		{
			cout << "공격3" << endl;
			attack2->visible = false;
			attack3->visible = true;
			attack3->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
			attackCount = 3;
			cout << attackCount << endl;
		}
		else if (INPUT->KeyDown('Z') && attackCount == 3) //3연타
		{
			cout << "공격4" << endl;
			attack3->visible = false;
			attack4->visible = true;
			attack4->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

			getTickTime = 1.0f;
			attackCount = 0;
			cout << attackCount << endl;
		}

		if (attackCount == 0)
		{
			getTickTime -= DELTA;
			if (getTickTime > 0.0f)
			{
				//start1->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
				cout << "dddd" << endl;
				cout << getTickTime << endl;
				cout << "attackCount : " << attackCount << endl;
			}
			else
			{
				cout << "시간 끝 애니메이션 변화" << endl;
				attack4->visible = false;
				getTickTime = 0.0f;
				cout << "attackCount : " << attackCount << endl;
				state = PLSTATE::STAND;
			}

		}

	}



	col->Update();
	stand1->Update();
	stand2->Update();
	walk->Update();
	run1->Update();
	run2->Update();
	jump->Update();
	attack1->Update();
	attack2->Update();
	attack3->Update();
	attack4->Update();
}

void DnFPlayer::Render()
{
	col->Render();
	stand1->Render();
	stand2->Render();
	walk->Render();
	run1->Render();
	run2->Render();
	jump->Render();
	attack1->Render();
	attack2->Render();
	attack3->Render();
	attack4->Render();
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

int DnFPlayer::getPlAttackCount()
{
	return attackCount;
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
