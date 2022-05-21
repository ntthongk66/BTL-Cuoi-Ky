#include "Bullet.h"

Bullet::Bullet()
{
	Xpos = 51;
	Ypos = screen_height-80;

	Xvel = 0;
	Yvel = 0;

	isDelete = false;

	isMove = false;

	bullet_degrees = 0;
}

Bullet::~Bullet()
{
}


void Bullet::set_vel(double angle)
{
	Xvel = cos(angle * M_PI / 180) * bullet_vel;
	Yvel = sin(angle * M_PI / 180) * bullet_vel;
}

void Bullet::HandleMove(const int&boder_x, const int &boder_y)
{
	Xpos += Xvel;
	Ypos += Yvel;

	if (Xpos <= 0 || Xpos >= screen_width)
	{
		isDelete = true;
		isMove = false;
	}
	if (Ypos <= 0 || Ypos >= screen_height)
	{
		isDelete = true;
		isMove = false;
	}
}