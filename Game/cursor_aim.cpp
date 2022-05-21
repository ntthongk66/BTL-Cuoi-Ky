#include "cursor_aim.h"

cursor_aim::cursor_aim()
{
	Xpos = 200;
	Ypos = 200;
}
cursor_aim::~cursor_aim()
{

}

bool cursor_aim::LoadTexture(const char* path, SDL_Renderer* render)
{
	 LTexture::LoadTexure("asset/aim.png", render);
	 return true;

}

void cursor_aim::handdleEvent(SDL_Event& e)
{
	if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		Xpos = x;
		Ypos = y;

	}
}

void cursor_aim::drawLineAim(SDL_Renderer* render,int xPos,int yPos)
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	SDL_SetRenderDrawColor(render, 0, 0, 0, 100);
	SDL_RenderDrawLine(render, xPos,yPos, x, y);

}

void cursor_aim::render(SDL_Renderer*render)
{
	LTexture::render(Xpos, Ypos, render);
}