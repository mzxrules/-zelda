typedef struct { /* Common CollisionBody Struct (Instance) */
    z_actor_t  *actor;          /* 0x00 */
    z_actor_t  *unk_actor_1;    /* 0x04 */
    z_actor_t  *unk_actor_2;    /* 0x08 */
    z_actor_t  *unk_actor_3;    /* 0x0C */
    
    uint8_t     collider_flags; /* 0x10 */ /* compared to 0x11 */
    uint8_t     collide_flags;  /* 0x11 */ /* compared to 0x10 */
    
    /* values checked against opposing collision */
    uint8_t     mask_a;         /* 0x12 */ /* bitwise-and compared to 0x13 */
    uint8_t     mask_b;         /* 0x13 */ /* bitwise-and compared to 0x12 */ 
    uint8_t     unk_0x14;       /* 0x14 */
    
    uint8_t     type;           /* 0x15 */ 
                /* 00 = Cylinder Collection 
                   01 = Cylinder            
                   02 = Tri Collection     
                   03 = Quad */
    
} z_collider_t; /* 0x18 */


typedef struct { 
    int32_t     flags;      /* 0x00 */ /* Toucher Attack Identifier Flags */
    uint8_t     unk_0x04;   /* 0x04 */
    uint8_t     damage;     /* 0x05 */ /* damage or stun timer */ 

} z_collider_touch_t; /* 0x08 */

typedef struct {
    int32_t     flags;      /* 0x00 */ /* Collision exclusion mask */
    uint8_t     effect;     /* 0x04 */
    uint8_t     unk_0x05;   /* 0x05 */
    int32_t     unk_0x08;   /* 0x08 */ 
    
} z_collider_bump_t; /* 0x0C */

typedef struct z_collider_body_s z_collider_body_t;
struct z_collider_body_s { /* Common CollisionBodyInfo: 0x28 bytes */
    z_collider_touch_t  toucher;        /* 0x00 */    
    z_collider_bump_t   bumper;         /* 0x08 */
    uint8_t             flags;          /* 0x14 */
    uint8_t             toucher_flags;  /* 0x15 */
    uint8_t             bumper_flags;   /* 0x16 */
    uint8_t             flags_2;        /* 0x17 */
    int32_t             unk_0x18;       /* 0x18 */
    z_collider_t       *collider;       /* 0x1C */
    int32_t             unk_0x20;       /* 0x20 */
    z_collider_body_t  *colliding;      /* 0x24 */
}; /* 0x28 */

typedef struct {
    z_collider_body_t   body;           /* 0x00 */
    vec3_f32_t          pointA;         /* 0x28 */
    vec3_f32_t          pointB;         /* 0x34 */
    vec3_f32_t          pointC;         /* 0x40 */
    vec3_f32_t          unit_normal;    /* 0x4C */
    float               normal_dist;    /* 0x58 */    
    
} z_collider_tri_t; /* 0x5C */

typedef struct {
    z_collider_body_t   body;           /* 0x00 */
    vec3_s16_t          unk_0x28;       /* 0x28 */
    int16_t             unk_0x2E;       /* 0x2E */
    vec3_s16_t          position;       /* 0x30 */
    int16_t             unk_0x36;       /* 0x36 */
    int32_t             unk_0x38;       /* 0x38 */
    uint8_t             unk_0x3C;       /* 0x3C */
    
} z_collider_cylinder_t; /* 0x40 */

typedef struct {    /* Type 0 */
    z_collider_t            base;   /* 0x00 */
    int32_t                 count;  /* 0x18 */
    z_collider_cylinder_t  *list;   /* 0x1C */
    
} z_collider_cylinder_collection_t;

typedef struct {    /* Type 1 */
    z_collider_t        base;       /* 0x00 */
    z_collider_body_t   body;       /* 0x18 */
    int16_t             radius;     /* 0x40 */ 
    int16_t             height;     /* 0x42 */
    int16_t             y_shift;    /* 0x44 */
    vec3_s16_t          position;   /* 0x46 */
    
} z_collider_cylinder_main_t; /* 0x4C? */


typedef struct {    /* Type 2 */
    z_collider_t        base;   /* 0x00 */
    int32_t             count;  /* 0x18 */
    z_collider_tri_t   *list;   /* 0x1C */
    
} z_collider_tri_collection_t;

typedef struct {    /* Type 3 */
    z_collider_t        base;           /* 0x00 */
    z_collider_body_t   body;           /* 0x18 */
    vec3_f32_t          pointA;         /* 0x40 */    
    vec3_f32_t          pointB;         /* 0x4C */
    vec3_f32_t          pointC;         /* 0x58 */
    vec3_f32_t          pointD;         /* 0x64 */
    vec3_s16_t          bounding_max;   /* 0x70 */
    vec3_s16_t          bounding_min;   /* 0x76 */
    
} z_collider_quad_t; /* 0x7C? */












