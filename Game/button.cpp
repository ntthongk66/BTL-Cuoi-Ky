#include "button.h"

button::button()
{
	height_frame = 0;
	width_frame = 0;
	
}
button::~button()
{

}

bool button::LoadTexture(const char* path, SDL_Renderer* render)
{
	bool success = LTexture::LoadTexure(path, render);

	if (success)
	{
		width_frame = src.w;
		height_frame = src.h;
	}

	return success;
}

void button::setPos(int x, int y, SDL_Renderer* render)
{
	LTexture::render(x, y, render);

}

bool button::isInside(SDL_Event& e)
{
	bool inside = true;
	if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
	{
		
		int x, y;
		SDL_GetMouseState(&x, &y);
		if (x < src.x )
		{
			inside = false;
		}
		else if (x > src.x + width_frame)
		{
			inside = false;
		}
		else if (y < src.y )
		{
			inside = false;
		}
		else if (y > src.y + height_frame)
		{
			inside = false;
		}

		return inside;
	
	}
	return 0;
}

void button::HandlePlayButton(SDL_Event& e, SDL_Renderer* render, bool& menu, bool& play, bool& quitMenu,Mix_Chunk*sound_effect)
{
	if (isInside(e))
	{
		LoadTexture("asset/button/play_button_red.png", render);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			Mix_PlayChannel(-1, sound_effect, 0);
			play = true;
			quitMenu = true;
			menu = false;
		}
		
	}
	else
	{
		LoadTexture("asset/button/play_button_black.png", render);
	}
}


void button::HandleHowToPlayButton(SDL_Event& e, SDL_Renderer* render, bool& menu, bool& play, bool& quitMenu,bool& HowToPlay, Mix_Chunk* sound_effect)
{
	if (isInside(e))
	{
		LoadTexture("asset/button/get_help_button_red.png", render);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			Mix_PlayChannel(-1, sound_effect, 0);
			play = false;
			quitMenu = false;
			menu = false;
			HowToPlay = true;
		}
	}
	else
	{
		LoadTexture("asset/button/get_help_button_black.png", render);
	}
}

void button::HandleGetBackButton(SDL_Event& e, SDL_Renderer* render, bool& menu, bool& play, bool& quitMenu, bool& howToPlay, bool& upgrade, Mix_Chunk* sound_effect)
{
	if (isInside(e))
	{
		LoadTexture("asset/button/get_back_red_button.png", render);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			Mix_PlayChannel(-1, sound_effect, 0);
			play = false;
			quitMenu = false;
			menu = true;
			howToPlay = false;
			upgrade = false;
		}
	}
	else
	{
		LoadTexture("asset/button/get_back_black_button.png", render);
	}
}

void button::HandleQuitButton(SDL_Event& e, SDL_Renderer* render, bool& quit_game,bool&play, Mix_Chunk* sound_effect)
{
	if (isInside(e))
	{
		LoadTexture("asset/button/quit_red.png", render);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			Mix_PlayChannel(-1, sound_effect, 0);
			quit_game = true;
			play = false;
		}
	}
	else
	{
		LoadTexture("asset/button/quit_black.png", render);
	}
}

void button::HandleReplayButton(SDL_Event& e, SDL_Renderer* render, bool& menu, bool& play, bool& howToPlay, Mix_Chunk* sound_effect,int&score, int&health, int& upgrade_blood, bool& upgrade_once_time, bool& option,  vector<enemy*>& p_list_enemy, vector<enemy_bomb*>& p_list_bomb,int&wave)
{
	if (isInside(e))
	{
		LoadTexture("asset/button/playAgain_red_button.png", render);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			Mix_PlayChannel(-1, sound_effect, 0);
			menu = false;
			howToPlay = false;
			play = true;
			score = 0;
			health = upgrade_blood;
			upgrade_once_time = true;
			option = false;
			// refresh enemy wave
			p_list_enemy.erase(p_list_enemy.begin(), p_list_enemy.begin() + p_list_enemy.size());
			p_list_bomb.erase( p_list_bomb.begin(), p_list_bomb.begin() + p_list_bomb.size());
			wave = 0;
		}
	}
	else
	{
		LoadTexture("asset/button/playAgain_black_button.png", render);
	}
}

void button::HandleMenuButton(SDL_Event& e, SDL_Renderer* render, bool& menu, bool& play, bool& quit_menu, int& score, int& health, int &upgrade_blood,Mix_Chunk* sound_effect, bool& upgrade_once_time, bool& option,  vector<enemy*>& p_list_enemy, vector<enemy_bomb*>& p_list_bomb, int &wave)
{
	if (isInside(e))
	{
		LoadTexture("asset/button/menu_red.png", render);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			Mix_PlayChannel(-1, sound_effect, 0);
			menu = true;
			quit_menu = false;
			upgrade_once_time = true;
			play = false;
			score = 0;
			health = upgrade_blood;
			option = false;
			// refresh enemy wave
			p_list_enemy.erase(p_list_enemy.begin(), p_list_enemy.begin() + p_list_enemy.size());
			p_list_bomb.erase( p_list_bomb.begin(), p_list_bomb.begin() + p_list_bomb.size());
			wave = 0;
		}
	}
	else
	{
		LoadTexture("asset/button/menu_black.png", render);
	}
}

void button::HandleUpgradeButton(SDL_Event& e, SDL_Renderer* render, bool& menu, bool& play,  bool& HowToPlay, bool& upgrade, Mix_Chunk* sound_effect)
{
	if (isInside(e))
	{
		LoadTexture("asset/button/upgrade_red_button.png", render);
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			Mix_PlayChannel(-1, sound_effect, 0);
			menu = false;
			HowToPlay = false;
			upgrade = true;
			play = false;
			
		}
	}
	else
	{
		LoadTexture("asset/button/upgrade_black_button.png", render);
	}
}

void button::HandleUpgrade(SDL_Event& e, SDL_Renderer* render, int& money_need_to_upgrade, int& current_upgraded, int& upgrade_plus,int&current_money,Mix_Chunk* sound_effect)
{
	if (isInside(e))
	{
		LoadTexture("asset/button/upgrade_red.png", render);
		if (e.type == SDL_MOUSEBUTTONDOWN&&current_money>=money_need_to_upgrade)
		{
			
			Mix_PlayChannel(-1, sound_effect, 0);
			current_upgraded += upgrade_plus; // ex: if your dam current is 1 then it will be plused to 1+upgrade_plus
			current_money -= money_need_to_upgrade;

		}
	}
	else
	{
		LoadTexture("asset/button/upgrade_black.png", render);
	}
}

void button::HandleOptionButton(SDL_Event& e, SDL_Renderer* render, bool& option, Mix_Chunk* sound_effect)
{
	if (isInside(e))
	{
		LoadTexture("asset/button/option_button_red.png", render);
		if (e.type == SDL_MOUSEBUTTONDOWN )
		{

			Mix_PlayChannel(-1, sound_effect, 0);
			option = true;

		}
	}
	else
	{
		LoadTexture("asset/button/option_button_black.png", render);
	}
}
