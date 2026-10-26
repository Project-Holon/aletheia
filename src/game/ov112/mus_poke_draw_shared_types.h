#ifndef MUS_POKE_DRAW_SHARED_TYPES_H
#define MUS_POKE_DRAW_SHARED_TYPES_H

#include "../ov112/musical_shot_sys_shared_types.h"
#include "../ov112/mus_item_draw_shared_types.h"

typedef struct { struct MusItemDrawVec3 a,b,c,d; u16 e,f; } McssMatrixInput;


typedef struct { int x,y,z; } MusPokeDrawVec;

typedef struct { char pad[200]; MusPokeDrawVec a,b,c; u32 b0:1,b1:1,b2:1,rest:29; char pad2[12]; u16 h,pad3; MusPokeDrawVec d,e; } MusPokeDrawObject;

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
    u16 reserved4C[4];      /* 0x4C */
    u32 values[9];          /* 0x54 */
    u16 reserved78;            /* 0x78 */
    u8 pad_7A[2];           /* 0x7A */
} McssMon;

/* One track of a render slot (0x38 bytes). */
typedef struct {
    u32 value;                      /* 0x00 */
    struct MusItemDrawVec3 a;       /* 0x04 */
    struct MusItemDrawVec3 b;       /* 0x10 */
    struct MusItemDrawVec3 c;       /* 0x1C */
    struct MusItemDrawVec3 d;       /* 0x28 */
    u16 e;                          /* 0x34 */
    u16 f;                          /* 0x36 */
} MusPokeDrawTrack;

typedef struct MusPokeDrawSlot {
    u32 active, enabled;
    struct McssMcAnim *object;
    struct McssMcAnim *primary, *secondary;
    MusPokeDrawTrack tracks[9];
    struct MusItemDrawVec3 t[2];    /* 0x20C: 0x218 is the matrix returned by GetRenderMatrix */
    int flag[2];                    /* 0x224 */
} MusPokeDrawSlot;

/* The render object (allocated 4456 bytes by CreateRenderObj): a halfword heap
   id, then the render pool pointer and 8 slots. heap is stored as a u16. */
typedef struct MusPokeDrawScene { u16 heap; u16 pad_2; struct McssRenderPool *main; MusPokeDrawSlot slots[8]; } MusPokeDrawScene;

#endif
