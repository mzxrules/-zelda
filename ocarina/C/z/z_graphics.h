#ifndef __Z_GRAPHICS_H_
#define __Z_GRAPHICS_H_
#include <ultra64.h>
typedef struct
{
	/* 0x000 */ Gfx* POLY_OPA_DISP;
	/* 0x004 */ Gfx* POLY_XLU_DISP;
	/* 0x008 */ u8 __pad_0x008[8];
	/* 0x010 */ Gfx* OVERLAY_DISP;
	/* 0x000 */
} z_gfx_t;
#endif