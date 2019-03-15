#ifndef __Z_SAVECTX_H_
#define __Z_SAVECTX_H_
#include <ultra64.h>

//z_common_data is likely the "save context" struct
//z_common_data.memory is likely the data that should actually be saved
//z_common_data.memory.information might be flags
//z_common_data.memory.information.room_inf //scene flags
//z_common_data.yabusame_total is likely referring to the points total outside save data

typedef struct {
	char b;
	union
	{
		char c_Buttons[3];
		struct
		{
			char c_left;
			char c_down;
			char c_right;
		};
	};
	union
	{
		char c_Slots[3];
		struct
		{
			char c_left_Slot;
			char c_down_Slot;
			char c_right_Slot;
		};
	};
	unsigned short equipment;
} z_item_equips_t; //0x0A bytes

typedef struct {
	/* 0x00 */ int chests;
	/* 0x04 */ int switches;
	/* 0x08 */ int roomClear;
	/* 0x0C */ int collectibles;
	/* 0x10 */ int unk;
	/* 0x14 */ int visited1;
	/* 0x18 */ int visited2;
} z_scene_flags_t; //0x1C bytes

typedef struct {
	/* 0x00 */ float x;
	/* 0x04 */ float y;
	/* 0x08 */ float z;
	/* 0x0C */ short yRot;
	/* 0x0E */ short linkVar;
	/* 0x10 */ short entIndex;
	/* 0x12 */ unsigned char room; //not sure?
	/* 0x13 */ unsigned char data; //used by grottos to store chest type, warp songs for spawn in sparkle color
	/* 0x14 */ int tempFlags1; //GlobalContext + 0x1D2C
	/* 0x18 */ int tempFlags2; //GlobalContext + 0x1D48
} z_respawn_t; //0x1C bytes

typedef struct {
	
	/* 0x0000 */ int entIndex;
	/* 0x0004 */ int age;
	/* 0x0008 */ int cutscene;
	/* 0x000C */ short time;
	//padding
	/* 0x0010 */ int isNight;
	/* 0x0014 */ char __pad_0x14[0x10];
	/* 0x0024 */ char name[0x8];
	/* 0x002C */ short diskSave;
	/* 0x002E */ short maxHp;
	/* 0x0030 */ short hp;
	/* 0x0032 */ char __unk_0x32_magic; //if 0, fills magic from somewhere else
	/* 0x0033 */ char mp; //current magic
	/* 0x0034 */ short rupees;
	/* 0x0036 */ short __pad_0x0036;
	/* 0x0038 */ short naviTimer;
	/* 0x003A */ char haveMagic;
	/* 0x003B */ char __pad_0x003B[4];
    /* 0x003F */ char ocarinaMinigame;
	/* 0x0040 */ z_item_equips_t childEquips;
	/* 0x004A */ z_item_equips_t adultEquips;
	/* 0x0054 */ char __pad_0x0054[0x12];
	/* 0x0066 */ short savedSceneId;
	/* 0x0068 */ z_item_equips_t currEquips;
	/* 0x0072 */ short __pad_0x0072;
	/* 0x0074 */ char inventory[24];
	/* 0x008C */ char inventoryAmmo[0xF];
	/* 0x009B */ char magicBeansBought;
	/* 0x009C */ struct
	{
		/* 0x009C */
		unsigned char __padBoots : 1;
		unsigned char hover_boots : 1;
		unsigned char iron_boots : 1;
		unsigned char kokiri_boots : 1;
		unsigned char __padTunics : 1;
		unsigned char zora_tunic : 1;
		unsigned char goron_tunic : 1;
		unsigned char kokiri_tunic : 1;
		
		/* 0x009D */
		unsigned char __padShields : 1;
		unsigned char mirror_shield : 1;
		unsigned char hylian_shield : 1;
		unsigned char deku_shield : 1;
		unsigned char brokenFlag : 1;
		unsigned char biggoronSword : 1;
		unsigned char masterSword : 1;
		unsigned char kokiriSword : 1;
		
		/* 0x009E */
		unsigned int padding : 16;
	} equipment;
	/* 0x00A0 */ struct
	{
		unsigned int test : 32;
	}	equipment2;
	/* 0x00A4 */ struct
	{
		
		/* 0x00A4 */
		unsigned char heart_pieces : 4;
		unsigned char unused : 4;
		
		/* 0x00A5 */
		/* 80 */
		unsigned char gold_skulltula_icon : 1;
		unsigned char gerudo_card : 1;
		unsigned char stone_agony : 1;
		unsigned char zora_sapphire : 1;
		unsigned char goron_ruby : 1;
		unsigned char kokiri_emerald : 1;
		unsigned char song_of_storms : 1;
		unsigned char song_of_time : 1;
		/* 01 */
		
		/* 0x00A6 */
		unsigned char suns_song : 1;
		unsigned char sarias_song : 1;
		unsigned char eponas_song : 1;
		unsigned char zeldas_lullaby : 1;
		unsigned char prelude_song : 1;
		unsigned char nocturne_song : 1;
		unsigned char requiem_song : 1;
		unsigned char serenade_song : 1;
		
		/* 0x00A7 */
		unsigned char bolero_song : 1;
		unsigned char minuet_song : 1;
		unsigned char light_medallion : 1;
		unsigned char shadow_medallion : 1;
		unsigned char spirit_medallion : 1;
		unsigned char water_medallion : 1;
		unsigned char fire_medallion : 1;
		unsigned char forest_medallion : 1;
		
	} questItems;
	/* 0x00A8 */ char dungeonItems[0x14];
	/* 0x00BC */ char dungeonKeys[0x13];
	/* 0x00CF */ char doubleDefenseHearts;
	/* 0x00D0 */ int goldSkulltulaTokens;
	/* 0x00D4 */ z_scene_flags_t sceneFlags[101]; //0x1C byte ea, 0xB0C
	/* 0x0BE0 */ char __pad_0x0A4C[0x284];
	struct 
	{
    /* 0x0E64 */	float x, y, z;	
    /* 0x0E70 */	short y_rot;		
    /* 0x0E72 */	char __pad_00[0x8];
	/* 0x0E7A */    unsigned short scene_no;
	/* 0x0E7C */    unsigned int map_no;
	/* 0x0E80 */    int	isset;
    } farore_warp;
	/* 0x0E84 */ char __pad_0x0E84[0x50];
	/* 0x0ED4 */ unsigned short event_chk_inf[14];
	/* 0x0EF0 */ unsigned short item_get_inf[4];
	/* 0x0EF8 */ unsigned short inf_table[30];
	/* 0x0F34 */ char __pad_0x0F34[0x428];
	/* 0x135C */ int gameMode;
	/* 0x1360 */ int __pad_0x1360;
	/* 0x1364 */ int zoneoutType; 
	/* zoneoutTypes
	// -3 = Warp Song, reset temp flags. Uses zoneoutRespawn 1 data for spawning
	// -2 = ?, preserves temporary flags (sun's song, tower collapse, continue)
	// -1 = ?, preserves temporary flags. Warp back to last entrance index
	// 00 = Standard Exit, reset temporary flags
	// 01 = zoneoutRespawn 0, void
	// 02 = zoneoutRespawn 1, grotto and warp songs
	// 03 = zoneoutRespawn 2, farore's wind
	/* 0x1368 */ z_respawn_t zoneoutRespawn[3];
	/* 0x13BC */ char __pad_0x13BC[0x8];
	/* 0x13C4 */ unsigned short dogVar; //variable component for dog following Link
	/* 0x13C6 */ unsigned char unk_0x13C6;
	/* 0x13C7 */ unsigned char unk_0x13C7; //used
	/* 0x13C8 */ char __pad_0x13C8[0x4A];
	/* 0x1409 */ // char language;
	/* 0x1412 */ unsigned short cutsceneNext;
	/* 0x1414 */ short unk_0x1414;
	/* 0x1416 */ unsigned short unk_0x1416;
    /* 0x1426 */
	
} z_save_t;

extern z_save_t z_savectx;
asm("z_save_t = 0x8011A5D0");
asm(".global z_savectx");
#endif