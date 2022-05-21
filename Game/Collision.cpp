#include "Collision.h"


void Collision(vector<enemy*>& Enemy_list, player& gun, int& bullet_dam, int& rocket_dam, vector<rocket*>rocket_list,vector<enemy_bomb*>p_list_bomb, vector<Mix_Chunk*>explosion_sound_effect,SDL_Renderer*render, int& score, int& health,Uint32& frame)
{
	
	
	for (int i = 0; i < Enemy_list.size(); i++)
	{
		enemy* p_enemy = Enemy_list.at(i);
		if (p_enemy != NULL)
		{
			if (!p_enemy->check_die()||!p_enemy->dose_enemy_dead())
			{
				p_enemy->handleMove(screen_width, screen_height, render);
				//put bomb in here 
				p_enemy->makeBomb(render);
				p_enemy->drop_bomb(render,health, explosion_sound_effect);
				p_enemy->render(render);
				
			}
			
			else
			{
			
				score += p_enemy->get_enemy_score();

				Enemy_list.erase(Enemy_list.begin() + i);
				if (p_enemy != NULL)
				{
					delete p_enemy;
					p_enemy = NULL;
				}
			}

			

		}
	}

	//enemy hited by bullet
	vector<Bullet*> gun_bullet_list = gun.get_bullet_list();
	for (int i = 0; i < gun_bullet_list.size(); i++)
	{
		Bullet* p_bullet = gun_bullet_list.at(i);
		if (p_bullet != NULL)
		{
			for (int j = 0; j < Enemy_list.size(); j++)
			{
				enemy* p_enemy = Enemy_list.at(j);
				if (p_enemy != NULL)
				{
					SDL_Rect enemy_rect;
					enemy_rect = p_enemy->get_rect();
					SDL_Rect bullet_rect = p_bullet->get_rect();
					if (CheckCollision(enemy_rect, bullet_rect))
					{
						gun.removeBullet(i);
						p_enemy->increase_die_by_bullet(bullet_dam);
						
						
						if (p_enemy->check_die()&&p_enemy->dose_enemy_dead())
						{
							
							//score += p_enemy->get_enemy_score();
							Enemy_list.erase(Enemy_list.begin() + j);
							if (p_enemy != NULL)
							{
								delete p_enemy;
								p_enemy = NULL;
							}
						}
					}
				}
			}
		}
	}

	//enemy hitted by rocket
	vector<rocket*> gun_rocket_list = gun.get_rocket_list();
	for (int i = 0; i < gun_rocket_list.size(); i++)
	{
		rocket* p_rocket = gun_rocket_list.at(i);
		if (p_rocket != NULL)
		{
			for (int j = 0; j < Enemy_list.size(); j++)
			{
				enemy* p_enemy = Enemy_list.at(j);
				if (p_enemy != NULL)
				{
					SDL_Rect enemy_rect;
					enemy_rect = p_enemy->get_rect();
					SDL_Rect rocket_rect = p_rocket->get_rect();
					if (CheckCollision(enemy_rect, rocket_rect))
					{
						gun.removeRocket(i);
						p_enemy->increase_die_by_rocket(rocket_dam);

						if (p_enemy->check_die() && p_enemy->dose_enemy_dead())
						{
							//score += p_enemy->get_enemy_score();
							Enemy_list.erase(Enemy_list.begin() + j);
							if (p_enemy != NULL)
							{
								delete p_enemy;
								p_enemy = NULL;
							}
						}
					}
				}
			}
		}
	}
}
