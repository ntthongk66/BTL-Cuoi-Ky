#pragma once
#include"Game_Utlis.h"
#include"LTexture.h"
class cursor_aim : public LTexture
{
public:

	cursor_aim();
	~cursor_aim();


	bool LoadTexture(const char* path, SDL_Renderer* render);
	void render(SDL_Renderer* render);

	void drawLineAim(SDL_Renderer* render, int x, int y);
	void handdleEvent(SDL_Event& e);


private:

	int Xpos, Ypos;

};

