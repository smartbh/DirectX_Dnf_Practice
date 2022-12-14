#pragma once
struct FLOOR
{
	ObImage* img;
	ObRect* col;
};

struct WALL
{
	ObImage* img;
	ObRect* col;
};


class Main : public Scene
{
private:
	ObImage*	bg1; //배경
	ObImage*	bg2;
	
	ObImage*	bossPortrait;
	ObImage*	playerPortrait;

	ObImage*	blackBar;
	ObImage*	blackBar2;

	ObRect*		bossHPbar;
	ObRect*		playerHPbar;

	ObRect*		bgCol; //배경아래 충돌체 발판

	DnFPlayer*	player; //플레이어
	bossFem *	boss;

	FLOOR		floors[3];
	WALL		walls[2];

	float		getTickTime;
	float		bgColor;

	float		startSceneTime;


public:
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;
};
