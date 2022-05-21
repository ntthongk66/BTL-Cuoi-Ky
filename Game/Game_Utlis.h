#pragma once
#include"SDL.h"
#include"SDL_image.h"
#include"SDL_mixer.h"
#include"SDL_ttf.h"
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>
#include<cmath>
#include<time.h>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::to_string;
using std::setw;
using std::stringstream;
using std::setfill;

const int screen_width = 1200;
const int screen_height = 600;
const int FPS = 50;


const int x_des = 25;
const int y_des = screen_height - 100 + 51;


bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
string convert_to_string(int number);
string convert_to_String(int health);
int get_from_file(const char* path);
void update(const char* path, int& new_value);

