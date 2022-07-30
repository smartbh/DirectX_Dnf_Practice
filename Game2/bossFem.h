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

//���� �߰� ����,
//����, �����, ��Ÿ��, ��ų1~4

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
	ObImage*		skill[4]; //���ݸ�� ������

	Vector2			dir;
	BOSSSTATE		BSstate;
	ObRect*			col; //�ݶ��̴�

	float			getTickTime;
	float			Timer;
	int				attackCount;

public:
	bossFem();
	~bossFem();

	void Update();
	void Render();
	ObRect* getCol();
	void TakeDamage(int damage);
};

