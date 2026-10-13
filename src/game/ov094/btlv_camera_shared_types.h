#ifndef BTLV_CAMERA_SHARED_TYPES_H
#define BTLV_CAMERA_SHARED_TYPES_H

#include "btlv_effvm_types.h"

typedef struct {
    int x, y, z;
} VecFx32_v6560;

typedef struct {
    int f0;
    int h4;
    char pad08[0x10];
    VecFx32_v6560 v18;        /* 0x18 */
    VecFx32_v6560 v24;        /* 0x24 */
    char pad30[0xb4 - 0x30];
    u16 hb4;            /* 0xb4 */
} Obj_021F6E3C;

typedef struct {
    char pad[4];
    void *h;            /* 0x04 */
    char pad08[0x18 - 8];
    int m[3];           /* 0x18 */
    int v[3];           /* 0x24 */
} Obj_021F6F20;

typedef int fx32;

typedef struct {
    char pad00[0x14];
    unsigned int flags;     /* 0x14 */
    VecFx32_v6560 cur0;           /* 0x18 */
    VecFx32_v6560 cur1;           /* 0x24 */
    VecFx32_v6560 dst0;           /* 0x30 */
    VecFx32_v6560 dst1;           /* 0x3c */
    VecFx32_v6560 step0;          /* 0x48 */
    VecFx32_v6560 step1;          /* 0x54 */
    char pad60[0x0c];
    int f6c;                /* 0x6c */
    int f70;                /* 0x70 */
    int f74;                /* 0x74 */
} Cam_021F6F48;

typedef struct {
    char pad00[0x14];
    unsigned int flags;     /* 0x14 */
    char pad18[0x60];
    int f78;                /* 0x78 */
    int f7c;                /* 0x7c */
    int f80;                /* 0x80 */
    int f84;                /* 0x84 */
    fx32 f88;               /* 0x88 */
    fx32 f8c;               /* 0x8c */
    int f90;                /* 0x90 */
    fx32 f94;               /* 0x94 */
    fx32 f98;               /* 0x98 */
    int f9c;                /* 0x9c */
    int fa0;                /* 0xa0 */
    int fa4;                /* 0xa4 */
    int fa8;                /* 0xa8 */
    int fac;                /* 0xac */
    int fb0;                /* 0xb0 */
} Cam_021F7000;

typedef signed short s16_021F6560;

typedef struct {
    fx32 x, y, z;
} VecFx32_021F8F30;

typedef struct {
    int mode;               /* 0x00 */
    VecFx32_021F8F30 end;            /* 0x04 */
    VecFx32_021F8F30 start;          /* 0x10 */
    VecFx32_021F8F30 step;           /* 0x1c */
    int count;              /* 0x28 */
    int countReset;         /* 0x2c */
    int wait;               /* 0x30 */
    int waitReset;          /* 0x34 */
    int repeat;             /* 0x38 */
} Mover_v8204;

#endif
