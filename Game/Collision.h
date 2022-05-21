#pragma once
#include"Game_Utlis.h"
#include"enemy.h"
#include"player.h"
#include"Bullet.h"
#include"rocket.h"

void Collision(vector<enemy*>& Enemy_list, player& gun,int&bullet_dam, int&rocket_dam, vector<rocket*>rocket_list,vector<enemy_bomb*>p_list_bomb, vector<Mix_Chunk*>explosion_sound_effect,SDL_Renderer*render,int & score, int& health, Uint32&frame);

