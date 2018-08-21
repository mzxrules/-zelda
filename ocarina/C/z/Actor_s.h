#ifndef __Z_ACTOR_S_H_
#define __Z_ACTOR_S_H_
#include <ultra64.h>
#include <h/vector.h>

struct z_GCtx;

typedef struct
{
    struct
    {
        char Damage : 4;
        char Effect : 4;
    } Attack[0x20];
} z_ActorDamageTable;

typedef struct
{
    /* 0x00 */ u16      id; //Actor Id. 
    /* 0x02 */ u8       type; //Actor Type. See Below
    /* 0x03 */ u8       room; //Room number the actor is part of. FF denotes that the actor won't despawn on a room change
    /* 0x04 */ s32      flags; //flags used for drawing stuff?
    // & 0x0040 0000 = Affects actor lighting. 0 passes current coords to 80066298 func, else pass null for coords
    // & 0x0000 1000 = ?
    // & 0x0000 0040 = ?
    /* 0x08 */ Coord_f  pos1; //Related to collision detection routine
    /* 0x14 */ Rotation initRot; //Initial Rotation when spawned
    /* 0x1A */ u16      unk_0x01A;
    /* 0x1C */ u16      variable; //Configurable variable set by an actor's spawn data
    /* 0x1E */ s8       objTableIndex; //index to table at Global Context + 0x117A4 
    /* 0x1F */ u8       unk_0x01F;
    /* 0x20 */ u16      soundEffect; //Plays sound effect relative to actor's location (if within range of camera?)
    /* 0x22 */ u16      unk_0x022;
    /* 0x24 */ Coord_f  position; //Current coordinates
    /* 0x30 */ Rotation speedRot; //0x32 sets what direction the 0x68 speedXZ variable is moving the actor
    /* 0x36 */ u16      unk_0x036; //same as 0x1A
    /* 0x38 */ Coord_f  pos3; //Related to camera
    /* 0x44 */ Rotation rot1; //0x30 rotation copied into here
    /* 0x4A */ u16      unk_0x04A;
    /* 0x4C */ float    unk_0x04C; /* I know this is a float from breakpointing it */
    /* 0x50 */ Coord_f  scale; //sets x,y,z scaling factor. Typically, a factor of 0.01 is used for each axis
    /* 0x5C */ Coord_f  velocity;
    /* 0x68 */ float    speedXZ; //Always positive, stores how fast the actor is traveling along the XZ plane
    /* 0x6C */ float    gravity; //acceleration due to gravity; value is added to Y velocity every frame
    /* 0x70 */ float    minVelocityY; //sets the lower bounds cap on velocity along the Y axis
	//struct, collision related
    /* 0x74 */ int*     wallPoly; //Wall polygon an actor is touching
    /* 0x78 */ int*     floorPoly; //Floor polygon an actor is over/touching
    /* 0x7C */ u8       wallPolySource; //Complex Poly Surface Source. 0x32 = Scene
    /* 0x7D */ u8       floorPolySource; //Complex Poly Surface Source. 0x32 = Scene. related to 0x80/88
	/* 0x7E */ s16		wallRotation; //Orientation of the wall poly plane's positive face
    /* 0x80 */ float    unk_0x080; //floor poly height?
    /* 0x84 */ float    waterSurfaceDistance; //relative, -32000f if not near water
    /* 0x88 */ u16      bgcheckState; //
	// & 0x0001 = near floor
	// & 0x0004 = near ledge
	// & 0x0008 = near wall?
	// & 0x0020 = set in water
	// & 0x0040 = set in water
	// & 0x0080 = on the ground
    // & 0x0100 = ?
	// & 0x0200 = facing wall
    /* 0x8A */ s16      unk_roty; //rotation y (give item, possibly next facing dir?/face toward link?)
    /* 0x8C */ float    unk_0x08C;
    /* 0x90 */ float    xzDistanceFromLink; 
    /* 0x94 */ float    yDistanceFromLink; // relative distance
    /* 8-10-2012 : Addition made by Jason777 */
    /* For actors which contain a damage chart (example: Stalfos)... */
    struct 
    {
    /* 0x98 */ z_ActorDamageTable* DamageChart;  /* Pointer to the actor's Damage Chart in RAM. */
    /* 0x9C */ Coord_f  displacement; //amount to correct velocity (0x5C) by when colliding into a body
    /* 0xA8 */ s16      unk_0x0A8; 
    /* 0xAA */ s16      unk_0x0AA; 
    /* 0xAC */ u16      unk_0x0AC; //unk
    /* 0xAE */ u8       mass; // Used to compute displacement, 50 is common value, 0xFF for infinite mass/unmoveable
    /* 0xAF */ u8       health; 
    /* 0xB0 */ u8       damage; //amount to decrement health by
    /* 0xB1 */ u8       damageEffect; //Stores what effect should occur when hit by a weapon
    /* 0xB2 */ u8       impactEffect; //Maybe? set on deku nut when deku nut collides with gossip stone
    /* 0xB3 */ u8       unk_0x0B3; //?
    }; //CollisionCheck common
    
    struct 
    {
    /* 0xB4 */ Rotation rot2; //updating this value changes an actor's rotation immediately
    /* 0xBA */ 
    /* 0xBB */ u8       unk_0x0BB; //unknown byte?
    /* 0xBC */ float    unk_0x0BC; //Model y axis offset. Represents model space units. collision mesh related
    /* 0xC0 */ void*     drawDropShadow; //Draw function for Piece of Heart drop shadow?
    /* 0xC4 */ float    unk_0x0C4;
    /* 0xC8 */ u8       unk_0x0C8;
    }; //NTSC 1.0 initializes with 8001EC20
    
    /* 0xCC */ Coord_f  unk_0x0CC; //used in Link, not Deku Babas 
    /* 0xD8 */ Coord_f  unk_0x0D8; //used in Link, not Deku Babas
    /* 0xE4 */ Coord_f  unk_0x0E4; //stores result of some vector transformation involving
                        // actor xyz vector, and a matrix at Global Context + 11D60
    /* 0xF0 */ float    unk_0x0F0; //related to above
    /* 0xF4 */ float    unk_0x0F4; //unknown
    /* 0xF8 */ float    unk_0x0F8; //unknown
    /* 0xFC */ float    unk_0x0FC; //unknown
    /* 0x100 */ Coord_f Pos4; //Final Coordinates last frame (collision, NTSC 1.0 f 8002F8E0)
    /* 0x10C */ u8      unk_0x10C; //Z-Target related
    /* 0x10D */ s8      unk_0x10D; //Z-Target related
    /* 0x10E */ u16     textId; //text id to pass to link/display when interacting with an actor (navi text, probably others)
    /* 0x110 */ s16     freezeActor; //Used for the "Redead Freeze" attack
    /* 0x112 */ s16     unk_0x112; //unknown
    /* 0x114 */ u8      unk_0x114; //Deku Nut Stun Timer?, decremented toward 0 every frame
    /* 0x115 */ u8      runActor; // Determines if actor instance should be processed. 01 for yes, 00 for no.
    /* 0x116 */ u8      unknown; //set within a routine that deals with collision
    /* 0x117 */ u8      naviEnemyId; //sets what 0600 dialog to display when talking to navi. Default 0xFF
    
    /* 0x118 */ struct z_Actor* attachedA; //Interfacing Actor? 
    //e.g. Link holding chu, Chu instance stores ptr to Link instance here; 
    //     Anju having Link's ptr when giving an item;
    //     Volvagia Hole stores Volvagia Flying here
    
    /* 0x11C */ struct z_Actor* attachedB; //Attached to Actor (
	//e.g. Link holding chu, Link instance stores ptr to Bombchu instance here
    /* 0x120 */ struct z_Actor* actor_prev; /* Previous z_Actor of this type */
    /* 0x124 */ struct z_Actor* actor_next; /* Next z_Actor of this type */
    /* 0x128 */ void *Init; //Initialization Routine. Mandatory
    /* 0x12C */ void *Dest; //Actor destructor 
    /* 0x130 */ void *Main; //Main Update function, called every frame the actor is to be updated
    /* 0x134 */ void *Draw; //Draw Routine, writes necessary display lists
    /* 0x138 */ u32 CodeEntry; //Address to source overlay file's reference in code (file)
    /* From here on, the structure and size varies for each actor */
} z_Actor;
//actors with a poly-type collision mesh will always set this variable
//    /* 0x13C */ s32 PolyActorId; //Index for poly mesh

//ActorMain, Actor Draw arguments
//A0 = Actor Instance
//A1 = Global Context


typedef struct
{
    /* 0x00 */ s16 id; //value does not always match the instance's real actor number
    /* 0x02 */ u8  type; //classifies actor and determines when actor will execute
    /* 0x03 */ u8  room; //Room instance was spawned in. If value set to FF in rom, instance does not despawn when swapping rooms

    /* 0x04 */ s32 flags; //unknown, but seems to have an effect on the ability to Z-Target an actor. 
    /* 0x08 */ s16 objectId; //possibly it's primary object dependency
    /* 0x0A */ //Padding

    /* 0x0C */ int instanceSize;
    /* 0x10 */ void* Init; //Constructor
    /* 0x14 */ void* Dest; //Destructor
    /* 0x18 */ void* Main; //Main Update Function
    /* 0x1C */ void* Draw; //Draw function
} z_ActorInit;

#endif
