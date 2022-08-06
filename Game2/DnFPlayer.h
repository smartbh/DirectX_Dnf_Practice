#pragma once
enum class PLSTATE
{
	START,
	STAND,
	STAND2,
	SIT,
	JUMP,
	JUMPATTACK,
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
	ObRect*			weaponCol;

	PLSTATE			state;
	
	float			hp;

	float			damagingTime;
	float			standTime;
	float			getTickTime;
	float			Timer;

	float			gravity;//�߷�


	int				attackCount; //����Ƚ�� �ٴ�
	int				walkCount; //�ȱ� ������ Ƚ��(2�� = run)

	Vector2			playerDir;

	/// <summary>
	/// �ִϸ��̼� �̹��� ����
	/// </summary>
	/// stand 1~2
	ObImage*		stand1;
	ObImage*		stand2;
	
	/// <summary>
	/// walk
	/// </summary>
	ObImage*		walk;

	/// <summary>
	/// run
	/// </summary>
	ObImage*		run1;
	ObImage*		run2;

	//jump
	ObImage*		jump;
	ObImage*		jumpAttack;
	
	/* attack 1~4 */
	ObImage*		attack1;
	ObImage*		attack2;
	ObImage*		attack3;
	ObImage*		attack4;

	/* skill 1~4 */
	ObImage* skill1; //�뽬
	ObImage* skill2; //���

public:

	DnFPlayer();
	~DnFPlayer();

	void		Update();
	void		Render();
	ObRect*		getCol();
	ObRect*		getWeaponCol();
	

	float		getPlGravity();
	void		setPlGravity(float number);

	PLSTATE		getPlState();
	void		setPlState(PLSTATE new_state);

	int			getPlAttackCount();
	void		printPlState();
	void		printPlayerHp();
	Vector2		getPlDir();
	void		TakeDamage(int damage);
	void		playerWeaponColon();
	void		playerWeaponColoff();
};

