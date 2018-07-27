#include <stddef.h>
#include <z/Actor.h>
#include <z/SaveCtx.h>
#include <z/GlobalCtx.h>
#include <z/Matrix.h>

#define ActorId 0x00D8

//VROM Start 0347 E000
//ovl cust.o 80B87280
//ovl C:\Users\mzxrules\Documents\c\work\act\cust.o 80B87280
//VRAM Start 80B87280  //80B873A0



void Init(z_Actor *actor, z_GCtx *gctx);
void Update(z_Actor *actor, z_GCtx *gctx);
void Draw(z_Actor *actor, z_GCtx *gctx);

int test[] = {
	offsetof(z_GameState, controllers),
	offsetof(z_GameState, controllers[0].last)
};

typedef struct {
	z_Actor actor;
} CustomInst;

int HaveItem = 0;
int SpawnedActor = 0;

z_ActorInit initVars = 
{
	.id = ActorId,
	.type = 1,
	.room = 0xFF,
	.flags = 0,
	.objectId = 0x00B9,
	.instanceSize = sizeof(CustomInst),
	.Init = (void *)Init,
	.Dest = 0,
	.Main = (void *)Update,
	.Draw = (void *)Draw
};



void Update(z_Actor *actor, z_GCtx *gctx)
{
	int test;
	z_GameState state = gctx->game_state;
	z_Input input = state.controllers[0];
	
	z_Buttons press = input.pressEdge.buttons;
	z_Buttons cur = input.current.buttons;
	
	int mytest = gctx->z_Obj_Ctx.objects[4].id;
	
	/*
	if (press & INPUT_L && z_savectx.rupees <=  0x1F2)
	{
		z_savectx.rupees += 1;
	}
	
	if (press & INPUT_R && z_savectx.rupees > 0)
	{
		z_savectx.rupees -= 1;
	}
	
	if (cur & INPUT_Z)
	{
		Func_80022F84(actor, 0x6000+z_savectx.rupees );
	}
	*/
	if (SpawnedActor < 10 && (press & INPUT_L))
	{
		SpawnedActor++;
		
		Rotation r = actor->rot2;
        z_SpawnActor(&gctx->actors, gctx, 0x1AF, actor->pos1, r.x, r.y, r.z, 0x0000);
	}
	
	if (!HaveItem)
	{
		if (GiveItem(actor, gctx, 0x3F, 50.0f, 200.0))
		{
			HaveItem = 1;
		}
	}	

}

//get object file index
int Func_80081628(z_GCtx* gctx, s16 object);
asm("Func_80081628 = 0x80081628");
asm(".global Func_80081628");

//test if object file dependency is loaded
int Func_80081688(int* objtbl, s16 index);
asm("Func_80081688 = 0x80081688");
asm(".global Func_80081688");

//draw get item
int Func_800582C0(z_GCtx*, s16 index);
asm("Func_800582C0 = 0x800582C0");
asm(".global Func_800582C0");

const float SCALE_FACTOR = 0.4f;

void Init(z_Actor* actor, z_GCtx* gctx)
{
	//actor->roomNo = 0xFF;
	//int objIndex = Func_80081628()
	actor->scale.x = SCALE_FACTOR;
	actor->scale.y = SCALE_FACTOR;
	actor->scale.z = SCALE_FACTOR;
}

void Draw(z_Actor* actor, z_GCtx* gctx)
{
	if (HaveItem)
		return;
	
	//Coord coord = actor->pos1;
	//Coord scale = actor->scale;
	actor->rot2.y += 0x400;
	//z_msTransform(0, 20, 0, 1);
	//z_msRotate(rot.x, rot.y, rot.z, 1);
	//z_msScalar(scale.x, scale.y, scale.z, 1);
	Func_800582C0(gctx, 9);
	//z_msPop();
}

//custom actor collision notes
//8004AB7C //initialize collision body struct
