#pragma once
#include"Game_Utlis.h"
#include"LTexture.h"
#include"Bullet.h"
#include"time.h"
#include"rocket.h"

class player : public LTexture
{
public:
	player();
	~player();



	bool LoadTexture(const char* path, SDL_Renderer* Render);

	void render(SDL_Renderer* render);

	void handleEvent(SDL_Event& e);

	//for collision
	void removeBullet(const int& index);
	void removeRocket(const int& index);

	void set_rotate_point(int x, int y) { pos.x = x; pos.y = y; }

	//Bullet
	vector<Bullet*> get_bullet_list() { return p_list_bullet; }
	void makeBullet(SDL_Renderer* render,int& delay_shoot_time,Mix_Chunk*sound_effect);
	void handleBullet(SDL_Renderer*render);


	//rocket
	vector<rocket*>get_rocket_list() { return p_list_rocket; }
	void makeRocket(SDL_Renderer* render,int&delay_launch_time ,Mix_Chunk* sound_effect);
	void handleRocket(SDL_Renderer* render);
	
	

private:

	int xpos, ypos;

	double rotate_angle;
	double rotate_angle_2;

	SDL_Point pos;
	//for bullet
	bool isFire;
	vector<Bullet*> p_list_bullet;
	Uint32 CurrentTime;
	Uint32 LastTime;

	//for rocket
	bool isLaunch;
	vector<rocket*>p_list_rocket;
	Uint32 CurrentTime_1;
	Uint32 LastTime_1;

};

