#pragma once
#include"Game_Utlis.h"
#include"LTexture.h"
#include"enemy.h"
class button :public LTexture
{
public:
	button();
	~button();

	virtual bool LoadTexture(const char* path, SDL_Renderer* render);
	int get_frame_width() { return width_frame; }
	int get_frame_height() { return height_frame; }

	bool isInside(SDL_Event& e);
	void setPos(int x, int y, SDL_Renderer* render);
	
	void HandlePlayButton(SDL_Event& e, SDL_Renderer* render, bool& menu, bool& play, bool& quit,Mix_Chunk*sound_effect);
	
	void HandleHowToPlayButton(SDL_Event& e, SDL_Renderer* render, bool& menu, bool& play, bool& quit,bool&HowToPlay,Mix_Chunk*sound_effect);
	
	void HandleGetBackButton(SDL_Event& e, SDL_Renderer* render, bool& menu, bool& play, bool& quit,bool& howToPlay, bool&upgrade,Mix_Chunk*sound_effect );
	
	void HandleQuitButton(SDL_Event& e, SDL_Renderer* render, bool& quit_game,bool &play, Mix_Chunk* sound_effect);
	
	void HandleReplayButton(SDL_Event& e, SDL_Renderer* render, bool& menu, bool& play, bool& howToPlay, Mix_Chunk* sound_effect,int& score,int&health, int& upgrade_blood, bool & upgrade_once_times, bool& option, vector<enemy*>&p_list_enemy, vector<enemy_bomb*>& p_list_bomb, int&wave);
	
	void HandleMenuButton(SDL_Event& e, SDL_Renderer* render, bool& menu, bool& play,bool&quit_menu,int&score,int& health, int&upgrade_blood,Mix_Chunk* sound_effect, bool & upgrade_once_time, bool&option, vector<enemy*>& p_list_enemy, vector<enemy_bomb*> &p_list_bomb,int&wave);
	
	void HandleUpgradeButton(SDL_Event& e, SDL_Renderer* render, bool& menu, bool& play,  bool& HowToPlay, bool& upgrade, Mix_Chunk* sound_effect);

	void HandleUpgrade(SDL_Event& e, SDL_Renderer* render, int& money_needed_to_upgrade, int& current_upgraded,int& upgrade_plus,int& current_money, Mix_Chunk*sound_effect);

	void HandleOptionButton(SDL_Event& e, SDL_Renderer* render, bool& option, Mix_Chunk* sound_effect);
private:
	
	int width_frame;
	int height_frame;

	


};

