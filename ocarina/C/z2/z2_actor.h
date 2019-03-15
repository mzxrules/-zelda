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
    /* 0x24 */ Coord    position; //Current coordinate
    /* 0x30 */ Rotation speedRot;  /* 0x32 sets what direction the 0x70 speedXZ variable is moving the actor */
    /* 0x38 */ s8       unk_0x038;
    /* 0x39 */ u8       unk_0x039;
    
    /* 0x3C */ Coord    Pos3;
    /* 0x48 */ rotation rot_1;
    /* 0x4E */ u16      unk_0x04E;
    /* 0x50 */ u32      unk_0x050
    /* 0x54 */ f32      unk_0x054; /* I know this is a float from breakpointing it */
    
    /* 0x58 */ Coord_f  scale;     /* sets x,y,z scaling factor. Typically, a factor of 0.01 is used for each axis */
    /* 0x64 */ Coord_f  velocity;
    /* 0x70 */ float    speedXZ;   /* Always positive, stores how fast the actor is traveling along the XZ plane */
    /* 0x74 */ float    gravity;   /* acceleration due to gravity; value is added to Y velocity every frame */
    /* 0x78 */ float    minVelocityY; /* sets the lower bounds cap on velocity along the Y axis */
    
    /* struct, collision related */
    /* 0x7C */ int*     wallPoly;  /* Wall polygon an actor is touching */
    /* 0x80 */ int*     floorPoly; /* Floor polygon an actor is over/touching */
    /* 0x84 */ u8       wallPolySource; /* Complex Poly Surface Source. 0x32 = Scene */
    /* 0x85 */ u8       floorPolySource; /* Complex Poly Surface Source. 0x32 = Scene. related to 0x80/88 */
    /* 0x86 */ s16      wallRotation; /* Orientation of the wall poly plane's positive face */
    /* 0x88 */ float    unk_0x080; /* floor poly height? */
    /* 0x8C */ float    water_surface_dist; /* relative, -32000f if not near water */
    /* 0x90 */ u16      bgcheck_flags; /*  */
        /*  & 0x0001 = near floor
        /*  & 0x0004 = near ledge
        /*  & 0x0008 = near wall?
        /*  & 0x0020 = set in water
        /*  & 0x0040 = set in water
        /*  & 0x0080 = on the ground
        /*  & 0x0100 = ? 
        /*  & 0x0200 = facing wall */
    /* 0x92 */ s16      unk_roty; /* rotation y (give item, possibly next facing dir?/face toward link?) */
    /* 0x94 */ float    unk_0x094;
    /* 0x98 */ float    xzDistanceFromLink; 
    /* 0x9C */ float    yDistanceFromLink; /*  relative distance */
    

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