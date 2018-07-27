#include <ultra64.h>
#ifndef __H_VECTOR_H_
#define __H_VECTOR_H_
typedef struct
{
	f32 x, y, z;
} Vector3_f32;

typedef struct
{
	s16 x, y, z;
} Vector3_s16;

typedef struct
{
	s32 x, y, z;
} Vector3_s32;

typedef Vector3_f32 Coord_f;

typedef Vector3_s16 Coord_s16;

typedef struct {
    u16 x, y, z;
} Rotation;
#endif