#include "stdafx.h"

DnFPlayer::DnFPlayer()
{
	col = new ObRect();
	col->scale = Vector2(120.0f, 300.0f) / 2.0f;
	col->SetWorldPos(Vector2(0.0f, 0.0f));
	col->pivot = OFFSET_B;
	col->isFilled = false;
	col->visible = true;
	col->collider = COLLIDER::RECT;


	/* �ִϸ��̼� ���� */
	/// stand 1~2
	stand1 = new ObImage(L"PLstand1.png");
	stand1->SetParentRT(*col);
	stand1->maxFrame.x = 4;
	stand1->scale.x = 372.0f* 1.5f; //* 3.0f
	stand1->scale.y = 231.0f* 1.5f;
	stand1->SetLocalPosX(-10.0f);
	stand1->SetLocalPosY(80.0f);
	stand1->pivot = OFFSET_N;
	stand1->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	stand1->visible = false;
	// 4 * 0.1 = 0.4f

	stand2 = new ObImage(L"PLstand2.png");
	stand2->SetParentRT(*col);
	stand2->maxFrame.x = 17;
	stand2->scale.x = 372.0f* 1.5f;
	stand2->scale.y = 231.0f* 1.5f;
	stand2->SetLocalPosY(80.0f);
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
	walk->SetLocalPosY(80.0f);
	walk->pivot = OFFSET_N;
	walk->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	walk->visible = false;

	/* run */
	//�޸��� ���۸�� �ѹ��� ���
	run1 = new ObImage(L"PLrun1.png");
	run1->SetParentRT(*col);
	run1->maxFrame.x = 5;
	run1->scale.x = 372.0f* 1.5f;
	run1->scale.y = 231.0f* 1.5f;
	run1->SetLocalPosY(60.0f);
	run1->pivot = OFFSET_N;
	run1->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	run1->visible = false;
	
	//keyPress �� ���, ��Ӵ޸�
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

	///�⺻ ����
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
	/////�÷��̾� �߷�
	col->MoveWorldPos(DOWN * gravity * DELTA);
	gravity += 700.0f * DELTA;

	/// <summary>
	/// �÷��̾� ����
	/// </summary>
	if (state == PLSTATE::STAND)
	{
		if (playerDir == RIGHT) //������ ���ĵ�
		{
			jump->visible = false; //���� ��������
			//motionRand = RANDOM->Int(0, 4);

			//sonic->run->reverseLR = !sonic->run->reverseLR; ������
			stand1->reverseLR = false; //����, �⺻�� false
			stand2->reverseLR = false;
			walk->reverseLR = false;
			jump->reverseLR = false;
			run2->reverseLR = false;
			attack1->reverseLR = false;
			attack2->reverseLR = false;
			attack3->reverseLR = false;
			attack4->reverseLR = false;

			stand1->visible = true;

			standTime += DELTA;

			cout << standTime << endl;

			if (standTime > 10.0f) //������ �ִ��� 10������ ������
			{
				state = PLSTATE::STAND2;
				stand1->visible = false;
				stand2->visible = true;
				getTickTime = 1.7f; //stand2�� �ִϸ��̼� ��� �ð�
			}

			if (INPUT->KeyDown(VK_RIGHT))
			{
				cout << "�ȱ����" << endl;
				stand1->visible = false;
				walk->visible = true;
				playerDir = RIGHT;
				walkCount = 1;
				standTime = 0.0f;
				getTickTime = 0.5f;
				state = PLSTATE::WALK_R;
			}
			else if (INPUT->KeyDown(VK_LEFT))
			{
				cout << "�ȱ����" << endl;
				stand1->visible = false;
				walk->reverseLR = true;
				walk->visible = true;
				playerDir = LEFT;
				walkCount = 1;
				standTime = 0.0f;
				getTickTime = 0.5f;
				state = PLSTATE::WALK_L;
			}

			if (INPUT->KeyDown('C'))
			{
				cout << "����" << endl;
				state = PLSTATE::JUMP;
				jump->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
				stand1->visible = false;
				jump->visible = true;
				gravity = -700.0f;
			}

			if (INPUT->KeyDown('Z'))
			{
				stand1->visible = false;

				attack1->visible = true;
				attack1->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
				state = PLSTATE::ATTACK;
				cout << "����1" << endl;
				attackCount = 1;
			}
		}

		if (playerDir == LEFT) //���� ���ĵ�
		{
			jump->visible = false; //���� ��������
			//motionRand = RANDOM->Int(0, 4);

			//sonic->run->reverseLR = !sonic->run->reverseLR; ������
			stand1->reverseLR = true; //����, �⺻�� false
			stand2->reverseLR = true; 
			walk->reverseLR = true; 
			jump->reverseLR = true; 
			run2->reverseLR = true; 
			attack1->reverseLR = true; 
			attack2->reverseLR = true; 
			attack3->reverseLR = true; 
			attack4->reverseLR = true; 

			stand1->visible = true;

			standTime += DELTA;

			cout << standTime << endl;

			if (standTime > 10.0f) //������ �ִ��� 10������ ������
			{
				state = PLSTATE::STAND2;
				stand1->visible = false;
				stand2->visible = true;
				getTickTime = 1.7f; //stand2�� �ִϸ��̼� ��� �ð�
			}


			if (INPUT->KeyDown(VK_LEFT))
			{
				cout << "�ȱ����" << endl;
				stand1->visible = false;
				walk->visible = true;
				playerDir = LEFT;
				walkCount = 1;
				standTime = 0.0f;
				getTickTime = 0.5f;
				state = PLSTATE::WALK_L;
			}

			else if (INPUT->KeyDown(VK_RIGHT))
			{
				cout << "�ȱ����" << endl;
				stand1->visible = false;
				walk->reverseLR = false;
				walk->visible = true;
				playerDir = RIGHT;
				walkCount = 1;
				standTime = 0.0f;
				getTickTime = 0.5f;
				state = PLSTATE::WALK_R;
			}

			if (INPUT->KeyDown('C'))
			{
				cout << "����" << endl;
				state = PLSTATE::JUMP;
				jump->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
				stand1->visible = false;
				jump->visible = true;
				gravity = -700.0f;
			}

			if (INPUT->KeyDown('Z'))
			{
				stand1->visible = false;

				attack1->visible = true;
				attack1->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
				state = PLSTATE::ATTACK;
				cout << "����1" << endl;
				attackCount = 1;
			}
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
	else if (state == PLSTATE::WALK_R) //���������� �ȱ�
	{
		if (INPUT->KeyUp(VK_RIGHT))
		{
			stand1->visible = true;
			walk->visible = false;
			state = PLSTATE::STAND;
		}
		else if (INPUT->KeyPress(VK_RIGHT) && INPUT->KeyPress(VK_LSHIFT))//�޸���
		{
			walk->visible = false;
			run2->visible = true;
			getTickTime = 0.0f;
			state = PLSTATE::RUN_R;
		}

		else if (INPUT->KeyDown('C'))
		{
			cout << "����" << endl;
			state = PLSTATE::JUMP;
			jump->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
			walk->visible = false;
			jump->visible = true;
			gravity = -500.0f;
		}
	}
	else if (state == PLSTATE::WALK_L) //�������� �ȱ�
	{
		if (INPUT->KeyUp(VK_LEFT))
		{
			playerDir = LEFT;
			stand1->reverseLR = true;
			stand1->visible = true;
			walk->visible = false;
			state = PLSTATE::STAND;
		}
		else if (INPUT->KeyPress(VK_LEFT) && INPUT->KeyPress(VK_LSHIFT))//�޸���
		{
			playerDir = LEFT;
			walk->visible = false;
			run2->reverseLR = true;
			run2->visible = true;
			getTickTime = 0.0f;
			state = PLSTATE::RUN_L;
		}

		else if (INPUT->KeyDown('C'))
		{
			playerDir = LEFT;
			cout << "����" << endl;
			state = PLSTATE::JUMP;
			jump->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
			walk->visible = false;
			jump->reverseLR = true;
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
			playerDir = RIGHT;
			run2->visible = false;
			walk->visible = true;
			state = PLSTATE::WALK_R;
		}
		if (INPUT->KeyPress(VK_LEFT) && INPUT->KeyPress(VK_LSHIFT)) //�������� ����
		{
			playerDir = LEFT;
			run2->reverseLR = true;
			run2->visible = true;
			getTickTime = 0.0f;
			state = PLSTATE::RUN_L;
		}
		if (INPUT->KeyDown('C'))
		{
			cout << "����" << endl;
			state = PLSTATE::JUMP;
			jump->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
			run2->visible = false;
			jump->visible = true;
			gravity = -700.0f;
		}

	}
	else if (state == PLSTATE::RUN_L)
	{
		/*col->MoveWorldPos(RIGHT * 400.0f * DELTA);
		CAM->position += RIGHT * 400.0f * DELTA;*/

		if (INPUT->KeyUp(VK_LSHIFT))
		{
			playerDir = LEFT;
			run2->visible = false;
			walk->visible = true;
			state = PLSTATE::WALK_L;
		}
		else if (INPUT->KeyDown('C'))
		{
			cout << "����" << endl;
			state = PLSTATE::JUMP;
			jump->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
			run2->visible = false;
			jump->visible = true;
			gravity = -700.0f;
		}
	}
	else if (state == PLSTATE::JUMP) {
		//�������� ����
	}
	else if (state == PLSTATE::ATTACK) {
		cout << attackCount << endl;

		if (INPUT->KeyDown('Z') && attackCount == 1) //2��Ÿ
		{
			cout << "����2" << endl;
			attack1->visible = false;
			attack2->visible = true;
			attack2->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
			attackCount = 2;
			cout << attackCount << endl;
		}

		else if (INPUT->KeyDown('Z') && attackCount == 2) //3��Ÿ
		{
			cout << "����3" << endl;
			attack2->visible = false;
			attack3->visible = true;
			attack3->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
			attackCount = 3;
			cout << attackCount << endl;
		}
		else if (INPUT->KeyDown('Z') && attackCount == 3) //3��Ÿ
		{
			cout << "����4" << endl;
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
				cout << "�ð� �� �ִϸ��̼� ��ȭ" << endl;
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

void DnFPlayer::printPlState()
{
	//START,
	//	STAND,
	//	STAND2,
	//	SIT,
	//	JUMP,
	//	ATTACK,
	//	WALK_R,
	//	WALK_L,
	//	RUN_R,
	//	RUN_L,
	//	DIE,
	//	APPEAR,
	//	DISAPPEAR,
	//	GORG,
	//	SKILL1,
	//	SKILL2,
	//	SKILL3,
	//	SKILL4
	if (state == PLSTATE::START)
	{
		cout << "state : START" << endl;
	}
	else if (state == PLSTATE::STAND)
	{
		cout << "state : STAND" << endl;
	}
	else if (state == PLSTATE::WALK_R)
	{
		cout << "state : WALK_R" << endl;
	}
	else if (state == PLSTATE::WALK_L)
	{
		cout << "state : WALK_L" << endl;
	}
	else if (state == PLSTATE::RUN_R)
	{
		cout << "state : RUN_R" << endl;
	}
	else if (state == PLSTATE::RUN_L)
	{
		cout << "state : RUN_L" << endl;
	}
	else if (state == PLSTATE::ATTACK)
	{
		cout << "state : RUN_R" << endl;
	}
	else if (state == PLSTATE::JUMP)
	{
		cout << "state : RUN_R" << endl;
	}
	else if (state == PLSTATE::RUN_R)
	{
		cout << "state : RUN_R" << endl;
	}
	else if (state == PLSTATE::RUN_R)
	{
		cout << "state : RUN_R" << endl;
	}
	else if (state == PLSTATE::RUN_R)
	{
		cout << "state : RUN_R" << endl;
	}

}

Vector2 DnFPlayer::getPlDir()
{
	return playerDir;
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
