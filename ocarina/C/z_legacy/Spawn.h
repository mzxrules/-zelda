typedef struct 
{
	char scene;
	char spawn;
	short vars;
} z_EntranceTable;
z_EntranceTable *EntranceTable = (void *)(int)0x800F9C90;

enum __attribute__ ((__packed__)) z_Ent 
{
	ENT_DEKU_TREE_0              = 0x0000,
	ENT_DEKU_TREE_1              = 0x0252,
	ENT_DODONGO_CAVERN_0         = 0x0004,
	ENT_DODONGO_CAVERN_1         = 0x00C5,
	ENT_JABU_JABU_0              = 0x0028,
	ENT_JABU_JABU_1              = 0x0407,
	ENT_FOREST_TEMPLE_0          = 0x0169,
	ENT_FOREST_TEMPLE_1          = 0x024E,
	ENT_FOREST_TEMPLE_2          = 0x0584,
	ENT_FIRE_TEMPLE_0            = 0x0165,
	ENT_FIRE_TEMPLE_1            = 0x0175,
	ENT_WATER_TEMPLE_0           = 0x0010,
	ENT_WATER_TEMPLE_1           = 0x0423,
	ENT_SPIRIT_TEMPLE_0          = 0x0082,
	ENT_SPIRIT_TEMPLE_1          = 0x02F5,
	ENT_SPIRIT_TEMPLE_2          = 0x03F0,
	ENT_SPIRIT_TEMPLE_3          = 0x03F4,
	ENT_SPIRIT_TEMPLE_4          = 0x03F8,
	ENT_SHADOW_TEMPLE_0          = 0x0037,
	ENT_SHADOW_TEMPLE_1          = 0x02B2,
	ENT_SHADOW_TEMPLE_2          = 0x02B6,
	ENT_SHADOW_TEMPLE_3          = 0x04EA,
	ENT_BOTTOM_THE_WELL_0        = 0x0098,
	ENT_BOTTOM_THE_WELL_1        = 0x05CC,
	ENT_ICE_CAVERN_0             = 0x0088,
	ENT_ICE_CAVERN_1             = 0x05D8,
	ENT_GANON_TOWER_CLIMB_0      = 0x041B,
	ENT_GANON_TOWER_CLIMB_1      = 0x0427,
	ENT_GANON_TOWER_CLIMB_2      = 0x042B,
	ENT_GERUDO_TRAINING_0        = 0x0008,
	ENT_THIEVES_HIDEOUT_0        = 0x0486,
	ENT_THIEVES_HIDEOUT_1        = 0x048A,
	ENT_THIEVES_HIDEOUT_2        = 0x048E,
	ENT_THIEVES_HIDEOUT_3        = 0x0492,
	ENT_THIEVES_HIDEOUT_4        = 0x0496,
	ENT_THIEVES_HIDEOUT_5        = 0x049A,
	ENT_THIEVES_HIDEOUT_6        = 0x049E,
	ENT_THIEVES_HIDEOUT_7        = 0x04A2,
	ENT_THIEVES_HIDEOUT_8        = 0x04A6,
	ENT_THIEVES_HIDEOUT_9        = 0x04AA,
	ENT_THIEVES_HIDEOUT_10       = 0x04AE,
	ENT_THIEVES_HIDEOUT_11       = 0x04B2,
	ENT_THIEVES_HIDEOUT_12       = 0x0570,
	ENT_INSIDE_GANON_CASTLE_0    = 0x0467,
	ENT_INSIDE_GANON_CASTLE_1    = 0x0534,
	ENT_INSIDE_GANON_CASTLE_2    = 0x0538,
	ENT_INSIDE_GANON_CASTLE_3    = 0x053C,
	ENT_INSIDE_GANON_CASTLE_4    = 0x0540,
	ENT_INSIDE_GANON_CASTLE_5    = 0x0544,
	ENT_INSIDE_GANON_CASTLE_6    = 0x0548,
	ENT_INSIDE_GANON_CASTLE_7    = 0x054C,
	ENT_TOWER_COLLAPSE_IN_1      = 0x0134,
	ENT_TOWER_COLLAPSE_IN_0      = 0x0179,
	ENT_TOWER_COLLAPSE_IN_2      = 0x01B5,
	ENT_TOWER_COLLAPSE_IN_3      = 0x0256,
	ENT_TOWER_COLLAPSE_IN_4      = 0x03DC,
	ENT_TOWER_COLLAPSE_IN_5      = 0x03E0,
	ENT_TOWER_COLLAPSE_IN_6      = 0x03E4,
	ENT_TOWER_COLLAPSE_IN_7      = 0x04B6,
	ENT_TOWER_COLLAPSE_EXIT_0    = 0x056C,
	ENT_TREASURE_BOX_SHOP_0      = 0x0063,
	ENT_DEKU_TREE_BOSS_0         = 0x040F,
	ENT_DODONGO_CAVERN_BOSS_0    = 0x040B,
	ENT_JABU_JABU_BOSS_0         = 0x0301,
	ENT_FOREST_TEMPLE_BOSS_0     = 0x000C,
	ENT_FIRE_TEMPLE_BOSS_0       = 0x0305,
	ENT_WATER_TEMPLE_BOSS_0      = 0x0417,
	ENT_SPIRIT_TEMPLE_BOSS_0     = 0x008D,
	ENT_SPIRIT_TEMPLE_BOSS_2     = 0x05EC,
	ENT_SHADOW_TEMPLE_BOSS_0     = 0x0413,
	ENT_GANONDORF_BOSS_0         = 0x041F,
	ENT_TOWER_COLLAPSE_EX_5      = 0x01C9,
	ENT_TOWER_COLLAPSE_EX_2      = 0x032C,
	ENT_TOWER_COLLAPSE_EX_3      = 0x0330,
	ENT_TOWER_COLLAPSE_EX_4      = 0x0334,
	ENT_TOWER_COLLAPSE_EX_0      = 0x043F,
	ENT_TOWER_COLLAPSE_EX_1      = 0x04BA,
	ENT_TOWER_COLLAPSE_EX_6      = 0x051C,
	ENT_TOWER_COLLAPSE_EX_7      = 0x0524,
	ENT_MARKET_ENTRANCE_0        = 0x0033,
	ENT_MARKET_ENTRANCE_2        = 0x026E,
	ENT_MARKET_ENTRANCE_1        = 0x0276,
	ENT_BACK_ALLEY_3             = 0x0067,
	ENT_BACK_ALLEY_0             = 0x00AD,
	ENT_BACK_ALLEY_1             = 0x029A,
	ENT_BACK_ALLEY_4             = 0x038C,
	ENT_BACK_ALLEY_2             = 0x03C0,
	ENT_MARKET_0                 = 0x00B1,
	ENT_MARKET_8                 = 0x01CD,
	ENT_MARKET_9                 = 0x01D1,
	ENT_MARKET_10                = 0x01D5,
	ENT_MARKET_1                 = 0x025A,
	ENT_MARKET_2                 = 0x025E,
	ENT_MARKET_3                 = 0x0262,
	ENT_MARKET_4                 = 0x029E,
	ENT_MARKET_5                 = 0x02A2,
	ENT_MARKET_6                 = 0x03B8,
	ENT_MARKET_7                 = 0x03BC,
	ENT_OUTSIDE_TEMPLE_TIME_0    = 0x0171,
	ENT_OUTSIDE_TEMPLE_TIME_1    = 0x0472,
	ENT_KNOW_IT_ALL_BROTHERS_0   = 0x00C9,
	ENT_HOUSE_TWINS_0            = 0x009C,
	ENT_MIDO_HOUSE_0             = 0x0433,
	ENT_SARIA_HOUSE_0            = 0x0437,
	ENT_KAKARIKO_HOUSE_0         = 0x02FD,
	ENT_BACK_ALLEY_HOUSE_0       = 0x043B,
	ENT_BAZAAR_0                 = 0x00B7,
	ENT_BAZAAR_1                 = 0x052C,
	ENT_KOKIRI_SHOP_0            = 0x00C1,
	ENT_GORON_SHOP_0             = 0x037C,
	ENT_ZORA_SHOP_0              = 0x0380,
	ENT_KAKARIKO_POTION_SHOP_0   = 0x0384,
	ENT_KAKARIKO_POTION_SHOP_1   = 0x03E8,
	ENT_KAKARIKO_POTION_SHOP_2   = 0x03EC,
	ENT_MARKET_POTION_SHOP_0     = 0x0388,
	ENT_BOMBCHU_SHOP_0           = 0x0390,
	ENT_BOMBCHU_SHOP_1           = 0x0528,
	ENT_HAPPY_MASK_SHOP_0        = 0x0530,
	ENT_LINK_HOUSE_0             = 0x00BB,
	ENT_LINK_HOUSE_1             = 0x0272,
	ENT_PUPPY_WOMAN_HOUSE_0      = 0x0398,
	ENT_STABLES_0                = 0x02F9,
	ENT_IMPA_HOUSE_0             = 0x039C,
	ENT_IMPA_HOUSE_1             = 0x05C8,
	ENT_LAKESIDE_LABORATORY_0    = 0x0043,
	ENT_LAKESIDE_LABORATORY_1    = 0x01C5,
	ENT_CARPENTER_TENT_0         = 0x03A0,
	ENT_GRAVEKEEPER_HUT_0        = 0x030D,
	ENT_FAIRY_FOUNTAIN_UPGRADE_0 = 0x0315,
	ENT_FAIRY_FOUNTAIN_UPGRADE_1 = 0x04BE,
	ENT_FAIRY_FOUNTAIN_UPGRADE_2 = 0x04C2,
	ENT_FAIRY_FOUNTAIN_UPGRADE_3 = 0x04F2,
	ENT_FAIRY_FOUNTAIN_0         = 0x036D,
	ENT_FAIRY_FOUNTAIN_SPELL_0   = 0x0371,
	ENT_FAIRY_FOUNTAIN_SPELL_1   = 0x0578,
	ENT_FAIRY_FOUNTAIN_SPELL_2   = 0x0588,
	ENT_GROTTOS_0                = 0x003F,
	ENT_GROTTOS_1                = 0x0598,
	ENT_GROTTOS_2                = 0x059C,
	ENT_GROTTOS_3                = 0x05A0,
	ENT_GROTTOS_4                = 0x05A4,
	ENT_GROTTOS_5                = 0x05A8,
	ENT_GROTTOS_6                = 0x05AC,
	ENT_GROTTOS_7                = 0x05B0,
	ENT_GROTTOS_8                = 0x05B4,
	ENT_GROTTOS_9                = 0x05B8,
	ENT_GROTTOS_10               = 0x05BC,
	ENT_GROTTOS_11               = 0x05C0,
	ENT_GROTTOS_12               = 0x05C4,
	ENT_GROTTOS_13               = 0x05FC,
	ENT_GRAVE_REDEAD_0           = 0x031C,
	ENT_GRAVE_SHIELD_0           = 0x004B,
	ENT_ROYAL_FAMILY_TOMB_0      = 0x002D,
	ENT_ROYAL_FAMILY_TOMB_1      = 0x0574,
	ENT_SHOOTING_GALLERY_0       = 0x003B,
	ENT_SHOOTING_GALLERY_1       = 0x016D,
	//ENT_SHOOTING_GALLERY_0       = 0x02EA,
	//ENT_SHOOTING_GALLERY_0       = 0x02F0,
	ENT_TEMPLE_TIME_0            = 0x0053,
	ENT_TEMPLE_TIME_2            = 0x02CA,
	ENT_TEMPLE_TIME_3            = 0x0320,
	ENT_TEMPLE_TIME_4            = 0x0324,
	ENT_TEMPLE_TIME_5            = 0x058C,
	ENT_TEMPLE_TIME_6            = 0x0590,
	ENT_TEMPLE_TIME_7            = 0x05F4,
	ENT_CHAMBER_SAGES_0          = 0x006B,
	ENT_CHAMBER_SAGES_1          = 0x02CE,
	ENT_CASTLE_COURTYARD_0       = 0x007A,
	ENT_CASTLE_COURTYARD_1       = 0x0296,
	ENT_CUTSCENE_MAP_0           = 0x00A0,
	//ENT_CUTSCENE_MAP_0           = 0x02EF,
	ENT_DAMPE_GRAVE_0            = 0x044F,
	ENT_DAMPE_GRAVE_1            = 0x0453,
	ENT_DAMPE_GRAVE_2            = 0x0503,
	ENT_FISHING_POND_0           = 0x045F,
	ENT_ZELDA_COURTYARD_0        = 0x0400,
	ENT_ZELDA_COURTYARD_1        = 0x05F0,
	ENT_BOMBCHU_BOWLING_0        = 0x0507,
	ENT_RANCH_BUILDINGS_0        = 0x004F,
	ENT_RANCH_BUILDINGS_1        = 0x05D0,
	ENT_RANCH_BUILDINGS_2        = 0x05E4,
	ENT_LOTS_POTS_0              = 0x007E,
	ENT_GRANNY_POTION_SHOP_0     = 0x0072,
	ENT_GANON_BATTLE_0           = 0x0517,
	ENT_HOUSE_SKULLTULA_0        = 0x0550,
	ENT_HYRULE_FIELD_0           = 0x00CD,
	ENT_HYRULE_FIELD_1           = 0x017D,
	ENT_HYRULE_FIELD_2           = 0x0181,
	ENT_HYRULE_FIELD_3           = 0x0185,
	ENT_HYRULE_FIELD_4           = 0x0189,
	ENT_HYRULE_FIELD_5           = 0x018D,
	ENT_HYRULE_FIELD_6           = 0x01F9,
	ENT_HYRULE_FIELD_7           = 0x01FD,
	ENT_HYRULE_FIELD_8           = 0x027A,
	ENT_HYRULE_FIELD_9           = 0x027E,
	ENT_HYRULE_FIELD_10          = 0x0282,
	ENT_HYRULE_FIELD_11          = 0x028A,
	ENT_HYRULE_FIELD_12          = 0x028E,
	ENT_HYRULE_FIELD_13          = 0x0292,
	ENT_HYRULE_FIELD_14          = 0x0311,
	ENT_HYRULE_FIELD_15          = 0x0476,
	ENT_HYRULE_FIELD_16          = 0x050F,
	ENT_HYRULE_FIELD_17          = 0x0594,
	ENT_KAKARIKO_VILLAGE_0       = 0x00DB,
	ENT_KAKARIKO_VILLAGE_1       = 0x0191,
	ENT_KAKARIKO_VILLAGE_2       = 0x0195,
	ENT_KAKARIKO_VILLAGE_3       = 0x0201,
	ENT_KAKARIKO_VILLAGE_4       = 0x02A6,
	ENT_KAKARIKO_VILLAGE_5       = 0x0345,
	ENT_KAKARIKO_VILLAGE_6       = 0x0349,
	ENT_KAKARIKO_VILLAGE_7       = 0x034D,
	ENT_KAKARIKO_VILLAGE_8       = 0x0351,
	ENT_KAKARIKO_VILLAGE_9       = 0x044B,
	ENT_KAKARIKO_VILLAGE_10      = 0x0463,
	ENT_KAKARIKO_VILLAGE_11      = 0x04EE,
	ENT_KAKARIKO_VILLAGE_12      = 0x04FF,
	ENT_KAKARIKO_VILLAGE_13      = 0x0513,
	ENT_KAKARIKO_VILLAGE_14      = 0x0554,
	ENT_KAKARIKO_VILLAGE_15      = 0x05DC,
	ENT_KAKARIKO_GRAVEYARD_0     = 0x00E4,
	ENT_KAKARIKO_GRAVEYARD_1     = 0x0205,
	ENT_KAKARIKO_GRAVEYARD_2     = 0x0355,
	ENT_KAKARIKO_GRAVEYARD_3     = 0x0359,
	ENT_KAKARIKO_GRAVEYARD_4     = 0x035D,
	ENT_KAKARIKO_GRAVEYARD_5     = 0x0361,
	ENT_KAKARIKO_GRAVEYARD_6     = 0x050B,
	ENT_KAKARIKO_GRAVEYARD_7     = 0x0568,
	ENT_KAKARIKO_GRAVEYARD_8     = 0x0580,
	ENT_ZORA_RIVER_0             = 0x00EA,
	ENT_ZORA_RIVER_1             = 0x0199,
	ENT_ZORA_RIVER_2             = 0x019D,
	ENT_ZORA_RIVER_3             = 0x01D9,
	ENT_ZORA_RIVER_4             = 0x01DD,
	ENT_KOKIRI_FOREST_0          = 0x00EE,
	ENT_KOKIRI_FOREST_1          = 0x0209,
	ENT_KOKIRI_FOREST_2          = 0x020D,
	ENT_KOKIRI_FOREST_3          = 0x0211,
	ENT_KOKIRI_FOREST_4          = 0x0266,
	ENT_KOKIRI_FOREST_5          = 0x026A,
	ENT_KOKIRI_FOREST_6          = 0x0286,
	ENT_KOKIRI_FOREST_7          = 0x0338,
	ENT_KOKIRI_FOREST_8          = 0x033C,
	ENT_KOKIRI_FOREST_9          = 0x0443,
	ENT_KOKIRI_FOREST_10         = 0x0447,
	ENT_KOKIRI_FOREST_11         = 0x0457,
	ENT_KOKIRI_FOREST_12         = 0x05E8,
	ENT_SACRED_FOREST_MEADOW_0   = 0x00FC,
	ENT_SACRED_FOREST_MEADOW_1   = 0x0215,
	//ENT_SACRED_FOREST_MEADOW_0   = 0x02EE,
	ENT_SACRED_FOREST_MEADOW_2   = 0x0600,
	ENT_SACRED_FOREST_MEADOW_3   = 0x0608,
	ENT_LAKE_HYLIA_0             = 0x0102,
	ENT_LAKE_HYLIA_1             = 0x0219,
	ENT_LAKE_HYLIA_2             = 0x021D,
	ENT_LAKE_HYLIA_6             = 0x0309,
	ENT_LAKE_HYLIA_3             = 0x03C8,
	ENT_LAKE_HYLIA_4             = 0x03CC,
	ENT_LAKE_HYLIA_5             = 0x04E6,
	ENT_LAKE_HYLIA_7             = 0x0560,
	ENT_LAKE_HYLIA_8             = 0x0604,
	ENT_LAKE_HYLIA_9             = 0x060C,
	ENT_ZORA_DOMAIN_0            = 0x0108,
	ENT_ZORA_DOMAIN_3            = 0x0153,
	ENT_ZORA_DOMAIN_1            = 0x01A1,
	ENT_ZORA_DOMAIN_4            = 0x0328,
	ENT_ZORA_DOMAIN_2            = 0x03C4,
	ENT_ZORA_FOUNTAIN_0          = 0x010E,
	ENT_ZORA_FOUNTAIN_1          = 0x0221,
	ENT_ZORA_FOUNTAIN_2          = 0x0225,
	ENT_ZORA_FOUNTAIN_5          = 0x0394,
	ENT_ZORA_FOUNTAIN_3          = 0x03D4,
	ENT_ZORA_FOUNTAIN_4          = 0x03D8,
	ENT_GERUDO_VALLEY_0          = 0x0117,
	ENT_GERUDO_VALLEY_1          = 0x01A5,
	ENT_GERUDO_VALLEY_2          = 0x0229,
	ENT_GERUDO_VALLEY_3          = 0x022D,
	ENT_GERUDO_VALLEY_4          = 0x03D0,
	ENT_LOST_WOODS_0             = 0x011E,
	ENT_LOST_WOODS_1             = 0x01A9,
	ENT_LOST_WOODS_2             = 0x01AD,
	ENT_LOST_WOODS_3             = 0x01B1,
	ENT_LOST_WOODS_4             = 0x04C6,
	ENT_LOST_WOODS_5             = 0x04D2,
	ENT_LOST_WOODS_6             = 0x04D6,
	ENT_LOST_WOODS_7             = 0x04DA,
	ENT_LOST_WOODS_8             = 0x04DE,
	ENT_LOST_WOODS_9             = 0x05E0,
	ENT_DESERT_COLOSSUS_0        = 0x0123,
	ENT_DESERT_COLOSSUS_1        = 0x01E1,
	ENT_DESERT_COLOSSUS_2        = 0x01E5,
	ENT_DESERT_COLOSSUS_3        = 0x01E9,
	ENT_DESERT_COLOSSUS_4        = 0x01ED,
	ENT_DESERT_COLOSSUS_5        = 0x01F1,
	ENT_DESERT_COLOSSUS_6        = 0x01F5,
	ENT_DESERT_COLOSSUS_7        = 0x057C,
	ENT_DESERT_COLOSSUS_8        = 0x0610,
	ENT_GERUDO_FORTRESS_0        = 0x0129,
	ENT_GERUDO_FORTRESS_1        = 0x0231,
	ENT_GERUDO_FORTRESS_2        = 0x0235,
	ENT_GERUDO_FORTRESS_3        = 0x0239,
	ENT_GERUDO_FORTRESS_4        = 0x02AA,
	ENT_GERUDO_FORTRESS_5        = 0x02BA,
	ENT_GERUDO_FORTRESS_6        = 0x02BE,
	ENT_GERUDO_FORTRESS_7        = 0x02C2,
	ENT_GERUDO_FORTRESS_8        = 0x02C6,
	ENT_GERUDO_FORTRESS_9        = 0x02D2,
	ENT_GERUDO_FORTRESS_10       = 0x02D6,
	ENT_GERUDO_FORTRESS_11       = 0x02DA,
	ENT_GERUDO_FORTRESS_12       = 0x02DE,
	ENT_GERUDO_FORTRESS_13       = 0x03A4,
	ENT_GERUDO_FORTRESS_14       = 0x03A8,
	ENT_GERUDO_FORTRESS_15       = 0x03AC,
	ENT_GERUDO_FORTRESS_16       = 0x03B0,
	ENT_GERUDO_FORTRESS_17       = 0x03B4,
	ENT_GERUDO_FORTRESS_18       = 0x05F8,
	ENT_HAUNTED_WASTELAND_0      = 0x0130,
	ENT_HAUNTED_WASTELAND_1      = 0x0365,
	ENT_HAUNTED_WASTELAND_2      = 0x0369,
	ENT_HYRULE_CASTLE_0          = 0x0138,
	ENT_HYRULE_CASTLE_1          = 0x023D,
	ENT_HYRULE_CASTLE_2          = 0x0340,
	ENT_HYRULE_CASTLE_4          = 0x047E,
	ENT_HYRULE_CASTLE_3          = 0x04FA,
	ENT_DEATH_MOUNTAIN_TRAIL_0   = 0x013D,
	ENT_DEATH_MOUNTAIN_TRAIL_1   = 0x01B9,
	ENT_DEATH_MOUNTAIN_TRAIL_2   = 0x01BD,
	ENT_DEATH_MOUNTAIN_TRAIL_3   = 0x0242,
	ENT_DEATH_MOUNTAIN_TRAIL_4   = 0x045B,
	ENT_DEATH_MOUNTAIN_TRAIL_5   = 0x047A,
	ENT_DEATH_MOUNTAIN_CRATER_0  = 0x0147,
	ENT_DEATH_MOUNTAIN_CRATER_1  = 0x0246,
	ENT_DEATH_MOUNTAIN_CRATER_2  = 0x024A,
	ENT_DEATH_MOUNTAIN_CRATER_3  = 0x0482,
	ENT_DEATH_MOUNTAIN_CRATER_4  = 0x04F6,
	ENT_DEATH_MOUNTAIN_CRATER_5  = 0x0564,
	ENT_GORON_CITY_0             = 0x014D,
	ENT_GORON_CITY_1             = 0x01C1,
	ENT_GORON_CITY_2             = 0x03FC,
	ENT_GORON_CITY_3             = 0x04E2,
	ENT_LON_LON_RANCH_0          = 0x0157,
	ENT_LON_LON_RANCH_1          = 0x02AE,
	ENT_LON_LON_RANCH_2          = 0x02E2,
	ENT_LON_LON_RANCH_3          = 0x02E6,
	ENT_LON_LON_RANCH_4          = 0x0378,
	ENT_LON_LON_RANCH_5          = 0x042F,
	ENT_LON_LON_RANCH_6          = 0x04CA,
	ENT_LON_LON_RANCH_7          = 0x04CE,
	ENT_LON_LON_RANCH_8          = 0x0558,
	ENT_LON_LON_RANCH_9          = 0x055C,
	ENT_LON_LON_RANCH_10         = 0x05D4,
	ENT_COLLISION_TEST_0         = 0x0094,
	ENT_BESHITU_0                = 0x0520,
	ENT_DEPTH_TEST_0             = 0x00B6,
	ENT_STALFOS_MIDDLE_ROOM_0    = 0x001C,
	ENT_STALFOS_BOSS_ROOM_0      = 0x0020,
	ENT_DARK_LINK_TEST_0         = 0x0047,
	ENT_BETA_COURTYARD_0         = 0x0076,
	ENT_ACTION_TESTING_ROOM_0    = 0x0018,
	ENT_ITEM_TESTING_ROOM_0      = 0x0024,
	ENT_LOST_SCENE_0             = 0x0014,
};