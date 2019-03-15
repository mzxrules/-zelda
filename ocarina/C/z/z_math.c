#include "h/vector.h"
#include <ultra64.h>

extern float func_800CDCCC();

s16 func_80063BF0(short offset, short range)
{
    return (s16)(func_800CDCCC() * range) + offset;
}

short func_80063C44(short offset, short mult, short range)
{
    return (short)(func_800CDCCC() * range) * mult + offset;
}

void func_80063CAC(Vector3_f32* result, Vector3_f32* source)
/* Copy Vector3_f32 */
{
    result->x = source->x;
    result->y = source->y;
    result->z = source->z;
}

void func_80063CCC(Vector3_f32* result, Vector3_s16* source)
/* Convert Vector3_s16 to Vector3_f32 vector */ 
{
    result->x = source->x;
    result->y = source->y;
    result->z = source->z;
}

void func_80063D10(Vector3_f32* a, Vector3_f32* b, Vector3_f32* r)
/* Add Vector3_f32 vectors */ 
{
    r->x = b->x + a->x;
    r->y = b->y + a->y;
    r->z = b->z + a->z;
    
}

void func_80063D48(Vector3_f32* a, Vector3_f32* b, Vector3_f32* r)
/* Subtract Vector3_f32 vectors (a - b) */ 
{
    r->x = a->x - b->x;
    r->y = a->y - b->y;
    r->z = a->z - b->z;
    
}

void func_80063D80(Vector3_f32* r, Vector3_s16* a, Vector3_s16* b)
/* Subtract Vector3_s16 vectors (a - b), return Vector3_f32 */ 
{
    r->x = a->x - b->x;
    r->y = a->y - b->y;
    r->z = a->z - b->z;
}

void func_80063DDC(Vector3_f32* r, float scalar)
/* Multiply vector by scalar value */ 
{
    
    r->x *= scalar;
    r->y *= scalar;
    r->z *= scalar;
}


float func_80063E18(Vector3_f32* a, Vector3_f32* b)
/* Calculate x,y,z distance between two points */
{
    float xD, yD, zD, result;
    xD = b->x - a->x;
    result = xD * xD;
    yD = b->y - a->y;
    result += yD * yD;
    zD = b->z - a->z;
    result += zD * zD;
    return sqrtf(result);
}

float func_80063E5C(Vector3_f32* a, Vector3_f32* b, Vector3_f32* result)
/* Calculate x,y,z distance between two points, returning the difference in result */
{
    return 0;
}


