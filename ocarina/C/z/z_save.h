#ifndef __Z_SAVECTX_H_
#define __Z_SAVECTX_H_
#include <ultra64.h>

//z_common_data is likely the "save context" struct
//z_common_data.memory is likely the data that should actually be saved
//z_common_data.memory.information might be flags
//z_common_data.memory.information.room_inf //scene flags
//z_common_data.yabusame_total is likely referring to the points total outside save data

typedef struct {
	uint8_t b;
	union
	{
		uint8_t c_Buttons[3];
		struct
		{
			uint8_t c_left;
			uint8_t c_down;
			uint8_t c_right;
		};
	};
	union
	{
		uint8_t c_Slots[3];
		struct
		{
			uint8_t c_left_Slot;
			uint8_t c_down_Slot;
			uint8_t c_right_Slot;
		};
	};
	uint16_t equipment;
} z_item_equips_t; //0x0A bytes

typedef struct {
	/* 0x00 */ int32_t chests;
	/* 0x04 */ int32_t switches;
	/* 0x08 */ int32_t roomClear;
	/* 0x0C */ int32_t collectibles;
	/* 0x10 */ int32_t unk;
	/* 0x14 */ int32_t visited1;
	/* 0x18 */ int32_t visited2;
} z_scene_flags_t; //0x1C bytes

typedef struct {
	/* 0x00 */ Vec3f pos;
	/* 0x0C */ int16_t yRot;
	/* 0x0E */ int16_t var; //Link's var component
	/* 0x10 */ int16_t entrance;
	/* 0x12 */ uint8_t room; //not sure?
	/* 0x13 */ uint8_t data; //used by grottos to store chest type, warp songs for spawn in sparkle color
	/* 0x14 */ int32_t temp_switch_flags; //GlobalContext + 0x1D2C
	/* 0x18 */ int32_t temp_collect_flags; //GlobalContext + 0x1D48
} z_respawn_t; //0x1C bytes

typedef struct {
	
	/* 0x0000 */ int32_t entIndex;
	/* 0x0004 */ int32_t age;
	/* 0x0008 */ int32_t cutscene;
	/* 0x000C */ int16_t time;
	//padding
	/* 0x0010 */ int32_t isNight;
	/* 0x0014 */ char __pad_0x14[0x10];
	/* 0x0024 */ char name[0x8];
	/* 0x002C */ int16_t diskSave;
	/* 0x002E */ int16_t maxHp;
	/* 0x0030 */ int16_t hp;
	/* 0x0032 */ uint8_t __unk_0x32_magic; //if 0, fills magic from somewhere else
	/* 0x0033 */ uint8_t mp; //current magic
	/* 0x0034 */ int16_t rupees;
	/* 0x0036 */ int16_t bgs_hits_left;
	/* 0x0038 */ int16_t naviTimer;
	/* 0x003A */ uint8_t haveMagic;
	/* 0x003B */ char __pad_0x003B[4];
    /* 0x003F */ char ocarinaMinigame;
	/* 0x0040 */ z_item_equips_t childEquips;
	/* 0x004A */ z_item_equips_t adultEquips;
	/* 0x0054 */ char __pad_0x0054[0x12];
	/* 0x0066 */ int16_t savedSceneId;
	/* 0x0068 */ z_item_equips_t currEquips;
	/* 0x0072 */ int16_t __pad_0x0072;
	/* 0x0074 */ uint8_t inventory[24];
	/* 0x008C */ char inventoryAmmo[0xF];
	/* 0x009B */ char magicBeansBought;
	/* 0x009C */ struct
	{
		/* 0x009C */
		uint8_t __padBoots : 1;
		uint8_t hover_boots : 1;
		uint8_t iron_boots : 1;
		uint8_t kokiri_boots : 1;
		uint8_t __padTunics : 1;
		uint8_t zora_tunic : 1;
		uint8_t goron_tunic : 1;
		uint8_t kokiri_tunic : 1;
		
		/* 0x009D */
		uint8_t __padShields : 1;
		uint8_t mirror_shield : 1;
		uint8_t hylian_shield : 1;
		uint8_t deku_shield : 1;
		uint8_t brokenFlag : 1;
		uint8_t biggoronSword : 1;
		uint8_t masterSword : 1;
		uint8_t kokiriSword : 1;
		
		/* 0x009E */
		uint32_t padding : 16;
	} equipment;
	/* 0x00A0 */ struct
	{
		uint32_t test : 32;
	}	equipment2;
	/* 0x00A4 */ struct
	{
		
		/* 0x00A4 */
		uint8_t heart_pieces : 4;
		uint8_t unused : 4;
		
		/* 0x00A5 */
		/* 80 */
		uint8_t gold_skulltula_icon : 1;
		uint8_t gerudo_card : 1;
		uint8_t stone_agony : 1;
		uint8_t zora_sapphire : 1;
		uint8_t goron_ruby : 1;
		uint8_t kokiri_emerald : 1;
		uint8_t song_of_storms : 1;
		uint8_t song_of_time : 1;
		/* 01 */
		
		/* 0x00A6 */
		uint8_t suns_song : 1;
		uint8_t sarias_song : 1;
		uint8_t eponas_song : 1;
		uint8_t zeldas_lullaby : 1;
		uint8_t prelude_song : 1;
		uint8_t nocturne_song : 1;
		uint8_t requiem_song : 1;
		uint8_t serenade_song : 1;
		
		/* 0x00A7 */
		uint8_t bolero_song : 1;
		uint8_t minuet_song : 1;
		uint8_t light_medallion : 1;
		uint8_t shadow_medallion : 1;
		uint8_t spirit_medallion : 1;
		uint8_t water_medallion : 1;
		uint8_t fire_medallion : 1;
		uint8_t forest_medallion : 1;
		
	} questItems;
	/* 0x00A8 */ uint8_t dungeonItems[0x14];
	/* 0x00BC */ char dungeonKeys[0x13];
	/* 0x00CF */ char doubleDefenseHearts;
	/* 0x00D0 */ int32_t goldSkulltulaTokens;
	/* 0x00D4 */ z_scene_flags_t sceneFlags[101]; //0x1C byte ea, 0xB0C
	/* 0x0BE0 */ char __pad_0x0A4C[0x284];
	struct 
	{
    /* 0x0E64 */	float x, y, z;	
    /* 0x0E70 */	int16_t y_rot;		
    /* 0x0E72 */	char __pad_00[0x8];
	/* 0x0E7A */    uint16_t scene_no;
	/* 0x0E7C */    uint32_t map_no;
	/* 0x0E80 */    int	isset;
    } farore_warp;
	/* 0x0E84 */ char __pad_0x0E84[0x50];
	/* 0x0ED4 */ uint16_t event_chk_inf[14];
	/* 0x0EF0 */ uint16_t item_get_inf[4];
	/* 0x0EF8 */ uint16_t inf_table[30];
	/* 0x0F34 */ char __pad_0x0F34[0x428];
	/* 0x135C */ int32_t gameMode;
	/* 0x1360 */ int32_t __pad_0x1360;
	/* 0x1364 */ int32_t zoneoutType; 
	/* zoneoutTypes
	// -3 = Warp Song, reset temp flags. Uses zoneoutRespawn 1 data for spawning
	// -2 = ?, preserves temporary flags (sun's song, tower collapse, continue)
	// -1 = ?, preserves temporary flags. Warp back to last entrance index
	// 00 = Standard Exit, reset temporary flags
	// 01 = zoneoutRespawn 0, void
	// 02 = zoneoutRespawn 1, grotto and warp songs
	// 03 = zoneoutRespawn 2, farore's wind */
	/* 0x1368 */ z_respawn_t zoneoutRespawn[3];
	/* 0x13BC */ char __pad_0x13BC[0x8];
	/* 0x13C4 */ uint16_t dogVar; //variable component for dog following Link
	/* 0x13C6 */ uint8_t unk_0x13C6;
	/* 0x13C7 */ uint8_t unk_0x13C7; //used
	/* 0x13C8 */ char __pad_0x13C8[0x4A];
	/* 0x1409 */ // char language;
	/* 0x1412 */ uint16_t cutsceneNext;
	/* 0x1414 */ int16_t unk_0x1414;
	/* 0x1416 */ uint16_t unk_0x1416;
    /* 0x1426 */
	
} z_save_t;

extern z_save_t z_savectx;
asm("z_save_t = 0x8011A5D0");
asm(".global z_savectx");
#endif