#include "enemy.h"

enemy::enemy()
{
	srand(time(NULL));
	xpos =  0;
	ypos = rand()% 200;
	vel_x = 3;
	vel_y = 0;
	isDead = false;
	isDisappear = false;
	rocket_had_launch = 0;

	delay_shoot_time = 600;

	angle_launch = -45;
	angle_die = 0;
	angle_falling = 0;

	//enemy's type- score-health
	type_of_enemy = 0;
	score = 0;
	enemy_blood = 0;

	is_dead = false;
	area_drop_bomb = 0;

	CurrentTime = 0;
	LastTime = 0;
	
	// for falling bomb
	go_from_left_to_right = true;

	for (int i = 0; i < 20; i++)
	{
		smoke[i] = new rocket_smoke(xpos, ypos);
	}

	//delay_shoot_time = 300;
	flip = SDL_FLIP_NONE;

}
enemy::~enemy()
{
	for (int i = 0; i < 20; i++)
	{
		delete smoke[i];
	}
}

bool enemy::loadTexture(const char* path, SDL_Renderer* render)
{
	return LTexture::LoadTexure(path, render);

}

void enemy::set_vel()
{
	vel_x = 3;
	vel_y = 0;

	if (check_die()) vel_y = 1;
}

void enemy::render(SDL_Renderer* render)
{
	
	LTexture::render(xpos, ypos, render,NULL,angle_falling,NULL,flip);

	
	if(check_die())	renderSmoke(render);
	
	
}

void enemy::renderSmoke(SDL_Renderer* render)
{
	for (int i = 0; i < 20; i++)
	{
		if (smoke[i]->isDead())
		{
			delete smoke[i];
			smoke[i] = new rocket_smoke(xpos, ypos);
		}
	}
	for (int i = 0; i < 20; i++)
	{
		smoke[i]->render(render);
	}

}

void enemy::load_type_of_enemy(SDL_Renderer* render)
{
	switch (type_of_enemy)
	{
	case 1:
		loadTexture("asset/enemy/f53.png", render);
		enemy_blood = 4;
		score = 100;
		area_drop_bomb = 100;
		delay_shoot_time = 800;
		break;
	case 2:
		loadTexture("asset/enemy/F35.png", render);
		enemy_blood = 8;
		score = 150;
		area_drop_bomb = 200;
		delay_shoot_time = 700;
		break;
	case 3:
		loadTexture("asset/enemy/ALC_17.png", render);
		enemy_blood = 14;
		score = 250;
		area_drop_bomb = 250;
		delay_shoot_time = 800;
		break;
	case 4:
		loadTexture("asset/enemy/p54.png", render);
		enemy_blood = 12;
		score = 220;
		area_drop_bomb = 200;
		delay_shoot_time = 700;
		break;
	case 5:
		loadTexture("asset/enemy/MiG-29.png", render);
		enemy_blood = 3;
		score = 150;
		area_drop_bomb = 200;
		delay_shoot_time = 800;
		break;
	default:
		break;
	}
}


void enemy::handleMove(const int& screen_Width, const int& screen_Height, SDL_Renderer*render)
{
	
		xpos += vel_x;
		ypos += vel_y;


		//LTexture::render(xpos, ypos, render);

		if (check_die())
		{
			vel_y = 1;
			angle_die =angle_launch+ atan2(vel_x, vel_y) * 180 / M_PI;
		}

		if (angle_launch == 45)
		{
			angle_falling -= 0.2;
			if (angle_falling < angle_die) angle_falling = angle_die;
		}
		else
		{
			angle_falling += 0.2;
			if (angle_falling > angle_die) angle_falling = angle_die;
		}


		if (xpos > screen_Width + 200)
		{
			flip = SDL_FLIP_HORIZONTAL;
			vel_x = -3;
			ypos = rand() % 200;
			if (check_die()) is_dead = true;
			angle_launch = 45;
			//for bomb
			go_from_left_to_right = false;
		}
		else if (xpos < -200)
		{
			flip = SDL_FLIP_NONE;
			vel_x = 3;
			ypos = rand() % 200;
			if (check_die()) is_dead = true;
			angle_launch = -45;
			//for bomb
			go_from_left_to_right = true;
		}
		

	if (ypos > screen_Height || ypos < 0)
	{
		is_dead = true;
	}
}

bool enemy::check_die()
{
	return die >= enemy_blood;
}


//make and launch rocket for enemy
bool enemy::can_make_rocket()
{
	CurrentTime = SDL_GetTicks();
	bool can_make_it = false;
	if (CurrentTime - LastTime > delay_shoot_time)
	{
		LastTime = CurrentTime;
		can_make_it = true;
	}
	return can_make_it;
}

void enemy::makeRocket( SDL_Renderer* render)
{
	
	CurrentTime = SDL_GetTicks();

	if (CurrentTime - LastTime > delay_shoot_time &&rocket_had_launch<=max_rocket )
	{
		rocket_had_launch++;
		rocket* p_rocket = new rocket();
		p_rocket->LoadTexture("asset/rocket.png", render);
		p_rocket->angle= p_rocket->set_angle(x_des, y_des, xpos, ypos);
		p_rocket->set_vel(p_rocket->angle);
		p_rocket->set_pos(xpos, ypos);
		p_rocket->set_move(true);
		p_list_rocket.push_back(p_rocket);

		LastTime = CurrentTime;
	}
}

void enemy::launchRocket(SDL_Renderer*render)
{
	for (int i = 0; i < p_list_rocket.size(); i++)
	{	
		rocket* p_rocket = p_list_rocket.at(i);
		if (p_rocket != NULL)
		{
			if (p_rocket->dose_rocket_move() == true)
			{
				p_rocket->handleMove(screen_width, screen_height);
				p_rocket->render(p_rocket->Xpos, p_rocket->Ypos, render, p_rocket->angle);
			}
			else
			{
				p_list_rocket.erase(p_list_rocket.begin() + i);
				if (p_rocket != NULL)
				{
					delete p_rocket;
					p_rocket = NULL;
				}
			}
		}
	}
}


//handle everythings related to bomb ( drop, fall, ...)
bool enemy::able_to_make_bomb()
{
	srand(time(NULL));
	int des_x_1 = 150 + rand() % 200;
	int des_x_2 = 900 + rand() % 150;

	if (go_from_left_to_right && (xpos > des_x_1 && xpos < des_x_1 + area_drop_bomb))
	{
		return true;
	}
	else if (!go_from_left_to_right && (xpos < des_x_2 && xpos > des_x_2-area_drop_bomb))
	{
		return true;
	}
	return false;
}

void enemy::makeBomb(SDL_Renderer* render)
{
	//delay_shoot_time = 500;
	CurrentTime =SDL_GetTicks();
	if (CurrentTime - LastTime > delay_shoot_time&&!check_die()&&able_to_make_bomb())
	{
		enemy_bomb* p_bomb = new enemy_bomb();
		p_bomb->LoadTexture("asset/bomb.png", render);
		p_bomb->set_pos(xpos, ypos);
		p_bomb->set_move(true);
		p_bomb->set_damage(score / 10);
		p_list_bomb.push_back(p_bomb);
		LastTime = CurrentTime;
	}
}

void enemy::drop_bomb(SDL_Renderer* render, int&health, vector<Mix_Chunk*>explosion_sound_effect)
{
	//cout << p_list_bomb.size() << endl;
	for (int i = 0; i < p_list_bomb.size(); i++)
	{
		//cout << "1" << endl;    
		enemy_bomb* p_bomb = p_list_bomb.at(i);
		if (p_bomb != NULL)
		{
			if (p_bomb->dose_bomb_move() == true)
			{
				p_bomb->direction_falling = go_from_left_to_right;
				p_bomb->handleMove(screen_width, screen_height);
				p_bomb->render(p_bomb->Xpos, p_bomb->Ypos, render);
			}
			else
			{
				//cout << "bommm" << endl;
				Mix_PlayChannel(-1, explosion_sound_effect[rand() % explosion_sound_effect.size()], 0);
				health -= p_bomb->damage;
				p_list_bomb.erase(p_list_bomb.begin() + i);
				if (p_bomb != NULL)
				{
					//cout << "11" << endl;
					delete p_bomb;
					p_bomb = NULL;
				}
			}
		}
	}
}