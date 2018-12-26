#ifndef __Z_BGCHECK_H_
#define __Z_BGCHECK_H_
#include <stdint.h>

typedef struct
{
  /* index of z64_col_type in col_hdr */
  uint16_t          type;                     /* 0x0000 */
  /* vertex indices, a and b are bitmasked for some reason */
  struct
  {
    uint16_t        flags               : 3;
    uint16_t        va                  : 13;
  };                                          /* 0x0002 */
  struct
  {
    uint16_t        pad_01_             : 2;
    uint16_t        conveyor            : 1;
    uint16_t        vb                  : 13;
  };                                          /* 0x0004 */
  struct
  {
    uint16_t        pad_00_             : 3;
    uint16_t        vc                  : 13;
  };                                          
  uint16_t          vc;                       /* 0x0006 */
  /* normal vector */
  Vector3_s16       norm;                     /* 0x0008 */
  /* plane distance from origin */
  int16_t           dist;                     /* 0x000E */
} z_col_poly_t; /* 0x0010 */

typedef struct
{
  struct
  {
    uint32_t        unk_00_             : 1;
    /* link drops one unit into the floor */
    uint32_t        drop                : 1;
    uint32_t        special             : 4;
    uint32_t        interaction         : 5;
    uint32_t        unk_01_             : 3;
    uint32_t        behavior            : 5;
    uint32_t        exit                : 5;
    uint32_t        camera              : 8;
  } flags_1;                                  /* 0x0000 */

  struct
  {
    uint32_t        pad_00_             : 4;
    uint32_t        wall_damage         : 1;
    uint32_t        unk_00_             : 6;
    uint32_t        unk_01_             : 3;
    uint32_t        hookshot            : 1;
    uint32_t        echo                : 6;
    uint32_t        unk_02_             : 5;
    uint32_t        terrain             : 2;
    uint32_t        material            : 4;
  } flags_2;                                  /* 0x0004 */

} z_col_type_t; /* 0x0008 */
#endif

typedef struct
{
  z64_xyz_t         min;                      /* 0x0000 */
  z64_xyz_t         max;                      /* 0x0006 */
  uint16_t          n_vtx;                    /* 0x000C */
//char              pad_00_[0x0002];          /* 0x000E */
  z64_xyz_t        *vtx;                      /* 0x0010 */
  uint16_t          n_poly;                   /* 0x0014 */
//char              pad_01_[0x0002];          /* 0x0016 */
  z64_col_poly_t   *poly;                     /* 0x0018 */
  z64_col_type_t   *type;                     /* 0x001C */
  z64_camera_t     *camera;                   /* 0x0020 */
  uint16_t          n_water;                  /* 0x0024 */
//char              pad_02_[0x0002];          /* 0x0026 */
  z64_col_water_t  *water;                    /* 0x0028 */
} z64_col_hdr_t; /* 0x002C */