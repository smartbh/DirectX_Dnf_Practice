#pragma once
enum class STATE
{
	STAND,
	ATTACK,
	WALK,
	DIE,
	GROG
};
//�⺻ �ʿ� �ִϸ��̼�
//1. ���ĵ�, 2. ����, 3. �ȱ�, 4. ���, 5. �׷α�

class GameCharacter
{
private:
	//����

protected:
	Vector2			dir; //���� ����
	STATE			state; //����
	ObRect*			col; //�ݶ��̴�

	float			getTickTime; //�ִϸ��̼ǿ� Ÿ��
	float			Timer;
	int				attackCount; //���� �ִϿ� ī��Ʈ

public:
	
	float			hp; //ü��
	float			damagingTime; //�ǰ�üũ

	GameCharacter();
	~GameCharacter();

	virtual void Update();
	virtual void Render();
	virtual ObRect* getCol(); //�ݶ��̴� ������
	void TakeDamage(int damage); //������ ������

};

