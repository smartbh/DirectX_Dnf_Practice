#pragma once

struct Bullet
{
	ObLine arrow;
	ObCircle arrowPet;
	Vector2 firePos;

	//��� ����
	float scalar;
	Vector2 fireDir;

	//�߷�
	float gravity;

	Bullet();
	
	bool Shoot(Vector2 fireDir, float scalar, Vector2 firePos);
	void Update();
	void LateUpdate();
	void Render();
};

