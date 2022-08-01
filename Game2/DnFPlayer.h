#pragma once
enum class PLSTATE
{
	START,
	STAND,
	STAND2,
	SIT,
	ATTACK,
	WALK_R,
	WALK_L,
	RUN_R,
	RUN_L,
	DIE,
	APPEAR,
	DISAPPEAR,
	GORG,
	SKILL1,
	SKILL2,
	SKILL3,
	SKILL4
};

class DnFPlayer
{
private:
	Vector2			dir;
	ObRect*			col;
	PLSTATE			state;
	
	float			hp;

	float			damagingTime;
	float			standTime;
	float			getTickTime;
	float			Timer;

	float			gravity;//�߷�


	int				attackCount; //����Ƚ�� �ٴ�
	int				walkCount; //�ȱ� ������ Ƚ��(2�� = run)


	/// <summary>
	/// �ִϸ��̼� �̹��� ����
	/// </summary>
	/// stand 1~2
	ObImage*	stand1;
	ObImage*	stand2;
	
	/// <summary>
	/// walk
	/// </summary>
	ObImage*	walk;

	/// <summary>
	/// run
	/// </summary>
	ObImage*	run1;
	ObImage*	run2;




public:

	DnFPlayer();
	~DnFPlayer();

	void		Update();
	void		Render();
	ObRect*		getCol();
	float		getPlGravity();
	void		setPlGravity();
	void		TakeDamage(int damage);
};

