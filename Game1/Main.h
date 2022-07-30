#pragma once
#define FMAX 8
#define RMAX 3

struct FLOOR
{
	ObImage* img;
	ObRect* col;
	bool	isVisible;
};

class Main : public Scene
{
private:
	ObImage*	test;
	float		testScale;

	Sonic*		sonic;

	FLOOR		floor[FMAX];
	ObImage*	rock[RMAX];

	ObImage*	bg; //���
	ObImage*	bg2; //��

	ObRect* ui;

	float bgmScale;
	float gunScale;


public:
	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;
};
