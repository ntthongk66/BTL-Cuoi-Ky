#include "enemy_bomb.h"
enemy_bomb:: enemy_bomb()
{
	Xpos = 0;
	Ypos = 0;

	Xvel = 0;
	Yvel = 2;

	is_move = false;
	isDelete = false;
	is_explode = false;

	angle_fall = 0;

	angle = 50;

	direction_falling = false;

	damage = 15;

	flip = SDL_FLIP_NONE;

}

enemy_bomb::~enemy_bomb()
{

}

bool enemy_bomb::LoadTexture(const char* path, SDL_Renderer* render)
{
	LTexture::LoadTexure(path, render);
	return true;
}

void enemy_bomb::handleMove(const int& screen_width, const int& screen_height)
{
	
	if (direction_falling)
	{
		Xvel = 1;
		flip = SDL_FLIP_NONE;
		angle_fall += 0.5;
		if (angle_fall > angle) angle_fall = angle;
		//cout << "true" << endl;
	}
	else
	{

		Xvel = -1;
		flip = SDL_FLIP_HORIZONTAL;
		angle_fall -=0.5;
		if (angle_fall < -angle) angle_fall = -angle;
		//cout << "false" << endl;
	}



	Xpos += Xvel;
	Ypos += Yvel;


	if (Xpos >= screen_width || Xpos <= 0)
	{
		isDelete = true;
		is_move = false;
	}
	if (Ypos >= screen_height  || Ypos <= 0)
	{
		is_explode = true;
		isDelete = true;
		is_move = false;

	}
}

void enemy_bomb::render(int x, int y, SDL_Renderer* render)
{
	
	//cout << angle_fall << endl;

	LTexture::render(x, y, render,NULL ,angle_fall,NULL,flip);
}