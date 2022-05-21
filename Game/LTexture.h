#pragma once
#include"Game_Utlis.h"

class LTexture
{
public:
	LTexture();
	~LTexture();

	virtual bool LoadTexure(const char * path, SDL_Renderer* Render);

	void render(int x,int y,SDL_Renderer * Render, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip = SDL_FLIP_NONE);

	bool loadFromRenderedText(string text, SDL_Color textColor, SDL_Renderer* render,TTF_Font* font);

	void free();


	//for colision	
	SDL_Rect get_rect()
	{
		return src;
	}

	int get_width() { return src.w; }
	int get_height() { return src.h; }

protected:
	SDL_Rect src;
	SDL_Texture* tmpTexture;


};

