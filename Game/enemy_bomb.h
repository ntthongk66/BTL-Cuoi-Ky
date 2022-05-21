#pragma once
#include"Game_Utlis.h"
#include"LTexture.h"
class enemy_bomb : public LTexture
{
public:
	enemy_bomb();
	~enemy_bomb();

	static const int rocket_vel = 10;

	int Xpos;
	int Ypos;

	int damage;

	bool direction_falling;

	bool isDelete;

	bool LoadTexture(const char* path, SDL_Renderer* render);

	void handleMove(const int& screen_width, const int& screen_height);

	bool dose_bomb_move() { return is_move; }

	void set_move(const bool& x) { is_move = x; }

	void set_pos(int x, int y) { Xpos = x; Ypos = y; }

	void render(int x, int y, SDL_Renderer* render);

	void set_damage(int dam) { damage = dam; }

	bool isExplode() { return is_explode; }
	
private:
	
	int Xvel;
	int Yvel;

	

	bool is_move;
	//bool isDelete;

	bool is_explode;
	//default is left to right
	
	SDL_RendererFlip flip;

	double angle;

	double angle_fall;

};

