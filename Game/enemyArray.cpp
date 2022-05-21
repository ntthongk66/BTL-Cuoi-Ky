#include "enemyArray.h"
void EnemyArray_1(vector<enemy*>& EnemyArray, SDL_Renderer* render)
{
	for (int i = 0; i < Num_of_type_1; i++)
	{
		srand(time(NULL));
		enemy* p_enemy = new enemy();
		p_enemy->set_type(1);
		p_enemy->load_type_of_enemy(render);
		p_enemy->set_pos(1500 + i* 100, i * 30);
		p_enemy->set_vel();
		EnemyArray.push_back(p_enemy);
	}
}

void EnemyArray_2(vector<enemy*>& EnemyArray, SDL_Renderer* render)
{
	for (int i = 0; i < Num_of_type_2; i++)
	{
		srand(time(NULL));
		enemy* p_enemy = new enemy();
		p_enemy->set_type(2);
		p_enemy->load_type_of_enemy(render);
		p_enemy->set_pos(-200 + i * -(100), i * 40);
		p_enemy->set_vel();
		EnemyArray.push_back(p_enemy);
	}
}

void EnemyArray_3(vector<enemy*>& EnemyArray, SDL_Renderer* render)
{
	for (int i = 0; i < Num_of_type_3; i++)
	{
		srand(time(NULL));
		enemy* p_enemy = new enemy();
		p_enemy->set_type(3);
		p_enemy->load_type_of_enemy(render);
		p_enemy->set_pos(1200 + i * 200, i * 30);
		p_enemy->set_vel();
		EnemyArray.push_back(p_enemy);
	}
}

void EnemyArray_4(vector<enemy*>& EnemyArray, SDL_Renderer* render)
{
	for (int i = 0; i < Num_of_type_4; i++)
	{
		srand(time(NULL));
		enemy* p_enemy = new enemy();
		p_enemy->set_type(4);
		p_enemy->load_type_of_enemy(render);
		p_enemy->set_pos(-200 + i * ( - 100), i * 40);
		p_enemy->set_vel();
		EnemyArray.push_back(p_enemy);
	}
}

void EnemyArray_5(vector<enemy*>& EnemyArray, SDL_Renderer* render)
{
	for (int i = 0; i < Num_of_type_5; i++)
	{
		srand(time(NULL));
		enemy* p_enemy = new enemy();
		p_enemy->set_type(5);
		p_enemy->load_type_of_enemy(render);
		p_enemy->set_pos(1400 + i * 100, i * 40);
		p_enemy->set_vel();
		EnemyArray.push_back(p_enemy);
	}
}

//level 2

void EnemyArray_1_2(vector<enemy*>& EnemyArray, SDL_Renderer* render)
{
	for (int i = 0; i < Num_of_type_1_2; i++)
	{
		srand(time(NULL));
		enemy* p_enemy = new enemy();
		p_enemy->set_type(1);
		p_enemy->load_type_of_enemy(render);
		p_enemy->set_pos(1500 + i * 100, i * 30);
		p_enemy->set_vel();
		EnemyArray.push_back(p_enemy);
	}
}

void EnemyArray_2_2(vector<enemy*>& EnemyArray, SDL_Renderer* render)
{
	for (int i = 0; i < Num_of_type_2_2; i++)
	{
		srand(time(NULL));
		enemy* p_enemy = new enemy();
		p_enemy->set_type(2);
		p_enemy->load_type_of_enemy(render);
		p_enemy->set_pos(-200 + i * -(100), i * 40);
		p_enemy->set_vel();
		EnemyArray.push_back(p_enemy);
	}
}

void EnemyArray_3_2(vector<enemy*>& EnemyArray, SDL_Renderer* render)
{
	for (int i = 0; i < Num_of_type_3_2; i++)
	{
		srand(time(NULL));
		enemy* p_enemy = new enemy();
		p_enemy->set_type(3);
		p_enemy->load_type_of_enemy(render);
		p_enemy->set_pos(1200 + i * 200, i * 30);
		p_enemy->set_vel();
		EnemyArray.push_back(p_enemy);
	}
}

void EnemyArray_4_2(vector<enemy*>& EnemyArray, SDL_Renderer* render)
{
	for (int i = 0; i < Num_of_type_4_2; i++)
	{
		srand(time(NULL));
		enemy* p_enemy = new enemy();
		p_enemy->set_type(4);
		p_enemy->load_type_of_enemy(render);
		p_enemy->set_pos(-200 + i * (-100), i * 40);
		p_enemy->set_vel();
		EnemyArray.push_back(p_enemy);
	}
}

void EnemyArray_5_2(vector<enemy*>& EnemyArray, SDL_Renderer* render)
{
	for (int i = 0; i < Num_of_type_5_2; i++)
	{
		srand(time(NULL));
		enemy* p_enemy = new enemy();
		p_enemy->set_type(5);
		p_enemy->load_type_of_enemy(render);
		p_enemy->set_pos(1400 + i * 100, i * 40);
		p_enemy->set_vel();
		EnemyArray.push_back(p_enemy);
	}
}



void generateEnemy(vector<enemy*>& enemy_list, SDL_Renderer* render, int& wave, bool& is_dead)
{
	
	if (!is_dead)
	{


		if (enemy_list.size() <= 0)
		{
			wave += 1;

			if (wave < 7)
			{
				
					srand(time(NULL));
					int random = rand() % 5 + 1;
					switch (random)
					{
					case 1:
						EnemyArray_1(enemy_list, render);
						break;
					case 2:
						EnemyArray_2(enemy_list, render);
						break;
					case 3:
						EnemyArray_3(enemy_list, render);
						break;
					case 4:
						EnemyArray_4(enemy_list, render);
						break;
					case 5:
						EnemyArray_5(enemy_list, render);
						break;
					default:
						break;
					}
				
			}
			else
			{
				srand(time(NULL));
				int random = rand() % 5 + 1;
				switch (random)
				{
				case 1:
					EnemyArray_1_2(enemy_list, render);
					break;
				case 2:
					EnemyArray_2_2(enemy_list, render);
					break;
				case 3:
					EnemyArray_3_2(enemy_list, render);
					break;
				case 4:
					EnemyArray_4_2(enemy_list, render);
					break;
				case 5:
					EnemyArray_5_2(enemy_list, render);
					break;
				default:
					break;
				}
			}
			
		}
	}
}