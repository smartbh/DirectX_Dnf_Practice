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
	ObImage*	bg1; //���
	ObImage*	bg2;
	
	ObImage*	bossPortrait;
	ObImage*	playerPortrait;

	ObImage*	blackBar;
	ObImage*	blackBar2;

	ObRect*		bossHPbar;
	ObRect*		playerHPbar;

	ObRect*		bgCol; //���Ʒ� �浹ü ����

	DnFPlayer*	player; //�÷��̾�
	bossFem *	boss;

	FLOOR		floors[3];
	WALL		walls[2];

	float		getTickTime;
	float		bgColor;

	float		startSceneTime;


public:
	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;
};
