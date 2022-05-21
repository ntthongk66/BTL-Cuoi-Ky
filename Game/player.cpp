#include "player.h"

player::player()
{
	xpos = 0;
	ypos = screen_height - 88;

	pos.x = 51;
	pos.y = 25;


	//bullet
	CurrentTime = 0;
	LastTime = 0;
	isFire = false;

	//rocket
	CurrentTime_1 = 0;
	LastTime_1 = 0;
	isLaunch = false;
}

player::~player()
{

}

bool player::LoadTexture(const char* path, SDL_Renderer* Render)
{
	bool ans = LTexture::LoadTexure(path, Render);
	return ans;
}

void player::handleEvent(SDL_Event& e)
{
	if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP||e.type==SDL_KEYDOWN)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);

		//double res = ((double)(x - 51)) / ((double)(screen_height - mHeight + 25 - y));

		rotate_angle = -atan2((double)(screen_height - 88 + 25 - y), (double)(x - 51)) * 180 / M_PI;
		rotate_angle_2 = -atan2((double)(screen_height - 88 + 25 - y), (double)(x - 1098)) * 180 / M_PI;
		
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			if (e.button.button == SDL_BUTTON_LEFT)
			{
				isFire = true;
			}
			else
			{
				isLaunch= true;
			}
		}
		else if (e.type == SDL_MOUSEBUTTONUP)
		{
			isFire = false;
			isLaunch = false;
		}
	}
}


// bullet

void player::makeBullet(SDL_Renderer* render, int& delay_shoot_time,Mix_Chunk*sound_effect)
{
	CurrentTime =  SDL_GetTicks();
	
	if (isFire&&CurrentTime>LastTime+ delay_shoot_time)
	{
		Bullet* p_bullet = new Bullet();
		p_bullet->LoadTexure("asset/Bullet.png", render);
		p_bullet->set_vel(rotate_angle);
		p_bullet->bullet_degrees = rotate_angle;
		p_bullet->set_move(true);
		p_list_bullet.push_back(p_bullet);
		Mix_PlayChannel(-1, sound_effect, 0);
		LastTime = CurrentTime;
	}

}

void player::handleBullet(SDL_Renderer*render)
{
	for (int i = 0; i < p_list_bullet.size(); i++)
	{
		Bullet* p_bullet = p_list_bullet.at(i);
		if (p_bullet != NULL)
		{
			
			if (p_bullet->dose_bullet_move() == true)
			{
				p_bullet->HandleMove(screen_width, screen_height);
				p_bullet->render(p_bullet->Xpos, p_bullet->Ypos, render, NULL, p_bullet->bullet_degrees);
			}
			else
			{
				p_list_bullet.erase(p_list_bullet.begin() + i);
				if (p_bullet != NULL)
				{
					delete p_bullet;
					p_bullet = NULL;
				}
			}
		}
	}
}

// remove bullet when get out the window or hit the plane

void player::removeBullet(const int& index)
{
	int n = p_list_bullet.size();

	if (n > 0 && index < n)
	{
		Bullet* p_bullet = p_list_bullet.at(index);
		p_list_bullet.erase(p_list_bullet.begin() + index);
		if (p_bullet != NULL)
		{
			delete p_bullet;
			p_bullet = NULL;
		}
	}
}



//rocket 
void player::makeRocket(SDL_Renderer* render, int& delay_launch_time, Mix_Chunk* sound_effect)
{
	CurrentTime_1 = SDL_GetTicks();
	if (isLaunch && CurrentTime_1 - LastTime_1 > delay_launch_time)
	{
		rocket* p_rocket = new rocket();
		p_rocket->LoadTexture("asset/rocket.png", render);
		p_rocket->set_vel(rotate_angle_2);
		p_rocket->set_pos(1098, screen_height - 80);
		p_rocket->set_move(true);
		p_rocket->angle = rotate_angle_2;
		p_list_rocket.push_back(p_rocket);
		Mix_PlayChannel(-1, sound_effect, 0);
		LastTime_1 = CurrentTime_1;
	}
}

void player::handleRocket(SDL_Renderer* render)
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

//remove rocket when get out the window or hit sth
void player::removeRocket(const int& index)
{
	int n = p_list_rocket.size();

	if (n > 0 && index < n)
	{
		rocket* p_rocket = p_list_rocket.at(index);
		p_list_rocket.erase(p_list_rocket.begin() + index);
		if (p_rocket != NULL)
		{
			delete p_rocket;
			p_rocket = NULL;
		}
	}
}


void player::render(SDL_Renderer* render)
{
	//SDL_Rect render_quad = { xpos,ypos, 100,88};
	LTexture::render( xpos,  ypos,render, NULL, rotate_angle, &pos, SDL_FLIP_HORIZONTAL);
}

