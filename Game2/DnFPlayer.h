#pragma once
enum class PLSTATE
{
	START,
	STAND,
	SIT,
	ATTACK,
	WALK,
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

	float			getTickTime;
	float			Timer;
	int				attackCount;

	int				motionRand;

	/// <summary>
	/// 애니메이션 이미지 모음
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
	void		TakeDamage(int damage);
};

