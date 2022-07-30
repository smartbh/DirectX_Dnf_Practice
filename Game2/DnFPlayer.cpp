#include "stdafx.h"

DnFPlayer::DnFPlayer()
{
	col = new ObRect();
	col->scale = Vector2(120.0f, 330.0f);
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
	stand1->scale.x = 372.0f * 3.0f;
	stand1->scale.y = 231.0f * 3.0f;
	stand1->SetLocalPosY(160.0f);
	stand1->pivot = OFFSET_N;
	stand1->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	stand1->visible = false;

	stand2 = new ObImage(L"PLstand2.png");
	stand2->SetParentRT(*col);
	stand2->maxFrame.x = 17;
	stand2->scale.x = 372.0f * 3.0f;
	stand2->scale.y = 231.0f * 3.0f;
	stand2->SetLocalPosY(160.0f);
	stand2->pivot = OFFSET_N;
	stand2->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	stand2->visible = false;

	/* walk */
	walk = new ObImage(L"PLwalk.png");
	walk->SetParentRT(*col);
	walk->maxFrame.x = 10;
	walk->scale.x = 372.0f * 3.0f;
	walk->scale.y = 231.0f * 3.0f;
	walk->SetLocalPosY(160.0f);
	walk->pivot = OFFSET_N;
	walk->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	walk->visible = false;

	/* run */
	//달리기 시작모습 한번만 재생
	run1 = new ObImage(L"PLrun1.png");
	run1->SetParentRT(*col);
	run1->maxFrame.x = 5;
	run1->scale.x = 372.0f * 3.0f;
	run1->scale.y = 231.0f * 3.0f;
	run1->SetLocalPosY(160.0f);
	run1->pivot = OFFSET_N;
	run1->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	run1->visible = false;
	
	//keyPress 시 모습, 계속달림
	run2 = new ObImage(L"PLrun2.png");
	run2->SetParentRT(*col);
	run2->maxFrame.x = 8;
	run2->scale.x = 372.0f * 3.0f;
	run2->scale.y = 231.0f * 3.0f;
	run2->SetLocalPosY(160.0f);
	run2->pivot = OFFSET_N;
	run2->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	run2->visible = false;

	//attack 1~6?


	///기본 변수
	state = PLSTATE::STAND;
	getTickTime = 1.3f;
	Timer = 0.0f;

	attackCount = 0;

	motionRand = 0;

}

DnFPlayer::~DnFPlayer()
{
}

void DnFPlayer::Update()
{

	if (state == PLSTATE::STAND)
	{
		motionRand = RANDOM->Int(0, 4);

		stand1->visible = true;

		cout << 
	}



	col->Update();
	stand1->Update();
	//stand2->Update();
	//walk->Update();
	run1->Update();
	//run2->Update();
	//stand2->Update();
	//stand2->Update();
	//stand2->Update();
}

void DnFPlayer::Render()
{
	col->Render();
	//stand1->Render();
	//stand2->Render();
	//walk->Render();
	run1->Render();
	//run2->Render();
	//stand2->Render();
	//stand2->Render();
	//stand2->Render();
}

ObRect* DnFPlayer::getCol()
{
	return col;
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
