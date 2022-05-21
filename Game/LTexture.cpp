#include "LTexture.h"


LTexture::LTexture()
{
	src = { 0,0,0,0 };
	tmpTexture = NULL;
}


LTexture::~LTexture()
{
	free();
}

void LTexture::free()
{
	if (tmpTexture != NULL)
	{
		SDL_DestroyTexture(tmpTexture);
		tmpTexture = NULL;
		src = { 0,0,0,0 };

	}
}

bool LTexture::LoadTexure(const char* path, SDL_Renderer* Render)
{
	bool success = true;
	SDL_Surface* loadedSurface = IMG_Load(path);
	SDL_Texture* newTexture = NULL;
	if (loadedSurface == NULL)
	{
		cout << "loadedSurface can not be loaded" << " path: " << path << " " << SDL_GetError() << endl;
		success = false;
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(Render, loadedSurface);

		src.h = loadedSurface->h;
		src.w = loadedSurface->w;

		SDL_FreeSurface(loadedSurface);
	}
	tmpTexture = newTexture;

	return tmpTexture != NULL;
}

void LTexture::render(int x, int y,SDL_Renderer* Render, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	src.x = x;
	src.y = y;
	SDL_RenderCopyEx(Render, tmpTexture, clip, &src, angle, center, flip);
}

bool LTexture::loadFromRenderedText(string text, SDL_Color textColor, SDL_Renderer* render,TTF_Font* font)
{
	free();
	SDL_Surface* textsurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
	if (textsurface == NULL)
	{
		cout << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << endl;
	}
	else
	{
		tmpTexture = SDL_CreateTextureFromSurface(render, textsurface);

		if (tmpTexture == NULL)
		{
			cout << "Unable to create texture from rendered text! SDL Error: " << SDL_GetError() << endl;
		}
		else
		{
			src.w = textsurface->w;
			src.h = textsurface->h;
		}

		SDL_FreeSurface(textsurface);
	}
	return tmpTexture != NULL;
	
}