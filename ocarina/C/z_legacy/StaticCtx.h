#ifndef __Z_STATICCTX_H_
#define __Z_STATICCTX_H_
typedef struct
{
	char __pad[0x0E60];
	/* 0x0E60 */ short SpawnOnEpona;
	/* 0x0E62 */ char __pad_0x0E62[0x772];
} z_StaticCtx; //0x15D4 bytes

extern z_StaticCtx *z_staticctx; //
asm("z_staticctx = 0x8011BA00");
asm(".global z_staticctx");
#endif