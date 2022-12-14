#include "stdafx.h"

DnFPlayer::DnFPlayer()
{
	col = new ObRect();
	col->scale = Vector2(120.0f, 300.0f) / 2.0f;
	col->SetWorldPos(Vector2(-450.0f, 450.0f));
	col->pivot = OFFSET_B;
	col->isFilled = false;
	col->visible = false;
	col->collider = COLLIDER::RECT;


	//무기 콜라이더
	weaponCol = new ObRect();
	weaponCol->SetParentRT(*col);
	weaponCol->scale = Vector2(120.0f, 300.0f) / 2.0f;
	weaponCol->SetLocalPos(Vector2(0.0f, 50.0f));
	weaponCol->pivot = OFFSET_N;
	weaponCol->isFilled = false;
	weaponCol->visible = false;
	weaponCol->color = Color(1.0f, 0.0f, 0.0f, 1.0f);
	weaponCol->collider = COLLIDER::RECT;

	/* 애니메이션 모음 */
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
	jump->maxFrame.x = 5;
	jump->scale.x = 372.0f * 1.5f;
	jump->scale.y = 231.0f * 1.5f;
	jump->SetLocalPosY(60.0f);
	jump->pivot = OFFSET_N;
	jump->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
	jump->visible = false;

	jumpAttack = new ObImage(L"PLjumpattack.png");
	jumpAttack->SetParentRT(*col);
	jumpAttack->maxFrame.x = 6;
	jumpAttack->scale.x = 372.0f * 1.5f;
	jumpAttack->scale.y = 231.0f * 1.5f;
	jumpAttack->SetLocalPosY(60.0f);
	jumpAttack->pivot = OFFSET_N;
	jumpAttack->ChangeAnim(ANIMSTATE::ONCE, 0.05f);
	jumpAttack->visible = false;

	//attack 1~6?
	attack1 = new ObImage(L"PLattack1.png");
	attack1->SetParentRT(*col);
	attack1->maxFrame.x = 5;
	attack1->scale.x = 372.0f * 1.5f;
	attack1->scale.y = 231.0f * 1.5f;
	attack1->SetLocalPosY(60.0f);
	attack1->pivot = OFFSET_N;
	attack1->ChangeAnim(ANIMSTATE::ONCE, 0.05f);
	attack1->visible = false;
	//0.25

	attack2 = new ObImage(L"PLattack2.png");
	attack2->SetParentRT(*col);
	attack2->maxFrame.x = 4;
	attack2->scale.x = 372.0f * 1.5f;
	attack2->scale.y = 231.0f * 1.5f;
	attack2->SetLocalPosY(90.0f);
	attack2->pivot = OFFSET_N;
	attack2->ChangeAnim(ANIMSTATE::ONCE, 0.05f);
	attack2->visible = false;
	//0.2

	attack3 = new ObImage(L"PLattack3.png");
	attack3->SetParentRT(*col);
	attack3->maxFrame.x = 9;
	attack3->scale.x = 372.0f * 1.5f;
	attack3->scale.y = 231.0f * 1.5f;
	attack3->SetLocalPosY(60.0f);
	attack3->pivot = OFFSET_N;
	attack3->ChangeAnim(ANIMSTATE::ONCE, 0.05f);
	attack3->visible = false;
	//0.45
	attack4 = new ObImage(L"PLattack4.png");
	attack4->SetParentRT(*col);
	attack4->maxFrame.x = 4;
	attack4->scale.x = 372.0f * 1.5f;
	attack4->scale.y = 231.0f * 1.5f;
	attack4->SetLocalPosY(60.0f);
	attack4->pivot = OFFSET_N;
	attack4->ChangeAnim(ANIMSTATE::LOOP, 0.05f);
	attack4->visible = false;
	//0.2

	// skill 1 ~ 4
	skill1 = new ObImage(L"PLskill1_dash.png"); //대쉬
	skill1->SetParentRT(*col);
	skill1->maxFrame.x = 11;
	skill1->scale.x = 372.0f * 1.5f;
	skill1->scale.y = 231.0f * 1.5f;
	skill1->SetLocalPosY(60.0f);
	skill1->pivot = OFFSET_N;
	skill1->ChangeAnim(ANIMSTATE::ONCE, 0.05f);
	skill1->visible = false;
	//1.1

	skill2 = new ObImage(L"PLskill2_attack.png"); //찌르기
	skill2->SetParentRT(*col);
	skill2->maxFrame.x = 13;
	skill2->scale.x = 372.0f * 1.5f;
	skill2->scale.y = 231.0f * 1.5f;
	skill2->SetLocalPosY(60.0f);
	skill2->pivot = OFFSET_N;
	skill2->ChangeAnim(ANIMSTATE::ONCE, 0.05f);
	skill2->visible = false;
	//1.3

	///기본 변수
	state = PLSTATE::STAND;
	getTickTime = 0.0f;
	standTime = 0.0f;
	Timer = 0.0f;
	hp = 100.0f;

	attackTrigger1 = false;
	attackTrigger2 = false;
	attackTrigger3 = false;
	attackTrigger4 = false;

	isDamaged = false;

	soundRand = 0;

	playerDir = RIGHT;

	/// <summary>
	/// 사운드 작업, 플레이어
	/// </summary>
	SOUND->AddSound("player_stand2-1.wav", "PLSTAND1"); //웃음
	SOUND->AddSound("player_stand2-2.wav", "PLSTAND2"); //시끄럽군
	SOUND->AddSound("player_attack1.wav", "PLATTACK1"); //공격1
	SOUND->AddSound("player_attack2.wav", "PLATTACK2"); //공격2
	SOUND->AddSound("player_attack3.wav", "PLATTACK3"); //공격3
	SOUND->AddSound("player_attack4.wav", "PLATTACK4"); //공격4
	SOUND->AddSound("player_jump.wav", "PLJUMP"); //점프
	SOUND->AddSound("player_skill1,2.wav", "PLSKILLBOTH"); //스킬 둘다 쓸수있게
	SOUND->AddSound("player_skill1-1.wav", "PLSKILL11"); //스킬1-1 (랜덤)
	SOUND->AddSound("player_skill1-2.wav", "PLSKILL12"); 
	SOUND->AddSound("player_skill1-3.wav", "PLSKILL13"); 
	SOUND->AddSound("player_skill2.wav", "PLSKILL21");  //스킬2
	SOUND->AddSound("player_skill2-2.wav", "PLSKILL22"); 
	
	//사운드 작업, 무기,공격
	SOUND->AddSound("sword_attack1.wav", "SATTACK1"); //검 공격1 사운드 랜덤
	SOUND->AddSound("sword_attack1-1.wav", "SATTACK11");
	SOUND->AddSound("sword_attack1-2.wav", "SATTACK12");//여기까지
	SOUND->AddSound("sword_attack2.wav", "SATTACK2");
	SOUND->AddSound("sword_attack3.wav", "SATTACK3");
	SOUND->AddSound("sword_attack4.wav", "SATTACK4");
	SOUND->AddSound("sword_skill1.wav", "SSKILL1"); 
	SOUND->AddSound("sword_skill2.wav", "SSKILL2");
}

DnFPlayer::~DnFPlayer()
{

}

void DnFPlayer::Update()
{
	/////플레이어 중력
	col->MoveWorldPos(DOWN * gravity * DELTA);
	gravity += 700.0f * DELTA;


	//데미지 입을시 변환
	if (isDamaged) //update에, isDamaged가 true면
	{
		damagingTime -= DELTA;

		stand1->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 0.5f);
		stand2->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 0.5f);
		walk->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 0.5f);
		run1->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 0.5f);
		run2->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 0.5f);
		jump->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 0.5f);
		jumpAttack->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 0.5f);
		attack1->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 0.5f);
		attack2->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 0.5f);
		attack3->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 0.5f);
		attack4->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 0.5f);
		skill1->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 0.5f);
		skill2->color = Color(RANDOM->Float(0.5f, 1.0f), 0.5f, 0.5f, 0.5f);
		
		if (damagingTime < 0.0f)
		{
			stand1->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			stand2->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			walk->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			run1->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			run2->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			jump->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			jumpAttack->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			attack1->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			attack2->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			attack3->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			attack4->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			skill1->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			skill2->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			isDamaged = false;
		}

	}


	/// <summary>
	/// 플레이어 조작
	/// </summary>
	if (state == PLSTATE::STAND)
	{
		//소리 한번 초기화
		SOUND->Stop("PLSTAND1");
		SOUND->Stop("PLSTAND2");
		SOUND->Stop("PLATTACK1");
		SOUND->Stop("PLATTACK2");
		SOUND->Stop("PLATTACK3");
		SOUND->Stop("PLATTACK4");
		SOUND->Stop("PLJUMP");
		SOUND->Stop("PLSKILLBOTH");
		SOUND->Stop("PLSKILL11");
		SOUND->Stop("PLSKILL12");
		SOUND->Stop("PLSKILL13");
		SOUND->Stop("PLSKILL21");
		SOUND->Stop("PLSKILL22");

		SOUND->Stop("SATTACK1");
		SOUND->Stop("SATTACK11");
		SOUND->Stop("SATTACK12");
		SOUND->Stop("SATTACK2");
		SOUND->Stop("SATTACK3");
		SOUND->Stop("SATTACK4");
		SOUND->Stop("SSKILL1");
		SOUND->Stop("SSKILL2");

		weaponCol->colOnOff = false;
		weaponCol->visible = false;
		weaponCol->scale = Vector2(120.0f, 300.0f) / 2.0f;
		weaponCol->SetLocalPos(Vector2(0.0f, 70.0f));

		if (playerDir == RIGHT) //오른쪽 스탠딩
		{
			jump->visible = false; //점프 끝났으니

			stand1->reverseLR = false; //우측, 기본이 false
			stand2->reverseLR = false;

			walk->reverseLR = false;
			jump->reverseLR = false;
			run2->reverseLR = false;

			attack1->reverseLR = false;
			attack2->reverseLR = false;
			attack3->reverseLR = false;
			attack4->reverseLR = false;

			skill1->reverseLR = false;
			skill2->reverseLR = false;

			stand1->visible = true;

			standTime += DELTA;

			//cout << standTime << endl;

			if (standTime > 10.0f) //가만히 있는지 10초정도 지나면
			{
				soundRand = RANDOM->Int(0, 1);
				switch (soundRand)
				{
				case 0:
					SOUND->Play("PLSTAND1");
					break;
				case 1:
					SOUND->Play("PLSTAND2");
					break;
				}
				state = PLSTATE::STAND2;
				stand1->visible = false;
				stand2->visible = true;
				getTickTime = 1.7f; //stand2의 애니메이션 출력 시간
			}

			if (INPUT->KeyDown(VK_RIGHT))
			{
				//cout << "우로 걷기시작" << endl;
				stand1->visible = false;
				walk->visible = true;
				playerDir = RIGHT;
				standTime = 0.0f;
				getTickTime = 0.5f;
				state = PLSTATE::WALK_R;
			}
			else if (INPUT->KeyDown(VK_LEFT))
			{
				//cout << "좌로 걷기시작" << endl;
				stand1->visible = false;
				walk->reverseLR = true;
				walk->visible = true;
				playerDir = LEFT;
				standTime = 0.0f;
				getTickTime = 0.5f;
				state = PLSTATE::WALK_L;
			}

			if (INPUT->KeyDown('C'))
			{
				SOUND->Play("PLJUMP");
				//cout << "점프" << endl;
				state = PLSTATE::JUMP;
				jump->ChangeAnim(ANIMSTATE::ONCE, 0.05f);
				stand1->visible = false;
				jump->visible = true;
				gravity = -700.0f;
			}

			if (INPUT->KeyDown('Z')) //일반공격
			{
				SOUND->Play("PLATTACK1");

				soundRand = RANDOM->Int(0, 2);
				switch (soundRand)
				{
				case 0:
					SOUND->Play("SATTACK1");
					break;
				case 1:
					SOUND->Play("SATTACK11");
					break;
				case 2:
					SOUND->Play("SATTACK12");
					break;
				}
				weaponCol->visible = false;
				stand1->visible = false;

				attack1->visible = true;
				attack1->ChangeAnim(ANIMSTATE::ONCE, 0.05f);
				weaponCol->colOnOff = true;
				weaponCol->scale = Vector2( 200.0f, 100.0f);
				weaponCol->SetLocalPos(Vector2 (150.0f,50.0f));
				attackTrigger1 = true;
				getTickTime = 0.25f;
				state = PLSTATE::ATTACK;
				//cout << "공격1" << endl;
				
			}

			if (INPUT->KeyDown('A')) //스킬1
			{
				soundRand = RANDOM->Int(0, 3);
				switch (soundRand)
				{
				case 0:
					SOUND->Play("PLSKILLBOTH");
					break;
				case 1:
					SOUND->Play("PLSKILL11");
					break;
				case 2:
					SOUND->Play("PLSKILL12");
					break;
				case 3:
					SOUND->Play("PLSKILL13");
					break;
				}

				SOUND->Play("SSKILL1");
				weaponCol->visible = false;
				stand1->visible = false;

				weaponCol->colOnOff = true;
				weaponCol->scale = Vector2(200.0f, 100.0f);
				weaponCol->SetLocalPos(Vector2(150.0f, 50.0f));

				skill1->visible = true;
				skill1->ChangeAnim(ANIMSTATE::ONCE, 0.05f);
				getTickTime = 1.1f;
				state = PLSTATE::SKILL1;
				//cout << "스킬1 대쉬" << endl;
			}
			else if (INPUT->KeyDown('S')) //스킬2
			{
				soundRand = RANDOM->Int(0, 2);
				switch (soundRand)
				{
				case 0:
					SOUND->Play("PLSKILLBOTH");
					break;
				case 1:
					SOUND->Play("PLSKILL21");
					break;
				case 2:
					SOUND->Play("PLSKILL22");
					break;
				}

				SOUND->Play("SSKILL2");
				weaponCol->visible = false;
				stand1->visible = false;

				weaponCol->colOnOff = true;
				weaponCol->scale = Vector2(200.0f, 300.0f);
				weaponCol->SetLocalPos(Vector2(150.0f, 50.0f));

				skill2->visible = true;
				skill2->ChangeAnim(ANIMSTATE::ONCE, 0.05f);
				getTickTime = 1.3f;
				state = PLSTATE::SKILL2;
				//cout << "스킬1 찌르기" << endl;
			}
		}

		if (playerDir == LEFT) //왼쪽 스탠딩
		{
			jump->visible = false; //점프 끝났으니

			stand1->reverseLR = true; //좌측, 기본이 false
			stand2->reverseLR = true; 
			walk->reverseLR = true; 
			jump->reverseLR = true; 
			run2->reverseLR = true; 
			attack1->reverseLR = true; 
			attack2->reverseLR = true; 
			attack3->reverseLR = true; 
			attack4->reverseLR = true; 

			skill1->reverseLR = true;
			skill2->reverseLR = true;

			stand1->visible = true;

			standTime += DELTA;

			//cout << standTime << endl;

			if (standTime > 10.0f) //가만히 있는지 10초정도 지나면
			{
				state = PLSTATE::STAND2;
				stand1->visible = false;
				stand2->visible = true;
				getTickTime = 1.7f; //stand2의 애니메이션 출력 시간
			}

			if (INPUT->KeyDown(VK_LEFT))
			{
				//cout << "걷기시작" << endl;
				stand1->visible = false;
				walk->visible = true;
				playerDir = LEFT;
				standTime = 0.0f;
				getTickTime = 0.5f;
				state = PLSTATE::WALK_L;
			}

			else if (INPUT->KeyDown(VK_RIGHT))
			{
				////cout << "걷기시작" << endl;
				stand1->visible = false;
				walk->reverseLR = false;
				walk->visible = true;
				playerDir = RIGHT;
				standTime = 0.0f;
				getTickTime = 0.5f;
				state = PLSTATE::WALK_R;
			}

			if (INPUT->KeyDown('C'))
			{
				SOUND->Play("PLJUMP");
				////cout << "점프" << endl;
				state = PLSTATE::JUMP;
				jump->ChangeAnim(ANIMSTATE::ONCE, 0.05f);
				stand1->visible = false;
				jump->visible = true;
				gravity = -700.0f;
			}

			if (INPUT->KeyDown('Z'))
			{
				SOUND->Play("PLATTACK1");

				switch (soundRand)
				{
				case 0:
					SOUND->Play("SATTACK1");
					break;
				case 1:
					SOUND->Play("SATTACK11");
					break;
				case 2:
					SOUND->Play("SATTACK12");
					break;
				}

				weaponCol->visible = false;
				stand1->visible = false;

				attack1->visible = true;
				attack1->ChangeAnim(ANIMSTATE::ONCE, 0.05f);
				weaponCol->colOnOff = true;
				weaponCol->scale = Vector2(200.0f, 100.0f);
				weaponCol->SetLocalPos(Vector2(-150.0f, 50.0f));
				attackTrigger1 = true;
				getTickTime = 0.25f;
				state = PLSTATE::ATTACK;
				//cout << "공격1" << endl;
			}

			if (INPUT->KeyDown('A')) //스킬1 돌진
			{
				soundRand = RANDOM->Int(0, 3);
				switch (soundRand)
				{
				case 0:
					SOUND->Play("PLSKILLBOTH");
					break;
				case 1:
					SOUND->Play("PLSKILL11");
					break;
				case 2:
					SOUND->Play("PLSKILL12");
					break;
				case 3:
					SOUND->Play("PLSKILL13");
					break;
				}

				SOUND->Play("SSKILL1");
				weaponCol->visible = false;
				stand1->visible = false;

				weaponCol->colOnOff = true;
				weaponCol->scale = Vector2(200.0f, 100.0f);
				weaponCol->SetLocalPos(Vector2(-150.0f, 50.0f));

				skill1->visible = true;
				skill1->ChangeAnim(ANIMSTATE::ONCE, 0.05f);
				getTickTime = 1.1f;
				state = PLSTATE::SKILL1;
				////cout << "스킬1 대쉬" << endl;
			}
			else if (INPUT->KeyDown('S')) //스킬2 찌르기
			{
				soundRand = RANDOM->Int(0, 2);
				switch (soundRand)
				{
				case 0:
					SOUND->Play("PLSKILLBOTH");
					break;
				case 1:
					SOUND->Play("PLSKILL21");
					break;
				case 2:
					SOUND->Play("PLSKILL22");
					break;
				}

				SOUND->Play("SSKILL2");
				weaponCol->visible = false;

				stand1->visible = false;

				weaponCol->colOnOff = true;
				weaponCol->scale = Vector2(200.0f, 300.0f);
				weaponCol->SetLocalPos(Vector2(-150.0f, 50.0f));

				skill2->visible = true;
				skill2->ChangeAnim(ANIMSTATE::ONCE, 0.05f);
				getTickTime = 1.3f;
				state = PLSTATE::SKILL2;
				////cout << "스킬2 찌르기" << endl;
			}
		}
		
	}
	else if (state == PLSTATE::STAND2)
	{
		getTickTime -= DELTA;
		if (getTickTime > 0.0f)
		{
			////cout << getTickTime << endl;
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
		if (playerDir == RIGHT)
		{
			walk->reverseLR = false;
		}

		else if (playerDir == LEFT)
		{
			walk->reverseLR = true;
		}
		
		if (INPUT->KeyUp(VK_RIGHT)) //걷기 끝내면
		{
			stand1->visible = true;
			walk->visible = false;
			state = PLSTATE::STAND;
		}
		if (INPUT->KeyPress(VK_LEFT)) //왼쪽 전환
		{
			stand1->visible = false;
			walk->reverseLR = true;
			walk->visible = true;
			playerDir = LEFT;
			standTime = 0.0f;
			getTickTime = 0.5f;
			state = PLSTATE::WALK_L;
		}
		else if (INPUT->KeyPress(VK_RIGHT) && INPUT->KeyPress(VK_LSHIFT))//달리기
		{
			walk->visible = false;
			run2->visible = true;
			getTickTime = 0.0f;
			state = PLSTATE::RUN_R;
		}

		else if (INPUT->KeyDown('C'))
		{
			//cout << "점프" << endl;
			state = PLSTATE::JUMP;
			jump->ChangeAnim(ANIMSTATE::ONCE, 0.05f);
			walk->visible = false;
			jump->visible = true;
			gravity = -500.0f;
		}
	}
	else if (state == PLSTATE::WALK_L) //왼쪽으로 걷기
	{
		if (playerDir == RIGHT)
		{
			walk->reverseLR = false;
		}

		else if (playerDir == LEFT)
		{
			walk->reverseLR = true;
		}


		if (INPUT->KeyUp(VK_LEFT))
		{
			playerDir = LEFT;
			stand1->reverseLR = true;
			stand1->visible = true;
			walk->visible = false;
			state = PLSTATE::STAND;
		}
		if (INPUT->KeyPress(VK_RIGHT)) //오른쪽 전환
		{
			stand1->visible = false;
			walk->reverseLR = false;
			walk->visible = true;
			playerDir = RIGHT;
			standTime = 0.0f;
			getTickTime = 0.5f;
			state = PLSTATE::WALK_R;
		}
		else if (INPUT->KeyPress(VK_LEFT) && INPUT->KeyPress(VK_LSHIFT))//달리기
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
			//cout << "점프" << endl;
			state = PLSTATE::JUMP;
			jump->ChangeAnim(ANIMSTATE::ONCE, 0.05f);
			walk->visible = false;
			jump->reverseLR = true;
			jump->visible = true;
			gravity = -500.0f;
		}
	}
	else if (state == PLSTATE::RUN_R)
	{
		if (playerDir == RIGHT)
		{
			run2->reverseLR = false;
		}

		else if (playerDir == LEFT)
		{
			run2->reverseLR = true;
		}	

		if (INPUT->KeyUp(VK_LSHIFT))
		{
			playerDir = RIGHT;
			run2->visible = false;
			walk->visible = true;
			state = PLSTATE::WALK_R;
		}
		else if (INPUT->KeyPress(VK_LEFT) && INPUT->KeyPress(VK_LSHIFT)) //왼쪽으로 돌때
		{
			playerDir = LEFT;
			run2->reverseLR = true;
			run2->visible = true;
			getTickTime = 0.0f;
			state = PLSTATE::RUN_L;
		}
		if (INPUT->KeyDown('C'))
		{
			//cout << "점프" << endl;
			state = PLSTATE::JUMP;
			jump->ChangeAnim(ANIMSTATE::ONCE, 0.05f);
			run2->visible = false;
			jump->visible = true;
			gravity = -700.0f;
		}

	}
	else if (state == PLSTATE::RUN_L)
	{

		if (playerDir == RIGHT)
		{
			run2->reverseLR = false;
		}

		else if (playerDir == LEFT)
		{
			run2->reverseLR = true;
		}

		if (INPUT->KeyUp(VK_LSHIFT))
		{
			playerDir = LEFT;
			run2->visible = false;
			walk->visible = true;
			state = PLSTATE::WALK_L;
		}
		if (INPUT->KeyPress(VK_RIGHT) && INPUT->KeyPress(VK_LSHIFT)) //오른쪽으로 돌때
		{
			playerDir = RIGHT;
			run2->reverseLR = false;
			run2->visible = true;
			getTickTime = 0.0f;
			state = PLSTATE::RUN_R;
		}
		else if (INPUT->KeyDown('C'))
		{
			//cout << "점프" << endl;
			state = PLSTATE::JUMP;
			jump->ChangeAnim(ANIMSTATE::ONCE, 0.05f);
			run2->visible = false;
			jump->visible = true;
			gravity = -700.0f;
		}
	}
	else if (state == PLSTATE::JUMP) {
		//점프공격 염두
		if (playerDir == RIGHT)
		{
			if (INPUT->KeyDown('Z'))
			{
				weaponCol->visible = false;
				weaponCol->colOnOff = true;
				weaponCol->scale = Vector2(100.0f, 200.0f);
				weaponCol->SetLocalPos(Vector2(30.0f, 30.0f));

				jump->visible = false;
				jumpAttack->visible = true;
				jumpAttack->ChangeAnim(ANIMSTATE::ONCE, 0.05f);
				getTickTime = 0.6f;
				state = PLSTATE::JUMPATTACK;

			}
		}
		if (playerDir == LEFT)
		{
			if (INPUT->KeyDown('Z')) //왼쪽공격
			{
				weaponCol->visible = false;
				weaponCol->colOnOff = true;
				weaponCol->scale = Vector2(100.0f, 200.0f);
				weaponCol->SetLocalPos(Vector2(-30.0f, -30.0f));

				jumpAttack->reverseLR = true;
				jump->visible = false;
				jumpAttack->visible = true;
				jumpAttack->ChangeAnim(ANIMSTATE::ONCE, 0.05f);
				getTickTime = 0.6f;
				state = PLSTATE::JUMPATTACK;
			}
		}
		
	}
	else if (state == PLSTATE::JUMPATTACK)
	{
		//0.6시간 후 다시 점프로
		//공격시 해당 위치에 잠시 고정
		col->SetWorldPos(col->GetWorldPos());
		
		getTickTime -= DELTA;
		if (getTickTime > 0.0f)
		{

		}
		else
		{
			//cout << "시간 끝 애니메이션 변화" << endl;
			jumpAttack->visible = false;
			jump->visible = true;
			getTickTime = 0.0f;
			//cout << "attackCount : " << attackCount << endl;
			state = PLSTATE::JUMP;
		}
	}
	else if (state == PLSTATE::ATTACK) 
	{
		if (attackTrigger1) //2연타
		{
			getTickTime -= DELTA;
			if (getTickTime > 0.0f)
			{

			}
			else
			{
				if (INPUT->KeyDown('Z'))
				{
					SOUND->Play("PLATTACK2");
					SOUND->Play("SATTACK2");
					attackTrigger1 = false;
					attackTrigger2 = true;
					weaponCol->colOnOff = true;
					attack1->visible = false;
					attack2->ChangeAnim(ANIMSTATE::ONCE, 0.05f);
					attack2->visible = true;
					getTickTime = 0.2f;
				}
				if (INPUT->KeyDown('X'))
				{
					attackTrigger1 = false;
					attackTrigger2 = false;
					attackTrigger3 = false;
					attackTrigger4 = false;
					attack1->visible = false;
					attack2->visible = false;
					attack3->visible = false;
					attack4->visible = false;
					stand1->visible = true;
					state = PLSTATE::STAND;
				}
			}
		}
		

		else if (attackTrigger2) //3연타
		{
			getTickTime -= DELTA;
			if (getTickTime > 0.0f)
			{

			}
			else
			{
				if (INPUT->KeyDown('Z'))
				{
					SOUND->Play("PLATTACK3");
					SOUND->Play("SATTACK3");
					attackTrigger2 = false;
					attackTrigger3 = true;
					weaponCol->colOnOff = true;
					attack2->visible = false;
					attack3->ChangeAnim(ANIMSTATE::ONCE, 0.05f);
					attack3->visible = true;
					getTickTime = 0.45f;
				}
				if (INPUT->KeyDown('X'))
				{
					attackTrigger1 = false;
					attackTrigger2 = false;
					attackTrigger3 = false;
					attackTrigger4 = false;
					attack1->visible = false;
					attack2->visible = false;
					attack3->visible = false;
					attack4->visible = false;
					stand1->visible = true;
					state = PLSTATE::STAND;
				}
			}
		}
		else if (attackTrigger3) //3연타
		{
			getTickTime -= DELTA;
			if (getTickTime > 0.0f)
			{

			}
			else
			{
				if (INPUT->KeyDown('Z'))
				{
					//SOUND->Play("PLATTACK4");
					SOUND->Play("SATTACK4");
					attackTrigger3 = false;
					attackTrigger4 = true;
					weaponCol->colOnOff = true;
					attack3->visible = false;
					attack4->ChangeAnim(ANIMSTATE::LOOP, 0.05f);
					attack4->visible = true;
					getTickTime = 1.0f;
				}
				if (INPUT->KeyDown('X'))
				{
					attackTrigger1 = false;
					attackTrigger2 = false;
					attackTrigger3 = false;
					attackTrigger4 = false;
					attack1->visible = false;
					attack2->visible = false;
					attack3->visible = false;
					attack4->visible = false;
					stand1->visible = true;
					state = PLSTATE::STAND;
				}
			}

		}

		else if (attackTrigger4)
		{
			getTickTime -= DELTA;
			if (getTickTime > 0.0f)
			{

			}
			else
			{
				attack4->visible = false;
				stand1->visible = true;
				getTickTime = 0.0f;
				attackTrigger4 = false;
				state = PLSTATE::STAND;
			}

		}

	}

	else if (state == PLSTATE::SKILL1)
	{
		getTickTime -= DELTA;
		if (getTickTime > 0.0f)
		{

		}
		else
		{
			skill1->visible = false;
			stand1->visible = true;
			getTickTime = 0.0f;

			state = PLSTATE::STAND;
		}
	}
	else if (state == PLSTATE::SKILL2) 
	{

		getTickTime -= DELTA;
		if (getTickTime > 0.0f)
		{

		}
		else
		{
			skill2->visible = false;
			stand1->visible = true;
			getTickTime = 0.0f;
			state = PLSTATE::STAND;
		}
	}


	if (hp < 0)
	{


		col->visible = false;
		col->colOnOff = false;

		stand1->visible = false;
		stand2->visible = false;

		walk->visible = false;

		run1->visible = false;
		run2->visible = false;

		jump->visible = false;
		jumpAttack->visible = false;

		attack1->visible = false;
		attack2->visible = false;
		attack3->visible = false;
		attack4->visible = false;

		skill1->visible = false; //대쉬
		skill2->visible = false; //찌르기
	}


	col->Update();
	weaponCol->Update();
	stand1->Update();
	stand2->Update();
	walk->Update();
	run1->Update();
	run2->Update();
	jump->Update();
	jumpAttack->Update();
	attack1->Update();
	attack2->Update();
	attack3->Update();
	attack4->Update();
	skill1->Update();
	skill2->Update();
}

void DnFPlayer::Render()
{
	col->Render();
	weaponCol->Render();
	stand1->Render();
	stand2->Render();
	walk->Render();
	run1->Render();
	run2->Render();
	jump->Render();
	jumpAttack->Render();
	attack1->Render();
	attack2->Render();
	attack3->Render();
	attack4->Render();
	skill1->Render();
	skill2->Render();
}

ObRect* DnFPlayer::getCol()
{
	return col;
}

ObRect* DnFPlayer::getWeaponCol()
{
	return weaponCol;
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

void DnFPlayer::printPlState()
{
	string print_out;

	if (state == PLSTATE::STAND)
	{
		//cout << "state : STAND" << endl;
		print_out = "state : STAND";
		//return print_out;
	}
	else if (state == PLSTATE::WALK_R)
	{
		//cout << "state : WALK_R" << endl;
		print_out = "state : WALK_R";
		//return print_out;
	}
	else if (state == PLSTATE::WALK_L)
	{
		//cout << "state : WALK_L" << endl;
		print_out = "state : WALK_L";
		//return print_out;
	}
	else if (state == PLSTATE::RUN_R)
	{
		//cout << "state : RUN_R" << endl;
		print_out = "state : RUN_R";
		//return print_out;
	}
	else if (state == PLSTATE::RUN_L)
	{
		//cout << "state : RUN_L" << endl;
		print_out = "state : RUN_L";
		//return print_out;
	}
	else if (state == PLSTATE::ATTACK)
	{
		//cout << "state : ATTACK" << endl;
		print_out = "state : ATTACK";
		//return print_out;
	}
	else if (state == PLSTATE::JUMP)
	{
		//cout << "state : JUMP" << endl;
		print_out = "state : JUMP";
		//return print_out;
	}
	//else if (state == PLSTATE::RUN_R)
	//{
	//	//cout << "state : RUN_R" << endl;
	//	print_out = "state : START";
	//	return print_out;
	//}
	//else if (state == PLSTATE::RUN_R)
	//{
	//	//cout << "state : RUN_R" << endl;
	//	print_out = "state : START";
	//	return print_out;
	//}
	//else if (state == PLSTATE::RUN_R)
	//	print_out = "state : START";
	//return print_out;
	//{
	//	//cout << "state : RUN_R" << endl;
	//}

}

void DnFPlayer::printPlayerHp()
{
	cout << "player hp : " << hp << endl;
}

Vector2 DnFPlayer::getPlDir()
{
	if (playerDir == LEFT) {
		//cout << "LEFT" << endl;
		return playerDir;
	}
	else if (playerDir == RIGHT)
	{
		//cout << "RIGHT" << endl;
		return playerDir;
	}
}

void DnFPlayer::TakeDamage(int damage)
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

void DnFPlayer::playerWeaponColon()
{
	weaponCol->colOnOff = true;
}

void DnFPlayer::playerWeaponColoff()
{
	weaponCol->colOnOff = false;
}
