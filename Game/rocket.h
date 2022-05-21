#pragma once
#include"Game_Utlis.h"
#include"LTexture.h"



extern LTexture gRedTexture;
extern LTexture gGreenTexture;
extern LTexture gBlueTexture;
extern LTexture gShimmerTexture;


//--particle---
 class rocket_smoke
{
public:
	
	~rocket_smoke();

	rocket_smoke(int x, int y);

	void render(SDL_Renderer* render);

	bool isDead();

	

private:

	int mPosX, mPosY;

	int mFrame;

	LTexture* mTexture;
};


//-------------



class rocket:public LTexture
{
public:
	
	rocket();
	~rocket();

	int Xpos;
	int Ypos;

	static const int rocket_vel = 13;

	void set_vel(double angle);

	bool LoadTexture(const char* path, SDL_Renderer* render);

	void render(int x, int y, SDL_Renderer* render, double angle);

	void handleMove(const int& screen_width, const int& screen_height);

	bool dose_rocket_move() { return is_move; }

	void set_move(const bool& x) { is_move = x; }

	void set_pos(int x, int y) { Xpos = x; Ypos = y; }

	double set_angle(int xpos, int ypox, int x_pos, int y_pos);

	double angle;

private:
	//particle
	rocket_smoke* smoke[20];
	void renderSmoke(SDL_Renderer*render);

	int Xvel;
	int Yvel;

	bool is_move;
	bool isDelete;

};