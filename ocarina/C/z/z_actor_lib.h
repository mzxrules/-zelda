#ifndef __Z_ACTOR_LIB_H_
#define __Z_ACTOR_LIB_H_
#include <ultra64.h>
#include "z_actor.h"
#include "z_game.h"
#include <h/vector.h>

//80025110 //code, graph, Spawn Actor
//A0 = Global Context + 0x1C24
//A1 = Global Context
//A2 = s16 Actor Id
//A3 = float x
//SP+0x10 = float y
//SP+0x14 = float z
//SP+0x18 = rotx
//SP+0x1C = roty
//SP+0x20 = rotz
//SP+0x24 = s16 var


extern int GiveItem(z_actor_t* actor, z_game_t* gctx, int c, float d, float e);
asm("GiveItem = 0x80022BD4");
asm(".global GiveItem");

//play sfx?
extern void Func_80022F84(z_actor_t*, u16);
asm("Func_80022F84 = 0x80022F84");
asm(".global Func_80022F84");

z_actor_t* z_SpawnActor(z_actor_ctxt_t* a_ctx, z_game_t* game, s16 id, Coord_f coord, u16 rx, u16 ry, u16 rz, u16 var);
asm("z_SpawnActor = 0x80025110");

#endif
