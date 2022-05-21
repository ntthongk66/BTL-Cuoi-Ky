#pragma once
#include"Game_Utlis.h"
#include"LTexture.h"
#include"rocket.h"
#include"player.h"
#include"enemy_bomb.h"

class enemy : public LTexture
{
public:
	enemy();
	~enemy();

	bool loadTexture(const char* path, SDL_Renderer* render);
	void render(SDL_Renderer* render);
	void set_type(int t) { type_of_enemy = t; }

	// handle physics move and position
	void set_pos(int x, int y) { xpos = x; ypos = y; }
	void set_height(int h) { ypos = h; }
	void set_vel();
	void handleMove(const int & screen_width, const int & screen_height, SDL_Renderer*render);
	void set_move(const bool& x) { is_dead = x; }

	//handle the rocket
	bool can_make_rocket();
	void makeRocket(SDL_Renderer *render);
	vector<rocket*> get_the_rocket_list() { return p_list_rocket; }
	void launchRocket(SDL_Renderer*render);

	//handle bomb
	bool able_to_make_bomb();
	void makeBomb(SDL_Renderer* render);
	void drop_bomb(SDL_Renderer* render, int&health,vector<Mix_Chunk*>explosion_sound_effect);
	vector<enemy_bomb*>p_list_bomb;

	void load_type_of_enemy(SDL_Renderer* render);
	bool dose_enemy_dead() { return is_dead; }
	bool check_die();

	//for colision
	void increase_die_by_bullet(int& bullet_dam) { die += bullet_dam; }
	void increase_die_by_rocket(int& rocket_dam) { die += rocket_dam; }

	//score
	Uint32 get_enemy_score() { return score; }

	int xpos, ypos;

private:

	//particle
	rocket_smoke* smoke[20];
	void renderSmoke(SDL_Renderer* render);

	int vel_x, vel_y;

	int type_of_enemy;
	int enemy_blood;
	Uint32 score;
	bool is_dead;

	const int max_rocket = 3;
	int rocket_had_launch;

	Uint32 CurrentTime;
	Uint32 LastTime;

	int delay_shoot_time;

	vector<rocket*>p_list_rocket;
	//vector<enemy_bomb*>p_list_bomb;

	bool isDisappear;
	bool isDead;
	SDL_RendererFlip flip;

	double angle_launch;

	bool go_from_left_to_right;

	//bomb
	int area_drop_bomb;
	int die;
	double angle_die;
	double angle_falling;

};

