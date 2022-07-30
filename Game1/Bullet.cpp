#include "stdafx.h"

Bullet::Bullet()
{
	//ȭ��
	arrow.SetWorldPos(Vector2(2000.0f, 2000.0f));
	arrow.scale.x = 15.0f;
	arrow.scale.y = 15.0f;
	arrow.visible = false;

	arrowPet.SetParentRT(arrow);
	arrowPet.SetLocalPos(Vector2(30.0f, 30.0f));
	arrowPet.scale.x = 15.0f;
	arrowPet.scale.y = 15.0f;
	arrowPet.axis = true;
	arrowPet.visible = false;
}

bool Bullet::Shoot(Vector2 fireDir, float scalar, Vector2 firePos)
{
	if (arrow.visible == false)
	{
		arrow.visible = true;
		arrowPet.visible = true;

		//�߻� �������� �÷��̾� ��ġ�� �޾ƿ�
		//arrow.SetWorldPos(player.GetWorldPos());
		arrow.SetWorldPos(firePos);

		this->fireDir = fireDir;
		this->scalar = scalar * 6.0f;

		gravity = 0.0f;
		arrowPet.rotation2 = 0.0f;

		//this->scalar = scalar;
		//				150 ~ 450
		//this->scalar = -scalar * 2.0f;

		return true;
	}

	return false;
}

void Bullet::Update()
{
	if (not arrow.visible) return;

	//scalar += 300.0f * DELTA;
	//cout << scalar << endl;

	gravity += 600.0f * DELTA;

	Vector2 velocity = fireDir * scalar + DOWN * gravity;
	//Vector2 velocity = fireDir * scalar;

	arrow.MoveWorldPos(velocity * DELTA); //ȭ�� ������
	arrowPet.rotation2 += 360.0f * ToRadian * DELTA;

	arrow.rotation = Utility::DirToRadian(velocity);

	arrow.Update();
	arrowPet.Update();

	//Vector2 dis = player.GetWorldPos() - arrow.GetWorldPos();
	//float length = dis.Length();

	//if (length > 1468)
	//{
	//	arrow.visible = false;
	//	arrowPet.visible = false;
	//}
}

void Bullet::LateUpdate()
{
	//�浹����

	//���� ��
	if (arrow.GetWorldPos().y >= app.GetHeight() * 0.5f + CAM->position.y)
	{
		/*arrow.visible = false;
		arrowPet.visible = false;*/

		//������ȯ
		fireDir.y *= -1.0f;
		gravity *= -1.0f;

		gravity *= 0.8f;
		scalar *= 0.8f;

		//��ġ��ȯ
		arrow.SetWorldPosY(app.GetHeight() * 0.5f + CAM->position.y);
	}

	//�Ʒ� ��
	if (arrow.GetWorldPos().y <= -app.GetHeight() * 0.5f + CAM->position.y)
	{
		/*arrow.visible = false;
		arrowPet.visible = false;*/

		//������ȯ
		fireDir.y *= -1.0f;
		gravity *= -1.0f;

		gravity *= 0.8f;
		scalar *= 0.8f;

		//��ġ��ȯ
		arrow.SetWorldPosY(-app.GetHeight() * 0.5f + CAM->position.y);
	}

	//���ʺ�
	if (arrow.GetWorldPos().x >= app.GetWidth() * 0.5f + CAM->position.x)
	{
		/*arrow.visible = false;
		arrowPet.visible = false;*/

		//������ȯ
		fireDir.x *= -1.0f;

		scalar *= 0.8f;

		//��ġ��ȯ
		arrow.SetWorldPosX(app.GetWidth() * 0.5f + CAM->position.x);
	}

	if (arrow.GetWorldPos().x <= -app.GetWidth() * 0.5f + CAM->position.x)
	{
		/*arrow.visible = false;
		arrowPet.visible = false;*/

		//������ȯ
		fireDir.x *= -1.0f;

		scalar *= 0.8f;

		//��ġ��ȯ
		arrow.SetWorldPosX(-app.GetWidth() * 0.5f + CAM->position.x);
	}
}

void Bullet::Render()
{
	arrow.Render();
	arrowPet.Render();
}
