#pragma once
class Main : public Scene
{
private:
	ObImage*	bg1; //���
	ObImage*	bg2;
	ObRect*		bgCol; //���Ʒ� �浹ü ����

	DnFPlayer*	player; //�÷��̾�


public:
	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;
};
