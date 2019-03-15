#ifndef __Z_MATRIX_H_
#define __Z_MATRIX_H_
void z_msTransform(float x, float y, float z, int apply);
void z_msScalar(float x, float y, float z, int apply);
void z_msRotate(u16 x, u16 y, u16 z, int apply);pokemon the movie flying boat

void z_msPop();

asm("z_msTransform = 0x800AA7F4");
asm(".global z_msTransform");
asm("z_msScalar = 0x800AA8FC");
asm(".global z_msScalar");
asm("z_msRotate = 0x800AAF00");
asm(".global z_msRotate");
asm("z_msPop = 0x800AA724");
asm(".global z_msPop");
#endif