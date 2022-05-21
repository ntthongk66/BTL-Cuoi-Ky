#include "rocket.h"

rocket_smoke::rocket_smoke(int x, int y)
{
	//srand(time(NULL));

	mPosX = x + 10 + (rand() % 20);
	mPosY = y + 5 + (rand() % 10);

	mFrame = rand() % 5;

	switch (rand() % 3)
	{
	case 0: mTexture = &gRedTexture; break;
	case 1: mTexture = &gGreenTexture; break;
	case 2: mTexture = &gBlueTexture; break;
	}

}
rocket_smoke::~rocket_smoke()
{
	
}


void rocket_smoke::render(SDL_Renderer* render)
{
	mTexture->render(mPosX, mPosY, render);
	if (mFrame % 2 == 0)
	{
		gShimmerTexture.render(mPosX, mPosY, render);
	}
	mFrame++;
}

bool rocket_smoke::isDead()
{
	return mFrame > 10;
}

//--------------------------
rocket::rocket()
{
	Xpos =51 ;
	Ypos = screen_height-80;

	Xvel = 0;
	Yvel = 0;

	angle = 0;

	is_move = false;

	isDelete = false;

	//---
	for (int i = 0; i < 20; i++)
	{
		smoke[i] = new rocket_smoke(Xpos, Ypos);
	}
	//---
}



rocket::~rocket()
{
	//here too
	for (int i = 0; i < 20; i++)
	{
		delete smoke[i];
	}
}

bool rocket::LoadTexture(const char* path, SDL_Renderer* render)
{
	
	return LTexture::LoadTexure(path, render);
	
	//return true;
}

double rocket::set_angle(int xpos, int ypos, int x_pos, int y_pos)
{
	
	
	double angle = atan2(x_pos - xpos, y_pos - ypos)*180/M_PI;

	return angle;
	
}

void rocket::set_vel(double angle)
{
	/*
	int x;
	int y;
	SDL_GetMouseState(&x, &y);
	angle = atan2(abs(x - Xpos), abs(y - Ypos));*/
	
	Xvel = cos(angle * M_PI / 180) * rocket_vel;
	Yvel = sin(angle * M_PI / 180) * rocket_vel;
}


void rocket::render(int x, int y, SDL_Renderer* render, double angle)
{
	LTexture::render(x, y, render, NULL, angle);
	//here
	renderSmoke(render);
}

//here
//---

 
  void rocket::renderSmoke(SDL_Renderer*render)
{
	for (int i = 0; i < 20; i++)
	{
		if (smoke[i]->isDead())
		{
			delete smoke[i];
			smoke[i] = new rocket_smoke(Xpos, Ypos);
		}
	}
	for (int i = 0; i < 20; i++)
	{
		smoke[i]->render(render);
	}

}
 

//---

void rocket::handleMove(const int& screen_width, const int& screen_height)
{
	Xpos += Xvel;
	Ypos += Yvel;


	if (Xpos >= screen_width || Xpos <= 0)
	{
		isDelete = true;
		is_move = false;
	}
	if (Ypos >= screen_height || Ypos <= 0)
	{
		isDelete = false;
		is_move = false;
	}

}