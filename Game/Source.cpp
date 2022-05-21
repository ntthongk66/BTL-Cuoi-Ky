
#include"Game_Utlis.h"
#include"LTexture.h"
#include"player.h"
#include"rocket.h"
#include"cursor_aim.h"
#include"button.h"
#include"enemy.h"
#include"enemyArray.h"
#include"Collision.h"

//initialize everythings we use
bool init();

//Load all the object we declare
bool loadMedia();

//close and free everythings
void close();


//particle_effect
 LTexture gRedTexture;
 LTexture gGreenTexture;
 LTexture gBlueTexture;
 LTexture gShimmerTexture;


//sound_effect
Mix_Chunk* switch_button_sound_effect = NULL;
Mix_Chunk* gun_sound_effect = NULL;
Mix_Chunk* rocket_sound_effect = NULL;
Mix_Chunk* upgrade_sound_effect = NULL;
Mix_Chunk* music_while_playing_game = NULL;

//bomb sound effect
vector<Mix_Chunk*>explosion_sound_effect(6,NULL);

//background_music
Mix_Music* main_waiting_music = NULL;

//ttf font
TTF_Font* game_font = NULL;

//game back ground
LTexture pic;
LTexture HocToPlayPics;
LTexture city_background;
LTexture backGround;
LTexture main_Background;
LTexture GameOver;

//player
player gun;
cursor_aim the_aim;

//for upgrade 
LTexture bullet_icon_dam;
LTexture bullet_icon_rmp;
LTexture rocket_icon_dam;
LTexture rocket_icon_rmp;

//text on screen
LTexture score;
LTexture city_blood;
LTexture your_high_score;
LTexture your_money;


LTexture content_of_upgrade_bullet_dam;
LTexture content_of_upgrade_bullet_rpm;
LTexture content_of_upgrade_rocket_dam;
LTexture content_of_upgrade_rocket_rpm;
LTexture content_of_upgrade_health;




// money needed to up grade
int money_to_upgrade_bullet_dam = 1000;
int money_to_upgrade_bullet_rpm = 1500;
int money_to_upgrade_rocket_dam = 2000;
int money_to_upgrade_rocket_rpm = 2500;
int money_to_upgrade_health = 3000;

int value_of_upgrade_bullet_dam = 1;
int value_of_upgrade_bullet_rpm = -50;
int value_of_upgrade_rocket_dam = 2;
int value_of_upgrade_rocket_rpm = -300;
int value_of_upgrade_health = 300;

int  blood ;
int your_score = 0;
int high_score;
int money;


//damage from player
int bullet_dam;
int rocket_dam;

//rate of fire (just decrease the delay shoot time)
int delay_shot_time;
int delay_launch_time;


// button int main bg
button play_button;
button getHelp_button;
button getBack_button;
button upgrade_button;
button option_button;

// button when lose
button replay_button;
button quit_game_button;
button main_button;

//inside upgrade button
button upgrade_bullet_dam_button;
button upgrade_bullet_rpm_button;
button upgrade_rocket_dam_button;
button upgrade_rocket_rpm_button;
button upgrade_health_button;

const int space_between_button = 50;

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Event e;

bool init()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0) // init SDL and SDL_mix
	{
		cout << "fail to initialize sdl, sdl_error: " << SDL_GetError() << endl;
		success = false;
	}
	else
	{
		if (SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			cout << "Warning: Linear texture filtering not enabled!" << endl;
		}

		gWindow = SDL_CreateWindow("fighter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			cout << "fail to initialize window, error: " << SDL_GetError() << endl;
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				cout << "cna not create renderer: " << SDL_GetError() << endl;
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				// init SDL_image
				int imgf = IMG_INIT_PNG; 
				if (!(IMG_Init(imgf) && imgf))
				{
					cout << "fail to init sdl_image: " << IMG_GetError() << endl;
					success = false;
				}

				//initialize sdl_mixer
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					cout << "mixer could not initialize! sdl_mixer error: " << Mix_GetError() << endl;
				}
				// init ttf
				if (TTF_Init() == -1) 
				{
					cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << endl;
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load sound effect
	switch_button_sound_effect = Mix_LoadWAV("asset/sound_effect/switch.wav");
	gun_sound_effect = Mix_LoadWAV("asset/sound_effect/gun_sound_effect.wav");
	rocket_sound_effect = Mix_LoadWAV("asset/sound_effect/rocket_sound.wav");
	upgrade_sound_effect = Mix_LoadWAV("asset/sound_effect/upgrade_sound_effect.wav");

	//load bomb sound effect
	explosion_sound_effect[0] = Mix_LoadWAV("asset/sound_effect/explosion effect 1.wav");
	explosion_sound_effect[1] = Mix_LoadWAV("asset/sound_effect/explosion effect 2.wav");
	explosion_sound_effect[2] = Mix_LoadWAV("asset/sound_effect/explosion effect 3.wav");
	explosion_sound_effect[3] = Mix_LoadWAV("asset/sound_effect/explosion effect 4.wav");
	explosion_sound_effect[4] = Mix_LoadWAV("asset/sound_effect/explosion effect 5.wav");
	explosion_sound_effect[5] = Mix_LoadWAV("asset/sound_effect/explosion effect 6.wav");
	
	//background_music
	main_waiting_music = Mix_LoadMUS("asset/sound_effect/Lake Town Theme.mp3");
	
	//font_game
	game_font = TTF_OpenFont("game_font.ttf", 20);
	if (game_font == NULL)
	{
		cout << "Failed to load lazy font! SDL_ttf Error: " << TTF_GetError() << endl;
		success = false;
	}

	//particle 
	gGreenTexture.LoadTexure("asset/particle/smoke1.png", gRenderer);
	gBlueTexture.LoadTexure("asset/particle/smoke1.png", gRenderer);
	gRedTexture.LoadTexure("asset/particle/smoke1.png", gRenderer);
	gShimmerTexture.LoadTexure("asset/particle/smoke2.png", gRenderer);
	

	//Load all the texture
	pic.LoadTexure("asset/gun_body.png", gRenderer);
	gun.LoadTexture("asset/the_gun.png", gRenderer);
	the_aim.LoadTexture("asset/aim.png", gRenderer);
	city_background.LoadTexure("asset/city3.png", gRenderer);
	backGround.LoadTexure("asset/bg1.png", gRenderer);
	main_Background.LoadTexure("asset/main_background.jpg", gRenderer);
	GameOver.LoadTexure("asset/gameOver.png", gRenderer);

	return success;
}

void close()
{
	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;

	//ttf_font
	TTF_CloseFont(game_font);
	game_font = NULL;

	//Free loaded image
	pic.free();
	gun.free();
	the_aim.free();
	HocToPlayPics.free();
	city_background.free();
	backGround.free();
	main_Background.free();

	bullet_icon_dam.free();
	bullet_icon_rmp.free();
	rocket_icon_dam.free();
	rocket_icon_rmp.free();

	GameOver.free();

	//free sound effect
	Mix_FreeChunk(switch_button_sound_effect);
	Mix_FreeChunk(gun_sound_effect);
	Mix_FreeChunk(rocket_sound_effect);
	Mix_FreeChunk(upgrade_sound_effect);
	Mix_FreeMusic(main_waiting_music);

	switch_button_sound_effect = NULL;
	gun_sound_effect = NULL;
	rocket_sound_effect = NULL;
	upgrade_sound_effect = NULL;
	main_waiting_music = NULL;

	for (int i = 0; i < explosion_sound_effect.size(); i++)
	{
		Mix_FreeChunk(explosion_sound_effect[i]);
		explosion_sound_effect[i] = NULL;
	}
	
	//button
	getBack_button.free();
	getHelp_button.free();
	play_button.free();

	quit_game_button.free();
	replay_button.free();
	main_button.free();
	upgrade_button.free();
	option_button.free();	

	//inside upgrade button
	upgrade_bullet_dam_button.free();
	upgrade_bullet_rpm_button.free();
	upgrade_rocket_dam_button.free();
	upgrade_rocket_rpm_button.free();
	upgrade_health_button.free();

	// text on screen
	score.free();
	city_blood.free();
	your_money.free();
	your_high_score.free();
	content_of_upgrade_bullet_dam;

	content_of_upgrade_bullet_rpm.free();
	content_of_upgrade_rocket_dam.free();
	content_of_upgrade_rocket_rpm.free();
	content_of_upgrade_health.free();


	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
	Mix_Quit();
	TTF_Quit();
}



int main(int argc, char* args[])
{
	// handle FPS
	Uint32 frameStart;
	const int timePerFrame = 1000 / FPS;
	int frameTime;
	Uint32 frame = 0;

	//city_blood
	blood = get_from_file("city_blood.txt");
	//money
	money = get_from_file("money.txt");

	//damage from player
	bullet_dam = get_from_file("bullet_dam.txt");
	rocket_dam = get_from_file("rocket_dam.txt");

	//rate of fire (just decrease the delay shoot time)
	delay_shot_time = get_from_file("bullet_rpm.txt");
	delay_launch_time = get_from_file("rocket_rpm.txt");

	//for plus money just once time
	bool plus_money_once_time = true;

	int upgrade_blood = blood;

	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;

			int wave = 0;

			//belong to button field
			bool play = false;
			bool menu = true;
			bool quitMenu = false;
			bool exitGame = false;
			bool howToPlay = false;
			bool upgrade = false;
			bool option = false;

			bool is_dead = false; // when your blood == 0

			//text color
			SDL_Color color_text_score = { 100,100,0 };
			SDL_Color color_of_blood = { 100,100,100 };
			SDL_Color color_black = { 0,0,0 };


			//belong to enemy
			vector<enemy*>enemy_list;
			vector<rocket*>rocket_list;
			vector<enemy_bomb*>bomb_list;

			

			SDL_ShowCursor(SDL_DISABLE);

			//While application is running
			while (!exitGame)
			{


				while (!quitMenu)
				{
					//update everythings in here
					
					update("city_blood.txt", blood);
					update("bullet_dam.txt", bullet_dam);
					update("bullet_rpm.txt", delay_shot_time);
					update("rocket_dam.txt", rocket_dam);
					update("rocket_rpm.txt", delay_launch_time);
					update("money.txt", money);
					upgrade_blood = blood;
					high_score = get_from_file("hight_score.txt");


					//Handle events on queue
					frameStart = SDL_GetTicks();
					if (menu)
					{
						while (SDL_PollEvent(&e) != 0)
						{
							//User requests quit
							if (e.type == SDL_QUIT)
							{
								exitGame = true;
								quitMenu = true;
							}
							the_aim.handdleEvent(e);

							//button event
							play_button.HandlePlayButton(e, gRenderer, menu, play, quitMenu, switch_button_sound_effect);
							getHelp_button.HandleHowToPlayButton(e, gRenderer, menu, play, quitMenu, howToPlay, switch_button_sound_effect);
							upgrade_button.HandleUpgradeButton(e, gRenderer, menu, play, howToPlay, upgrade, switch_button_sound_effect);
						}

						SDL_SetRenderDrawColor(gRenderer, 100, 100, 0, 100);
						SDL_RenderClear(gRenderer);

						if (Mix_PlayingMusic() == 0)
						{
							Mix_PlayMusic(main_waiting_music, -1);
						}

						//Game main background
						main_Background.render(0, 0, gRenderer);
						the_aim.render(gRenderer);

						//render highscore text
						your_high_score.loadFromRenderedText("Your high score: " + convert_to_string(high_score), color_black, gRenderer, game_font);
						your_high_score.render(0, 0, gRenderer);

						//button
						play_button.setPos((screen_width - play_button.get_frame_width()) / 2, (screen_height - play_button.get_frame_height()) / 2 + 100, gRenderer);
						getHelp_button.setPos((screen_width - getHelp_button.get_frame_width()) / 2, (screen_height - getHelp_button.get_frame_height()) / 2 + space_between_button + 100, gRenderer);
						upgrade_button.setPos((screen_width - upgrade_button.get_frame_width()) / 2, (screen_height - upgrade_button.get_frame_height()) / 2 + space_between_button * 2 + 100, gRenderer);

						SDL_RenderPresent(gRenderer);
					}

					if (howToPlay)
					{
						while (SDL_PollEvent(&e) != 0)
						{
							if (e.type == SDL_QUIT)
							{
								exitGame = true;
							}

							getBack_button.HandleGetBackButton(e, gRenderer, menu, play, quitMenu, howToPlay, upgrade, switch_button_sound_effect);
							the_aim.handdleEvent(e);
						}
						SDL_SetRenderDrawColor(gRenderer, 100,100, 0, 100);
						SDL_RenderClear(gRenderer);
						//button
						getBack_button.setPos(100, 20, gRenderer);
						the_aim.render(gRenderer);
						SDL_RenderPresent(gRenderer);
					}


					if (upgrade)
					{
						while (SDL_PollEvent(&e) != 0)
						{
							if (e.type == SDL_QUIT)
							{
								exitGame = true;
								
							}
							//button event
							
							upgrade_bullet_dam_button.HandleUpgrade(e, gRenderer, money_to_upgrade_bullet_dam, bullet_dam, value_of_upgrade_bullet_dam, money, upgrade_sound_effect);
							upgrade_bullet_rpm_button.HandleUpgrade(e, gRenderer, money_to_upgrade_bullet_rpm, delay_shot_time, value_of_upgrade_bullet_rpm, money, upgrade_sound_effect);
							upgrade_rocket_dam_button.HandleUpgrade(e, gRenderer, money_to_upgrade_rocket_dam, rocket_dam, value_of_upgrade_rocket_dam, money, upgrade_sound_effect);
							upgrade_rocket_rpm_button.HandleUpgrade(e, gRenderer, money_to_upgrade_bullet_rpm, delay_launch_time, value_of_upgrade_rocket_rpm, money, upgrade_sound_effect);
							upgrade_health_button.HandleUpgrade(e, gRenderer, money_to_upgrade_health, blood, value_of_upgrade_health, money, upgrade_sound_effect);
							
							getBack_button.HandleGetBackButton(e, gRenderer, menu, play, quitMenu, howToPlay, upgrade, switch_button_sound_effect);
							the_aim.handdleEvent(e);

						}
						SDL_SetRenderDrawColor(gRenderer, 100, 100, 0, 100);
						SDL_RenderClear(gRenderer);

						upgrade_bullet_dam_button.setPos(300, 150, gRenderer);
						content_of_upgrade_bullet_dam.loadFromRenderedText("+1 bullet damage ( " +convert_to_string(bullet_dam)+ " ) :: cost 1000$", color_black, gRenderer, game_font);
						content_of_upgrade_bullet_dam.render(350, 150, gRenderer);

						upgrade_bullet_rpm_button.setPos(300, 200, gRenderer);
						content_of_upgrade_bullet_rpm.loadFromRenderedText("-50ms delay shoot time ( " +convert_to_string(delay_shot_time)+ "ms ) :: cost 1500$", color_black, gRenderer, game_font);
						content_of_upgrade_bullet_rpm.render(350, 200, gRenderer);

						upgrade_rocket_dam_button.setPos(300, 250, gRenderer);
						content_of_upgrade_rocket_dam.loadFromRenderedText("+2 rocket damage ( " +convert_to_string(rocket_dam) + " ) :: cost 2000$", color_black, gRenderer, game_font);
						content_of_upgrade_rocket_dam.render(350, 250, gRenderer);

						upgrade_rocket_rpm_button.setPos(300, 300, gRenderer);
						content_of_upgrade_rocket_rpm.loadFromRenderedText("-300ms delay launch time ( " +convert_to_string(delay_launch_time)+ "ms ):: cost 2500$", color_black, gRenderer, game_font);
						content_of_upgrade_rocket_rpm.render(350, 300, gRenderer);

						upgrade_health_button.setPos(300, 350, gRenderer);
						content_of_upgrade_health.loadFromRenderedText("+300 city health ( " +convert_to_string(blood)+" ) :: cost 3000$", color_black, gRenderer, game_font);
						content_of_upgrade_health.render(350, 350, gRenderer);

						your_money.loadFromRenderedText("Your money: " + convert_to_string(money) + "$", color_black, gRenderer, game_font);
						your_money.render(1000, 0, gRenderer);

						the_aim.render(gRenderer);
						getBack_button.setPos(100, 20, gRenderer);

						SDL_RenderPresent(gRenderer);
					}
				}

				// when PLAY
				while (play)
				{
					if (Mix_PlayingMusic() == 1)
					{
						Mix_HaltMusic();
					}

					while (SDL_PollEvent(&e) != 0)
					{
						if (e.type == SDL_QUIT)
						{
							exitGame = true;
							play = false;
						}
						gun.handleEvent(e);
						the_aim.handdleEvent(e);


						quit_game_button.HandleQuitButton(e, gRenderer, exitGame, play, switch_button_sound_effect);
						replay_button.HandleReplayButton(e, gRenderer, menu, play, howToPlay, switch_button_sound_effect, your_score, blood, upgrade_blood,plus_money_once_time,option,enemy_list,bomb_list,wave);
						main_button.HandleMenuButton(e, gRenderer, menu, play, quitMenu, your_score, blood,  upgrade_blood,switch_button_sound_effect,plus_money_once_time, option,enemy_list,bomb_list,wave);
						option_button.HandleOptionButton(e, gRenderer, option, switch_button_sound_effect);
					}

					if (blood <= 0)
					{
						is_dead = true;
						blood = 0;
					}
					else
					{
						is_dead = false;
					}

					//fps
					frameStart = SDL_GetTicks();

					SDL_SetRenderDrawColor(gRenderer, 100, 100, 0, 100);
					SDL_RenderClear(gRenderer);

					SDL_ShowCursor(SDL_DISABLE);
					backGround.render(0, 0, gRenderer);

					if (!is_dead)
					{
						generateEnemy(enemy_list, gRenderer, wave, is_dead);
					}


					Collision(enemy_list, gun, bullet_dam, rocket_dam, rocket_list, bomb_list,explosion_sound_effect ,gRenderer, your_score, blood, frame);

					//player
					gun.render(gRenderer);

					if (!is_dead && !option)
					{
						//bullet
						gun.makeBullet(gRenderer, delay_shot_time, gun_sound_effect);
						gun.handleBullet(gRenderer);
						//rocket
						gun.makeRocket(gRenderer, delay_launch_time, rocket_sound_effect);
						gun.handleRocket(gRenderer);
					}
					

					pic.render(0, screen_height - 88, gRenderer);
					
					city_background.render(0, screen_height - city_background.get_height(), gRenderer);

					//render score text
					score.loadFromRenderedText("Score: " + convert_to_string(your_score), color_text_score, gRenderer, game_font);
					score.render(0, 0, gRenderer);

					//render city_blood text
					city_blood.loadFromRenderedText("City Health: " + convert_to_String(blood) + "/" + convert_to_String(upgrade_blood), color_of_blood, gRenderer, game_font);
					city_blood.render(50, 550, gRenderer);

					//button
					option_button.setPos(screen_width - option_button.get_width()-20, screen_height - option_button.get_height()-20, gRenderer);
					the_aim.render(gRenderer);
					if (is_dead) 
					{
						GameOver.render((screen_width - GameOver.get_width()) / 2, (screen_height - GameOver.get_height()) / 2 - space_between_button - 50, gRenderer);
						//button
						quit_game_button.setPos((screen_width - quit_game_button.get_frame_width()) / 2, (screen_height - quit_game_button.get_frame_height()) / 2, gRenderer);
						replay_button.setPos((screen_width - replay_button.get_frame_width()) / 2, (screen_height - replay_button.get_frame_height()) / 2 + space_between_button, gRenderer);
						main_button.setPos((screen_width - main_button.get_frame_width()) / 2, (screen_height - main_button.get_frame_height()) / 2 + space_between_button * 2, gRenderer);
						if (your_score > high_score)
						{
							update("hight_score.txt", your_score);
						}
						if (plus_money_once_time)
						{
							money += your_score;
							plus_money_once_time = false;
						}
					}

					if (option)
					{
						quit_game_button.setPos((screen_width - quit_game_button.get_frame_width()) / 2, (screen_height - quit_game_button.get_frame_height()) / 2, gRenderer);
						replay_button.setPos((screen_width - replay_button.get_frame_width()) / 2, (screen_height - replay_button.get_frame_height()) / 2 + space_between_button, gRenderer);
						main_button.setPos((screen_width - main_button.get_frame_width()) / 2, (screen_height - main_button.get_frame_height()) / 2 + space_between_button * 2, gRenderer);
					}

					SDL_RenderPresent(gRenderer);

					//fps
					frameTime = SDL_GetTicks() - frameStart;
					if (timePerFrame > frameTime)
					{
						SDL_Delay(timePerFrame - frameTime);
					}

				}
			}
		}
		//update before close
		update("city_blood.txt", upgrade_blood);
		update("bullet_dam.txt", bullet_dam);
		update("bullet_rpm.txt", delay_shot_time);
		update("rocket_dam.txt", rocket_dam);
		update("rocket_rpm.txt", delay_launch_time);
		update("money.txt", money);
	}
	

	//Free resources and close everythings
	close();

	return 0;
}