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
	//���ݸ�� ������
	ObImage*		skill1_1; //�ѹ���
	ObImage*		skill1_2; //�ð����� ����
	ObImage*		skill2_1; //����
	ObImage*		skill2_2; 

	Vector2			dir;
	BOSSSTATE		BSstate;
	ObRect*			col; //�ݶ��̴�
	ObRect*			attackCol; //���� �ݶ��̴�

	float			getTickTime;
	float			Timer;
	float			damagingTime;
	float			gravity;

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

	void		Update();
	void		Render();
	ObRect*		getCol();
	void		setBossDir(Vector2 _playerPos);
	void		TakeDamage(int damage);
	void		setBSGravity(float _gravity);
};

