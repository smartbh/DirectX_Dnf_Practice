#pragma once
enum class PLSTATE
{
	STAND,
	STAND2,
	JUMP,
	JUMPATTACK,
	ATTACK,
	WALK_R,
	WALK_L,
	RUN_R,
	RUN_L,
	SKILL1,
	SKILL2,
};

class DnFPlayer
{
private:
	ObRect*			col;
	ObRect*			weaponCol;

	PLSTATE			state;
	
	float			hp;

	bool			isDamaged;
	float			damagingTime;
	float			standTime;
	float			getTickTime;
	float			Timer;

	float			gravity;//중력

	bool			attackTrigger1;
	bool			attackTrigger2;
	bool			attackTrigger3;
	bool			attackTrigger4;

	int				soundRand;


	Vector2			playerDir;

	/// <summary>
	/// 애니메이션 이미지 모음
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
	ObImage* skill1; //대쉬
	ObImage* skill2; //찌르기

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

	void		printPlState();
	void		printPlayerHp();
	Vector2		getPlDir();
	void		TakeDamage(int damage);
	void		playerWeaponColon();
	void		playerWeaponColoff();
};

