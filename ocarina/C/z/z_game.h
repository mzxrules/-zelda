#ifndef __Z_GAME_H_
#define __Z_GAME_H_
#include <ultra64.h>
#include <h/vector.h>
#include "z_actor.h"
#include "z_graphics.h"


typedef struct /*  z_getfile_t */
{
  /*  file loading params */
  u32	      	vrom_addr;
  void         *dram_addr;
  u32      		size;
  /*  unknown, seem to be unused */
  void         *unk_00_;
  u32      		unk_01_;
  u32      		unk_02_;
  /*  completion notification params */
  OSMesgQueue  *notify_queue; /* 0x18 */
  OSMesg        notify_message;
} z_getfile_t;

typedef struct
{
	/* 0x00 */ OSContPad current;
	/* 0x06 */ OSContPad last;
	/* 0x0C */ OSContPad pressEdge;
	/* 0x12 */ OSContPad releaseEdge;
} z_input_t; /*  0x0018  */

/* volatile const int _wtf = sizeof(z_Input); */

typedef struct
{
	/* 0x00 */ z_gfx_t *gfxCtx;
	/* 0x04 */ int *update;
	/* 0x08 */ int *destuctor;
	/* 0x0C */ int *init_next;
	/* 0x10 */ int size;
	/* 0x14 */ z_input_t controllers[4];
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
	
} z_game_common_t; /* 0xA4 bytes */

typedef struct {
	/* 0x000 */ char __pad_0x000[0x18];
	/* 0x018 */ float angleOfView;
	/* 0x01C */ char __pad_0x01C[0x70];
	/* 0x08C */ z_game_common_t* gameState;
	/* 0x090 */ char __pad_0x090[0x50];
	/* 0x0E0 */ int* projectionMatrix;
	/* 0x0E4 */ int* projectionMatrixMult;
	/* 0x0E8 */ char __pad_0x0E8[0x40];
} z_view_t; /* 0x128 bytes;  */

typedef struct {
	char __pad[0x16C];
} z_camera_t;


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
} z_ActorMesh; /* 0x64 bytes */

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
} z_actor_ctxt_t; /*  */

/* z_GCtx */
/* Global Context, or the variables accessible to the */
/* "game" game state */
typedef struct { 
	/* 0x0000 */ z_game_common_t game_state;
	/* 0x00A4 */ short sceneId;
	/* 0x00A6 */ char sceneDrawSettings;
	/* 0x00A7 */ char __pad_0x00A7[9]; /* unused */
	/* 0x00B0 */ int *scene; /* scene file ptr */
	/* 0x00B4 */ int __pad_0x00B4;
	/* 0x00B8 */ z_view_t VIEW;
	/* 0x01E0 */ z_camera_t camera_data[4];
	/* 0x0790 */ z_camera_t *cameras[4];
	/* 0x07A0 */ char __pad_0x07A0[0x20];
	/* 0x07C0 */ struct /* collision */
	{
		/* 0x7C0 */ int* sceneMesh; /* Mesh 50, scene */
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
	/* 0x1C24 */ z_actor_ctxt_t actors;

	/* 0x1C90 */ char __pad_0x1C90[0x98]; 
	/* 0x1D28 */ int SceneSwitchFlags;
	/* 0x1D2C */ int SceneTempSwitchFlags;
	/* 0x1D30 */ int __pad_0x1D30;
	/* 0x1D34 */ int __pad_0x1D34;
	/* 0x1D38 */ int SceneChestFlags;
	/* 0x1D3C */ int SceneClearFlags;
	/* 0x1D40 */ char __pad_0x1D40[0x234];
	/* 0x1F74 */ int saveUnknown; /* pointer to some unknown data */
	
	/* 0x104F0 */ z_view_t VIEW_2;
	/* 0x117A4 */ typedef struct /* z_ObjCtx_t */
	{
		/* 0x117A4 */ void	*obj_space_start;
		/* 0x117A8 */ void	*obj_space_end;
		/* 0x117AC */ u8	obj_count;
		/* 0x117AD */ char	unk_0x117AD;
		/* 0x117AE */ u8	keep_index; /* Gameplay Keep Index */
		/* 0x117AF */ u8 	skeep_index; /* Gameplay Field or Dungeon Keep index */
		struct
		{
			s16 id;
			void* file;
			z_getfile_t getfile;
			OSMesgQueue	load_mq;
			OSMesg		load_m;
		} objects[0x13];
	} z_obj_ctx_t obj_ctx;
	
} z_game_t;
#endif


/* volatile const int TEST = &(((z_game_t *)((void *)0))->saveUnknown); */
