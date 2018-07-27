#ifndef __Z_GLOBALCTX_H_
#define __Z_GLOBALCTX_H_
#include <ultra64.h>
#include <z/actor_s.h>
#include <h/vector.h>
#include <z/graphicsctx.h>


typedef struct // z_getfile_t
{
  // file loading params
  u32	      	vrom_addr;
  void         *dram_addr;
  u32      		size;
  // unknown, seem to be unused
  void         *unk_00_;
  u32      		unk_01_;
  u32      		unk_02_;
  // completion notification params
  OSMesgQueue  *notify_queue; /* 0x18 */
  OSMesg        notify_message;
} z_getfile_t;

typedef enum __attribute__ ((__packed__)) e_z_Buttons
{
	INPUT_C_RIGHT	= 0x0001, 
	INPUT_C_LEFT 	= 0x0002, 
	INPUT_C_DOWN 	= 0x0004,
	INPUT_C_UP		= 0x0008,
	INPUT_R 		= 0x0010,
	INPUT_L 		= 0x0020,
	INPUT_D_RIGHT	= 0x0100,
	INPUT_D_LEFT	= 0x0200,
	INPUT_D_DOWN	= 0x0400,
	INPUT_D_UP		= 0x0800,
	INPUT_START 	= 0x1000,
	INPUT_Z			= 0x2000,
	INPUT_B			= 0x4000,
	INPUT_A 		= 0x8000,
} z_Buttons;

typedef struct
{
	z_Buttons buttons;
	s8 x;
	s8 y;
	char __pad[0x2];
} z_InputInfo;

typedef struct
{
	/* 0x00 */ z_InputInfo current;
	/* 0x06 */ z_InputInfo last;
	/* 0x0C */ z_InputInfo pressEdge;
	/* 0x12 */ z_InputInfo releaseEdge;
} z_Input; // 0x0018 

//volatile const int _wtf = sizeof(z_Input);

typedef struct
{
	/* 0x00 */ int *gfxCtx;
	/* 0x04 */ int *update;
	/* 0x08 */ int *destuctor;
	/* 0x0C */ int *init_next;
	/* 0x10 */ int size;
	/* 0x14 */ z_Input controllers[4];
	/* 0x74 */ unsigned int heap_size;
	/* 0x78 */ int *heap;
	/* 0x7C */ int *heap_free_start;
	/* 0x80 */ int *heap_free_end;
	/* 0x84 */ int *unk1;
	/* 0x88 */ int *unk2;
	/* 0x8C */ int *unk3;
	/* 0x90 */ int *unk4;
	/* 0x94 */ int *unk5;
	/* 0x98 */ int execute;
	/* 0x9C */ int updateCount;
	/* 0xA0 */ int unk6;
	
} z_GameState; //0xA4 bytes

typedef struct {
	/* 0x000 */ char __pad_0x000[0x18];
	/* 0x018 */ float angleOfView;
	/* 0x01C */ char __pad_0x01C[0x70];
	/* 0x08C */ z_GameState* gameState;
	/* 0x090 */ char __pad_0x090[0x50];
	/* 0x0E0 */ int* projectionMatrix;
	/* 0x0E4 */ int* projectionMatrixMult;
	/* 0x0E8 */ char __pad_0x0E8[0x40];
} z_VIEW_t; //0x128 bytes; 

typedef struct {
	char __pad[0x16C];
} z_Camera;


typedef struct {
	/* 0x00 */ z_Actor *actor;
	/* 0x04 */ int *mesh;
	/* 0x08 */ char __pad_0x08[0xC];
	/* 0x14 */ Vector3_f	scale1;
	/* 0x20 */ Vector3_s16	rotation1;
	/* 0x28 */ Vector3_f	pos1;
	/* 0x34 */ Vector3_f	scale2;
	/* 0x40 */ Vector3_s16	rotation2;
	/* 0x48 */ Vector3_f	pos2;
	/* 0x54 */ char __pad_0x54[0x10];
} z_ActorMesh; //0x64 bytes

typedef struct {
	/* 0x1C24 */ u8 unk_0x1C24;
	/* 0x1C25 */ u8 unk_0x1C25;
	/* 0x1C26 */ u8 unk_0x1C26;
	/* 0x1C27 */ u8 unk_0x1C27;
	
	
	/* 0x1C28 */ u32 unk_0x1C28;
	
	/* 0x1C2C */ u8 actors_count;
	/* 0x1C30 */ struct 
	{
		int count;
		z_Actor* head;
	} category[12];
} z_ActorCtx_t; //

//z_GCtx
//Global Context, or the variables accessible to the
//"game" game state
typedef struct { 
	/* 0x0000 */ z_GameState game_state;
	/* 0x00A4 */ short sceneId;
	/* 0x00A6 */ char sceneDrawSettings;
	/* 0x00A7 */ char __pad_0x00A7[9]; //unused
	/* 0x00B0 */ int *scene; //scene file ptr
	/* 0x00B4 */ int __pad_0x00B4;
	/* 0x00B8 */ z_VIEW_t VIEW;
	/* 0x01E0 */ z_Camera camera_data[4];
	/* 0x0790 */ z_Camera *cameras[4];
	/* 0x07A0 */ char __pad_0x07A0[0x20];
	/* 0x07C0 */ struct //collision
	{
		/* 0x7C0 */ int* sceneMesh; //Mesh 50, scene
		/* 0x7C4 */ Vector3_f boundsMin;
		/* 0x7D0 */ Vector3_f boundsMax;
		/* 0x7DC */ Vector3_s32 gridDimensions;
		/* 0x7E8 */ Vector3_f gridUnitSize;
		/* 0x7F4 */ Vector3_f gridUnitInverse;
		/* 0x800 */ int* lookup;
		/* 0x804 */ struct 
		{
			/* 0x804 */ short max;
			/* 0x806 */ short count;
			/* 0x808 */ int* records;
			/* 0x80C */ int* polyInfo;
		} z_CollisonDictionary_t;
	} z_Collision_t;
	/* 0x0810 */ int unk_0x0810;
	/* 0x0814 */ z_ActorMesh actorMesh[50];
	/* 0x1B9C */ short actorMeshLoaded[50];
	/* 0x1C00 */ char __pad_0x1C00[0x24]; 
	/* 0x1C24 */ z_ActorCtx_t actors;

	/* 0x1C90 */ char __pad_0x1C90[0x98]; 
	/* 0x1D28 */ int SceneSwitchFlags;
	/* 0x1D2C */ int SceneTempSwitchFlags;
	/* 0x1D30 */ int __pad_0x1D30;
	/* 0x1D34 */ int __pad_0x1D34;
	/* 0x1D38 */ int SceneChestFlags;
	/* 0x1D3C */ int SceneClearFlags;
	/* 0x1D40 */ char __pad_0x1D40[0x234];
	/* 0x1F74 */ int saveUnknown; //pointer to some unknown data
	
	/* 0x104F0 */ z_VIEW_t VIEW_2;
	/* 0x117A4 */ struct //z_ObjCtx_t
	{
		/* 0x117A4 */ void	*obj_space_start;
		/* 0x117A8 */ void	*obj_space_end;
		/* 0x117AC */ u8	obj_count;
		/* 0x117AD */ char	unk_0x117AD;
		/* 0x117AE */ u8	keep_index; //Gameplay Keep Index
		/* 0x117AF */ u8 	skeep_index; //Gameplay Field or Dungeon Keep index
		struct
		{
			s16 id;
			void* file;
			z_getfile_t getfile;
			OSMesgQueue	load_mq;
			OSMesg		load_m;
		} objects[0x13];
	} z_ObjCtx_t;
	
} z_GCtx;
#endif


//volatile const int TEST = &(((z_GCtx *)((void *)0))->saveUnknown);
