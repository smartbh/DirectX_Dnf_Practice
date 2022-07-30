#pragma once
enum class STATE
{
	STAND,
	ATTACK,
	WALK,
	DIE,
	GROG
};
//기본 필요 애니메이션
//1. 스탠드, 2. 공격, 3. 걷기, 4. 사망, 5. 그로기

class GameCharacter
{
private:
	//하하

protected:
	Vector2			dir; //공격 방향
	STATE			state; //상태
	ObRect*			col; //콜라이더

	float			getTickTime; //애니메이션용 타임
	float			Timer;
	int				attackCount; //공격 애니용 카운트

public:
	
	float			hp; //체력
	float			damagingTime; //피격체크

	GameCharacter();
	~GameCharacter();

	virtual void Update();
	virtual void Render();
	virtual ObRect* getCol(); //콜라이더 얻어오기
	void TakeDamage(int damage); //데미지 받을시

};

