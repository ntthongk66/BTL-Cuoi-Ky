#pragma once
#include"Game_Utlis.h"
#include"LTexture.h"
class Bullet : public LTexture
{
public:
	static const int bullet_vel = 10;

	int Xpos, Ypos;
	Bullet();
	~Bullet();

	void set_vel(double angle);

	void HandleMove(const int &boder_x, const int & boder_y);

	bool dose_bullet_move() { return isMove; }

	void set_move(const bool& x) { isMove = x; }

	double bullet_degrees;


private:
	
	int Xvel, Yvel;
	bool isMove;

	bool isDelete;
};

