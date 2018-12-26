#include <ultra64.h>


typedef struct
{
	/* 0x00 */ OSContPad current;
	/* 0x06 */ OSContPad last;
	/* 0x0C */ OSContPad pressEdge;
	/* 0x12 */ OSContPad releaseEdge;
} z_Input; /*  0x0018  */

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
	
} z_GameState; /* 0xA4 bytes */


void test(z_GameState* ctx)
{
    z_Input test;
    memcpy(&test, &ctx->controllers[0], sizeof(z_Input));
    
}
