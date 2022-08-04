#include "stdafx.h"

bossFem::bossFem()
{
	col = new ObRect();
	col->scale = Vector2(678.0f, 527.0f);
	col->SetWorldPos(Vector2(0.0f, 0.0f));
	col->pivot = OFFSET_N;
	col->isFilled = false;
	col->visible = true;
	col->collider = COLLIDER::RECT;

	/// <summary>
	/// ���� �ִϸ��̼� (1���� ����)
	/// </summary>
	start1 = new ObImage(L"start1.png");
	start1->SetParentRT(*col);
	start1->maxFrame.x = 13;
	start1->scale.x = 678.0f;
	start1->scale.y = 527.0f;
	start1->pivot = OFFSET_N;
	start1->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	start1->visible = true;

	start2 = new ObImage(L"start2.png");
	start2->SetParentRT(*col);
	start2->maxFrame.x = 10;
	start2->scale.x = 678.0f;
	start2->scale.y = 527.0f;
	start2->pivot = OFFSET_N;
	start2->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	start2->visible = false;

	start3 = new ObImage(L"start3.png");
	start3->SetParentRT(*col);
	start3->maxFrame.x = 13;
	start3->scale.x = 678.0f;
	start3->scale.y = 527.0f;
	start3->pivot = OFFSET_N;
	start3->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	start3->visible = false;

	start4 = new ObImage(L"start4.png");
	start4->SetParentRT(*col);
	start4->maxFrame.x = 14;
	start4->scale.x = 678.0f;
	start4->scale.y = 527.0f;
	start4->pivot = OFFSET_N;
	start4->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	start4->visible = false;

	/// <summary>
	/// ���ĵ� �ִϸ��̼�
	/// </summary>
	stand = new ObImage(L"stand.png");
	stand->SetParentRT(*col);
	stand->maxFrame.x = 8;
	stand->scale.x = 178.0f;
	stand->scale.y = 201.0f;
	stand->pivot = OFFSET_N;
	stand->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	stand->visible = false;	

	///walk
	stand = new ObImage(L"BSwalk.png");
	stand->SetParentRT(*col);
	stand->maxFrame.x = 12;
	stand->scale.x = 221.0f;
	stand->scale.y = 204.0f;
	stand->pivot = OFFSET_N;
	stand->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	stand->visible = false;


	///appear
	appear = new ObImage(L"BSappear.png");
	appear->SetParentRT(*col);
	appear->maxFrame.x = 11;
	appear->scale.x = 261.0f;
	appear->scale.y = 204.0f;
	appear->pivot = OFFSET_N;
	appear->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	appear->visible = false;

	///disappear
	disappear = new ObImage(L"BSdisappear.png");
	disappear->SetParentRT(*col);
	disappear->maxFrame.x = 9;
	disappear->scale.x = 249.0f;
	disappear->scale.y = 182.0f;
	disappear->pivot = OFFSET_N;
	disappear->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	disappear->visible = false;
	

	/// <summary>
	/// ���� �ִϸ��̼�
	/// </summary>
	attack[0] = new ObImage(L"attack1.png");
	attack[0]->SetParentRT(*col);
	attack[0]->maxFrame.x = 15;
	attack[0]->scale.x = 359.0f;
	attack[0]->scale.y = 239.0f;
	attack[0]->pivot = OFFSET_B;
	attack[0]->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	attack[0]->visible = false;

	attack[1] = new ObImage(L"attack2.png");
	attack[1]->SetParentRT(*col);
	attack[1]->maxFrame.x = 9;
	attack[1]->scale.x = 359.0f;
	attack[1]->scale.y = 239.0f;
	attack[1]->pivot = OFFSET_B;
	attack[1]->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	attack[1]->visible = false;

	attack[2] = new ObImage(L"attack3.png");
	attack[2]->SetParentRT(*col);
	attack[2]->maxFrame.x = 17;
	attack[2]->scale.x = 359.0f;
	attack[2]->scale.y = 239.0f;
	attack[2]->pivot = OFFSET_B;
	attack[2]->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	attack[2]->visible = false;

	/// <summary>
	/// 
	/// </summary>
	
	BSstate = BOSSSTATE::START;
	getTickTime = 1.3f;
	Timer = 0.0f;
	hp = 100.0f;

	attackCount = 0;
	motionRand = 0;
}

bossFem::~bossFem()
{
}

void bossFem::Update()
{
	if (bossDir.x < 0)
		cout << "bossDir = LEFT" << endl;
	else if (bossDir.x > 0)
		cout << "bossDir = RIGHT" << endl;


	if (isDamaged) //update��, isDamaged�� true��
	{
		damagingTime -= DELTA;

		stand->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 1.0f);
		attack[0]->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 1.0f);
		attack[1]->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 1.0f);
		attack[2]->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 1.0f);

		if (damagingTime < 0.0f)
		{
			stand->color = Color(0.5f, 0.5f, 0.5f, 1.0f);
			attack[0]->color = Color(0.5f, 0.5f, 0.5f, 1.0f);
			attack[1]->color = Color(0.5f, 0.5f, 0.5f, 1.0f);
			attack[2]->color = Color(0.5f, 0.5f, 0.5f, 1.0f);
			isDamaged = false;
		}

	}

	if (BSstate == BOSSSTATE::START) {
		cout << "��ŸƮ ����" << endl;
		col->colOnOff = false;
		//if (bossDir == RIGHT || bossDir == LEFT)
		//{
			if (start1->visible) {
				getTickTime -= DELTA;
				if (getTickTime > 0.0f)
				{
					//start1->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
					cout << "start1" << endl;
					cout << "start1 : " << getTickTime << endl;
				}
				else
				{
					cout << "�ð� �� �ִϸ��̼� ��ȭ" << endl;
					start1->visible = false;
					start2->visible = true;
					getTickTime = 1.0f;
				}
			}

			if (start2->visible) {
				getTickTime -= DELTA;
				if (getTickTime > 0.0f)
				{
					//start1->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
					cout << "start2" << endl;
					cout << "start2 : " << getTickTime << endl;
				}
				else
				{
					cout << "�ð� �� �ִϸ��̼� ��ȭ" << endl;
					start2->visible = false;
					start3->visible = true;
					getTickTime = 1.3f;
				}
			}

			if (start3->visible) {
				getTickTime -= DELTA;
				if (getTickTime > 0.0f)
				{
					//start1->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
					cout << "start3" << endl;
					cout << "start3 : " << getTickTime << endl;
				}
				else
				{
					cout << "�ð� �� �ִϸ��̼� ��ȭ" << endl;
					start3->visible = false;
					start4->visible = true;
					getTickTime = 1.4f;
				}
			}

			if (start4->visible) {
				getTickTime -= DELTA;
				if (getTickTime > 0.0f)
				{
					//start1->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
					cout << "start4" << endl;
					cout << "start4 : " << getTickTime << endl;
				}
				else
				{
					cout << "�ð� �� �ִϸ��̼� ��ȭ" << endl;
					start4->visible = false;
					getTickTime = 0.0f;
					cout << "������ ����" << endl;
					col->colOnOff = true;
					BSstate = BOSSSTATE::STAND;
					col->SetWorldPos(Vector2(-20.0f, -450.0f));
				}
			//}
		}
		
	}
	if (BSstate == BOSSSTATE::STAND) //���⼭���� ��� �������� Idle�� ������ 
	{
		motionRand = RANDOM->Int(0, 6);

		getTickTime = 8.0f; //�ϴ� 8�ʵ��� ���ĵ�

		if (bossDir == RIGHT)
		{
			stand->reverseLR = false;
			attack[0]->reverseLR = false;
			attack[1]->reverseLR = false;
			attack[2]->reverseLR = false;
			walk->reverseLR = false;

			col->pivot = OFFSET_B;
			col->scale = stand->scale;
			col->scale.y += 70.0f;
			stand->pivot = OFFSET_B;
			stand->visible = true;


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
				switch (motionRand)
				{
				case 0:
					BSstate = BOSSSTATE::STAND;
					break;
				case 1:
					BSstate = BOSSSTATE::WALK;
					break;
				case 2:
					BSstate = BOSSSTATE::STAND;
					break;
				case 3:
					BSstate = BOSSSTATE::STAND;
					break;
				case 4:
					BSstate = BOSSSTATE::STAND;
					break;
				case 5:
					BSstate = BOSSSTATE::STAND;
					break;
				case 6:
					BSstate = BOSSSTATE::STAND;
					break;
				}
				cout << "�ð� �� �ִϸ��̼� ��ȭ" << endl;
				jumpAttack->visible = false;
				jump->visible = true;
				getTickTime = 0.0f;
				cout << "attackCount : " << attackCount << endl;
				state = PLSTATE::JUMP;
			}


			if (INPUT->KeyDown('Z'))
			{
				stand->visible = false;

				attack[0]->visible = true;
				attack[0]->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
				BSstate = BOSSSTATE::ATTACK;
				cout << "����1" << endl;
				attackCount = 1;
			}
		}
		else if (bossDir == LEFT)
		{
			stand->reverseLR = true;
			attack[0]->reverseLR = true;
			attack[1]->reverseLR = true;
			attack[2]->reverseLR = true;

			col->pivot = OFFSET_B;
			col->scale = stand->scale;
			col->scale.y += 70.0f;
			stand->pivot = OFFSET_B;
			stand->visible = true;

			if (INPUT->KeyDown('Z'))
			{
				stand->visible = false;

				attack[0]->visible = true;
				attack[0]->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
				BSstate = BOSSSTATE::ATTACK;
				cout << "����1" << endl;
				attackCount = 1;
			}
		}
			
	}
	else if (BSstate == BOSSSTATE::ATTACK)
	{
		cout << attackCount << endl;
		if (INPUT->KeyDown('Z') && attackCount == 1)
		{
			cout << "����2" << endl;
			attack[0]->visible = false;
			attack[1]->visible = true;
			attack[1]->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
			attackCount = 2;
			cout << attackCount << endl;
		}

		else if (INPUT->KeyDown('Z') && attackCount == 2)
		{
			cout << "����3" << endl;
			attack[1]->visible = false;
			attack[2]->visible = true;
			attack[2]->ChangeAnim(ANIMSTATE::ONCE, 0.1f);

			getTickTime = 1.6f;
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
			}
			else
			{
				cout << "�ð� �� �ִϸ��̼� ��ȭ" << endl;
				BSstate = BOSSSTATE::STAND;
				attack[2]->visible = false;
				getTickTime = 0.0f;
			}

		}
		//else
		//{
		//	state = BOSSSTATE::STAND;
		//}
	}

	if (hp < 0)
	{
		col->visible = false;
		col->colOnOff = false;
		stand->visible = false;
		attack[0]->visible = false;
		attack[1]->visible = false;
		attack[2]->visible = false;
	}


	col->Update();
	start1->Update();
	start2->Update();
	start3->Update();
	start4->Update();
	stand->Update();
	attack[0]->Update();
	attack[1]->Update();
	attack[2]->Update();
	appear->Update();
	disappear->Update();
	//attack->Update();
}

void bossFem::Render()
{
	col->Render();
	start1->Render();
	start2->Render();
	start3->Render();
	start4->Render();
	stand->Render();
	attack[0]->Render();
	attack[1]->Render();
	attack[2]->Render();
	appear->Render();
	disappear->Render();
	//attack->Render();
}

ObRect* bossFem::getCol()
{
	return col;
}

void bossFem::setBossDir(Vector2 _playerPos)
{
	bossDir.x = _playerPos.x - col->GetWorldPos().x;
	cout << "bossDIR.x : " << bossDir.x << endl;
	if (bossDir.x < 0)
		bossDir = LEFT;
	else if(bossDir.x > 0)
		bossDir = RIGHT;
}

void bossFem::TakeDamage(int damage)
{
	hp -= damage * DELTA;
	damagingTime = 0.5f;
	isDamaged = true;

	if (damagingTime > 0.0f)
	{
		damagingTime -= DELTA;
		col->color.w = RANDOM->Float(0.0f, 0.5f);
	}
	else
		col->color.w = 0.5f;
}
