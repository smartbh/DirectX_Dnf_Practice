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
}

bossFem::~bossFem()
{
}

void bossFem::Update()
{

	if (BSstate == BOSSSTATE::START) {
		cout << "��ŸƮ ����" << endl;
		col->colOnOff = false;

		if (start1->visible) {
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
				cout << "dddd" << endl;
				cout << getTickTime << endl;
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
				cout << "dddd" << endl;
				cout << getTickTime << endl;
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
				cout << "dddd" << endl;
				cout << getTickTime << endl;
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
		}
	}
	if (BSstate == BOSSSTATE::STAND) //���⼭���� ��� �������� Idle�� ������ 
	{
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
	else if (BSstate == BOSSSTATE::ATTACK) {
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
	col->Update();
	start1->Update();
	start2->Update();
	start3->Update();
	start4->Update();
	stand->Update();
	attack[0]->Update();
	attack[1]->Update();
	attack[2]->Update();
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
	//attack->Render();
}

ObRect* bossFem::getCol()
{
	return col;
}

void bossFem::TakeDamage(int damage)
{
	hp -= damage;
	damagingTime = 0.5f;

	if (hp < 0)
	{
		col->visible = false;
		col->colOnOff = false;
	}

	if (damagingTime > 0.0f)
	{
		damagingTime -= DELTA;
		col->color.w = RANDOM->Float(0.0f, 0.5f);
	}
	else
		col->color.w = 0.5f;


	if (isDamaged) //update��, isDamaged�� true��
	{
		damageTime -= DELTA;

		run->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 1.0f);
		spin->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 1.0f);

		if (damageTime < 0.0f)
		{
			run->color = Color(0.5f, 0.5f, 0.5f, 1.0f);
			spin->color = Color(0.5f, 0.5f, 0.5f, 1.0f);
			isDamaged = false;
		}

	}
}
