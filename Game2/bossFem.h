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
	ObImage*		skill[4]; //공격모션 나눠서

	Vector2			dir;
	BOSSSTATE		BSstate;
	ObRect*			col; //콜라이더

	float			getTickTime;
	float			Timer;
	float			damagingTime;
	bool			isDamaged;

	float			hp;
	Vector2			bossDir;
	int				attackCount;

public:
	bossFem();
	~bossFem();

	void		Update();
	void		Render();
	ObRect*		getCol();
	void		setBossDir(Vector2 _playerPos);
	void		TakeDamage(int damage);
};

