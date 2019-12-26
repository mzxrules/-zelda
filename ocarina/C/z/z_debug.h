#ifndef __Z_STATICCTX_H_
#define __Z_STATICCTX_H_
typedef struct
{
    /* 0x0000 */ s32 page_no; //1 is first page
    /* 0x0004 */ s32 r_group; //"register" group (R, RS, RO, RP etc.)
    /* 0x0008 */ s32 unk_08;
    /* 0x000C */ s32 unk_0C;
    /* 0x0010 */ s32 unk_10; 
    // /* 0x0014 */ s16 mem[0xAE0];
	char __pad[0x0E60];
	/* 0x0E60 */ short SpawnOnEpona;
	/* 0x0E62 */ char __pad_0x0E62[0x772];
} z_static_ctx_t; //0x15D4 bytes

extern z_static_ctx_t *z_staticctx; //
asm("z_staticctx = 0x8011BA00");
asm(".global z_staticctx");
#endif


//(r_group * 6 + page_no) * 0x10 - 0x10