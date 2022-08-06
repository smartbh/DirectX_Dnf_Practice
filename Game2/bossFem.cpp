#include "stdafx.h"

bossFem::bossFem()
{
	col = new ObRect();
	col->scale = Vector2(678.0f, 527.0f);
	col->SetWorldPos(Vector2(0.0f, 0.0f));
	col->pivot = OFFSET_B;
	col->isFilled = false;
	col->visible = true;
	col->collider = COLLIDER::RECT;

	//���� �ݶ��̴�
	attackCol = new ObRect();
	attackCol->SetParentRT(*col);
	attackCol->scale = Vector2(120.0f, 300.0f) / 2.0f;
	attackCol->SetLocalPos(Vector2(0.0f, 50.0f));
	attackCol->pivot = OFFSET_N;
	attackCol->isFilled = false;
	attackCol->visible = true;
	attackCol->color = Color(1.0f, 0.0f, 0.0f, 1.0f);
	attackCol->collider = COLLIDER::RECT;

	/// <summary>
	/// ���� �ִϸ��̼� (1���� ����)
	/// </summary>
	start1 = new ObImage(L"start1.png");
	start1->SetParentRT(*col);
	start1->maxFrame.x = 13;
	start1->scale.x = 678.0f;
	start1->scale.y = 527.0f;
	start1->pivot = OFFSET_B;
	start1->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	start1->visible = true;

	start2 = new ObImage(L"start2.png");
	start2->SetParentRT(*col);
	start2->maxFrame.x = 10;
	start2->scale.x = 678.0f;
	start2->scale.y = 527.0f;
	start2->pivot = OFFSET_B;
	start2->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	start2->visible = false;

	start3 = new ObImage(L"start3.png");
	start3->SetParentRT(*col);
	start3->maxFrame.x = 13;
	start3->scale.x = 678.0f;
	start3->scale.y = 527.0f;
	start3->pivot = OFFSET_B;
	start3->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	start3->visible = false;

	start4 = new ObImage(L"start4.png");
	start4->SetParentRT(*col);
	start4->maxFrame.x = 14;
	start4->SetLocalPosY(100.0f);
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
	walk = new ObImage(L"BSwalk.png");
	walk->SetParentRT(*col);
	walk->maxFrame.x = 12;
	walk->SetLocalPosY(100.0f);
	walk->scale.x = 221.0f;
	walk->scale.y = 204.0f;
	walk->pivot = OFFSET_N;
	walk->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	walk->visible = false;


	///appear
	appear = new ObImage(L"BSappear.png");
	appear->SetParentRT(*col);
	appear->maxFrame.x = 11;
	appear->scale.x = 261.0f;
	appear->scale.y = 204.0f;
	appear->SetLocalPosY(85.0f);
	appear->pivot = OFFSET_N;
	appear->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	appear->visible = false;

	///disappear
	disappear = new ObImage(L"BSdisappear.png");
	disappear->SetParentRT(*col);
	disappear->maxFrame.x = 13;
	disappear->scale.x = 249.0f;
	disappear->scale.y = 182.0f;
	appear->SetLocalPosY(85.0f);
	disappear->pivot = OFFSET_B;
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
	attack[2]->SetLocalPos(Vector2(20.0f ,-5.0f));
	attack[2]->scale.x = 359.0f;
	attack[2]->scale.y = 239.0f;
	attack[2]->pivot = OFFSET_B;
	attack[2]->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	attack[2]->visible = false;

	/// <summary>
	/// skill1 �ִϸ��̼�
	/// </summary>
	skill1_1 = new ObImage(L"BSskill1-1.png");
	skill1_1->SetParentRT(*col);
	skill1_1->maxFrame.x = 13;
	skill1_1->scale.x = 273.0f;
	skill1_1->scale.y = 204.0f;
	skill1_1->pivot = OFFSET_B;
	skill1_1->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	skill1_1->visible = false;


	skill1_2 = new ObImage(L"BSskill1-2.png");
	skill1_2->SetParentRT(*col);
	skill1_2->maxFrame.x = 4;
	skill1_2->scale.x = 273.0f;
	skill1_2->scale.y = 204.0f;
	skill1_2->pivot = OFFSET_B;
	skill1_2->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	skill1_2->visible = false;
	//1.3, 0.4

	skill1_1effect = new ObImage(L"BSskill_1_1effect.png"); //�ѹ���
	skill1_1effect->SetParentRT(*col);
	skill1_1effect->SetWorldPos(Vector2(0.0f, 0.0f));
	skill1_1effect->maxFrame.x = 6;
	skill1_1effect->scale.x = 256.0f * 7.0f;
	skill1_1effect->scale.y = 256.0f;
	skill1_1effect->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	skill1_1effect->visible = false;

	skill1_2effect = new ObImage(L"BSskill_1effect.png");
	skill1_2effect->SetParentRT(*col);
	skill1_2effect->SetWorldPos(Vector2(0.0f, 0.0f));
	skill1_2effect->maxFrame.x = 24;
	skill1_2effect->scale.x = 256.0f * 7.0f;
	skill1_2effect->scale.y = 256.0f * 1.5f;
	skill1_2effect->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	skill1_2effect->visible = false;

	/// <summary>
	/// skill2
	/// </summary>
	skill2_1 = new ObImage(L"BSskill2-1.png");
	skill2_1->SetParentRT(*col);
	skill2_1->maxFrame.x = 21;
	skill2_1->scale.x = 270.0f;
	skill2_1->scale.y = 244.0f;
	skill2_1->pivot = OFFSET_B;
	skill2_1->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	skill2_1->visible = false;

	skill2_2 = new ObImage(L"BSskill2-2.png");
	skill2_2->SetParentRT(*col);
	skill2_2->maxFrame.x = 6;
	skill2_2->scale.x = 270.0f;
	skill2_2->scale.y = 244.0f;
	skill2_2->pivot = OFFSET_B;
	skill2_2->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	skill2_2->visible = false;
	//2.1, 0.6

	skill2_1effect = new ObImage(L"BSskill_2effect.png");
	skill2_1effect->SetParentRT(*attackCol);
	skill2_1effect->SetWorldPos(Vector2(0.0f, 0.0f));
	skill2_1effect->maxFrame.x = 25;
	skill2_1effect->scale.x = 256.0f * 2.0f;
	skill2_1effect->scale.y = 256.0f * 4.0f;
	skill2_1effect->pivot = OFFSET_B;
	skill2_1effect->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	skill2_1effect->visible = false;

	///�׷α�
	grog = new ObImage(L"BSgrog.png");
	grog->SetParentRT(*col);
	grog->maxFrame.x = 8;
	grog->scale.x = 237.0f;
	grog->scale.y = 205.0f;
	grog->pivot = OFFSET_B;
	grog->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	grog->visible = false;


	/// <summary>
	/// �⺻ ������
	/// </summary>
	BSstate = BOSSSTATE::START;
	getTickTime = 1.3f;
	Timer = 0.0f;
	hp = 100.0f;
	imageColor = 0.5f;

	attackCount = 0;
	motionRand = 0;
	checkGrog = false;
	checkSkill_1On = false;
	checkSkill_2On = false;
}

bossFem::~bossFem()
{
}

void bossFem::Update()
{

	if (isDamaged) //update��, isDamaged�� true��
	{
		damagingTime -= DELTA;

		stand->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 0.5f);
		attack[0]->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 0.5f);
		attack[1]->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 0.5f);
		attack[2]->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 0.5f);
		walk->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 0.5f);
		skill1_1->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 0.5f);
		skill1_2->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 0.5f);
		skill2_1->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 0.5f);
		skill2_2->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 0.5f);
		appear->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 0.5f);
		disappear->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 0.5f);
		grog->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 0.5f);


		if (damagingTime < 0.0f)
		{
			stand->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			attack[0]->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			attack[1]->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			attack[2]->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			walk->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			skill1_1->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			skill1_2->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			skill2_1->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			skill2_2->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			appear->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			disappear->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			grog->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			isDamaged = false;
		}

	}

	if (BSstate == BOSSSTATE::START) {

		attackCol->visible = false;
		col->colOnOff = false;

		if (start1->visible) {
			getTickTime -= DELTA;
			if (getTickTime > 0.0f)
			{

			}
			else
			{
				start1->visible = false;
				start2->visible = true;
				getTickTime = 1.0f;
			}
		}

		if (start2->visible) {
			getTickTime -= DELTA;
			if (getTickTime > 0.0f)
			{

			}
			else
			{
				start2->visible = false;
				start3->visible = true;
				getTickTime = 1.3f;
			}
		}

		if (start3->visible) {
			getTickTime -= DELTA;
			if (getTickTime > 0.0f)
			{

			}
			else
			{
				start3->visible = false;
				start4->visible = true;
				getTickTime = 1.4f;
			}
		}

		if (start4->visible)
		{
			getTickTime -= DELTA;
			if (getTickTime > 0.0f)
			{

			}
			else
			{
				start4->visible = false;
				disappear->visible = true;
				getTickTime = 0.9; //0.9, 1.1, 8.0
			}
		}

		if (disappear->visible)
		{
			col->scale = stand->scale;
			getTickTime -= DELTA;
			if (getTickTime > 0.0f)
			{

			}
			else
			{
				disappear->visible = false;
				col->SetWorldPos(Vector2(-20.0f, -450.0f));
				appear->visible = true;
				getTickTime = 1.1; // 1.1, 8.0
			}
		}
		if (appear->visible)
		{
			getTickTime -= DELTA;
			if (getTickTime > 0.0f)
			{

			}
			else
			{
				appear->visible = false;
				stand->visible = true;
				getTickTime = 8.0f; // 1.1, 8.0

				BSstate = BOSSSTATE::STAND;
				col->SetLocalPos(Vector2(0.0f, -450.0f));
			}
		}


	}

	if (BSstate == BOSSSTATE::STAND) //���⼭���� ��� �������� Idle�� ������ 
	{
		attackCol->visible = false;
		attackCol->colOnOff = false;
		col->colOnOff = true;
		
		if (bossDir == RIGHT)
		{
			stand->reverseLR = false;
			attack[0]->reverseLR = false;
			attack[1]->reverseLR = false;
			attack[2]->reverseLR = false;
			walk->reverseLR = false;
			appear->reverseLR = false;
			disappear->reverseLR = false;
			skill1_1->reverseLR = false;
			skill1_2->reverseLR = false;
			skill2_1->reverseLR = false;
			skill2_2->reverseLR = false;

			col->pivot = OFFSET_B;
			col->scale = stand->scale;
			col->scale.y += 70.0f;
			stand->pivot = OFFSET_B;
			stand->visible = true;


			getTickTime -= DELTA;
			if (getTickTime > 0.0f)
			{

			}
			else
			{
				motionRand = RANDOM->Int(1, 7);

				cout << "motionRand : " << motionRand << endl;

				switch (motionRand)
				{
				case 0:
					BSstate = BOSSSTATE::STAND;
					break;
				case 1:
					stand->visible = false;
					walk->visible = true;
					walk->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
					getTickTime = 4.0f;
					BSstate = BOSSSTATE::WALK;
					break;
				case 2:
					stand->visible = false;
					attackCol->colOnOff = true;
					attackCol->visible = true;
					attackCol->SetLocalPosX(100.0f);
					attackCol->scale = Vector2(100.0f, 400.0f);
					attack[0]->visible = true;
					attack[0]->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
					getTickTime = 0.9f;
					BSstate = BOSSSTATE::ATTACK;
					break;
				case 3:
					stand->visible = false;
					getTickTime = 1.3f;
					disappear->visible = true;
					disappear->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
					BSstate = BOSSSTATE::DISAPPEAR;
					break;
				case 5: //��ų1
					getTickTime = 1.3f;//10�ʰ� ����
					checkSkill_1On = true;
					stand->visible = false;
					disappear->visible = true;
					disappear->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
					BSstate = BOSSSTATE::DISAPPEAR;
					break;
				case 6: //��ų2
					getTickTime = 1.3f;//10�ʰ� ����
					checkSkill_2On = true;
					stand->visible = false;
					disappear->visible = true;
					disappear->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
					BSstate = BOSSSTATE::DISAPPEAR;
					break;
				case 7:
					if (checkGrog)
					{
						getTickTime = 10.0f;
						stand->visible = false;
						grog->visible = true;
						BSstate = BOSSSTATE::GROG;
						break;
					}
					else
					{
						getTickTime = 6.0f;
						BSstate = BOSSSTATE::STAND;
						break;
					}
				}
			}
		}
		else if (bossDir == LEFT)
		{
			stand->reverseLR = true;
			attack[0]->reverseLR = true;
			attack[1]->reverseLR = true;
			attack[2]->reverseLR = true;
			walk->reverseLR = true;
			skill1_1->reverseLR = true;
			skill1_2->reverseLR = true;
			skill2_1->reverseLR = true;
			skill2_2->reverseLR = true;

			col->pivot = OFFSET_B;
			col->scale = stand->scale;
			col->scale.y += 70.0f;
			stand->pivot = OFFSET_B;
			stand->visible = true;

			getTickTime -= DELTA;
			if (getTickTime > 0.0f)
			{

			}
			else
			{
				motionRand = RANDOM->Int(1, 7);
				cout << "motionRand = " << motionRand << endl;
				switch (motionRand)
				{
				case 0:
					BSstate = BOSSSTATE::STAND;
					break;
				case 1:
					stand->visible = false;
					walk->visible = true;
					walk->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
					getTickTime = 4.0f;
					BSstate = BOSSSTATE::WALK;
					break;
				case 2:
					stand->visible = false;
					attackCol->colOnOff = true;
					attackCol->visible = true;
					attackCol->SetLocalPosX(-100.0f);
					attackCol->scale = Vector2(100.0f, 400.0f);
					attack[0]->visible = true;
					attack[0]->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
					getTickTime = 0.9f;
					BSstate = BOSSSTATE::ATTACK;
					break;
				case 3:
					stand->visible = false;
					getTickTime = 1.3f;
					disappear->visible = true;
					disappear->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
					BSstate = BOSSSTATE::DISAPPEAR;
					break;
				case 5:
					getTickTime = 1.3f;//10�ʰ� ����
					checkSkill_1On = true;
					stand->visible = false;
					disappear->visible = true;
					disappear->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
					BSstate = BOSSSTATE::DISAPPEAR;
					break;
				case 6:
					getTickTime = 1.3f;//10�ʰ� ����
					checkSkill_2On = true;
					stand->visible = false;
					disappear->visible = true;
					disappear->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
					BSstate = BOSSSTATE::DISAPPEAR;
					break;
				case 7:
					if (checkGrog)
					{
						getTickTime = 10.0f;
						stand->visible = false;
						grog->visible = true;
						BSstate = BOSSSTATE::GROG;
						break;
					}
					else
					{
						getTickTime = 6.0f;
						BSstate = BOSSSTATE::STAND;
						break;
					}
				}
			}
		}

	}
	else if (BSstate == BOSSSTATE::ATTACK)
	{
		//0.9 1.7
		if (attack[0]->visible) {
			getTickTime -= DELTA;
			if (getTickTime > 0.0f)
			{
				if (bossDir == RIGHT)
				{
					attack[0]->reverseLR = false;
					attackCol->SetLocalPosX(100.0f);
				}
					
				else if (bossDir == LEFT)
				{
					attack[0]->reverseLR = true;
					attackCol->SetLocalPosX(-100.0f);
				}

			}
			else
			{
				attackCol->colOnOff = true;

				attack[0]->visible = false;
				attack[1]->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
				attack[1]->visible = true;
				getTickTime = 0.9f;
			}
		}

		if (attack[1]->visible) {
			getTickTime -= DELTA;
			if (getTickTime > 0.0f)
			{
				if (bossDir == RIGHT)
				{
					attack[1]->reverseLR = false;
					attackCol->SetLocalPosX(100.0f);
				}

				else if (bossDir == LEFT)
				{
					attack[1]->reverseLR = true;
					attackCol->SetLocalPosX(-100.0f);
				}

			}
			else
			{
				attackCol->colOnOff = true;

				attack[1]->visible = false;
				attack[2]->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
				attack[2]->visible = true;
				getTickTime = 1.7f;
			}
		}

		if (attack[2]->visible) {
			getTickTime -= DELTA;
			if (getTickTime > 0.0f)
			{
				if (bossDir == RIGHT)
				{
					attack[2]->reverseLR = false;
					attackCol->SetLocalPosX(100.0f);
				}

				else if (bossDir == LEFT)
				{
					attack[2]->reverseLR = true;
					attackCol->SetLocalPosX(-100.0f);
				}

			}
			else
			{

				attack[2]->visible = false;
				stand->visible = true;
				getTickTime = 5.0f;

				BSstate = BOSSSTATE::STAND;
			}
		}

	}
	else if (BSstate == BOSSSTATE::WALK)
	{
		getTickTime -= DELTA;
		if (getTickTime > 0.0f)
		{
			col->MoveWorldPos(bossDir * 100.0f * DELTA);
			if (bossDir == RIGHT)
				walk->reverseLR = false;
			else if (bossDir == LEFT)
				walk->reverseLR = true;

		}
		else
		{

			walk->visible = false;
			stand->visible = true;
			getTickTime = 8.0f; //�ϴ� 8�ʵ��� ���ĵ�
			BSstate = BOSSSTATE::STAND;
		}
	}
	else if (BSstate == BOSSSTATE::APPEAR)
	{
		getTickTime -= DELTA;
		if (getTickTime > 0.0f)
		{

		}
		else
		{
			if (checkSkill_1On)
			{
				getTickTime = 1.3f; //�ϴ� 6�ʵ��� ���ĵ�
				appear->visible = false;

				if (bossDir == RIGHT) {
					skill1_1->reverseLR = false;
					skill1_2->reverseLR = false;

					skill1_1effect->reverseLR = false;
					skill1_1effect->SetLocalPosX(100.0f);
					skill1_1effect->SetLocalPosY(100.0f);
					skill1_1effect->pivot = OFFSET_L;

					skill1_2effect->reverseLR = false;
					skill1_2effect->SetLocalPosX(100.0f);
					skill1_2effect->SetLocalPosY(100.0f);
					skill1_2effect->pivot = OFFSET_L;

					attackCol->visible = true;
					attackCol->pivot = OFFSET_L;
					attackCol->SetLocalPosX(100.0f);
					attackCol->scale = Vector2(app.GetWidth() - 200.0f, 400.0f);
				}
				else if (bossDir == LEFT)
				{
					skill1_1->reverseLR = true;
					skill1_2->reverseLR = true;
					
					skill1_1effect->reverseLR = true;
					skill1_1effect->SetLocalPosX(100.0f);
					skill1_1effect->SetLocalPosY(100.0f);
					skill1_1effect->pivot = OFFSET_R;

					skill1_2effect->reverseLR = true;
					skill1_2effect->SetLocalPosX(-100.0f);
					skill1_2effect->SetLocalPosY(100.0f);
					skill1_2effect->pivot = OFFSET_R;

					attackCol->visible = true;
					attackCol->pivot = OFFSET_R;
					attackCol->SetLocalPosX(-100.0f);
					attackCol->scale = Vector2(app.GetWidth() - 200.0f, 400.0f);
				}

				skill1_1->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
				skill1_1->visible = true;

				BSstate = BOSSSTATE::SKILL1;
			}
			else if (checkSkill_2On)
			{
				getTickTime = 2.1f; //�ϴ� 6�ʵ��� ���ĵ�
				appear->visible = false;
				col->SetLocalPosY(100.0f);

				attackCol->visible = true;
				attackCol->SetLocalPos(Vector2(-550.0f, -550.0f));
				attackCol->scale = Vector2(300.0f, 700.0f);
				attackCol->pivot = OFFSET_B;

				skill2_1->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
				skill2_1->visible = true;

				BSstate = BOSSSTATE::SKILL2;
			}
			else
			{
				appear->visible = false;
				stand->visible = true;
				getTickTime = 3.0f; //�ϴ� 6�ʵ��� ���ĵ�
				BSstate = BOSSSTATE::STAND;
			}
		}
	}
	else if (BSstate == BOSSSTATE::DISAPPEAR)
	{
		getTickTime -= DELTA;
		if (getTickTime > 0.0f)
		{

		}
		else
		{
			if (checkSkill_1On) //��ų 1�̸�
			{
				getTickTime = 1.0f;
				disappear->visible = false;
				motionRand = RANDOM->Int(0, 1); //��, �� �� ������

				switch (motionRand)
				{
				case 0:
					col->SetWorldPosX(-450.0f);
					break;
				case 1:
					col->SetWorldPosX(450.0f);
					break;
				}
				appear->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
				appear->visible = true;
				BSstate = BOSSSTATE::APPEAR;
			}
			else if (checkSkill_2On) //��ų 2��
			{
				getTickTime = 1.0f;
				disappear->visible = false;
				col->SetWorldPos(Vector2( 0.0f, 100.0f)); //����� ����
				appear->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
				appear->visible = true;
				BSstate = BOSSSTATE::APPEAR;
			}
			else //�ܼ� �����̵��� �Ҷ��� ��� 
			{
				getTickTime = 1.0f;

				disappear->visible = false;
				motionRand = RANDOM->Int(0, 2);
				cout << "motionRand = " << motionRand << endl;
				switch (motionRand)
				{
				case 0:
					col->SetWorldPosX(RANDOM->Float(-450.0f, 0.0f));
					col->SetWorldPosY(-450.0f);
					break;
				case 1:
					col->SetWorldPosX(RANDOM->Float(0.0f, 450.0f));
					col->SetWorldPosY(-450.0f);
					break;
				case 2:
					col->SetWorldPosX(0.0f);
					col->SetWorldPosY(-450.0f);
					break;
				}
				appear->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
				appear->visible = true;
				BSstate = BOSSSTATE::APPEAR;
			}
		}
	}

	else if (BSstate == BOSSSTATE::GROG)
	{
		getTickTime -= DELTA;
		if (getTickTime > 0.0f)
		{

		}
		else
		{
			grog->visible = false;
			stand->visible = true;
			getTickTime = 6.0f;
			BSstate = BOSSSTATE::STAND;
		}
	}

	else if (BSstate == BOSSSTATE::SKILL1)
	{
		
		if (skill1_1->visible)
		{
			getTickTime -= DELTA;
			if (getTickTime > 0.0f)
			{
				skill1_1effect->visible = true;
			}
			else
			{
				skill1_1->visible = false;
				skill1_2->visible = true;
				skill1_1effect->visible = false;
				skill1_2effect->visible = true;
				getTickTime = 10.0f; //10�� ���� ������ ����
			}
		}
		if (skill1_2->visible)
		{
			attackCol->colOnOff = true; // ���������� ������ ����
			getTickTime -= DELTA;
			if (getTickTime > 0.0f)
			{
				if (imageColor < 0.7)
				{
					imageColor += 0.0001f;
					skill1_2->color = Color(imageColor, imageColor, imageColor,0.5);
				}
					
			}
			else
			{
				skill1_2effect->visible = false;
				skill1_2->visible = false;
				disappear->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
				disappear->visible = true;
				getTickTime = 1.3f;
				checkSkill_1On = false;
				attackCol->colOnOff = false; //���ݳ� �ݶ��̴� ����
				BSstate = BOSSSTATE::DISAPPEAR;
				skill1_2->color = Color(0.5, 0.5, 0.5, 0.5);
			}
		}

	}
	else if (BSstate == BOSSSTATE::SKILL2)
	{
		if (skill2_1->visible)
		{
			getTickTime -= DELTA;
			if (getTickTime > 0.0f)
			{

			}
			else
			{
				skill2_1->visible = false;
				skill2_2->visible = true;
				getTickTime = 10.0f;
			}
		}
		if (skill2_2->visible)
		{
			getTickTime -= DELTA;
			if (getTickTime > 0.0f)
			{
				float XlocalPos = attackCol->GetLocalPos().x;

				attackCol->SetLocalPosX(XlocalPos);
				attackCol->visible = true;
				attackCol->colOnOff = true;
				skill2_1effect->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
				attackCol->SetLocalPosX(XlocalPos += 0.3f);
			}
			else
			{
				skill2_1effect->visible = false;
				skill2_2->visible = false;
				skill2_1effect->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
				attackCol->visible = false;
				disappear->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
				disappear->visible = true;
				getTickTime = 1.3f;
				checkSkill_2On = false; //��ų��
				attackCol->colOnOff = false; //���ݳ� �ݶ��̴� ����
				BSstate = BOSSSTATE::DISAPPEAR;
			}
		}
	}

	if (hp < 0)
	{
		col->visible = false;
		col->colOnOff = false;
		attackCol->visible = false;
		attackCol->colOnOff = false;
		stand->visible = false;
		attack[0]->visible = false;
		attack[1]->visible = false;
		attack[2]->visible = false;
		appear->visible = false;
		disappear->visible = false;
		skill1_1->visible = false;
		skill1_2->visible = false;
		skill1_1effect->visible = false;
		skill1_2effect->visible = false;
		skill2_1->visible = false;
		skill2_2->visible = false;
		grog->visible = false;
	}
	else if (hp > 0 && hp < 50.0f)
	{
		checkGrog = true;
	}


	col->Update();
	start1->Update();
	start2->Update();
	start3->Update();
	start4->Update();
	stand->Update();
	walk->Update();
	attack[0]->Update();
	attack[1]->Update();
	attack[2]->Update();
	appear->Update();
	disappear->Update();
	skill1_1->Update();
	skill1_2->Update();
	skill1_1effect->Update();
	skill1_2effect->Update();
	skill2_1->Update();
	skill2_2->Update();
	skill2_1effect->Update();
	grog->Update();
	attackCol->Update();
}

void bossFem::Render()
{
	skill1_1effect->Render();
	skill1_2effect->Render();
	skill2_1effect->Render();
	col->Render();
	start1->Render();
	start2->Render();
	start3->Render();
	start4->Render();
	stand->Render();
	walk->Render();
	attack[0]->Render();
	attack[1]->Render();
	attack[2]->Render();
	appear->Render();
	disappear->Render();
	skill1_1->Render();
	skill1_2->Render();
	skill2_1->Render();
	skill2_2->Render();
	grog->Render();
	attackCol->Render();
}

ObRect* bossFem::getCol()
{
	return col;
}

ObRect* bossFem::getAttackCol()
{
	return attackCol;
}

void bossFem::setBossDir(Vector2 _playerPos)
{
	bossDir.x = _playerPos.x - col->GetWorldPos().x;

	if (bossDir.x < 0)
		bossDir = LEFT;
	else if (bossDir.x > 0)
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

void bossFem::setBSGravity(float _gravity)
{
	gravity = _gravity;
}

void bossFem::printBossHp()
{
	cout << "Boss Hp : " << hp << endl;
}

void bossFem::bossAttackColon()
{
	attackCol->colOnOff = true;
}

void bossFem::bossAttackColoff()
{
	attackCol->colOnOff = false;
}

BOSSSTATE bossFem::getBossState()
{
	return BSstate;
}

float bossFem::getBsGetTickTime()
{
	return getTickTime;
}
