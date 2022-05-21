#pragma once
#include"enemy.h"
#include"Game_Utlis.h"

const int Num_of_type_1 = 4;
const int Num_of_type_2 = 3;
const int Num_of_type_3 = 2;
const int Num_of_type_4 = 3;
const int Num_of_type_5 = 5;

const int Num_of_type_1_2 = 7;
const int Num_of_type_2_2 = 5;
const int Num_of_type_3_2 = 4;
const int Num_of_type_4_2 = 5;
const int Num_of_type_5_2 = 8;


void EnemyArray_1(vector<enemy*>& EnemyArray, SDL_Renderer* render);
void EnemyArray_2(vector<enemy*>& EnemyArray, SDL_Renderer* render);
void EnemyArray_3(vector<enemy*>& EnemyArray, SDL_Renderer* render);
void EnemyArray_4(vector<enemy*>& EnemyArray, SDL_Renderer* render);
void EnemyArray_5(vector<enemy*>& EnemyArray, SDL_Renderer* render);

void EnemyArray_1_2(vector<enemy*>& EnemyArray, SDL_Renderer* render);
void EnemyArray_2_2(vector<enemy*>& EnemyArray, SDL_Renderer* render);
void EnemyArray_3_2(vector<enemy*>& EnemyArray, SDL_Renderer* render);
void EnemyArray_4_2(vector<enemy*>& EnemyArray, SDL_Renderer* render);
void EnemyArray_5_2(vector<enemy*>& EnemyArray, SDL_Renderer* render);



void generateEnemy(vector<enemy*>& enemy_list, SDL_Renderer* render, int&wave,bool&is_dead);
