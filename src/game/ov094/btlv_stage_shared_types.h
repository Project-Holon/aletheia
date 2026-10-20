#ifndef BTLV_STAGE_SHARED_TYPES_H
#define BTLV_STAGE_SHARED_TYPES_H

#include "../ov094/btlv_effvm_types.h"
#include "../ov094/btlv_camera_shared_types.h"

#include "../sdk_fx.h"
#include "../sdk_nnsfnd.h"
#include "../arm9/nns_g3d_anm_calc_types.h"
#include "../arm9/g3d_system_types.h"

/* Palette block of a texture resource (NSBTX), as in arm9/g3d_system.c. */
/* Texture resource, up to the palette block (0x40 bytes before the dictionary). */
/* Animation state of one model animation of a stage or field. */
#define BTLV_ANIM_LOOP  0   /* plays at normal speed forever */
#define BTLV_ANIM_TIMED 1   /* plays at a set speed for a set number of updates when armed */

typedef struct BtlvAnimState {
    int kind;           /* 0x00: BTLV_ANIM_* */
    int armed;          /* 0x04: 1 while a timed run is active */
    int speed;          /* 0x08: frame step of the timed run */
    int updatesLeft;    /* 0x0C */
} BtlvAnimState;

/*
 * Palette fade of a background texture (16 bytes). The enabled flag is the
 * "effect active" test of the stage and the field.
 */
typedef struct BtlvPalFade {
    G3dResource **resources;    /* 0x00: textures whose palettes are blended */
    u16 **palettes;             /* 0x04: blended palette buffers, one per texture */
    u8 enabled;                 /* 0x08 */
    u8 count;                   /* 0x09: number of textures */
    u8 current;                 /* 0x0A: current blend level */
    u8 target;                  /* 0x0B */
    u8 wait;                    /* 0x0C: updates left before the next level */
    u8 interval;                /* 0x0D */
    u16 color;                  /* 0x0E: RGB555 blended toward */
} BtlvPalFade;

/* One group of the stage resource table (archive 0x98 member 2). */
typedef struct BtlvStageFiles {
    int unknown00;              /* 0x00: not read by the code */
    int fileId[4][4];           /* 0x04: [0][v] model, [1..3][v] animations, v = variant; -1 = none */
} BtlvStageFiles;

/* The battle stage: ground model drawn twice (0xBC bytes). */
typedef struct BtlvStage {
    G3dResource *resource;          /* 0x00: model and textures */
    int animCount;                  /* 0x04 */
    BtlvAnimState *animState[2];    /* 0x08: per side */
    G3dResource **animResource;     /* 0x10 */
    G3dAnime **anime[2];            /* 0x14: per side */
    G3dRender *render[2];           /* 0x1C */
    G3dObject *object[2];           /* 0x24 */
    G3dObjectStatus status[2];      /* 0x2C: draw position of each side */
    BtlvPalFade palFade;            /* 0xA4 */
    u32 hiddenMask : 2;             /* 0xB4: bit n hides side n */
    u32 : 30;
    u16 heap;                       /* 0xB8 */
    u16 pad_BA;                     /* struct padding */
} BtlvStage;

#endif
