#ifndef BTLV_FIELD_SHARED_TYPES_H
#define BTLV_FIELD_SHARED_TYPES_H

#include "btlv_effvm_types.h"
#include "btlv_stage_shared_types.h"

/* The battle field: one background model with its animations (0x70 bytes). */
typedef struct BtlvField {
    G3dResource *resource;          /* 0x00: model and textures */
    int animCount;                  /* 0x04 */
    BtlvAnimState *animState;       /* 0x08: one per animation */
    G3dResource **animResource;     /* 0x0C */
    G3dAnime **anime;               /* 0x10 */
    G3dRender *render;              /* 0x14 */
    G3dObject *object;              /* 0x18 */
    G3dObjectStatus status;         /* 0x1C */
    BtlvPalFade palFade;            /* 0x58 */
    u32 hidden : 1;                 /* 0x68: the field is not drawn */
    u32 skipUpdate : 1;             /* set to skip the next update */
    u32 : 30;
    u16 heap;                       /* 0x6C */
    u16 pad_6E;                     /* struct padding */
} BtlvField;

#endif
