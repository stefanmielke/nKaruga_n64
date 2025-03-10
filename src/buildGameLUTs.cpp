// This file was not generated by a tool.
#include "common.h"
#include "gfx/titleScreen.h"
#include "gfx/gfx.h"
#include "gfx/bossgfx.h"
#include "gfx/bg.h"
#include "gfx/bossWarning.h"
#include "sfx/list.h"

unsigned short *image_entries[NB_IMAGES];
unsigned short *bossImage_entries[NB_BOSS_IMAGES];
unsigned short *bgImage_entries[NB_BACKGROUND_IMAGES];
Mix_Chunk *sound_entries[NB_SOUNDS];
Mix_Music *music_entries[NB_MUSICS];

void buildGameLUTs()
{
	/* GFX */
	// Base images
	image_entries[image_LUT_null] = image_null;
	image_entries[image_LUT_player_ship_light] = image_player_ship_light;
	image_entries[image_LUT_player_ship_shadow] = image_player_ship_shadow;
	image_entries[image_LUT_player_ship_polarityswitch_0_light] = image_player_ship_polarityswitch_0_light;
	image_entries[image_LUT_player_ship_polarityswitch_0_shadow] = image_player_ship_polarityswitch_0_shadow;
	image_entries[image_LUT_player_ship_polarityswitch_1_light] = image_player_ship_polarityswitch_1_light;
	image_entries[image_LUT_player_ship_polarityswitch_1_shadow] = image_player_ship_polarityswitch_1_shadow;
	image_entries[image_LUT_player_ship_invincible_light] = image_player_ship_invincible_light;
	image_entries[image_LUT_player_ship_invincible_shadow] = image_player_ship_invincible_shadow;
	image_entries[image_LUT_player_homing_bullet_light_0] = image_player_homing_bullet_light_0;
	image_entries[image_LUT_player_homing_bullet_light_1] = image_player_homing_bullet_light_1;
	image_entries[image_LUT_player_homing_bullet_light_2] = image_player_homing_bullet_light_2;
	image_entries[image_LUT_player_homing_bullet_shadow_0] = image_player_homing_bullet_shadow_0;
	image_entries[image_LUT_player_homing_bullet_shadow_1] = image_player_homing_bullet_shadow_1;
	image_entries[image_LUT_player_homing_bullet_shadow_2] = image_player_homing_bullet_shadow_2;
	image_entries[image_LUT_player_bullet_light] = image_player_bullet_light;
	image_entries[image_LUT_player_bullet_shadow] = image_player_bullet_shadow;
	image_entries[image_LUT_player_explosion_0] = image_player_explosion_0;
	image_entries[image_LUT_player_explosion_1] = image_player_explosion_1;
	image_entries[image_LUT_player_explosion_2] = image_player_explosion_2;
	image_entries[image_LUT_player_explosion_3] = image_player_explosion_3;
	image_entries[image_LUT_player_explosion_4] = image_player_explosion_4;
	image_entries[image_LUT_player_explosion_5] = image_player_explosion_5;
	image_entries[image_LUT_player_explosion_6] = image_player_explosion_6;
	image_entries[image_LUT_player_explosion_7] = image_player_explosion_7;
	image_entries[image_LUT_player_explosion_8] = image_player_explosion_8;
	image_entries[image_LUT_player_explosion_9] = image_player_explosion_9;
	image_entries[image_LUT_player_explosion_10] = image_player_explosion_10;
	image_entries[image_LUT_player_explosion_11] = image_player_explosion_11;
	image_entries[image_LUT_enemy_bullet_0_light] = image_enemy_bullet_0_light;
	image_entries[image_LUT_enemy_bullet_0_shadow] = image_enemy_bullet_0_shadow;
	image_entries[image_LUT_enemy_bullet_1_light] = image_enemy_bullet_1_light;
	image_entries[image_LUT_enemy_bullet_1_shadow] = image_enemy_bullet_1_shadow;
	image_entries[image_LUT_enemy_bullet_2_light] = image_enemy_bullet_2_light;
	image_entries[image_LUT_enemy_bullet_2_shadow] = image_enemy_bullet_2_shadow;
	image_entries[image_LUT_enemy_homing_bullet_light] = image_enemy_homing_bullet_light;
	image_entries[image_LUT_enemy_homing_bullet_shadow] = image_enemy_homing_bullet_shadow;
	image_entries[image_LUT_enemy_laser_light] = image_enemy_laser_light;
	image_entries[image_LUT_enemy_laser_shadow] = image_enemy_laser_shadow;
	image_entries[image_LUT_enemy_generator_light] = image_enemy_generator_light;
	image_entries[image_LUT_enemy_generator_shadow] = image_enemy_generator_shadow;
	image_entries[image_LUT_enemy_wall_light] = image_enemy_wall_light;
	image_entries[image_LUT_enemy_wall_shadow] = image_enemy_wall_shadow;
	image_entries[image_LUT_enemy_ship_0_light] = image_enemy_ship_0_light;
	image_entries[image_LUT_enemy_ship_0_shadow] = image_enemy_ship_0_shadow;
	image_entries[image_LUT_enemy_ship_1_light] = image_enemy_ship_1_light;
	image_entries[image_LUT_enemy_ship_1_shadow] = image_enemy_ship_1_shadow;
	image_entries[image_LUT_enemy_ship_2_light] = image_enemy_ship_2_light;
	image_entries[image_LUT_enemy_ship_2_shadow] = image_enemy_ship_2_shadow;
	image_entries[image_LUT_enemy_ship_3_light] = image_enemy_ship_3_light;
	image_entries[image_LUT_enemy_ship_3_shadow] = image_enemy_ship_3_shadow;
	image_entries[image_LUT_enemy_ship_4_light] = image_enemy_ship_4_light;
	image_entries[image_LUT_enemy_ship_4_shadow] = image_enemy_ship_4_shadow;
	image_entries[image_LUT_enemy_ship_4_lightball] = image_enemy_ship_4_lightball;
	image_entries[image_LUT_enemy_ship_4_shadowball] = image_enemy_ship_4_shadowball;
	image_entries[image_LUT_enemy_ship_5_light] = image_enemy_ship_5_light;
	image_entries[image_LUT_enemy_ship_5_shadow] = image_enemy_ship_5_shadow;
	image_entries[image_LUT_enemy_ship_6_light] = image_enemy_ship_6_light;
	image_entries[image_LUT_enemy_ship_6_shadow] = image_enemy_ship_6_shadow;
	image_entries[image_LUT_door_left] = image_door_left;
	image_entries[image_LUT_door_right] = image_door_right;
	image_entries[image_LUT_box_light_1] = image_box_light_1;
	image_entries[image_LUT_box_light_2] = image_box_light_2;
	image_entries[image_LUT_box_light_3] = image_box_light_3;
	image_entries[image_LUT_box_light_4] = image_box_light_4;
	image_entries[image_LUT_box_light_5] = image_box_light_5;
	image_entries[image_LUT_box_light_6] = image_box_light_6;
	image_entries[image_LUT_box_shadow_1] = image_box_shadow_1;
	image_entries[image_LUT_box_shadow_2] = image_box_shadow_2;
	image_entries[image_LUT_box_shadow_3] = image_box_shadow_3;
	image_entries[image_LUT_box_shadow_4] = image_box_shadow_4;
	image_entries[image_LUT_box_shadow_5] = image_box_shadow_5;
	image_entries[image_LUT_box_shadow_6] = image_box_shadow_6;
	image_entries[image_LUT_box_solid_1] = image_box_solid_1;
	image_entries[image_LUT_box_solid_2] = image_box_solid_2;
	image_entries[image_LUT_box_solid_3] = image_box_solid_3;
	image_entries[image_LUT_box_solid_4] = image_box_solid_4;
	image_entries[image_LUT_box_solid_5] = image_box_solid_5;
	image_entries[image_LUT_box_solid_6] = image_box_solid_6;
	image_entries[image_LUT_prop_wall_left] = image_prop_wall_left;
	image_entries[image_LUT_prop_wall_right] = image_prop_wall_right;
	image_entries[image_LUT_boss1_enemy_ship_light] = image_boss1_enemy_ship_light;
	image_entries[image_LUT_boss1_enemy_ship_shadow] = image_boss1_enemy_ship_shadow;
	image_entries[image_LUT_boss1_grenade_light] = image_boss1_grenade_light;
	image_entries[image_LUT_boss1_grenade_shadow] = image_boss1_grenade_shadow;
	image_entries[image_LUT_boss2_leftShield] = image_boss2_leftShield;
	image_entries[image_LUT_boss2_rightShield] = image_boss2_rightShield;
	image_entries[image_LUT_boss2_leftUpperArm] = image_boss2_leftUpperArm;
	image_entries[image_LUT_boss2_rightUpperArm] = image_boss2_rightUpperArm;
	image_entries[image_LUT_chain_hit_light] = image_chain_hit_light;
	image_entries[image_LUT_chain_hit_shadow] = image_chain_hit_shadow;
	image_entries[image_LUT_explosion_light_0] = image_explosion_light_0;
	image_entries[image_LUT_explosion_light_1] = image_explosion_light_1;
	image_entries[image_LUT_explosion_light_2] = image_explosion_light_2;
	image_entries[image_LUT_explosion_light_3] = image_explosion_light_3;
	image_entries[image_LUT_explosion_light_4] = image_explosion_light_4;
	image_entries[image_LUT_explosion_light_5] = image_explosion_light_5;
	image_entries[image_LUT_explosion_shadow_0] = image_explosion_shadow_0;
	image_entries[image_LUT_explosion_shadow_1] = image_explosion_shadow_1;
	image_entries[image_LUT_explosion_shadow_2] = image_explosion_shadow_2;
	image_entries[image_LUT_explosion_shadow_3] = image_explosion_shadow_3;
	image_entries[image_LUT_explosion_shadow_4] = image_explosion_shadow_4;
	image_entries[image_LUT_explosion_shadow_5] = image_explosion_shadow_5;
	image_entries[image_LUT_powerslot] = image_powerslot;
	image_entries[image_LUT_lives] = image_lives;
	image_entries[image_LUT_bossWarning] = image_bossWarning;
	image_entries[image_LUT_titleScreen] = image_titleScreen;
	
	// Boss images
	bossImage_entries[bossImage_LUT_1_body] = bossImage_1_body;
	bossImage_entries[bossImage_LUT_1_leftarm_armed] = bossImage_1_leftarm_armed;
	bossImage_entries[bossImage_LUT_1_rightarm_armed1] = bossImage_1_rightarm_armed1;
	bossImage_entries[bossImage_LUT_1_rightarm_armed2] = bossImage_1_rightarm_armed2;
	bossImage_entries[bossImage_LUT_1_leftarm_nonarmed] = bossImage_1_leftarm_nonarmed;
	bossImage_entries[bossImage_LUT_1_rightarm_nonarmed] = bossImage_1_rightarm_nonarmed;
	bossImage_entries[bossImage_LUT_2_body] = bossImage_2_body;
	bossImage_entries[bossImage_LUT_2_leftShield] = bossImage_2_leftShield;
	bossImage_entries[bossImage_LUT_2_rightShield] = bossImage_2_rightShield;
	bossImage_entries[bossImage_LUT_2_leftArm] = bossImage_2_leftArm;
	bossImage_entries[bossImage_LUT_2_rightArm] = bossImage_2_rightArm;
	bossImage_entries[bossImage_LUT_2_leftUpperArm] = bossImage_2_leftUpperArm;
	bossImage_entries[bossImage_LUT_2_rightUpperArm] = bossImage_2_rightUpperArm;
	bossImage_entries[bossImage_LUT_2_leftWing] = bossImage_2_leftWing;
	bossImage_entries[bossImage_LUT_2_leftWingOpening_1] = bossImage_2_leftWingOpening_1;
	bossImage_entries[bossImage_LUT_2_leftWingOpening_2] = bossImage_2_leftWingOpening_2;
	bossImage_entries[bossImage_LUT_2_leftWingOpening_3] = bossImage_2_leftWingOpening_3;
	bossImage_entries[bossImage_LUT_2_leftWingOpening_4] = bossImage_2_leftWingOpening_4;
	bossImage_entries[bossImage_LUT_2_rightWing] = bossImage_2_rightWing;
	bossImage_entries[bossImage_LUT_2_rightWingOpening_1] = bossImage_2_rightWingOpening_1;
	bossImage_entries[bossImage_LUT_2_rightWingOpening_2] = bossImage_2_rightWingOpening_2;
	bossImage_entries[bossImage_LUT_2_rightWingOpening_3] = bossImage_2_rightWingOpening_3;
	bossImage_entries[bossImage_LUT_2_rightWingOpening_4] = bossImage_2_rightWingOpening_4;
	bossImage_entries[bossImage_LUT_2_rails] = bossImage_2_rails;
	bossImage_entries[bossImage_LUT_2_hitpoint_left_1] = bossImage_2_hitpoint_left_1;
	bossImage_entries[bossImage_LUT_2_hitpoint_left_2] = bossImage_2_hitpoint_left_2;
	bossImage_entries[bossImage_LUT_2_hitpoint_left_3] = bossImage_2_hitpoint_left_3;
	bossImage_entries[bossImage_LUT_2_hitpoint_left_4] = bossImage_2_hitpoint_left_4;
	bossImage_entries[bossImage_LUT_2_hitpoint_left_5] = bossImage_2_hitpoint_left_5;
	bossImage_entries[bossImage_LUT_2_hitpoint_right_1] = bossImage_2_hitpoint_right_1;
	bossImage_entries[bossImage_LUT_2_hitpoint_right_2] = bossImage_2_hitpoint_right_2;
	bossImage_entries[bossImage_LUT_2_hitpoint_right_3] = bossImage_2_hitpoint_right_3;
	bossImage_entries[bossImage_LUT_2_hitpoint_right_4] = bossImage_2_hitpoint_right_4;
	bossImage_entries[bossImage_LUT_2_hitpoint_right_5] = bossImage_2_hitpoint_right_5;

	// Background images
	bgImage_entries[bgImage_LUT_1_0] = image_bg1_0;
	bgImage_entries[bgImage_LUT_1_1] = image_bg1_1;
	bgImage_entries[bgImage_LUT_1_2] = image_bg1_2;
	bgImage_entries[bgImage_LUT_1_3] = image_bg1_3;
	bgImage_entries[bgImage_LUT_1_4] = image_bg1_4;
	bgImage_entries[bgImage_LUT_2_0] = image_bg2_0;
	bgImage_entries[bgImage_LUT_2_1] = image_bg2_1;
	bgImage_entries[bgImage_LUT_2_2] = image_bg2_2;
	bgImage_entries[bgImage_LUT_2_3] = image_bg2_3;
	bgImage_entries[bgImage_LUT_2_4] = image_bg2_4;
	bgImage_entries[bgImage_LUT_2_5] = image_bg2_5;
	bgImage_entries[bgImage_LUT_2_6] = image_bg2_6;
	bgImage_entries[bgImage_LUT_2_7] = image_bg2_7;
	
#ifndef N64
	/* SFX */
	// Sounds
	for (int i = 0; i < NB_SOUNDS; i++)
	{
		printf("Loading sound '%s' ... ", sfxList[i]);
		sound_entries[i] = Mix_LoadWAV(sfxList[i]);
		printf("done\n");
	}
	// Background musics
	for (int i = 0; i < NB_MUSICS; i++)
	{
		printf("Loading music '%s' ... ", musicList[i]);
		music_entries[i] = Mix_LoadMUS(musicList[i]);
		printf("done\n");
	}
#endif
}

void freeGameLUTs()
{
#ifndef N64
	// Sounds
	for (int i = 0; i < NB_SOUNDS; i++)
		Mix_FreeChunk(sound_entries[i]);
	// Background musics
	for (int i = 0; i < NB_MUSICS; i++)
		Mix_FreeMusic(music_entries[i]);
#endif
}