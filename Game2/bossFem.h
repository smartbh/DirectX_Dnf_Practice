#pragma once
enum class BOSSSTATE
{
	STAND,
	ATTACK,
	WALK,
	DIE,
	GROG,

	START,
	APPEAR,
	DISAPPEAR,
	SKILL1,
	SKILL2,
	SKILL3,
	SKILL4
};

//보스 추가 상태,
//시작, 사라짐, 나타남, 스킬1~4

class bossFem
{
private:
	ObImage*		start1;
	ObImage*		start2;
	ObImage*		start3;
	ObImage*		start4;

	ObImage*		stand;
	ObImage*		attack[3];
	ObImage*		walk;
	ObImage*		die;
	ObImage*		appear;
	ObImage*		disappear;
	ObImage*		grog;
	//공격모션 나눠서
	ObImage*		skill1_1; //한번만
	ObImage*		skill1_2; //시간동안 루프
	ObImage*		skill2_1; //같음
	ObImage*		skill2_2; 
	
	ObImage*		skill1_1effect;  //한번만
	ObImage*		skill1_2effect;  //시간동안 루프



	Vector2			dir;
	BOSSSTATE		BSstate;
	ObRect*			col; //콜라이더
	ObRect*			attackCol; //공격 콜라이더

	float			getTickTime;
	float			Timer;
	float			damagingTime;
	float			gravity;
	float			imageColor;

	bool			isDamaged;
	bool			checkGrog;
	bool			checkSkill_1On;
	bool			checkSkill_2On;

	float			hp;
	Vector2			bossDir;
	int				attackCount;
	int				motionRand;

public:
	bossFem();
	~bossFem();

	void			Update();
	void			Render();
	ObRect*			getCol();
	ObRect*			getAttackCol();
	void			setBossDir(Vector2 _playerPos);
	void			TakeDamage(int damage);
	void			setBSGravity(float _gravity);
	void			printBossHp();
	void			bossAttackColon();
	void			bossAttackColoff();
	BOSSSTATE		getBossState();
	float			getBsGetTickTime();
};

