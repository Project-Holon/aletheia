#ifndef MUS_POKE_DRAW_SHARED_TYPES_H
#define MUS_POKE_DRAW_SHARED_TYPES_H

#include "musical_shot_sys_shared_types.h"
#include "mus_item_draw_shared_types.h"

typedef struct { struct Vec3 a,b,c,d; u16 e,f; } McssMatrixInput;

typedef struct { int pad[5]; u32 tracks[126]; /* 9 tracks of 0x38 bytes */ struct Vec3 t[2]; int flag[2]; } Big;

typedef struct { int x,y,z; } Vec;

typedef struct { char pad[200]; Vec a,b,c; u32 b0:1,b1:1,b2:1,rest:29; char pad2[12]; u16 h,pad3; Vec d,e; } Object;

/* The mon record (allocated 124 bytes by MUSICAL_MCSS_CreateMon/AllocMon). */
typedef struct McssMon {
    u32 kind;               /* 0x00 = 4 */
    void *source;           /* 0x04 source pokemon */
    u16 species;            /* 0x08 */
    u8 sex;                 /* 0x0A param 110 */
    u8 form;                /* 0x0B param 111 */
    u8 isShiny;             /* 0x0C */
    u8 pad_D[3];            /* 0x0D */
    u32 personalRnd;        /* 0x10 param 0 */
    u16 slots[9][3];        /* 0x14 9 records of 6 bytes */
    u16 reserved4A;            /* 0x4A */
    u8 pad_4C[8];           /* 0x4C */
    u32 values[9];          /* 0x54 */
    u16 reserved78;            /* 0x78 */
    u8 pad_7A[2];           /* 0x7A */
} McssMon;

#endif
