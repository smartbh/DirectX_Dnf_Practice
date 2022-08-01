#pragma once
class Main : public Scene
{
private:
	ObImage*	bg1; //배경
	ObImage*	bg2;
	ObRect*		bgCol; //배경아래 충돌체 발판

	DnFPlayer*	player; //플레이어


public:
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;
};
