typedef struct {
	f32 x, y, z;
} Coord;

typedef struct {
	u16 x, y, z;
} rotation;


typedef struct
{
    struct
    {
        char Damage : 4;
        char Effect : 4;
    } Attack[0x20];
} z2_ActorDamageTable;

typedef struct
{
    /* 0x00 */ u16      id;
    /* 0x02 */ u8       type;
    /* 0x03 */ u8       room; //Room number the actor is part of. FF denotes that the actor won't despawn on a room change
    /* 0x04 */ s32      flags;
    /* 0x08 */ Coord    Pos1; //Related to collision detection routine
    /* 0x14 */ rotation initRot;
    /* 0x1A */ u16      unk_0x01A;
    /* 0x1C */ u16      variable;
    /* 0x1E */ u16      unk_0x01E;
    /* 0x20 */ u16      soundEffect; //Plays sound effect (relative to actor's location, if within range of camera?) 
    /* 0x22 */ u16      unk_0x022;
    /* 0x24 */ Coord    Pos2; //Current coordinate
    /* 0x30 */ u16      unk_0x030;
    /* 0x32 */ u16      unk_0x032;
    /* 0x34 */ char     buff[4];
    /* 0x38 */ Coord    Pos3;
    /* 0x44 */ rotation rot_1;
    /* 0x4A */ u16      unk_0x04A;
    /* 0x4C */ f32      unk_0x04C; /* I know this is a float from breakpointing it */
    /* 0x50 */ Coord    Scale;
    /* 0x5C */ char     buff2[0x54];
    

    /* 8-10-2012 : Addition made by Jason777 */
    /* For actors which contain a damage chart (example: Stalfos)... */
    typedef struct
    {
    /* 0xA0 */ z2_ActorDamageTable* DamageChart;  /* Pointer to the actor's Damage Chart in RAM. */
    /* 0xA4 */ Coord_f  displacement; //amount to correct velocity (0x5C) by when colliding into a body
    /* 0xB0 */ s16      unk_0x0B0; 
    /* 0xB2 */ s16      unk_0x0B2; 
    /* 0xB4 */ u16      unk_0x0B4; //unk
    /* 0xB6 */ u8       mass; // Used to compute displacement, 50 is common value, 0xFF for infinite mass/unmoveable
    /* 0xB7 */ u8       health; 
    /* 0xB8 */ u8       damage; 
    /* 0xB9 */ u8       damageEffect; //Stores what effect should occur when hit by a weapon
    /* 0xBA */ u8       impactEffect;
    /* 0xBB */ u8       unk_0x0BB;
    };
    
    /* 0xBC */ rotation rot_2; //Setting this immediately changes actor's rotation
    /* ? */ char buff3[0x66];
    /* 0x115 */ u8 runActor; // Determines if actor instance should be processed. 01 for yes, 00 for no.
    /* 0x128 */ struct z2_Actor* actor_prev; /* Previous z_ram_actor of this type */
    /* 0x12C */ struct z2_Actor* actor_next; /* Next z_ram_actor of this type */
    /* 0x130 */ void*   Init; //Actor Constructor?
    /* 0x134 */ void*   Dest; //Actor Deconstructor?
    /* 0x138 */ void*   Main;
    /* 0x13C */ void*   Draw;
    /* 0x140 */ void*   CodeEntry; //Address to source overlay file's reference in code (file)
    /* ? */
    /* From here on, the structure and size varies for each actor */
} z2_Actor;